//
// Created by hezi on 1/14/19.
//

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include "Searcher.h"
#include "algorithm"
using namespace std;

template <class T>
class AStar:public Searcher<T>{
    vector<State<T>*> openList;

    string search(Searchable<T> *searchable){
        int k= 0 ;
        vector<State<T>*> closeList;
        State<T>* goal = searchable->getGoalState();
        State<T>* start = searchable->getInitalState();

        double f = abs(start->getNumRow() - goal->getNumRow()) +abs(start->getNumCol() - goal->getNumCol());

        this->openList.push_back(start);

        while(!this->openList.empty()){

            State<T>* current = this->valowest(goal);
            current->setHasVisited();

            closeList.push_back(current);
            this->evaluatedNodes++;
            //end of the algorithm
            if(current->getState() == goal->getState()){
                break;
            }
            vector<State<T>*> neighbors = searchable->getAllPossibleStatesAstar(current);
            while (!neighbors.empty()){
                State<T>* temp = neighbors.back();
                neighbors.pop_back();
                if(temp ->getHasVisited()){
                    continue;
                }
                double pathFromCurrent = current->getpathCost()+temp->getCost();
                if(find(this->openList.begin(),this->openList.end(),temp)!=this->openList.end()){
                    if(temp->getpathCost()<pathFromCurrent){
                        continue;
                    }
                }else if(find(closeList.begin(),closeList.end(),temp)!=closeList.end()){
                    if(temp->getpathCost()<pathFromCurrent) {
                        continue;
                    }
                    this->moveToOpen(closeList,temp);

                }else{
                    this->openList.push_back(temp);
                }
                temp->setpathCost(pathFromCurrent);
                temp->setcameFrom(current);
            }
        }
        vector<State<T>*> path = searchable->backtrace(searchable->getGoalState());
        string solution =  searchable->getDirections(path);
        if(solution == ""){
           searchable->getGoalState()->setpathCost(-1);
        }
        return solution;
    }

    State<T>* valowest(State<T>* goal) {
        vector<State<T>*> temp;

        State<T>* lowest = openList.back();
        openList.pop_back();


        double huristic = abs(lowest->getNumRow() - goal->getNumRow()) +abs(lowest->getNumCol() - goal->getNumCol());
        double first = huristic + lowest->getpathCost();

        while(!this->openList.empty()){
            State<T>* state = openList.back();
            openList.pop_back();


            huristic = abs(state->getNumRow() - goal->getNumRow()) +abs(state->getNumCol() - goal->getNumCol());
            double newCost = huristic + state->getpathCost();

            if(newCost<first){
                first = newCost;
                temp.push_back(lowest);
                lowest = state;
                continue;
            }
            temp.push_back(state);
        }

        for(int i = 0 ; i < temp.size();i++){
            this->openList.push_back(temp[i]);
        }
        return lowest;
    }

    void moveToOpen(vector<State<T>*> close, State<T>* temp){
        vector<State<T>*> move;
        typename vector<State<T>*>::iterator it;
        it = close.begin();
        for(;it !=close.end();++it){
            State<T>* now = close.back();
            close.pop_back();
            move.push_back(now);
            if(now == temp){
                this->openList.push_back(now);
                return;
            }
        }
    }

};




#endif //PROJ2_ASTAR_H
