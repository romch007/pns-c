set(TD_NAME "td8")

file(GLOB SRCS *.c)
file(GLOB HDRS *.h)

message(STATUS "Adding TD ${TD_NAME}")

add_executable(td8-arbre main.c table-arbre.c table.h)
add_executable(td8-liste main.c table-liste.c table.h)
add_executable(td8-tableau main.c table-tableau.c table.h)

if (UNIX)
    target_compile_options(td8-arbre PRIVATE "-Wall")
    target_compile_options(td8-liste PRIVATE "-Wall")
    target_compile_options(td8-tableau PRIVATE "-Wall")
endif ()

