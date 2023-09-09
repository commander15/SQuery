#ifndef SDELETEQUERYBUILDER_P_H
#define SDELETEQUERYBUILDER_P_H

#include "sdeletequerybuilder.h"

#include "squerybuilder_p.h"

class SDeleteQueryBuilderPrivate : public SQueryBuilderPrivate
{
public:
    SDeleteQueryBuilderPrivate();
    SDeleteQueryBuilderPrivate(const SDeleteQueryBuilderPrivate &other);
    ~SDeleteQueryBuilderPrivate();

    bool isValid() const override
    {return !table.isEmpty();}

    QString build() override;

    QString table;
};

#endif // SDELETEQUERYBUILDER_P_H
