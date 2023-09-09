#ifndef SQUERYBUILDER_P_H
#define SQUERYBUILDER_P_H

#include "squerybuilder.h"

#include <QtCore/qvariant.h>

#define SQUERYBUILDER_VALUE(i) val##i

class SQueryBuilderPrivate : public QSharedData
{
public:
    SQueryBuilderPrivate();
    SQueryBuilderPrivate(const SQueryBuilderPrivate &other);
    virtual ~SQueryBuilderPrivate();

    virtual bool isValid() const
    {return false;}

    virtual QString build();

    QChar lineSeparator() const
    {return humanReadable ? '\n' : ' ';}

    bool humanReadable;
    QString where;

    static QString format(const QVariant &data = QVariant());
    static QString equality(const QString &name, const QVariant &data);

protected:
    QString whereClause() const;
};

#endif // SQUERYBUILDER_P_H
