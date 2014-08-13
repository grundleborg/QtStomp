include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(testconnection lib/test.cpp test-connection.cpp)
target_link_libraries(testconnection Qt5::Network Qt5::Test QtStomp)
add_test(testconnection testconnection)


