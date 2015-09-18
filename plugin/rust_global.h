#ifndef RUST_GLOBAL_H
#define RUST_GLOBAL_H

#include <QtGlobal>

#if defined(RUST_LIBRARY)
#  define RUSTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RUSTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RUST_GLOBAL_H

