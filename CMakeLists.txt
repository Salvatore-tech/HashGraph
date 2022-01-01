cmake_minimum_required(VERSION 3.21)
project(HashGraph)

set(CMAKE_CXX_STANDARD 20)

add_executable(HashGraph main.cpp Graph/TreeNode.h Graph/DirectedGraph.cpp Graph/DirectedGraph.h HashTable.cpp HashTable.h)
