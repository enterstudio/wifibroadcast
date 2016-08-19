
project(wifibroadcast)
cmake_minimum_required(VERSION 2.8)

option(WALL_ON "Compile with all warnings" ON)
if(WALL_ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif()


find_library(FOUND_PCAP pcap)
message(STATUS "FOUND_PCAP -> ${FOUND_PCAP}")

add_subdirectory(radiotap)
add_subdirectory(cutils)
add_subdirectory(utils)

add_executable(tx tx.cpp)
target_link_libraries(tx cutils utils)

if(TARGET radiotap)
  add_executable(rx rx.cpp)
  target_link_libraries(rx cutils radiotap)
else()
  message(STATUS "Can't build rx without radiotap")
endif()

add_subdirectory(tests)
