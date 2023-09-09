set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(squery ${SQuery_BUILD_TYPE})

add_subdirectory(kernel)
add_subdirectory(query)
add_subdirectory(global)
