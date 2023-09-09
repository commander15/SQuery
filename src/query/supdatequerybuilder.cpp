#include "supdatequerybuilder.h"
#include "supdatequerybuilder_p.h"

SUpdateQueryBuilder::SUpdateQueryBuilder() :
    SQueryBuilder(*new SUpdateQueryBuilderPrivate)
{
}

SUpdateQueryBuilder::SUpdateQueryBuilder(const QString &table) :
    SQueryBuilder(*new SUpdateQueryBuilderPrivate)
{
    S_D(SUpdateQueryBuilder);
    d->tableName = table;
}

SUpdateQueryBuilder::SUpdateQueryBuilder(const SUpdateQueryBuilder &other) :
    SQueryBuilder(other)
{
}

SUpdateQueryBuilder::SUpdateQueryBuilder(SUpdateQueryBuilder &&other) :
    SQueryBuilder(other)
{
}

SUpdateQueryBuilder::~SUpdateQueryBuilder()
{
}

SUpdateQueryBuilder &SUpdateQueryBuilder::operator=(const SUpdateQueryBuilder &other)
{
    if (this != &other)
        d = other.d;
    return *this;
}

SUpdateQueryBuilder &SUpdateQueryBuilder::operator=(SUpdateQueryBuilder &&other)
{
    if (this != &other)
        d.swap(other.d);
    return *this;
}

SUpdateQueryBuilder &SUpdateQueryBuilder::set(const QString col0, const QVariant &val0,
                                              const QString col1, const QVariant &val1,
                                              const QString col2, const QVariant &val2,
                                              const QString col3, const QVariant &val3,
                                              const QString col4, const QVariant &val4,
                                              const QString col5, const QVariant &val5,
                                              const QString col6, const QVariant &val6,
                                              const QString col7, const QVariant &val7,
                                              const QString col8, const QVariant &val8,
                                              const QString col9, const QVariant &val9)
{
    S_D(SUpdateQueryBuilder);
    d->values.clear();
    if (!col0.isEmpty())
        d->values.append(SValue(col0, val0));
    if (!col1.isEmpty())
        d->values.append(SValue(col1, val1));
    if (!col2.isEmpty())
        d->values.append(SValue(col2, val2));
    if (!col3.isEmpty())
        d->values.append(SValue(col3, val3));
    if (!col4.isEmpty())
        d->values.append(SValue(col4, val4));
    if (!col5.isEmpty())
        d->values.append(SValue(col5, val5));
    if (!col6.isEmpty())
        d->values.append(SValue(col6, val6));
    if (!col7.isEmpty())
        d->values.append(SValue(col7, val7));
    if (!col8.isEmpty())
        d->values.append(SValue(col8, val8));
    if (!col9.isEmpty())
        d->values.append(SValue(col9, val9));
    return *this;
}

SUpdateQueryBuilderPrivate::SUpdateQueryBuilderPrivate()
{
}

SUpdateQueryBuilderPrivate::SUpdateQueryBuilderPrivate(const SUpdateQueryBuilderPrivate &other)
{

}

SUpdateQueryBuilderPrivate::~SUpdateQueryBuilderPrivate()
{

}

QString SUpdateQueryBuilderPrivate::build()
{
    QString more;

    {
        QStringList clauses;
        if (!where.isEmpty())
            clauses.append(whereClause());

        if (!clauses.isEmpty())
            more = "  " + clauses.join("  ");
    }

    return QStringLiteral("UPDATE %1  "
                          "SET %2%3")
            .arg(tableName, valuesString(), more);
}

QString SUpdateQueryBuilderPrivate::valuesString() const
{
    QStringList vals;
    for (int i(0); i < values.size(); ++i) {
        SValue v = values.at(i);
        vals.append(equality(v.first, v.second));
    }
    return vals.join(",  ");
}
