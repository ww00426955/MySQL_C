cmake_minimum_required(VERSION 3.10)
project(mysqlSDK)

set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src mysql_demo_src)

INCLUDE_DIRECTORIES("/usr/include/mysql"
        ${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES("/usr/lib/x86_64-linux-gnu")

ADD_EXECUTABLE(mysql_demo_main ${mysql_demo_src})
TARGET_LINK_LIBRARIES(mysql_demo_main
        mysqlclient
        )
