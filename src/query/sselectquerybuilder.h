#ifndef SSELECTQUERYBUILDER_H
#define SSELECTQUERYBUILDER_H

#include <SQuery/sglobal.h>
#include <SQuery/squerybuilder.h>

class SSelectQueryBuilderPrivate;
class SQUERY_EXPORT SSelectQueryBuilder : public SQueryBuilder
{
public:
    enum JoinMode {
        InnerJoin,
        LeftJoin
    };

    SSelectQueryBuilder();
    SSelectQueryBuilder(const QStringList &columns);
    SSelectQueryBuilder(QString columns);
    SSelectQueryBuilder(const SSelectQueryBuilder &other);
    SSelectQueryBuilder(SSelectQueryBuilder &&other);
    ~SSelectQueryBuilder();

    SSelectQueryBuilder &operator=(const SSelectQueryBuilder &other);
    SSelectQueryBuilder &operator=(SSelectQueryBuilder &&other);

    SSelectQueryBuilder &from(const QStringList &tables);
    SSelectQueryBuilder &from(QString tables);

    SSelectQueryBuilder &join(int mode, const QString &table, const QString &fkColumn, const QString &pkColumn);
    SSelectQueryBuilder &join(int mode, const QString &table, const QString &column)
    {return join(mode, table, column, column);}

    SSelectQueryBuilder &where(const QString &clause)
    {return static_cast<SSelectQueryBuilder &>(SQueryBuilder::where(clause));}

    SSelectQueryBuilder &orderBy(const QString &column0, Qt::SortOrder order0 = Qt::AscendingOrder,
                                 const QString &column1 = QString(), Qt::SortOrder order1 = Qt::AscendingOrder);

    SSelectQueryBuilder &limit(int l);
    SSelectQueryBuilder &offset(int o);
};

#endif // SSELECTQUERYBUILDER_H
