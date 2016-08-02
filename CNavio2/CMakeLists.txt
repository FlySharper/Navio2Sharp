cmake_minimum_required(VERSION 2.8)

# define a macro that helps defining an option
macro(cnavio2_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# set a default build type if none was provided
cnavio2_set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release)")

# project name
project(CNavio2)

# setup version numbers
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# add the CNavio header path
include_directories(${CMAKE_SOURCE_DIR}/include)

# add an option for choosing the build type (shared or static)
cnavio2_set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build CNavio2 as a shared library, FALSE to build it as a static library")

# add an option for building examples
cnavio2_set_option(CNAVIO2_BUILD_EXAMPLES FALSE BOOL "TRUE to build CNavio2 examples, FALSE to skip")

# disable the rpath stuff
set(CMAKE_SKIP_BUILD_RPATH TRUE)
if(NOT MSVC)
    set(CMAKE_CXX_FLAGS -std=c++11)
endif()

# add the subdirectories
add_subdirectory(src/CNavio2)

if(CNAVIO2_BUILD_EXAMPLES)
    add_subdirectory(examples/CNavio2)
endif()

# setup the install rules
install(DIRECTORY include
        DESTINATION .
        COMPONENT devel
        PATTERN ".svn" EXCLUDE)
