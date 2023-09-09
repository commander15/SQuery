#include "sinsertquerybuilder.h"
#include "sinsertquerybuilder_p.h"

SInsertQueryBuilder::SInsertQueryBuilder() :
    SQueryBuilder(*new SInsertQueryBuilderPrivate)
{
}

SInsertQueryBuilder::SInsertQueryBuilder(const QString &table, const QStringList &columns) :
    SQueryBuilder(*new SInsertQueryBuilderPrivate)
{
    S_D(SInsertQueryBuilder);
    d->tableName = table;
    if (!columns.isEmpty())
        d->tableColumnNames = columns;
}

SInsertQueryBuilder::SInsertQueryBuilder(const QString &table, QString columns) :
    SQueryBuilder(*new SInsertQueryBuilderPrivate)
{
    S_D(SInsertQueryBuilder);
    d->tableName = table;
    if (!columns.isEmpty()) {
        columns.remove(' ');
        d->tableColumnNames = columns.split(',');
    }
}

SInsertQueryBuilder::SInsertQueryBuilder(const QString &table) :
    SQueryBuilder(*new SInsertQueryBuilderPrivate)
{
    S_D(SInsertQueryBuilder);
    d->tableName = table;
}

SInsertQueryBuilder::SInsertQueryBuilder(const SInsertQueryBuilder &other) :
    SQueryBuilder(other)
{
}

SInsertQueryBuilder::SInsertQueryBuilder(SInsertQueryBuilder &&other) :
    SQueryBuilder(other)
{
}

SInsertQueryBuilder::~SInsertQueryBuilder()
{
}

SInsertQueryBuilder &SInsertQueryBuilder::operator=(const SInsertQueryBuilder &other)
{
    return static_cast<SInsertQueryBuilder &>(SQueryBuilder::operator=(other));
}

SInsertQueryBuilder &SInsertQueryBuilder::values(const QVariantList &values)
{
    S_D(SInsertQueryBuilder);
    d->tableColumnValues = values;
    return *this;
}

SInsertQueryBuilder &SInsertQueryBuilder::values(const QVariant &val0, const QVariant &val1,
                                                 const QVariant &val2, const QVariant &val3,
                                                 const QVariant &val4, const QVariant &val5,
                                                 const QVariant &val6, const QVariant &val7,
                                                 const QVariant &val8, const QVariant &val9)
{
    S_D(SInsertQueryBuilder);
    int c = d->tableColumnNames.size();

    QVariantList vals;
    if (c > 0)
        vals.reserve(c);
    if (c > 0 || (c == 0 && val0.isValid()))
        vals.append(val0);
    if (c > 1 || (c == 0 && val1.isValid()))
        vals.append(val1);
    if (c > 2 || (c == 0 && val2.isValid()))
        vals.append(val2);
    if (c > 3 || (c == 0 && val3.isValid()))
        vals.append(val3);
    if (c > 4 || (c == 0 && val4.isValid()))
        vals.append(val4);
    if (c > 5 || (c == 0 && val5.isValid()))
        vals.append(val5);
    if (c > 6 || (c == 0 && val6.isValid()))
        vals.append(val6);
    if (c > 7 || (c == 0 && val7.isValid()))
        vals.append(val7);
    if (c > 8 || (c == 0 && val8.isValid()))
        vals.append(val8);
    if (c > 9 || (c == 0 && val9.isValid()))
        vals.append(val9);
    return values(vals);
}

SQueryBuilder &SInsertQueryBuilder::where(const QString &clause)
{
    Q_UNUSED(clause)
    return *this;
}

SInsertQueryBuilder &SInsertQueryBuilder::operator=(SInsertQueryBuilder &&other)
{
    return static_cast<SInsertQueryBuilder &>(SQueryBuilder::operator=(other));
}

SInsertQueryBuilderPrivate::SInsertQueryBuilderPrivate()
{
}

SInsertQueryBuilderPrivate::SInsertQueryBuilderPrivate(const SInsertQueryBuilderPrivate &other) :
    SQueryBuilderPrivate(other),
    tableName(other.tableName),
    tableColumnNames(other.tableColumnNames),
    tableColumnValues(other.tableColumnValues)
{
}

SInsertQueryBuilderPrivate::~SInsertQueryBuilderPrivate()
{
}

QString SInsertQueryBuilderPrivate::build()
{
    QString columns;
    if (!tableColumnNames.isEmpty())
        columns = QStringLiteral("(%1)").arg(tableColumnNames.join(", "));

    return QStringLiteral("INSERT INTO %1%2  "
                          "VALUES(%3)")
            .arg(tableName, columns, values());
}

QString SInsertQueryBuilderPrivate::values() const
{
    QStringList vs;
    for (int i(0); i < tableColumnValues.size(); ++i)
        vs.append(format(tableColumnValues.at(i)));
    return vs.join(", ");
}
