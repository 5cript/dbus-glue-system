add_library(dbus-glue-system INTERFACE)

target_include_directories(dbus-glue-system
                           INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
