#[[-------------------------------------------------------------------------
                    Definition and description of function
]]#-------------------------------------------------------------------------
#[[
# This function make list of paths to everything that is determined by given extensions
# @name             : create_paths_list_to
# @param            : none
# @external params  : EP_CLPT_Directories       - These directories will be involved
# @external params  : EP_CLPT_Ignored           - These files will not be added to list
# @external params  : EP_CLPT_Extra_File        - These files will be added to list
# @external params  : EP_CLPT_Extension         - These extensions determine necessary files
# @return           : out_List_Path_To 
#
# @author Andrei-KS
]]#
function(create_paths_list_to out_Paths_List_To)
  set(paths_List_To)
  set(ignore_List)

  # make ignore List
  if(EP_CLPT_Ignored)

    foreach(curr_Ign IN LISTS EP_CLPT_Ignored)
      if(NOT ignore_List)
        set(ignore_List ${curr_Ign})
      else()
        set(ignore_List "${ignore_List}|${curr_Ign}")
      endif()
    endforeach()

    set(ignore_List "(${ignore_List})")
  endif()

  set(extensions_For_Search)
  if(EP_CLPT_Extension)

    set(is_Skip False)
    foreach(curr_Ext IN LISTS EP_CLPT_Extension)

      if(curr_Ext STREQUAL "*")

        set(extensions_For_Search "*")
        break()
      elseif(curr_Ext STREQUAL ".*")

        set(extensions_For_Search "*.*")
        set(is_Skip True)
        continue()
      else()

        if(is_Skip)
          continue()
        endif()

        string(REGEX REPLACE "([^.]+)" "*.\\1" replace_item "${curr_Ext}")
        list(APPEND extensions_For_Search
          "${replace_item}"
        )
      endif()

    endforeach()
  else()

    list(APPEND extensions_For_Search
    "*"
    )
  endif()
  
  # walk given directories and make paths list
  if(EP_CLPT_Directories)

    foreach(curr_Ext IN LISTS extensions_For_Search)

      set(is_Find False)
      foreach(curr_Dir IN LISTS EP_CLPT_Directories)

        file(GLOB curr_Target "${curr_Dir}/${curr_Ext}")
        if(curr_Target)

          if(ignore_List)
            set(curr_Target "${curr_Target};")
            string(REGEX REPLACE "[^;]*/${ignore_List}([.][^.;]*)?[;]" "" curr_Target "${curr_Target}")
          endif()
          
          set(exist_files)
          foreach(file IN LISTS curr_Target)
            if(NOT IS_DIRECTORY "${file}")
              message("${file}")
              list(APPEND exist_files
                "${file}"
              )
            endif()
          endforeach()

          if(exist_files)
            set(is_Find TRUE)
          endif()

          list(APPEND paths_List_To ${exist_files})
        endif()

      endforeach()

      if(NOT is_Find)
        message(WARNING "Warrning: Not found files (with extension ${curr_Ext})")
      endif()

    endforeach()
  endif()

  # add extra file
  if(EP_CLPT_Extra_File)

    set(default_Dir ${PROJECT_SOURCE_DIR})
    foreach(file_Name IN LISTS EP_CLPT_Extra_File)
      
      if(NOT file_Name MATCHES "[^:]+:[^:]+")
        set(file_Name "${default_Dir}/${file_Name}")
      endif()

      set(curr_Target)
      if(file_Name MATCHES "[.][^./]*$")
        file(GLOB curr_Target "${file_Name}")
      else()
        foreach(curr_Ext IN LISTS EP_CLPT_Extension)
          file(GLOB curr_Target "${file_Name}.${curr_Ext}")
        endforeach()
      endif()

      if(NOT curr_Target)
        message(WARNING "Warrning: Not found files (with extensions: ${EP_CLPT_Extension}) ${file_Name}")
      else()
        list(APPEND paths_List_To ${curr_Target})
      endif()

    endforeach()
  endif()

  set(${out_Paths_List_To} ${paths_List_To} PARENT_SCOPE)
endfunction()