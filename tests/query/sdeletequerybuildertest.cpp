#include "squerybuildertest.h"

#include <SQuery/sdeletequerybuilder.h>

TEST(SDeleteQueryBuilderTest, buildTest)
{
    SDeleteQueryBuilder b("Table");
    b.where("id = 1");
    CHECK_BUILDER("DELETE FROM Table "
                  "WHERE id = 1");
}
