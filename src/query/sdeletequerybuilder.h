#ifndef SDELETEQUERYBUILDER_H
#define SDELETEQUERYBUILDER_H

#include <SQuery/sglobal.h>
#include <SQuery/squerybuilder.h>

class SDeleteQueryBuilderPrivate;
class SQUERY_EXPORT SDeleteQueryBuilder : public SQueryBuilder
{
public:
    SDeleteQueryBuilder();
    SDeleteQueryBuilder(const QString &table);
    SDeleteQueryBuilder(const SDeleteQueryBuilder &other);
    SDeleteQueryBuilder(SDeleteQueryBuilder &&other);
    ~SDeleteQueryBuilder();

    SDeleteQueryBuilder &operator=(const SDeleteQueryBuilder &other);
    SDeleteQueryBuilder &operator=(SDeleteQueryBuilder &&other);

    SDeleteQueryBuilder &where(const QString &clause)
    {return static_cast<SDeleteQueryBuilder &>(SQueryBuilder::where(clause));}
};

#endif // SDELETEQUERYBUILDER_H
