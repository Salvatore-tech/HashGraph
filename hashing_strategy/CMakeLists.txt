project(hashing_strategy)
set(SOURCE_FILES impl/LinearProbingStrategy.cpp impl/DoubleHashingStrategy.cpp)
set(HEADER_FILES api/LinearProbingStrategy.h api/DoubleHashingStrategy.h)
add_library(hashing_strategy STATIC ${HEADER_FILES} ${SOURCE_FILES})