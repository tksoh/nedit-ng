
#ifndef UTIL_QT_HELPER_H_
#define UTIL_QT_HELPER_H_

#include <QCoreApplication>

#define Q_DECLARE_NAMESPACE_TR(context)                                                             \
	inline QString tr(const char *sourceText, const char *disambiguation = Q_NULLPTR, int n = -1) { \
		return QCoreApplication::translate(#context, sourceText, disambiguation, n);                \
	}

#endif
