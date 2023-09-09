#ifndef SUPDATEQUERYBUILDER_P_H
#define SUPDATEQUERYBUILDER_P_H

#include "supdatequerybuilder.h"

#include "squerybuilder_p.h"

typedef QPair<QString, QVariant> SValue;

class SUpdateQueryBuilderPrivate : public SQueryBuilderPrivate
{
public:
    SUpdateQueryBuilderPrivate();
    SUpdateQueryBuilderPrivate(const SUpdateQueryBuilderPrivate &other);
    ~SUpdateQueryBuilderPrivate();

    bool isValid() const override
    {return !tableName.isEmpty() && !values.isEmpty();}

    QString build() override;

    QString tableName;
    QVector<SValue> values;

protected:
    QString valuesString() const;
};

#endif // SUPDATEQUERYBUILDER_P_H
