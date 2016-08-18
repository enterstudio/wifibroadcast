project(radiotap)

if(NOT LINUX)
  message(STATUS "${PROJECT_NAME} only available on linux")
  return()
endif()

file(GLOB SOURCES "*.c" )
file(GLOB HEADERS "*.h" )

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
