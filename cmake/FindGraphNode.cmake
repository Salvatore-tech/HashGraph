set(FIND_GRAPHNODE_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../Libraries/graphnode)

find_path(GRAPHNODE_INCLUDE_DIR GraphNode.h
        PATH_SUFFIXES include
        PATHS ${FIND_GRAPHNODE_PATHS})

find_library(GRAPHNODE_LIBRARY               # The variable to store where it found the .a files
        NAMES graphnode                      # The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES build                   # The folder the .a file is in
        PATHS ${FIND_GRAPHNODE_PATHS})