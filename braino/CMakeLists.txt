# https://github.com/krofna/Warrior-of-Dreamworld-r3/blob/master/Build/Modules/FindMySQLConnectorCPP.cmake
find_package(MySQLConnectorCPP REQUIRED)

add_library(Message Message.cpp Message.hpp)
target_include_directories(Message PUBLIC ${MYSQLCONNECTORCPP_INCLUDE_DIR})

add_executable(Main Main.cpp)
link_libraries(Main Message ${MYSQLCONNECTORCPP_LIBRARY})

# https://dev.mysql.com/doc/connector-cpp/en/connector-cpp-getting-started-examples.html