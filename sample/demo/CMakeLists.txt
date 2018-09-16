cmake_minimum_required(VERSION 3.12)
project( BehaviorTreeDemo )

file( GLOB BTD_LIB_HDRS "${CMAKE_CURRENT_LIST_DIR}/*.h" )
file( GLOB BTD_LIB_SRCS "${CMAKE_CURRENT_LIST_DIR}/*.cpp" )
add_executable( BehaviorTreeDemo ${BTD_LIB_HDRS} ${BTD_LIB_SRCS} )
target_link_libraries( BehaviorTreeDemo BT_LIB )
include_directories( ${CMAKE_CURRENT_LIST_DIR}/../../include )

set_property(TARGET BehaviorTreeDemo PROPERTY CXX_STANDARD 14)
