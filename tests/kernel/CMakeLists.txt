set(SOURCES main.cpp)

target_sources(squery_test PRIVATE ${SOURCES})

target_link_libraries(squery_test squery Qt5::Test GTest::gtest)
