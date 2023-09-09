set(HEADERS squerybuilder.h sinsertquerybuilder.h sselectquerybuilder.h
    supdatequerybuilder.h sdeletequerybuilder.h
)

set(SOURCES squerybuilder.cpp sinsertquerybuilder.cpp sselectquerybuilder.cpp
    supdatequerybuilder.cpp sdeletequerybuilder.cpp
)

squery_generate_nested_headers(${HEADERS})

target_sources(squery PRIVATE ${SOURCES})
