#include "sselectquerybuilder.h"
#include "sselectquerybuilder_p.h"

SSelectQueryBuilder::SSelectQueryBuilder() :
    SQueryBuilder(*new SSelectQueryBuilderPrivate)
{
}

SSelectQueryBuilder::SSelectQueryBuilder(const QStringList &columns) :
    SQueryBuilder(*new SSelectQueryBuilderPrivate)
{
    S_D(SSelectQueryBuilder);
    d->columns = columns;
}

SSelectQueryBuilder::SSelectQueryBuilder(QString columns) :
    SQueryBuilder(*new SSelectQueryBuilderPrivate)
{
    S_D(SSelectQueryBuilder);
    if (!columns.isEmpty()) {
        columns.remove(' ');
        d->columns = columns.split(',');
    }
}

SSelectQueryBuilder::SSelectQueryBuilder(const SSelectQueryBuilder &other) :
    SQueryBuilder(other)
{
}

SSelectQueryBuilder::SSelectQueryBuilder(SSelectQueryBuilder &&other) :
    SQueryBuilder(other)
{
}

SSelectQueryBuilder::~SSelectQueryBuilder()
{
}

SSelectQueryBuilder &SSelectQueryBuilder::operator=(const SSelectQueryBuilder &other)
{
    if (this != &other)
        d = other.d;
    return *this;
}

SSelectQueryBuilder &SSelectQueryBuilder::operator=(SSelectQueryBuilder &&other)
{
    if (this != &other)
        d.swap(other.d);
    return *this;
}

SSelectQueryBuilder &SSelectQueryBuilder::from(const QStringList &tables)
{
    S_D(SSelectQueryBuilder);
    d->tables = tables;
    return *this;
}

SSelectQueryBuilder &SSelectQueryBuilder::from(QString tables)
{
    tables.remove(' ');
    return from(tables.split(','));
}

SSelectQueryBuilder &SSelectQueryBuilder::join(int mode, const QString &table,
                                               const QString &fkColumn, const QString &pkColumn)
{
    SJoin join;
    if (mode >= InnerJoin && mode <= LeftJoin)
        join.mode = mode;
    else
        join.mode = LeftJoin;
    join.table = table;
    join.fkColumn = fkColumn;
    join.pkColumn = pkColumn;

    S_D(SSelectQueryBuilder);
    d->joins.append(join);
    return *this;
}

SSelectQueryBuilder &SSelectQueryBuilder::orderBy(const QString &column0, Qt::SortOrder order0,
                                                  const QString &column1, Qt::SortOrder order1)
{
    S_D(SSelectQueryBuilder);

    if (!column0.isEmpty())
        d->orders.append(SOrder(column0, order0));
    if (!column1.isEmpty())
        d->orders.append(SOrder(column1, order1));

    return *this;
}

SSelectQueryBuilder &SSelectQueryBuilder::limit(int l)
{
    S_D(SSelectQueryBuilder);
    d->limit = l;
    return *this;
}

SSelectQueryBuilder &SSelectQueryBuilder::offset(int o)
{
    S_D(SSelectQueryBuilder);
    d->offset = o;
    return *this;
}

SSelectQueryBuilderPrivate::SSelectQueryBuilderPrivate() :
    limit(-1),
    offset(-1)
{
}

SSelectQueryBuilderPrivate::SSelectQueryBuilderPrivate(const SSelectQueryBuilderPrivate &other) :
    SQueryBuilderPrivate(other),
    columns(other.columns),
    tables(other.tables),
    joins(other.joins),
    orders(other.orders),
    limit(other.limit),
    offset(other.offset)
{
}

SSelectQueryBuilderPrivate::~SSelectQueryBuilderPrivate()
{
}

QString SSelectQueryBuilderPrivate::build()
{
    QString more;

    {
        QStringList clauses;

        if (!joins.isEmpty())
            clauses.append(joinClauses());

        if (!where.isEmpty())
            clauses.append(whereClause());

        if (!orders.isEmpty())
            clauses.append(orderByClause());

        if (limit > 0 || offset > 0)
            clauses.append(limitOffsetClause());

        if (!clauses.isEmpty())
            more = "  " + clauses.join("  ");
    }

    QString cols;
    if (!columns.isEmpty())
        cols = columns.join(", ");
    else
        cols = '*';

    return QStringLiteral("SELECT %1  "
                          "FROM %2")
            .arg(cols, tables.join(", "))
            + more;
}

QString SSelectQueryBuilderPrivate::joinClauses() const
{
    QStringList clauses;

    for (int i(0); i < joins.size(); ++i) {
        SJoin j = joins.at(i);

        QString cond;
        if (j.fkColumn == j.pkColumn)
            cond = QStringLiteral("USING(%1)").arg(j.fkColumn);
        else
            cond = QStringLiteral("ON %1 = %2.%3")
                    .arg(j.fkColumn, j.table, j.pkColumn);

        clauses.append(QStringLiteral("%1 JOIN %2 %3")
                       .arg(j.mode == SSelectQueryBuilder::InnerJoin ? "INNER" : "LEFT",
                            j.table, cond));
    }

    return clauses.join("  ");
}

QString SSelectQueryBuilderPrivate::orderByClause() const
{
    QStringList cs;

    for (int i(0); i < orders.size(); ++i) {
        SOrder o = orders.at(i);
        cs.append(QStringLiteral("%1 %2").arg(o.first, o.second == Qt::AscendingOrder ? "ASC" : "DESC"));
    }

    if (!cs.isEmpty())
        return QStringLiteral("ORDER BY %1").arg(cs.join(", "));
    else
        return QString();
}

QString SSelectQueryBuilderPrivate::limitOffsetClause() const
{
    QStringList c;

    if (limit > 0)
        c.append(QStringLiteral("LIMIT %1").arg(limit));

    if (offset > 0)
        c.append(QStringLiteral("OFFSET %1").arg(offset));

    return c.join(' ');
}
