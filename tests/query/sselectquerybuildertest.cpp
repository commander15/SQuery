#include "squerybuildertest.h"

#include <SQuery/sselectquerybuilder.h>
#include <SQuery/squery.h>

TEST(SSelectQueryBuilderTest, buildTest)
{
    SSelectQueryBuilder b("col1, col2, colN, colX, colY");
    b.from("Table1");
    b.join(SQuery::InnerJoin, "Table2", "colX");
    b.join(SQuery::LeftJoin, "Table3", "colY", "col1");
    b.where("col1 = 1");
    b.orderBy("col1", Qt::AscendingOrder, "colN", Qt::DescendingOrder);
    b.limit(5).offset(40);
    CHECK_BUILDER("SELECT col1, col2, colN, colX, colY "
                  "FROM Table1 "
                  "INNER JOIN Table2 USING(colX) "
                  "LEFT JOIN Table3 ON colY = Table3.col1 "
                  "WHERE col1 = 1 "
                  "ORDER BY col1 ASC, colN DESC "
                  "LIMIT 5 OFFSET 40");
}
