#ifndef SGLOBAL_H
#define SGLOBAL_H

#include <SQuery/sconfig.h>

#ifdef SQUERY_SHARED
#   ifdef BUILD_SQUERY_LIB
#       define SQUERY_EXPORT Q_DECL_EXPORT
#   else
#       define SQUERY_EXPORT Q_DECL_IMPORT
#   endif
#else
#   define SQUERY_EXPORT
#endif

#ifndef SQUERY_LIB
#   define SQUERY_LIB
#endif

#define S_D(Class) Class##Private *d = static_cast<Class##Private *>(qGetPtrHelper(this->d))

#endif // SGLOBAL_H
