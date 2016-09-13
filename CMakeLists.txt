cmake_minimum_required(VERSION 2.8)
set(INSTALL_PREFIX /usr)

set(PROJECT_NAME "whisper_relay")

project(${PROJECT_NAME})

set(SOURCE "")
set(HEADERS "")

add_subdirectory(src)

include_directories(${PROJECT_INC_DIR}src)

message("${SOURCE}")
message("${HEADERS}")

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} -ljnxc)
