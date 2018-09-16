project( BehaviorTreeDemo )

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_library( BT_LIB STATIC IMPORTED )
set_property( TARGET BT_LIB PROPERTY IMPORTED_LOCATION_DEBUG ${CMAKE_CURRENT_LIST_DIR}/../lib/Debug/libBehaviorTree.a)
set_property( TARGET BT_LIB PROPERTY IMPORTED_LOCATION_RELEASE ${CMAKE_CURRENT_LIST_DIR}/../lib/Release/libBehaviorTree.a)

add_subdirectory(demo)
