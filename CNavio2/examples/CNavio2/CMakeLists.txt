# include the CNavio2 specific macros
include(${CMAKE_SOURCE_DIR}/cmake/Macros.cmake)

# add the CNavio2 headers path
include_directories(${CMAKE_SOURCE_DIR}/include)

# set the output directory for CNavio2 examples
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

set(SRCROOT ${CMAKE_SOURCE_DIR}/examples/CNavio2)

set(MPU9250_SRC
    ${SRCROOT}/MPU9250.cpp
)

# define the cnavio2 target
cnavio2_add_example(MPU9250
                  SOURCES ${MPU9250_SRC}
                  DEPENDS )
