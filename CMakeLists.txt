
project(wifibroadcast)
cmake_minimum_required(VERSION 2.8)

option(WALL_ON "Compile with all warnings" ON)
if(WALL_ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif()


find_library(FOUND_PCAP pcap)
message(STATUS "FOUND_PCAP -> ${FOUND_PCAP}")

add_subdirectory(radiotap)

add_library(wifibroadcast defines.h lib.h lib.c fec.h fec.c)

target_link_libraries(wifibroadcast ${FOUND_PCAP})
if(UNIX AND NOT APPLE)
  target_link_libraries(wifibroadcast rt)
endif()

add_executable(tx tx.c)
target_link_libraries(tx wifibroadcast)

if(TARGET radiotap)
  add_executable(rx rx.c)
  target_link_libraries(rx wifibroadcast radiotap)
else()
  message(STATUS "Can't build rx without radiotap")
endif()

add_subdirectory(tests)
