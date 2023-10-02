cmake_minimum_required(VERSION 3.20)

project(pns-c LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(default_build_type "Debug")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
            STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

file(GLOB tds LIST_DIRECTORIES true td*)

foreach (dir ${tds})
    if (EXISTS "${dir}/CMakeLists.txt")
        add_subdirectory(${dir})
        message(STATUS "Adding TD ${EXEC_NAME} using custom CMakeLists.txt")
    else ()
        file(GLOB SRCS ${dir}/*.c)
        file(GLOB HDRS ${dir}/*.h)

        get_filename_component(TD_NAME ${dir} NAME)
        message(STATUS "Adding TD ${TD_NAME}")

        foreach (src_file ${SRCS})
            get_filename_component(EXEC_NAME ${src_file} NAME_WE)
            add_executable(${EXEC_NAME} ${src_file} ${HDRS})
            if (UNIX)
                target_compile_options(${EXEC_NAME} PRIVATE "-Wall")
            endif ()
            target_link_libraries(${EXEC_NAME} m)
        endforeach ()
    endif ()
endforeach ()
