
project(wifibroadcast)
cmake_minimum_required(VERSION 2.8)

option(WALL_ON "Compile with all warnings" ON)
if(WALL_ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif()


find_library(FOUND_PCAP pcap)
message(STATUS "FOUND_PCAP -> ${FOUND_PCAP}")

add_library(radiotap radiotap.h radiotap.c ieee80211_radiotap.h)
add_library(wbcLib lib.h lib.c radiotap.h radiotap.c fec.h fec.c)
target_link_libraries(wbcLib radiotap)

target_link_libraries(wbcLib ${FOUND_PCAP})
if(UNIX AND NOT APPLE)
  target_link_libraries(wbcLib rt)
endif()

add_executable(tx tx.c)
target_link_libraries(tx wbcLib)

add_executable(rx rx.c)
target_link_libraries(rx wbcLib)

add_executable(tx_test tx_test.c)
target_link_libraries(tx_test wbcLib)

add_executable(rx_status_test rx_status_test.c)
target_link_libraries(rx_status_test wbcLib)
