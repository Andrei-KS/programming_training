## This function creat a lib from files. 
## Name : CreatPackageFromFiles
## Params:
## arg1 - namePackage
## argumentDelimiter - NESINCLUDE
## arg1 - first path to necessary include folders
## ...
## argumentDelimiter - NESSRCPATH
## arg1 - first path(if set path, this is only name cpp file) to necessary cpp file folder
## ...
## argumentDelimiter - NESSRC
## arg1 - first path to necessary file.cpp
## ...
## argumentDelimiter - NESLIB
## arg1 - first necessary lib
## ...
## argumentDelimiter - NESTESTPATH
## arg1 - first path to necessary folder for test
## ...
## argumentDelimiter - NESTEST
## arg1 - first path(if set path, this is only name cpp file) to necessary file.cpp for test
## ..
## Output: none
function(CreatPackageFromFiles)
    #we read the received arguments and distribute them according to the corresponding lists
    set(function_args_ ${ARGV})
    set(Flag_GetNamePackage_ OFF)
    set(Flag_NeedGetInclude_ OFF)
    set(Flag_NeedGetSrcPath_ OFF)
    set(Flag_NeedGetSrc_ OFF)
    set(Flag_NeedGetLib_ OFF)
    set(Flag_NeedGetTestPath_ OFF)
    set(Flag_NeedGetTest_ OFF)
    
    set(NamePackege)
    set(ListInclude)
    set(ListSrcPath)
    set(ListSRCfiles)
    set(ListLibs)
    set(ListTestPath)
    set(ListTestfiles)

    foreach(arg IN LISTS function_args_)
        if(NOT Flag_GetNamePackage_ )
            set(NamePackege ${arg})
            set(Flag_GetNamePackage_ ON) 
        elseif("${arg}" MATCHES "NESINCLUDE")
            set(Flag_NeedGetInclude_ ON)
            set(Flag_NeedGetSrcPath_ OFF)
            set(Flag_NeedGetSrc_ OFF)
            set(Flag_NeedGetLib_ OFF)
            set(Flag_NeedGetTestPath_ OFF)
            set(Flag_NeedGetTest_ OFF)
        elseif("${arg}" MATCHES "NESSRCPATH")
            set(Flag_NeedGetInclude_ OFF)
            set(Flag_NeedGetSrcPath_ ON)
            set(Flag_NeedGetSrc_ OFF)
            set(Flag_NeedGetLib_ OFF)
            set(Flag_NeedGetTestPath_ OFF)
            set(Flag_NeedGetTest_ OFF)
        elseif("${arg}" MATCHES "NESSRC")
            set(Flag_NeedGetInclude_ OFF)
            set(Flag_NeedGetSrcPath_ OFF)
            set(Flag_NeedGetSrc_ ON)
            set(Flag_NeedGetLib_ OFF)
            set(Flag_NeedGetTestPath_ OFF)
            set(Flag_NeedGetTest_ OFF)
        elseif("${arg}" MATCHES "NESLIB")
            set(Flag_NeedGetInclude_ OFF)
            set(Flag_NeedGetSrcPath_ OFF)
            set(Flag_NeedGetSrc_ OFF)
            set(Flag_NeedGetLib_ ON)
            set(Flag_NeedGetTestPath_ OFF)
            set(Flag_NeedGetTest_ OFF)
        elseif("${arg}" MATCHES "NESTESTPATH")
            set(Flag_NeedGetInclude_ OFF)
            set(Flag_NeedGetSrcPath_ OFF)
            set(Flag_NeedGetSrc_ OFF)
            set(Flag_NeedGetLib_ OFF)
            set(Flag_NeedGetTestPath_ ON)
            set(Flag_NeedGetTest_ OFF)
        elseif("${arg}" MATCHES "NESTEST")
            set(Flag_NeedGetInclude_ OFF)
            set(Flag_NeedGetSrcPath_ OFF)
            set(Flag_NeedGetSrc_ OFF)
            set(Flag_NeedGetLib_ OFF)
            set(Flag_NeedGetTestPath_ OFF)
            set(Flag_NeedGetTest_ ON)
        elseif(Flag_NeedGetInclude_)
            list(APPEND ListInclude ${arg})
        elseif(Flag_NeedGetSrcPath_)
            list(APPEND ListSrcPath ${arg})
        elseif(Flag_NeedGetSrc_)
            list(APPEND ListSRCfiles ${arg})
        elseif(Flag_NeedGetLib_)
            list(APPEND ListLibs ${arg})
        elseif(Flag_NeedGetTestPath_)
            list(APPEND ListTestPath ${arg})
        elseif(Flag_NeedGetTest_)
            list(APPEND ListTestfiles ${arg})
        else()
            message(WARNING "Warrning: An error may have occurred while passing arguments[${arg}] to the function CreatPackageFromFiles")
        endif()
        #message(STATUS "Flag_GetNamePackage_: ${Flag_GetNamePackage_}\tFlag_NeedGetInclude_: ${Flag_NeedGetInclude_}\tFlag_NeedGetSrcPath_: ${Flag_NeedGetSrcPath_}\tFlag_NeedGetSrc_: ${Flag_NeedGetSrc_}\tFlag_NeedGetLib_ : ${Flag_NeedGetLib_}\tFlag_NeedGetTestPath_: ${Flag_NeedGetTestPath_}\tFlag_NeedGetTest_: ${Flag_NeedGetTest_}")
    endforeach()

    #Since the library will be built after the build process has started, a stub file will be created in the absence of this library file. 
    if(NOT EXISTS "${PROJECT_BINARY_DIR}/${NamePackege}.lib")
	    file(WRITE "${PROJECT_BINARY_DIR}/${NamePackege}.lib" "IS EMPTY")
    endif()


    message("\n")
    message(STATUS "Name package is ${NamePackege}")
    message(STATUS "ListInclude: ${ListInclude}")
    message(STATUS "ListSrcPath: ${ListSrcPath}")
    message(STATUS "ListSRCfiles: ${ListSRCfiles}")
    message(STATUS "ListLibs: ${ListLibs}")
    message(STATUS "ListTestPath: ${ListTestPath}")
    message(STATUS "ListTestfiles: ${ListTestfiles}")

    # Local Paths to sources files of package
    set(PathsToSRC)

    # Get all paths of files for source of packege
    if(ListSrcPath AND ListSRCfiles)
        foreach(SrcPath IN LISTS ListSrcPath)
            foreach(nameSrc IN LISTS ListSRCfiles)
                file(GLOB TARGET_SRC "${SrcPath}/${nameSrc}.cpp")
                if(NOT TARGET_SRC)
                    message(WARNING "Warrning: Not found ${SrcPath}/${nameSrc}.cpp")
                endif()
                list(APPEND PathsToSRC ${TARGET_SRC})
            endforeach()
        endforeach()
    elseif(ListSrcPath)
        foreach(SrcPath IN LISTS ListSrcPath)
            file(GLOB TARGET_SRC "${SrcPath}/*.cpp")
            if(NOT TARGET_SRC)
                message(WARNING "Warrning: Directory [${SrcPath}] is not contained cpp file")
            endif()
            list(APPEND PathsToSRC ${TARGET_SRC})
        endforeach()
    else()
        foreach(nameSrc IN LISTS ListSRCfiles)
            file(GLOB TARGET_SRC "${nameSrc}.cpp")
            if(NOT TARGET_SRC)
                message(WARNING "Warrning: Not found ${nameSrc}.cpp")
            endif()
            list(APPEND PathsToSRC ${TARGET_SRC})
        endforeach()
    endif()
    message(STATUS "PathsToSRC: ${PathsToSRC}")
    
    #Creat lib
    if(PathsToSRC)
        add_library(${NamePackege} STATIC ${PathsToSRC})
        foreach(includePath IN LISTS ListInclude)
            target_include_directories(${NamePackege} PUBLIC "${includePath}/")
        endforeach()

        set(UsingLibs)
        foreach(curNameLib IN LISTS ListLibs)
            file(GLOB NameLib "${curNameLib}.lib")
			if(NOT NameLib)
                message(WARNING "Warrning: Not found ${nameSrc}.lib")
            endif()
            list(APPEND UsingLibs ${NameLib})
        endforeach()
        if(UsingLibs)
            target_link_libraries(${NamePackege} PRIVATE ${UsingLibs})
        endif()
    endif()

    #Add test for this lib
    # Local Paths to test sources files of package
    set(PathsToTestSRC)

    # Get all paths of files for source of packege
    if(ListTestPath AND ListTestfiles)
        foreach(SrcPath IN LISTS ListTestPath)
            foreach(nameSrc IN LISTS ListTestfiles)
                file(GLOB TARGET_SRC "${SrcPath}/${nameSrc}.cpp")
                if(NOT TARGET_SRC)
                    message(WARNING "Warrning: Not found ${SrcPath}/${nameSrc}.cpp")
                endif()
                list(APPEND PathsToTestSRC ${TARGET_SRC})
            endforeach()
        endforeach()
    elseif(ListTestPath)
        foreach(SrcPath IN LISTS ListTestPath)
            file(GLOB TARGET_SRC "${SrcPath}/*.cpp")
            if(NOT TARGET_SRC)
                message(WARNING "Warrning: Directory [${SrcPath}] is not contained cpp file")
            endif()
            list(APPEND PathsToTestSRC ${TARGET_SRC})
        endforeach()
    else()
        foreach(nameSrc IN LISTS ListTestfiles)
            file(GLOB TARGET_SRC "${nameSrc}.cpp")
            if(NOT TARGET_SRC)
                message(WARNING "Warrning: Not found ${nameSrc}.cpp")
            endif()
            list(APPEND PathsToTestSRC ${TARGET_SRC})
        endforeach()
    endif()
    message(STATUS "PathsToTestSRC: ${PathsToTestSRC}")

    if(PathsToTestSRC)
        add_executable (${NamePackege}_test ${PathsToTestSRC})
        
        foreach(includePath IN LISTS ListInclude)
            target_include_directories(${NamePackege}_test PUBLIC "${includePath}/")
        endforeach()
        foreach(includePath IN LISTS ListTestPath)
            target_include_directories(${NamePackege}_test PUBLIC "${includePath}/")
        endforeach()

        set(UsingLibs)
        list(APPEND ListLibs "${PROJECT_BINARY_DIR}/${NamePackege}")
        foreach(curNameLib IN LISTS ListLibs)
            file(GLOB NameLib "${curNameLib}.lib")
			if(NOT NameLib)
                message(WARNING "Warrning: Not found ${nameSrc}.lib")
            endif()
            list(APPEND UsingLibs ${NameLib})
        endforeach()
        if(UsingLibs)
            target_link_libraries(${NamePackege}_test PRIVATE ${UsingLibs})
        endif()
        add_test(NAME ${NamePackege}_test COMMAND ${NamePackege}_test)
    endif()

endfunction()



#### Example of function design 
## This definition can be done into a do_stuff.cmake into a cmake dir
## Name : do_stuff
## Params: arg1, arg2
## Output: result
#function(do_stuff arg1 arg2 result)
#  foreach(f ${ARGN})
#    # do something interesting with 'f' -> other optional arg list
#    message("f='${f}' arg1='${arg1}' arg2='${arg2}'")
#  endforeach()
#  message("f='${f}' arg1='${arg1}' arg2='${arg2}'")  
#  message("ARGV0='${ARGV0}' ARGV1='${ARGV1}' ARGV2='${ARGV2}'")
#  set (${result} ${arg1}_TOTO PARENT_SCOPE)
#endfunction()