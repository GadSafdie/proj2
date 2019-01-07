cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(proj2 main.cpp ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h CacheManager.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Problem.h Problem.cpp Solution.h Solution.cpp Solver.h StringReverser.cpp StringReverser.h Main.cpp Main.h ReadFile.cpp ReadFile.h WriteFile.cpp WriteFile.h)