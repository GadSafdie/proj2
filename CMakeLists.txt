cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj2 main.cpp FileCacheManager.cpp FileCacheManager.h CacheManager.cpp CacheManager.h Problem.cpp Problem.h Solution.cpp Solution.h)