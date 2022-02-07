cmake_minimum_required(VERSION 3.21)
project(HashGraph)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(SOURCE_FILES main.cpp HashTable/HashTable.cpp HashTable/HashTable.h IO/InputOutputHandler.cpp IO/InputOutputHandler.h IO/FileMetadata.h HashTable/HashTableIterator.cpp HashTable/HashTableIterator.h HashTable/hashingStrategy/api/HashingStrategy.h HashTable/hashingStrategy/impl/DoubleHashingStrategy.cpp HashTable/hashingStrategy/api/DoubleHashingStrategy.h HashTable/hashingStrategy/impl/LinearProbingStrategy.cpp HashTable/hashingStrategy/api/LinearProbingStrategy.h)
add_executable(HashGraph ${SOURCE_FILES})


include(FindPkgConfig)
find_package(GraphNode REQUIRED)
include_directories(${GRAPHNODE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GRAPHNODE_LIBRARY})