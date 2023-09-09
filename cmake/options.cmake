option(SQuery_BUILD_STATIC OFF)
option(SQuery_BUILD_TESTS  OFF)

if (SQuery_BUILD_STATIC)
    set(SQuery_BUILD_TYPE STATIC)
else()
    set(SQuery_BUILD_TYPE SHARED)
endif()
