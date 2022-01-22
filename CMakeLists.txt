cmake_minimum_required(VERSION 3.21)
project(HashGraph)

set(CMAKE_CXX_STANDARD 20)

add_executable(HashGraph main.cpp Graph/TreeNode.h HashTable.cpp HashTable.h IO/RWFileHandler.cpp IO/RWFileHandler.h IO/FileMetadata.h)
