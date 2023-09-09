#ifndef ScolSPACE_H
#define ScolSPACE_H

#include <SQuery/sglobal.h>
#include <SQuery/sinsertquerybuilder.h>
#include <SQuery/sselectquerybuilder.h>
#include <SQuery/supdatequerybuilder.h>
#include <SQuery/sdeletequerybuilder.h>

namespace SQuery
{

enum JoinMode {
    InnerJoin = SSelectQueryBuilder::InnerJoin,
    LeftJoin = SSelectQueryBuilder::LeftJoin
};

SQUERY_EXPORT SInsertQueryBuilder insertInto(const QString &table);
SQUERY_EXPORT SInsertQueryBuilder insertInto(const QString &table, const QStringList &columns);
SQUERY_EXPORT SInsertQueryBuilder insertInto(const QString &table, const QString &columns);

SQUERY_EXPORT SSelectQueryBuilder select();
SQUERY_EXPORT SSelectQueryBuilder select(const QStringList &columns);
SQUERY_EXPORT SSelectQueryBuilder select(const QString &columns);

SQUERY_EXPORT SUpdateQueryBuilder update(const QString &table);

SQUERY_EXPORT SDeleteQueryBuilder deleteFrom(const QString &table);

SQUERY_EXPORT QString format(const QVariant &data = QVariant());
SQUERY_EXPORT QString equality(const QString &a, const QVariant &b);

SQUERY_EXPORT QString AS(const QString &col, const QString &alias);

SQUERY_EXPORT QString LT(const QString &col, const QVariant &val);
SQUERY_EXPORT QString LE(const QString &col, const QVariant &val);
SQUERY_EXPORT QString EQ(const QString &col, const QVariant &val);
SQUERY_EXPORT QString NE(const QString &col, const QVariant &val);
SQUERY_EXPORT QString GT(const QString &col, const QVariant &val);
SQUERY_EXPORT QString GE(const QString &col, const QVariant &val);

SQUERY_EXPORT QString BETWEEN(const QString &col, int val1, int val2);
SQUERY_EXPORT QString BETWEEN(const QString &col, double val1, double val2);

SQUERY_EXPORT QString IN(const QString &col, const QVariantList &vals);
SQUERY_EXPORT QString IN(const QString &col, const QStringList &vals);

SQUERY_EXPORT QString LIKE(const QString &val1, const QString &val2);

SQUERY_EXPORT QString AND(const QString &exp1, const QString &exp2);
SQUERY_EXPORT QString OR(const QString &exp1, const QString &exp2);
};

#endif // ScolSPACE_H
