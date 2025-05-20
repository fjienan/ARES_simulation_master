#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ares_comm::ares_comm_lib" for configuration ""
set_property(TARGET ares_comm::ares_comm_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ares_comm::ares_comm_lib PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libares_comm_lib.so"
  IMPORTED_SONAME_NOCONFIG "libares_comm_lib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS ares_comm::ares_comm_lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_ares_comm::ares_comm_lib "${_IMPORT_PREFIX}/lib/libares_comm_lib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
