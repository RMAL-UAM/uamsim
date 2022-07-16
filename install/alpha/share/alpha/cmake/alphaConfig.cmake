# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_alpha_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED alpha_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(alpha_FOUND FALSE)
  elseif(NOT alpha_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(alpha_FOUND FALSE)
  endif()
  return()
endif()
set(_alpha_CONFIG_INCLUDED TRUE)

# output package information
if(NOT alpha_FIND_QUIETLY)
  message(STATUS "Found alpha: 0.0.0 (${alpha_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'alpha' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${alpha_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(alpha_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${alpha_DIR}/${_extra}")
endforeach()
