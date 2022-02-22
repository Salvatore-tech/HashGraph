cmake_minimum_required(VERSION 3.21)
project(HashGraph)
set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(INCLUDE_FILES hash_table/api/HashTable.h hash_table/api/HashTableIterator.h)
set(SOURCE_FILES main.cpp hash_table/impl/HashTable.cpp hash_table/impl/HashTableIterator.cpp)
add_executable(HashGraph ${INCLUDE_FILES} ${SOURCE_FILES})

include(FindPkgConfig)
find_package(GraphNode REQUIRED)
include_directories(${GRAPHNODE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GRAPHNODE_LIBRARY})

include(FindPkgConfig)
find_package(IOGraph REQUIRED)
include_directories(${IOGRAPH_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${IOGRAPH_LIBRARY})

include(FindPkgConfig)
find_package(HashingStrategy REQUIRED)
include_directories(${HASHINGSTRATEGY_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${HASHINGSTRATEGY_LIBRARY})