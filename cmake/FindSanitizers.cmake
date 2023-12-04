#
# Copyright 2009- ECMWF.
#
# This software is licensed under the terms of the Apache Licence version 2.0
# which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
# In applying this licence, ECMWF does not waive the privileges and immunities
# granted to it by virtue of its status as an intergovernmental organisation
# nor does it submit to any jurisdiction.
#

# FindUBSan
# ----------
#

#
# Find Sanitizers
#
# The following options are considered:
#
#   - ENABLE_SANITIZE_ADDRESS
#   - ENABLE_SANITIZE_MEMORY
#   - ENABLE_SANITIZE_THREAD
#   - ENABLE_SANITIZE_UNDEFINED 
#
# Use this module by invoking find_package with the form:
#
#   find_package(Sanitizers)   # Fails with error enabled Sanitizers are not found
#
# This module finds the tool(s), specifying the following variables:
#
#   UBSan_FOUND            - True if library is found
#
#

option(ENABLE_SANITIZE_ADDRESS "Enable Address Sanitizer." Off)
option(ENABLE_SANITIZE_MEMORY "Enable Memory Sanitizer." Off)
option(ENABLE_SANITIZE_THREAD "Enable Thread Sanitizer." Off)
option(ENABLE_SANITIZE_UNDEFINED "Enable Undefined Behaviour Sanitizer." Off)

include(CheckCXXCompilerFlag)

function(add_sanitize_address)
  # Enable sanitizing address...
  set(SANITIZE_FLAGS "-fsanitize=address;-fno-omit-frame-pointer")

  # (1) check if compiler supports necessary compilation flag(s)
  check_cxx_compiler_flag(${SANITIZE_FLAGS} HAVE_SANITIZER_ADDRESS)

  if (NOT ${HAVE_SANITIZER_ADDRESS})
    message(FATAL "Sanitizers: Address Sanitizer enabled, but not supported by compiler! Quitting...")
  endif()

  # (2) configure compilation/linking flag(s)
  add_compile_options(${SANITIZE_FLAGS})
  message(STATUS "Sanitizer: Address Sanitizer is enabled.")
endfunction()

function(add_sanitize_memory)
  # Enable sanitizing memory...
  set(SANITIZE_FLAGS "-fsanitize=memory")

  # (1) check if compiler supports necessary compilation flag(s)
  check_cxx_compiler_flag(${SANITIZE_FLAGS} HAVE_SANITIZER_MEMORY)

  if (NOT ${HAVE_SANITIZER_MEMORY})
    message(FATAL "Sanitizers: Memory Sanitizer enabled, but not supported by compiler! Quitting...")
  endif()

  # (2) configure compilation/linking flag(s)
  add_compile_options(${SANITIZE_FLAGS})
  message(STATUS "Sanitizer: Memory Sanitizer is enabled.")
endfunction()

function(add_sanitize_thread)
  # Enable sanitizing Thread...
  set(SANITIZE_FLAGS "-fsanitize=thread")

  # (1) check if compiler supports necessary compilation flag(s)
  check_cxx_compiler_flag(${SANITIZE_FLAGS} HAVE_SANITIZER_THREAD)

  if (NOT ${HAVE_SANITIZER_THREAD})
    message(FATAL "Sanitizers: Thread Sanitizer enabled, but not supported by compiler! Quitting...")
  endif()

  # (2) configure compilation/linking flag(s)
  add_compile_options(${SANITIZE_FLAGS})
  message(STATUS "Sanitizer: Thread Sanitizer is enabled.")
endfunction()

function(add_sanitize_undefined)
  # Enable sanitizing undefined behaviour...
  set(SANITIZE_FLAGS "-fsanitize=undefined")

  # (1) check if compiler supports necessary compilation flag(s)
  check_cxx_compiler_flag(${SANITIZE_FLAGS} HAVE_SANITIZER_UB)

  if (NOT ${HAVE_SANITIZER_UB})
    message(FATAL "Sanitizers: Undefined Behaviour Sanitizer enabled, but not supported by compiler! Quitting...")
  endif()

  # (2) configure compilation/linking flag(s)
  add_compile_options(${SANITIZE_FLAGS})
  add_link_options(${SANITIZE_FLAGS})
  message(STATUS "Sanitizer: Undefined Behaviour Sanitizer is enabled.")
endfunction()

#
# __MAIN__ (the following is evaluated immediately when the module is found/included)
#

if (SANITIZE_ADDRESS AND SANITIZE_THREAD)
  message(FATAL_ERROR "Sanitizer: Incompatible sanitizers detected (Address and Memory Sanitizers).")
elseif (SANITIZE_ADDRESS AND SANITIZE_MEMORY)
  message(FATAL_ERROR "Sanitizer: Incompatible sanitizers detected (Address and Memory Sanitizers).")
elseif (SANITIZE_THREAD AND SANITIZE_MEMORY)
  message(FATAL_ERROR "Sanitizer: Incompatible sanitizers detected (Thread and Memory Sanitizers).")
endif ()

if (SANITIZE_MEMORY)
  if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message(STATUS "Sanitizer: [WARNING] Memory Sanitizer disabled. Only supported on Linux!") 
    set(SANITIZE_MEMORY Off CACHE BOOL "Enable Memory Sanitizer." FORCE)
  elseif (NOT ${CMAKE_SIZEOF_VOID_P} EQUAL 8)
    message(STATUS "Sanitizers [] WARNING: Memory Sanitizer disabled. Only supported on 64bit!")
    set(SANITIZE_MEMORY Off CACHE BOOL "Enable Memory Sanitizer." FORCE)
  endif ()
endif ()


if (ENABLE_SANITIZE_ADDRESS)
  add_sanitize_address()
endif ()
if (ENABLE_SANITIZE_MEMORY)
  add_sanitize_memory()
endif ()
if (ENABLE_SANITIZE_THREAD)
  add_sanitize_thread()
endif ()
if (ENABLE_SANITIZE_UNDEFINED)
  add_sanitize_undefined()  
endif ()

