#include "sdeletequerybuilder.h"
#include "sdeletequerybuilder_p.h"

SDeleteQueryBuilder::SDeleteQueryBuilder() :
    SQueryBuilder(*new SDeleteQueryBuilderPrivate)
{
}

SDeleteQueryBuilder::SDeleteQueryBuilder(const QString &table) :
    SQueryBuilder(*new SDeleteQueryBuilderPrivate)
{
    S_D(SDeleteQueryBuilder);
    d->table = table;
}

SDeleteQueryBuilder::SDeleteQueryBuilder(const SDeleteQueryBuilder &other) :
    SQueryBuilder(other)
{
}

SDeleteQueryBuilder::SDeleteQueryBuilder(SDeleteQueryBuilder &&other) :
    SQueryBuilder(other)
{
}

SDeleteQueryBuilder::~SDeleteQueryBuilder()
{
}

SDeleteQueryBuilder &SDeleteQueryBuilder::operator=(const SDeleteQueryBuilder &other)
{
    if (this != &other)
        d = other.d;
    return *this;
}

SDeleteQueryBuilder &SDeleteQueryBuilder::operator=(SDeleteQueryBuilder &&other)
{
    if (this != &other)
        d.swap(other.d);
    return *this;
}

SDeleteQueryBuilderPrivate::SDeleteQueryBuilderPrivate()
{
}

SDeleteQueryBuilderPrivate::SDeleteQueryBuilderPrivate(const SDeleteQueryBuilderPrivate &other) :
    SQueryBuilderPrivate(other),
    table(other.table)
{
}

SDeleteQueryBuilderPrivate::~SDeleteQueryBuilderPrivate()
{
}

QString SDeleteQueryBuilderPrivate::build()
{
    return QStringLiteral("DELETE FROM %1  "
                          "%2")
            .arg(table, !where.isEmpty() ? whereClause() : QString());
}
