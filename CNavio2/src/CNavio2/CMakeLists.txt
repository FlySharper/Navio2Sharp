# include the CNavio2 specific macros
include(${CMAKE_SOURCE_DIR}/cmake/Macros.cmake)

# add the CNavio2 sources path
include_directories(${CMAKE_SOURCE_DIR}/src)

# set the output directory for CNavio2 libraries
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

# define the export symbol
add_definitions(-DCNAVIO2_EXPORTS)

set(INCROOT ${CMAKE_SOURCE_DIR}/include/CNavio2)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/CNavio2)

cnavio2_set_option(NAVIO2_ROOT_DIR "NAVIO2_ROOT_DIR Not Found" PATH "Navio2 Root Directory")
include_directories(${NAVIO2_ROOT_DIR}/C++)

# all source files
set(SRC
    ${INCROOT}/Export.h
    ${INCROOT}/MPU9250.h
    ${SRCROOT}/MPU9250.cpp
    ${INCROOT}/Types.h
)

# define the cnavio2 target
cnavio2_add_library(CNavio2
                  SOURCES ${SRC}
                  DEPENDS )
