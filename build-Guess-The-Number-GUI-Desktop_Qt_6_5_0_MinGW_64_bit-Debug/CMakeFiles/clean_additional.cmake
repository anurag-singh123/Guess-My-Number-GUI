# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Guess-The-Number-GUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Guess-The-Number-GUI_autogen.dir\\ParseCache.txt"
  "Guess-The-Number-GUI_autogen"
  )
endif()
