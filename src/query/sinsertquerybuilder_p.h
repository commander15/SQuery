#ifndef SINSERTQUERYBUILDER_P_H
#define SINSERTQUERYBUILDER_P_H

#include "sinsertquerybuilder.h"

#include "squerybuilder_p.h"

class SInsertQueryBuilderPrivate : public SQueryBuilderPrivate
{
public:
    SInsertQueryBuilderPrivate();
    SInsertQueryBuilderPrivate(const SInsertQueryBuilderPrivate &other);
    ~SInsertQueryBuilderPrivate();

    bool isValid() const override
    {return !tableName.isEmpty() && !tableColumnValues.isEmpty();}

    QString build() override;

    QString tableName;
    QStringList tableColumnNames;
    QVariantList tableColumnValues;

private:
    QString values() const;
};

#endif // SINSERTQUERYBUILDER_P_H
