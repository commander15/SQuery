#ifndef SQUERYBUILDER_H
#define SQUERYBUILDER_H

#include <SQuery/sglobal.h>

#ifdef QT_SQL_LIB
#   include <QtSql/qsqlquery.h>
#endif

#include <QtCore/qstring.h>
#include <QtCore/qshareddata.h>

class SQueryBuilderPrivate;
class SQUERY_EXPORT SQueryBuilder
{
public:
    SQueryBuilder();
    SQueryBuilder(const SQueryBuilder &other);
    SQueryBuilder(SQueryBuilder &&other);
    ~SQueryBuilder();

    SQueryBuilder &operator=(const SQueryBuilder &other);
    SQueryBuilder &operator=(SQueryBuilder &&other);

    operator QString()
    {return build();}

    bool isValid() const;

    SQueryBuilder &where(const QString &clause);

    QString build(bool humanReadable = false);

#ifdef QT_SQL_LIB
    QSqlQuery exec(const QSqlDatabase &db)
    {return QSqlQuery(build(), db);}
#endif

protected:
    SQueryBuilder(SQueryBuilderPrivate &dd);

    QSharedDataPointer<SQueryBuilderPrivate> d;
};

#endif // SQUERYBUILDER_H
