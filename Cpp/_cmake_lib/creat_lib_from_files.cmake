#[[-------------------------------------------------------------------------
                    Connecting the necessary modules
]]#-------------------------------------------------------------------------
include(creat_list_path_to_src)

#[[-------------------------------------------------------------------------
                    Definition and description of function
]]#-------------------------------------------------------------------------
#[[
# This function creat a lib from files. Also, so that there are no problems during
# the first assembly, instead of the created library, it creates a stub.
# 
# @name             : creat_lib_from_files
# @param            : nameLib
# @external params  : EP_CLFF_Includes  - paths to necessary include`s folders
# @external params  : EP_CLFF_Src       - paths (if set path, this is only name cpp file) to necessary cpp file folder
# @external params  : EP_CLFF_SrcFiles  - names necessary cpp file
# @external params  : EP_CLFF_Libs      - paths to necessary libs
# @return           : none
#
# @author Andrei-KS
]]#
function(creat_lib_from_files nameLib)
    #Since the library will be built after the build process has started, a stub file will be created in the absence of this library file. 
    if(NOT EXISTS "${PROJECT_BINARY_DIR}/${nameLib}.lib")
	    file(WRITE "${PROJECT_BINARY_DIR}/${nameLib}.lib" "IS EMPTY")
    endif()

	message(STATUS "Name package is ${nameLib}")
    message("ListPathToInclude: ${EP_CLFF_Includes}")
    message("ListPathToSrc: ${EP_CLFF_Src}")
    message("ListNamesSRCfiles: ${EP_CLFF_SrcFiles}")
    message("ListPathToLibs: ${EP_CLFF_Libs}")

    # Local Paths to sources files of package
    set(pathsToSRC)
    set(EP_CLP_Directories ${EP_CLFF_Src})
    set(EP_CLP_FileNames ${EP_CLFF_SrcFiles})
    # Get all paths of files for source of packege
    creat_list_path_to_src(pathsToSRC)
    message("pathsToSRC: ${pathsToSRC}")

    #Creat lib
    if(pathsToSRC)
        add_library(${nameLib} STATIC ${pathsToSRC})
        foreach(includePath IN LISTS EP_CLFF_Includes)
            target_include_directories(${nameLib} PUBLIC "${includePath}/")
        endforeach()

        set(UsingLibs)
        foreach(curNameLib IN LISTS EP_CLFF_Libs)
            file(GLOB NameLib "${curNameLib}.lib")
			if(NOT NameLib)
                message(WARNING "Warrning: Not found ${curNameLib}.lib")
            endif()
            list(APPEND UsingLibs ${NameLib})
        endforeach()
        if(UsingLibs)
            target_link_libraries(${nameLib} PRIVATE ${UsingLibs})
        endif()
    else()
        message(WARNING "Warrning: pathsToSRC does not constened anything")
    endif()

endfunction()