#include "squerybuildertest.h"

#include <SQuery/sinsertquerybuilder.h>

#include <QtCore/qdatetime.h>

TEST(SInsertQueryBuilderTest, buildTest)
{
    SInsertQueryBuilder b("Table", "column1, column2, columnn");
    b.values(1, "Hello World", QDate(2022, 6, 15));

    CHECK_BUILDER("INSERT INTO Table(column1, column2, columnn) "
                  "VALUES(1, 'Hello World', '2022-06-15')");
}
