#include "squerybuilder.h"
#include "squerybuilder_p.h"

#include <QtCore/qdatetime.h>

SQueryBuilder::SQueryBuilder() :
    d(new SQueryBuilderPrivate)
{
}

SQueryBuilder::SQueryBuilder(const SQueryBuilder &other) :
    d(other.d)
{
}

SQueryBuilder::SQueryBuilder(SQueryBuilder &&other) :
    d(other.d)
{
}

SQueryBuilder::SQueryBuilder(SQueryBuilderPrivate &dd) :
    d(&dd)
{
}

SQueryBuilder::~SQueryBuilder()
{
}

SQueryBuilder &SQueryBuilder::operator=(const SQueryBuilder &other)
{
    if (this != &other)
        d = other.d;
    return *this;
}

bool SQueryBuilder::isValid() const
{
    return d->isValid();
}


SQueryBuilder &SQueryBuilder::operator=(SQueryBuilder &&other)
{
    if (this != &other)
        d.swap(other.d);
    return *this;
}

SQueryBuilder &SQueryBuilder::where(const QString &clause)
{
    d->where = clause;
    return *this;
}

QString SQueryBuilder::build(bool humanReadable)
{
    if (d->isValid()) {
        d->humanReadable = humanReadable;
        return d->build().replace("  ", d->lineSeparator());
    } else
        return QString();
}

SQueryBuilderPrivate::SQueryBuilderPrivate() :
    humanReadable(false)
{
}

SQueryBuilderPrivate::SQueryBuilderPrivate(const SQueryBuilderPrivate &other) :
    QSharedData(other),
    where(other.where),
    humanReadable(other.humanReadable)
{
}

SQueryBuilderPrivate::~SQueryBuilderPrivate()
{
}

QString SQueryBuilderPrivate::build()
{
    return whereClause();
}

QString SQueryBuilderPrivate::whereClause() const
{
    if (!where.isEmpty())
        return QStringLiteral("WHERE %1").arg(where);
    else
        return QString();
}


QString SQueryBuilderPrivate::format(const QVariant &data)
{
    bool quotes = false;
    QString d;

    switch (data.type()) {
    case QVariant::Char:
    case QVariant::String:
    case QVariant::Date:
    case QVariant::Time:
    case QVariant::DateTime:
        quotes = true;
        break;

    default:
        break;
    }

    switch (data.type()) {
    case QVariant::Invalid:
        d = "NULL";
        break;

    case QVariant::Bool:
        d = data.toBool() ? "TRUE" : "FALSE";
        break;

    case QVariant::Date:
        d = data.toDate().toString(Qt::ISODate);
        break;

    case QVariant::Time:
        d = data.toTime().toString(Qt::ISODate);
        break;

    case QVariant::DateTime:
        d = data.toDateTime().toString(Qt::ISODate);
        break;

    default:
        d = data.canConvert(QVariant::String) ? data.toString() : format();
        break;
    }

    return quotes ? '\'' + d + '\'' : d;
}

QString SQueryBuilderPrivate::equality(const QString &name, const QVariant &data)
{
    return QStringLiteral("%1 = %2").arg(name, format(data));
}
