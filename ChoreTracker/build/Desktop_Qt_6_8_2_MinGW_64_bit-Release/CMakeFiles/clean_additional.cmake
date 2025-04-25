# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\appChoreTracker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appChoreTracker_autogen.dir\\ParseCache.txt"
  "appChoreTracker_autogen"
  )
endif()
