#[[-------------------------------------------------------------------------
                    Definition and description of function
]]#-------------------------------------------------------------------------
#[[
# This function make list of paths to everything that is determined by given extensions
# @name             : create_paths_list_to
# @param            : none
# @external params  : EP_CLPT_Directories     - These directories will be involved
# @external params  : EP_CLPT_Ignored         - These files will not be added to list
# @external params  : EP_CLPT_ExtraFile       - These files will be added to list
# @external params  : EP_CLPT_Extension       - These extensions determine necessary files
# @return           : outListPathTo 
#
# @author Andrei-KS
]]#
function(create_paths_list_to outPathsListTo)
  set(pathsListTo)
  set(ignoreList)

  # make ignore List
  if(EP_CLPT_Ignored)
    foreach(currIgn IN LISTS EP_CLPT_Ignored)
      if(NOT ignoreList)
        set(ignoreList ${currIgn})
      else()
        set(ignoreList "${ignoreList}|${currIgn}")
      endif()
    endforeach()
    set(ignoreList "(${ignoreList})")
  endif()

  # walk given directories and make paths list
  if(EP_CLPT_Directories)
    foreach(currDir IN LISTS EP_CLPT_Directories)
      foreach(currExt IN LISTS EP_CLPT_Extension)

        file(GLOB currTarget "${currDir}/*.${currExt}")
        if(NOT currTarget)

          message(WARNING "Warrning: Not found files ${SrcDir}/*.${currExt}")
        else()

          if(ignoreList)
            string(REGEX REPLACE "[^;]*${ignoreList}[.]${currExt}[;]*" "" currTarget "${currTarget}")
          endif()

          list(APPEND pathsListTo ${currTarget})
        endif()

      endforeach()
    endforeach()
  endif()

  # add extra file
  if(EP_CLPT_ExtraFile)
    set(defaultDir ${PROJECT_SOURCE_DIR})
    foreach(fileName IN LISTS EP_CLPT_ExtraFile)
      
      if(NOT fileName MATCHES "[^:]+:[^:]+")
        set(fileName "${defaultDir}/${fileName}")
      endif()

      set(currTarget)
      if(fileName MATCHES "[.][^./]*$")
        file(GLOB currTarget "${fileName}")
      else()
        foreach(currExt IN LISTS EP_CLPT_Extension)
          file(GLOB currTarget "${fileName}.${currExt}")
        endforeach()
      endif()

      if(NOT currTarget)
        message(WARNING "Warrning: Not found files (with extension ${EP_CLPT_Extension}) ${fileName}")
      else()
        list(APPEND pathsListTo ${currTarget})
      endif()

    endforeach()
  endif()

  set(${outPathsListTo} ${pathsListTo} PARENT_SCOPE)
endfunction()