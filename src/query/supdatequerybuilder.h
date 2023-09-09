 #ifndef SUPDATEQUERYBUILDER_H
#define SUPDATEQUERYBUILDER_H

#include <SQuery/sglobal.h>
#include <SQuery/squerybuilder.h>

#include <QtCore/qvariant.h>

class SUpdateQueryBuilderPrivate;
class SQUERY_EXPORT SUpdateQueryBuilder : public SQueryBuilder
{
public:
    SUpdateQueryBuilder();
    SUpdateQueryBuilder(const QString &table);
    SUpdateQueryBuilder(const SUpdateQueryBuilder &other);
    SUpdateQueryBuilder(SUpdateQueryBuilder &&other);
    ~SUpdateQueryBuilder();

    SUpdateQueryBuilder &operator=(const SUpdateQueryBuilder &other);
    SUpdateQueryBuilder &operator=(SUpdateQueryBuilder &&other);

    SUpdateQueryBuilder &set(const QString col0            , const QVariant &val0,
                             const QString col1 = QString(), const QVariant &val1 = QVariant(),
                             const QString col2 = QString(), const QVariant &val2 = QVariant(),
                             const QString col3 = QString(), const QVariant &val3 = QVariant(),
                             const QString col4 = QString(), const QVariant &val4 = QVariant(),
                             const QString col5 = QString(), const QVariant &val5 = QVariant(),
                             const QString col6 = QString(), const QVariant &val6 = QVariant(),
                             const QString col7 = QString(), const QVariant &val7 = QVariant(),
                             const QString col8 = QString(), const QVariant &val8 = QVariant(),
                             const QString col9 = QString(), const QVariant &val9 = QVariant());

    SUpdateQueryBuilder &where(const QString &clause)
    {return static_cast<SUpdateQueryBuilder &>(SQueryBuilder::where(clause));}
};

#endif // SUPDATEQUERYBUILDER_H
