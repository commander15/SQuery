#include "squerybuildertest.h"

#include <SQuery/supdatequerybuilder.h>

TEST(SUpdateQueryBuilderTest, buildTest)
{
    SUpdateQueryBuilder b("Table");
    b.set("col1", 1, "col2", "Yes", "colN", QChar('M'));
    b.where("col1 = 1");
    CHECK_BUILDER("UPDATE Table "
                  "SET col1 = 1, col2 = 'Yes', colN = 'M' "
                  "WHERE col1 = 1");
}
