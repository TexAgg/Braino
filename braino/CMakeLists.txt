add_library(Message Message.cpp Message.hpp)
target_include_directories(Message PUBLIC ${MYSQLCONNECTORCPP_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

add_library(Logger Logger.cpp Logger.hpp)

add_executable(Braino Main.cpp)
target_link_libraries(Braino Message Logger ${MYSQLCONNECTORCPP_LIBRARY})