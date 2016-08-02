include(CMakeParseArguments)

macro(cnavio2_add_library target)

    # parse the arguments
    cmake_parse_arguments(THIS "" "" "SOURCES;DEPENDS;EXTERNAL_LIBS" ${ARGN})

    # create the target
    add_library(${target} ${THIS_SOURCES})

    # define the export symbol of the module
    string(REPLACE "-" "_" NAME_UPPER "${target}")
    string(TOUPPER "${NAME_UPPER}" NAME_UPPER)
    set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORTS)

    set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)

    # set the version and soversion of the target (for compatible systems -- mostly Linuxes)
    set_target_properties(${target} PROPERTIES SOVERSION ${VERSION_MAJOR})
    set_target_properties(${target} PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR})

    # set the target's folder (for IDEs that support it, e.g. Visual Studio)
    set_target_properties(${target} PROPERTIES FOLDER "CNAVIO2")

    set_target_properties(${target} PROPERTIES COMPILE_FLAGS -fvisibility=hidden)

    target_link_libraries(${target} ${THIS_DEPENDS})

    # add the install rule
    install(TARGETS ${target}
            RUNTIME DESTINATION bin COMPONENT bin
            LIBRARY DESTINATION lib${LIB_SUFFIX} COMPONENT bin 
            ARCHIVE DESTINATION lib${LIB_SUFFIX} COMPONENT devel)

endmacro()

macro(cnavio2_add_example target)

    # parse the arguments
    cmake_parse_arguments(THIS "" "" "SOURCES;DEPENDS" ${ARGN})

    # create the target
    add_executable(${target} ${THIS_SOURCES})

    target_link_libraries(${target} ${THIS_DEPENDS} CNavio2)

endmacro()
