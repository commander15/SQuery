configure_file(sconfig.h.in ${CMAKE_CURRENT_SOURCE_DIR}/sconfig.h @ONLY)

set(HEADERS sconfig.h sglobal.h)

squery_generate_nested_headers(${HEADERS})

target_include_directories(squery PUBLIC ${SQuery_SOURCE_DIR}/include)

target_link_libraries(squery PUBLIC Qt5::Core)

target_compile_definitions(squery PUBLIC SQUERY_LIB PRIVATE BUILD_SQUERY_LIB)
