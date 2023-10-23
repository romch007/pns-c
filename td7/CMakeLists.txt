set(TD_NAME "td7")

file(GLOB SRCS *.c)
file(GLOB HDRS *.h)

message(STATUS "Adding TD ${TD_NAME}")

foreach (src_file ${SRCS})
    get_filename_component(EXEC_NAME ${src_file} NAME_WE)
    add_executable(${EXEC_NAME} ${src_file} ${HDRS})
    if (UNIX)
        target_compile_options(${EXEC_NAME} PRIVATE "-Wall")
    endif ()
    target_link_libraries(${EXEC_NAME} m)
endforeach ()
