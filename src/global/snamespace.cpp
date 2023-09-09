#include "snamespace.h"

#include "../query/squerybuilder_p.h"

#include <QtCore/qdatetime.h>

SInsertQueryBuilder SQuery::insertInto(const QString &table)
{
    return SInsertQueryBuilder(table);
}

SInsertQueryBuilder SQuery::insertInto(const QString &table, const QStringList &columns)
{
    return SInsertQueryBuilder(table, columns);
}

SInsertQueryBuilder SQuery::insertInto(const QString &table, const QString &columns)
{
    return SInsertQueryBuilder(table, columns);
}

SSelectQueryBuilder SQuery::select()
{
    return SSelectQueryBuilder();
}

SSelectQueryBuilder SQuery::select(const QStringList &columns)
{
    return SSelectQueryBuilder(columns);
}

SSelectQueryBuilder SQuery::select(const QString &columns)
{
    return SSelectQueryBuilder(columns);
}

SUpdateQueryBuilder SQuery::update(const QString &table)
{
    return SUpdateQueryBuilder(table);
}

SDeleteQueryBuilder SQuery::deleteFrom(const QString &table)
{
    return SDeleteQueryBuilder(table);
}

QString SQuery::format(const QVariant &data)
{
    return SQueryBuilderPrivate::format(data);
}

QString SQuery::equality(const QString &a, const QVariant &b)
{
    return SQueryBuilderPrivate::equality(a, b);
}

QString SQuery::AS(const QString &col, const QString &alias)
{
    return QStringLiteral("%1 AS %2").arg(col, alias);
}

QString SQuery::LT(const QString &col, const QVariant &val)
{
    return QStringLiteral("%1 < %2").arg(col, format(val));
}

QString SQuery::LE(const QString &col, const QVariant &val)
{
    return QStringLiteral("%1 <= %2").arg(col, format(val));
}

QString SQuery::EQ(const QString &col, const QVariant &val)
{
    return QStringLiteral("%1 = %2").arg(col, format(val));
}

QString SQuery::NE(const QString &col, const QVariant &val)
{
    return QStringLiteral("%1 != %2").arg(col, format(val));
}

QString SQuery::GT(const QString &col, const QVariant &val)
{
    return QStringLiteral("%1 > %2").arg(col, format(val));
}

QString SQuery::GE(const QString &col, const QVariant &val)
{
    return QStringLiteral("%1 >= %2").arg(col, format(val));
}

QString SQuery::BETWEEN(const QString &col, int val1, int val2)
{
    return QStringLiteral("%1 BETWEEN %2 AND %3").arg(col).arg(val1).arg(val2);
}

QString SQuery::BETWEEN(const QString &col, double val1, double val2)
{
    return QStringLiteral("%1 BETWEEN %2 AND %3").arg(col).arg(val1).arg(val2);
}

QString SQuery::IN(const QString &col, const QVariantList &vals)
{
    QStringList values;
    for (int i(0); i < vals.size(); ++i)
        values.append(format(vals.at(i)));
    return QStringLiteral("%1 IN (%2)").arg(col, values.join(", "));
}

QString SQuery::IN(const QString &col, const QStringList &vals)
{
    QStringList values;
    for (int i(0); i < vals.size(); ++i)
        values.append('"' + vals.at(i) + '"');
    return QStringLiteral("%1 IN (%2)").arg(col, values.join(", "));
}

QString SQuery::LIKE(const QString &val1, const QString &val2)
{
    return QStringLiteral("%1 LIKE '%%2%'").arg(val1, val2);
}

QString SQuery::AND(const QString &exp1, const QString &exp2)
{
    return QStringLiteral("%1 AND %2").arg(exp1, exp2);
}

QString SQuery::OR(const QString &exp1, const QString &exp2)
{
    return QStringLiteral("%1 OR %2").arg(exp1, exp2);
}
