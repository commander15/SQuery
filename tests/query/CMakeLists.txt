set(SOURCES squerybuildertest.cpp sinsertquerybuildertest.cpp
    sselectquerybuildertest.cpp supdatequerybuildertest.cpp
    sdeletequerybuildertest.cpp
)

target_sources(squery_test PRIVATE ${SOURCES})
