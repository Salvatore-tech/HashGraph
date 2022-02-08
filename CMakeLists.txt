cmake_minimum_required(VERSION 3.21)
project(HashGraph)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(INCLUDE_FILES hash_table/HashTable.h IO/InputOutputHandler.h IO/FileMetadata.h hash_table/HashTableIterator.h hashing_strategy/api/HashingStrategy.h hashing_strategy/api/DoubleHashingStrategy.h hashing_strategy/api/LinearProbingStrategy.h)
set(SOURCE_FILES main.cpp hash_table/HashTable.cpp IO/InputOutputHandler.cpp hash_table/HashTableIterator.cpp hashing_strategy/impl/DoubleHashingStrategy.cpp hashing_strategy/impl/LinearProbingStrategy.cpp)
add_executable(HashGraph ${INCLUDE_FILES} ${SOURCE_FILES})


include(FindPkgConfig)
find_package(GraphNode REQUIRED)
include_directories(${GRAPHNODE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GRAPHNODE_LIBRARY})