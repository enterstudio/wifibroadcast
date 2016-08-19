project(utils)

file(GLOB SOURCES "*.cpp" )
file(GLOB HEADERS "*.h" )

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")

target_compile_options(${PROJECT_NAME} PUBLIC -std=c++11)
