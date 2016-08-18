
project(tests)

add_executable(tx_test tx_test.c)
target_link_libraries(tx_test wifibroadcast)

add_executable(rx_status_test rx_status_test.c)
target_link_libraries(rx_status_test wifibroadcast)
