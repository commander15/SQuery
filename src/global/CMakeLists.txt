set(HEADERS snamespace.h squery.h)

set(SOURCES snamespace.cpp)

squery_generate_nested_headers(${HEADERS})

target_sources(squery PRIVATE ${SOURCES})
