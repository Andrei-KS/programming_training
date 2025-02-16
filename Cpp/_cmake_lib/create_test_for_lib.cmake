#[[-------------------------------------------------------------------------
                    Connecting the necessary modules
]]#-------------------------------------------------------------------------
include(creat_list_path_to_src)

#[[-------------------------------------------------------------------------
                    Definition and description of function
]]#-------------------------------------------------------------------------
#[[
# This function make unit test for lib
#
# @name             : creat_test_for_lib
# @param            : nameTest
# @external params  : EP_CTFL_Includes          - paths to necessary include`s folders
# @external params  : EP_CTFL_Libs              - paths to necessary libs
# @external params  : EP_CTFL_TestSrcDir        - paths (if set path, this is only name cpp file) to necessary cpp file folder
# @external params  : EP_CTFL_NamesTestSRCfiles - names necessary test cpp file
# @return           : none
#
# @author Andrei-KS
]]#
function(create_test_for_lib nameTest)
	message(STATUS "Name test is ${nameTest}")
	message("ListPathToInclude: ${EP_CTFL_Includes}")
	message("ListPathToLibs: ${EP_CTFL_Libs}")
	message("ListPathToTestSrc: ${EP_CTFL_TestSrcDir}")
	message("ListNamesTestSRCfiles: ${EP_CTFL_NamesTestSRCfiles}")

	# Local Paths to sources files of package
    set(pathsToSRC)
    set(EP_CLP_Directories ${EP_CTFL_TestSrcDir})
    set(EP_CLP_FileNames ${EP_CTFL_NamesTestSRCfiles})
    # Get all paths of files for source of packege
    create_list_path_to_src(pathsToSRC)
    message("pathsToSRC: ${pathsToSRC}")

	#Creat Test
    if(pathsToSRC)
        add_executable(${nameTest}_test ${pathsToSRC})
        
        foreach(includePath IN LISTS EP_CTFL_Includes)
            target_include_directories(${nameTest}_test PUBLIC "${includePath}/")
        endforeach()
        foreach(includePath IN LISTS EP_CTFL_TestSrcDir)
            target_include_directories(${nameTest}_test PUBLIC "${includePath}/")
        endforeach()

        set(UsingLibs)
        foreach(curNameLib IN LISTS EP_CTFL_Libs)
            file(GLOB NameLib "${curNameLib}.lib")
			if(NOT NameLib)
                message(WARNING "Warrning: Not found ${nameSrc}.lib")
            endif()
            list(APPEND UsingLibs ${NameLib})
        endforeach()
        if(UsingLibs)
            target_link_libraries(${nameTest}_test PRIVATE ${UsingLibs})
        endif()
        add_test(NAME ${nameTest}_test COMMAND ${nameTest}_test)
    endif()

endfunction()