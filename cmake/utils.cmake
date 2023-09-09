macro(squery_generate_nested_headers)
    foreach(header ${ARGN})
        file(RELATIVE_PATH path ${SQuery_SOURCE_DIR}/include/SQuery ${CMAKE_CURRENT_SOURCE_DIR}/${header})
        file(WRITE ${SQuery_SOURCE_DIR}/include/SQuery/${header} "#include \"${path}\"")
    endforeach()

    install(FILES ${ARGN} DESTINATION include/SQuery)
endmacro()
