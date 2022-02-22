set(FIND_HASHINGSTRATEGY_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../Libraries/hashing_strategy)

find_path(HASHINGSTRATEGY_INCLUDE_DIR HashingStrategy.h LinearProbingStrategy.h DoubleHashingStrategy.h
        PATH_SUFFIXES include
        PATHS ${FIND_HASHINGSTRATEGY_PATHS})

find_library(HASHINGSTRATEGY_LIBRARY               # The variable to store where it found the .a files
        NAMES hashing_strategy                      # The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES build                   # The folder the .a file is in
        PATHS ${FIND_HASHINGSTRATEGY_PATHS})