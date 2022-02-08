set(FIND_IOGRAPH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../Libraries/iograph)

find_path(IOGRAPH_INCLUDE_DIR FileMetadata.h InputOutputHandler.h
        PATH_SUFFIXES include
        PATHS ${FIND_IOGRAPH_PATHS})

find_library(IOGRAPH_LIBRARY               # The variable to store where it found the .a files
        NAMES iograph                      # The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES lib                   # The folder the .a file is in
        PATHS ${FIND_IOGRAPH_PATHS})