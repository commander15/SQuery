#ifndef SSELECTQUERYBUILDER_P_H
#define SSELECTQUERYBUILDER_P_H

#include "sselectquerybuilder.h"

#include "squerybuilder_p.h"

#include <QtCore/qpair.h>

struct SJoin
{
    int mode;
    QString table, fkColumn, pkColumn;
};

typedef QPair<QString, Qt::SortOrder> SOrder;

class SSelectQueryBuilderPrivate : public SQueryBuilderPrivate
{
public:
    SSelectQueryBuilderPrivate();
    SSelectQueryBuilderPrivate(const SSelectQueryBuilderPrivate &other);
    ~SSelectQueryBuilderPrivate();

    bool isValid() const override
    {return !tables.isEmpty();}

    QString build() override;

    QStringList columns, tables;
    QVector<SJoin> joins;
    QVector<SOrder> orders;
    int limit, offset;

protected:
    QString joinClauses() const;
    QString orderByClause() const;
    QString limitOffsetClause() const;
};

#endif // SSELECTQUERYBUILDER_P_H
