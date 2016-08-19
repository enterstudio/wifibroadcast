project(cutils)

file(GLOB SOURCES "*.c" )
file(GLOB HEADERS "*.h" )

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")

target_link_libraries(${PROJECT_NAME} ${FOUND_PCAP})
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} rt)
endif()
