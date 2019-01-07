//
// Created by gad on 1/6/19.
//
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "ReadFile.h"

map<string, string> ReadFile::ReadFileCacheManager() {
    map<string, string> le;
    string first = "";
    string second = "";
    std::ifstream infile("RFCM.txt");
    if (infile.is_open()) {
        std::string line;
        while (getline(infile, line)) {
            int flag = 0;
            if (line != "") {
                for (int i = 0; i < line.length(); ++i) {
                    if (line[i] != '$') {
                        first = first + line[i];
                    } else {
                        if (flag == 0) {
                            flag = 1;
                        } else {
                            second = second + line[i];
                        }

                    }
                }
                le.insert(std::pair<string, string>(first, second));


            } else {
                string first = "";
                string second = "";
                break;
            }
        }
        infile.close();
        remove("RFCM.txt");
    }
    return le;
}