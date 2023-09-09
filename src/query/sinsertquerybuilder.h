#ifndef SINSERTQUERYBUILDER_H
#define SINSERTQUERYBUILDER_H

#include <SQuery/sglobal.h>
#include <SQuery/squerybuilder.h>

#include <QtCore/qstringlist.h>
#include <QtCore/qvariant.h>

class SInsertQueryBuilderPrivate;
class SQUERY_EXPORT SInsertQueryBuilder : public SQueryBuilder
{
public:
    SInsertQueryBuilder();
    SInsertQueryBuilder(const QString &table, const QStringList &columns);
    SInsertQueryBuilder(const QString &table, QString columns);
    SInsertQueryBuilder(const QString &table);
    SInsertQueryBuilder(const SInsertQueryBuilder &other);
    SInsertQueryBuilder(SInsertQueryBuilder &&other);
    ~SInsertQueryBuilder();

    SInsertQueryBuilder &operator=(const SInsertQueryBuilder &other);
    SInsertQueryBuilder &operator=(SInsertQueryBuilder &&other);

    SInsertQueryBuilder &values(const QVariantList &values);
    SInsertQueryBuilder &values(const QVariant &val0, const QVariant &val1 = QVariant(),
                                const QVariant &val2 = QVariant(), const QVariant &val3 = QVariant(),
                                const QVariant &val4 = QVariant(), const QVariant &val5 = QVariant(),
                                const QVariant &val6 = QVariant(), const QVariant &val7 = QVariant(),
                                const QVariant &val8 = QVariant(), const QVariant &val9 = QVariant());

private:
    SQueryBuilder &where(const QString &clause);
};

#endif // SINSERTQUERYBUILDER_H
