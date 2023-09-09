#include "squerybuildertest.h"

bool checkBuilder(SQueryBuilder &builder, const QString &s)
{
    bool ok = builder.build() == s;

    if (ok)
        return true;
    else {
        QString o = builder.build();

        int i;
        for (i = 0; i < o.size(); ++i)
            if (o.at(i) != s.at(i))
                break;
        qDebug().nospace() << o.left(i) << '|' << o.mid(i);
        return false;
    }
}
