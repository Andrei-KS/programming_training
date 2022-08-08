#[[-------------------------------------------------------------------------
                    Connecting the necessary modules
]]#-------------------------------------------------------------------------
include(create_paths_list_to)

#[[-------------------------------------------------------------------------
                    Definition and description of function
]]#-------------------------------------------------------------------------
#[[
# This function creat a lib from files. Also, so that there are no problems during
# the first assembly, instead of the created library, it creates a stub.
# 
# @name   : creat_lib_from_files
# @param  : SHOWE_INFO_MESSAGE    - option that allows showing of extra info of the paths making process
# @param  : NAME_LIB              - will be title of the lib that will be made
# @param  : NAME_TARGET           - will depend on target of this lib to ensure that it build before name_target does.
# @param  : INCLUDES_DIRECTORIES  - will be involved to find include files
# @param  : SRC_DIRECTORIES       - will be involved to find source files
# @param  : SRC_IGNORE_NAMES      - source files that use these names is excluded
# @param  : SRC_EXTRA_FILES       - will be added
# @param  : LIB_DIRECTORIES       - will be involved to find lib files
# @param  : LIB_IGNORE_NAMES      - lib files that use these names is excluded
# @param  : EXTRA_LIBS            - will be added
# @param  : DEPENDENCIES_ON       - this library will be depended on these target
# @return : NONE
#
# @requirement cmake_minimum_required 8.0 
# @author Andrei-KS
]]#
function(creat_lib_from_files)
  set(options
    SHOWE_INFO_MESSAGE
  )
  set(args
    NAME_LIB
    NAME_TARGET
  )
  set(list_Args
    INCLUDES_DIRECTORIES
    SRC_DIRECTORIES
    SRC_IGNORE_NAMES
    SRC_EXTRA_FILES
    LIB_DIRECTORIES
    LIB_IGNORE_NAMES
    EXTRA_LIBS
    DEPENDENCIES_ON
  )
  cmake_parse_arguments(
    PARSE_ARGV 0
    creat_lib_from_files
    "${options}"
    "${args}"
    "${list_Args}"
  )

  if(NOT DEFINED creat_lib_from_files_NAME_LIB)
    message(FATAL_ERROR "Error : NAME_LIB is not defined")
  endif()

  if(creat_lib_from_files_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Error : Unparsed argument: ${creat_lib_from_files_UNPARSED_ARGUMENTS}")
  endif()

  message(STATUS "Call creat_lib_from_files(NAME_LIB ${creat_lib_from_files_NAME_LIB} ...)")

  if(creat_lib_from_files_SHOWE_INFO_MESSAGE)
    message(STATUS "Name lib will be ${creat_lib_from_files_NAME_LIB}")
    message(STATUS "${creat_lib_from_files_NAME_TARGET} depend on ${creat_lib_from_files_NAME_LIB}")
      
    message("Directories List To Include: ${creat_lib_from_files_INCLUDES_DIRECTORIES}")

    message("Directories List To Src: ${creat_lib_from_files_SRC_DIRECTORIES}")
    message("Ignore List To Src: ${creat_lib_from_files_SRC_IGNORE_NAMES}")
    message("Extra Src Files: ${creat_lib_from_files_SRC_EXTRA_FILES}")

    message("Directories List To Lib: ${creat_lib_from_files_LIB_DIRECTORIES}")
    message("Ignore List To Lib: ${creat_lib_from_files_LIB_IGNORE_NAMES}")
    message("Extra Libs: ${creat_lib_from_files_EXTRA_LIBS}")
    message("Dependencies on: ${creat_lib_from_files_DEPENDENCIES_ON}")
  endif()


  # Local Paths to sources files of lib
  set(paths_To_SRC)
  # Get all paths of files for source of packege
  create_paths_list_to(
    paths_To_SRC
    DIRECTORIES   ${creat_lib_from_files_SRC_DIRECTORIES}
    IGNORE_NAMES  ${creat_lib_from_files_SRC_IGNORE_NAMES}
    EXTRA_FILES   ${creat_lib_from_files_SRC_EXTRA_FILES}
    EXTENSION     "cpp" "c"
  )

  # Local Paths to additional libs of current lib
  set(paths_To_Lib)
  # Get all paths of files for source of packege
  create_paths_list_to(
    paths_To_Lib
    DIRECTORIES   ${creat_lib_from_files_LIB_DIRECTORIES}
    IGNORE_NAMES  ${creat_lib_from_files_LIB_IGNORE_NAMES}
    EXTRA_FILES   ${creat_lib_from_files_SRC_EXTRA_FILES}
    EXTENSION     "lib"
  )

  if(creat_lib_from_files_SHOWE_INFO_MESSAGE)
    message("paths_To_SRC: ${paths_To_SRC}")
    message("paths_To_Lib: ${paths_To_Lib}")
  endif()

  # Creat lib
  if(paths_To_SRC)
    add_library(${name_Lib} STATIC ${paths_To_SRC})
    foreach(include_Path IN LISTS creat_lib_from_files_INCLUDES_DIRECTORIES)
      target_include_directories(${name_Lib} PUBLIC "${include_Path}/")
    endforeach()

    if(paths_To_Lib)
      target_link_libraries(${name_Lib} PRIVATE ${paths_To_Lib})
    endif()
  else()
      message(WARNING "Warrning: paths_To_SRC does not constened anything")
  endif()

  # make dependence
  if(creat_lib_from_files_NAME_TARGET)
    add_dependencies(${creat_lib_from_files_NAME_TARGET} ${creat_lib_from_files_NAME_LIB})
  endif()
  if(creat_lib_from_files_DEPENDENCIES_ON)
    add_dependencies(${creat_lib_from_files_NAME_LIB} ${creat_lib_from_files_DEPENDENCIES_ON})
  endif()

endfunction()