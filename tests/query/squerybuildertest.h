#ifndef SQUERYBUILDERTEST_H
#define SQUERYBUILDERTEST_H

#include <gtest/gtest.h>

#include <SQuery/squerybuilder.h>

#include <QtCore/qdebug.h>

#define CHECK_BUILDER(s) ASSERT_TRUE(checkBuilder(b, s))

bool checkBuilder(SQueryBuilder &builder, const QString &s);

#endif // SQUERYBUILDERTEST_H
