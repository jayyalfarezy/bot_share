

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_19"
#define CYTHON_HEX_VERSION 0x001D13F0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? PyMethod_New(func, self) : (Py_INCREF(func), func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__share
#define __PYX_HAVE_API__share

#ifdef _OPENMP
#include <omp.h>
#endif 

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif



#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else 
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif 
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "share.py",
};





#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name);


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif


#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var, name)  {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif


#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);


static CYTHON_INLINE int __Pyx_PySequence_ContainsTF(PyObject* item, PyObject* seq, int eq) {
    int result = PySequence_Contains(seq, item);
    return unlikely(result < 0) ? result : (result == (eq == Py_EQ));
}


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif


#if CYTHON_COMPILING_IN_PYPY
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#elif PY_MAJOR_VERSION < 3
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyString_CheckExact(s)) ? PyUnicode_FromEncodedObject(s, NULL, "strict") :\
        PyObject_Format(s, f))
#elif CYTHON_USE_TYPE_SLOTS
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyLong_CheckExact(s)) ? PyLong_Type.tp_str(s) :\
        likely(PyFloat_CheckExact(s)) ? PyFloat_Type.tp_str(s) :\
        PyObject_Format(s, f))
#else
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#endif


#include <string.h>


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      Py_UCS4 max_char);


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key);
#define __Pyx_PyObject_Dict_GetItem(obj, name)\
    (likely(PyDict_CheckExact(obj)) ?\
     __Pyx_PyDict_GetItem(obj, name) : PyObject_GetItem(obj, name))
#else
#define __Pyx_PyDict_GetItem(d, key) PyObject_GetItem(d, key)
#define __Pyx_PyObject_Dict_GetItem(obj, name)  PyObject_GetItem(obj, name)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_ExceptionMatches(err) __Pyx_PyErr_ExceptionMatchesInState(__pyx_tstate, err)
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err);
#else
#define __Pyx_PyErr_ExceptionMatches(err)  PyErr_ExceptionMatches(err)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif


static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname);


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_PyList_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len) & likely(len > (L->allocated >> 1))) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        Py_SIZE(list) = len+1;
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_PyList_Append(L,x) PyList_Append(L,x)
#endif


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);


static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x);


#if CYTHON_USE_PYTYPE_LOOKUP && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_LookupSpecial(PyObject* obj, PyObject* attr_name) {
    PyObject *res;
    PyTypeObject *tp = Py_TYPE(obj);
#if PY_MAJOR_VERSION < 3
    if (unlikely(PyInstance_Check(obj)))
        return __Pyx_PyObject_GetAttrStr(obj, attr_name);
#endif
    res = _PyType_Lookup(tp, attr_name);
    if (likely(res)) {
        descrgetfunc f = Py_TYPE(res)->tp_descr_get;
        if (!f) {
            Py_INCREF(res);
        } else {
            res = f(res, obj, (PyObject *)tp);
        }
    } else {
        PyErr_SetObject(PyExc_AttributeError, attr_name);
    }
    return res;
}
#else
#define __Pyx_PyObject_LookupSpecial(o,n) __Pyx_PyObject_GetAttrStr(o,n)
#endif


static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);


static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);


static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_AddObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceAdd(op1, op2) : PyNumber_Add(op1, op2))
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);


static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);


#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);


#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f)\
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;  // used by FusedFunction for copying defaults
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj)  (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals);


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals);


#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif


typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);


static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);


static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);


static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);


static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);


static int __Pyx_check_binary_version(void);


static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);



#define __Pyx_MODULE_NAME "share"
extern int __pyx_module_is_main_share;
int __pyx_module_is_main_share = 0;


static PyObject *__pyx_builtin_open;
static PyObject *__pyx_builtin_exit;
static PyObject *__pyx_builtin_input;
static PyObject *__pyx_builtin_range;
static const char __pyx_k_[] = " _______  ___________  ________  __    __   \n|   _  \"\\(\"     _   \")/\"       )/\" |  | \"\\    ";
static const char __pyx_k_0[] = "?0";
static const char __pyx_k_1[] = "1";
static const char __pyx_k_B[] = "B";
static const char __pyx_k_H[] = "H";
static const char __pyx_k_K[] = "K";
static const char __pyx_k_M[] = "M";
static const char __pyx_k_N[] = "N";
static const char __pyx_k_O[] = "O";
static const char __pyx_k_P[] = "P";
static const char __pyx_k_U[] = "U";
static const char __pyx_k_e[] = "e";
static const char __pyx_k_r[] = "r";
static const char __pyx_k_w[] = "w";
static const char __pyx_k_z[] = "z";
static const char __pyx_k_0m[] = "\033[0m";
static const char __pyx_k_A2[] = "A2";
static const char __pyx_k_B2[] = "B2";
static const char __pyx_k_H2[] = "H2";
static const char __pyx_k_IP[] = "IP";
static const char __pyx_k_J2[] = "J2";
static const char __pyx_k_K2[] = "K2";
static const char __pyx_k_M2[] = "M2";
static const char __pyx_k_N2[] = "N2";
static const char __pyx_k_O2[] = "O2";
static const char __pyx_k_P2[] = "P2";
static const char __pyx_k_U2[] = "U2";
static const char __pyx_k_Z2[] = "Z2";
static const char __pyx_k__2[] = "\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210";
static const char __pyx_k__3[] = "\n(. |_)  :))__/  \\__/(:   \\___/(:  (__)  :)    ";
static const char __pyx_k__4[] = "\n|:     \\/    \\_ /    \\___  \\   \\/      \\/     ";
static const char __pyx_k__5[] = "\n(|  _  \\    |.  |     __/  \\  //  __  \\       ";
static const char __pyx_k__6[] = "\n|: |_)  :)   \\:  |    /\" \\   :)(:  (  )  :)     ";
static const char __pyx_k__7[] = "\n(_______/     \\__|   (_______/  \\__|  |__/    ";
static const char __pyx_k_id[] = "id";
static const char __pyx_k_os[] = "os";
static const char __pyx_k_re[] = "re";
static const char __pyx_k__18[] = " ";
static const char __pyx_k__20[] = "";
static const char __pyx_k__21[] = "[";
static const char __pyx_k__22[] = "+";
static const char __pyx_k__29[] = "/";
static const char __pyx_k__31[] = "[/]";
static const char __pyx_k_bs4[] = "bs4";
static const char __pyx_k_cls[] = "cls";
static const char __pyx_k_cok[] = "cok";
static const char __pyx_k_des[] = "des";
static const char __pyx_k_get[] = "get";
static const char __pyx_k_idt[] = "idt";
static const char __pyx_k_iya[] = "iya";
static const char __pyx_k_men[] = "men";
static const char __pyx_k_mun[] = "mun";
static const char __pyx_k_now[] = "now";
static const char __pyx_k_ses[] = "ses";
static const char __pyx_k_sys[] = "sys";
static const char __pyx_k_url[] = "url";
static const char __pyx_k_war[] = "war";
static const char __pyx_k_win[] = "win";
static const char __pyx_k_List[] = "List";
static const char __pyx_k_Tree[] = "Tree";
static const char __pyx_k_biru[] = "biru";
static const char __pyx_k_data[] = "data";
static const char __pyx_k_date[] = "date";
static const char __pyx_k_exit[] = "exit";
static const char __pyx_k_fall[] = "fall";
static const char __pyx_k_host[] = "host";
static const char __pyx_k_hour[] = "hour";
static const char __pyx_k_http[] = "http";
static const char __pyx_k_json[] = "json";
static const char __pyx_k_logo[] = "logo";
static const char __pyx_k_loop[] = "loop";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_menu[] = "menu";
static const char __pyx_k_nama[] = "nama";
static const char __pyx_k_name[] = "name";
static const char __pyx_k_open[] = "open";
static const char __pyx_k_oren[] = "oren";
static const char __pyx_k_pink[] = "pink";
static const char __pyx_k_post[] = "post";
static const char __pyx_k_prog[] = "prog";
static const char __pyx_k_prox[] = "prox";
static const char __pyx_k_read[] = "read";
static const char __pyx_k_rich[] = "rich";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_text[] = "text";
static const char __pyx_k_time[] = "time";
static const char __pyx_k_ungu[] = "ungu";
static const char __pyx_k_1_91m[] = "\033[1;91m";
static const char __pyx_k_1_92m[] = "\033[1;92m";
static const char __pyx_k_1_93m[] = "\033[1;93m";
static const char __pyx_k_1_94m[] = "\033[1;94m";
static const char __pyx_k_1_95m[] = "\033[1;95m";
static const char __pyx_k_1_96m[] = "\033[1;96m";
static const char __pyx_k_1_97m[] = "\033[1;97m";
static const char __pyx_k_Panel[] = "Panel";
static const char __pyx_k_clear[] = "clear";
static const char __pyx_k_clock[] = "clock";
static const char __pyx_k_close[] = "close";
static const char __pyx_k_enter[] = "__enter__";
static const char __pyx_k_group[] = "group";
static const char __pyx_k_hijau[] = "hijau";
static const char __pyx_k_hours[] = "hours";
static const char __pyx_k_input[] = "input";
static const char __pyx_k_limit[] = "limit";
static const char __pyx_k_linux[] = "linux";
static const char __pyx_k_loads[] = "loads";
static const char __pyx_k_login[] = "login";
static const char __pyx_k_lower[] = "lower";
static const char __pyx_k_merah[] = "merah";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_proxy[] = "proxy";
static const char __pyx_k_putih[] = "putih";
static const char __pyx_k_query[] = "query";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_reset[] = "reset";
static const char __pyx_k_share[] = "share";
static const char __pyx_k_sleep[] = "sleep";
static const char __pyx_k_style[] = "style";
static const char __pyx_k_tanya[] = "tanya";
static const char __pyx_k_tinyi[] = "tinyi";
static const char __pyx_k_title[] = "title";
static const char __pyx_k_token[] = "token";
static const char __pyx_k_total[] = "total";
static const char __pyx_k_waktu[] = "waktu";
static const char __pyx_k_warna[] = "warna";
static const char __pyx_k_width[] = "width";
static const char __pyx_k_write[] = "write";
static const char __pyx_k_000000[] = "[#000000]";
static const char __pyx_k_00C8FF[] = "[#00C8FF]";
static const char __pyx_k_00FF00[] = "[#00FF00]";
static const char __pyx_k_00FFFF[] = "[#00FFFF]";
static const char __pyx_k_AAAAAA[] = "[#AAAAAA]";
static const char __pyx_k_AF00FF[] = "[#AF00FF]";
static const char __pyx_k_EAAG_w[] = "(EAAG\\w+)";
static const char __pyx_k_FF0000[] = "[#FF0000]";
static const char __pyx_k_FF00FF[] = "[#FF00FF]";
static const char __pyx_k_FF8F00[] = "[#FF8F00]";
static const char __pyx_k_FFFF00[] = "[#FFFF00]";
static const char __pyx_k_FFFFFF[] = "[#FFFFFF]";
static const char __pyx_k_Thread[] = "Thread";
static const char __pyx_k_accept[] = "accept";
static const char __pyx_k_append[] = "append";
static const char __pyx_k_cookie[] = "cookie";
static const char __pyx_k_exit_2[] = "__exit__";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_kuning[] = "kuning";
static const char __pyx_k_muncul[] = "muncul";
static const char __pyx_k_name_2[] = "__name__";
static const char __pyx_k_negara[] = "negara";
static const char __pyx_k_origin[] = "origin";
static const char __pyx_k_parser[] = "parser";
static const char __pyx_k_prints[] = "prints";
static const char __pyx_k_prompt[] = "prompt";
static const char __pyx_k_search[] = "search";
static const char __pyx_k_submit[] = "submit";
static const char __pyx_k_system[] = "system";
static const char __pyx_k_update[] = "update";
static const char __pyx_k_Console[] = "Console";
static const char __pyx_k_Session[] = "Session";
static const char __pyx_k_advance[] = "advance";
static const char __pyx_k_choices[] = "choices";
static const char __pyx_k_console[] = "console";
static const char __pyx_k_cookies[] = "cookies";
static const char __pyx_k_country[] = "country";
static const char __pyx_k_default[] = "default";
static const char __pyx_k_headers[] = "headers";
static const char __pyx_k_message[] = "message";
static const char __pyx_k_padding[] = "padding";
static const char __pyx_k_proxies[] = "proxies";
static const char __pyx_k_referer[] = "referer";
static const char __pyx_k_timenow[] = "timenow";
static const char __pyx_k_00C8FF_2[] = "#00C8FF";
static const char __pyx_k_00FF00_2[] = "#00FF00";
static const char __pyx_k_AF00FF_2[] = "#AF00FF";
static const char __pyx_k_FF0000_2[] = "#FF0000";
static const char __pyx_k_FF00FF_2[] = "#FF00FF";
static const char __pyx_k_FF8F00_2[] = "#FF8F00";
static const char __pyx_k_FFFF00_2[] = "#FFFF00";
static const char __pyx_k_FFFFFF_2[] = "#FFFFFF";
static const char __pyx_k_Progress[] = "Progress";
static const char __pyx_k_add_task[] = "add_task";
static const char __pyx_k_datetime[] = "datetime";
static const char __pyx_k_inquirer[] = "inquirer";
static const char __pyx_k_platform[] = "platform";
static const char __pyx_k_requests[] = "requests";
static const char __pyx_k_share_py[] = "share.py";
static const char __pyx_k_subtitle[] = "subtitle";
static const char __pyx_k_BarColumn[] = "BarColumn";
static const char __pyx_k_Indonesia[] = "Indonesia";
static const char __pyx_k_authority[] = "authority";
static const char __pyx_k_max_age_0[] = "max-age=0";
static const char __pyx_k_rich_tree[] = "rich.tree";
static const char __pyx_k_threading[] = "threading";
static const char __pyx_k_TextColumn[] = "TextColumn";
static const char __pyx_k_color_rich[] = "color_rich";
static const char __pyx_k_exceptions[] = "exceptions";
static const char __pyx_k_find_token[] = "find_token";
static const char __pyx_k_pilih_menu[] = "pilih menu";
static const char __pyx_k_rich_panel[] = "rich.panel";
static const char __pyx_k_splitlines[] = "splitlines";
static const char __pyx_k_user_agent[] = "user-agent";
static const char __pyx_k_color_table[] = "color_table";
static const char __pyx_k_description[] = "description";
static const char __pyx_k_max_workers[] = "max_workers";
static const char __pyx_k_pilih_warna[] = "pilih warna";
static const char __pyx_k_share_cepat[] = "share_cepat";
static const char __pyx_k_Buatan_Coder[] = "Buatan Coder ";
static const char __pyx_k_access_token[] = "&access_token=";
static const char __pyx_k_clear_screen[] = "clear_screen";
static const char __pyx_k_content_type[] = "content-type";
static const char __pyx_k_ganti_tumbal[] = "ganti tumbal";
static const char __pyx_k_keluar_tools[] = "keluar tools";
static const char __pyx_k_masukan_link[] = "] masukan link : ";
static const char __pyx_k_proses_share[] = "proses share ";
static const char __pyx_k_rich_console[] = "rich.console";
static const char __pyx_k_selamat_pagi[] = "selamat pagi";
static const char __pyx_k_selamat_sore[] = "selamat sore";
static const char __pyx_k_share_lambat[] = "share_lambat";
static const char __pyx_k_BeautifulSoup[] = "BeautifulSoup";
static const char __pyx_k_SpinnerColumn[] = "SpinnerColumn";
static const char __pyx_k_cache_control[] = "cache-control";
static const char __pyx_k_masukan_limit[] = "] masukan limit : ";
static const char __pyx_k_rich_progress[] = "rich.progress";
static const char __pyx_k_selamat_malam[] = "selamat malam";
static const char __pyx_k_selamat_siang[] = "selamat siang";
static const char __pyx_k_data_proxy_txt[] = "data/proxy.txt";
static const char __pyx_k_data_token_txt[] = "data/token.txt";
static const char __pyx_k_masukan_cookie[] = " masukan cookie : ";
static const char __pyx_k_ConnectionError[] = "ConnectionError";
static const char __pyx_k_accept_language[] = "accept-language";
static const char __pyx_k_data_cookie_txt[] = "data/cookie.txt";
static const char __pyx_k_ganti_warna_tema[] = "ganti warna tema";
static const char __pyx_k_sec_ch_ua_mobile[] = "sec-ch-ua-mobile";
static const char __pyx_k_task_description[] = "{task.description}";
static const char __pyx_k_FileNotFoundError[] = "FileNotFoundError";
static const char __pyx_k_TimeElapsedColumn[] = "TimeElapsedColumn";
static const char __pyx_k_Bot_Share_Facebook[] = "Bot Share Facebook ";
static const char __pyx_k_ThreadPoolExecutor[] = "ThreadPoolExecutor";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_concurrent_futures[] = "concurrent.futures";
static const char __pyx_k_graph_facebook_com[] = "graph.facebook.com";
static const char __pyx_k_task_percentage_0f[] = "{task.percentage:.0f}%";
static const char __pyx_k_data_color_rich_txt[] = "data/color_rich.txt";
static const char __pyx_k_data_color_table_txt[] = "data/color_table.txt";
static const char __pyx_k_http_ip_api_com_json[] = "http://ip-api.com/json/";
static const char __pyx_k_business_facebook_com[] = "business.facebook.com";
static const char __pyx_k_share_postingan_cepat[] = "share postingan cepat";
static const char __pyx_k_https_www_facebook_com[] = "https://www.facebook.com/";
static const char __pyx_k_munculkan_proses_share[] = "munculkan proses share";
static const char __pyx_k_share_postingan_lambat[] = "share postingan lambat";
static const char __pyx_k_text_html_charset_utf_8[] = "text/html; charset=utf-8";
static const char __pyx_k_published_0_access_token[] = "&published=0&access_token=";
static const char __pyx_k_berhasil_membagikan_total[] = "berhasil membagikan total ";
static const char __pyx_k_socks5_random_choice_prox[] = "socks5://{random.choice(prox)}";
static const char __pyx_k_upgrade_insecure_requests[] = "upgrade-insecure-requests";
static const char __pyx_k_dan_selamat_menikmati_tools[] = " dan selamat menikmati tools";
static const char __pyx_k_https_business_facebook_com[] = "https://business.facebook.com";
static const char __pyx_k_jangan_munculkan_proses_share[] = "jangan munculkan proses share";
static const char __pyx_k_berhasil_mengubah_tema_menjadi[] = "berhasil mengubah tema menjadi ";
static const char __pyx_k_Mozilla_5_0_Linux_Android_8_1_0[] = "Mozilla/5.0 (Linux; Android 8.1.0; MI 8 Build/OPM1.171019.011) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.86 Mobile Safari/537.36";
static const char __pyx_k_cookie_tidak_valid_silahkan_cek[] = "cookie tidak valid, silahkan cek akun tumbal atau matikan autentik";
static const char __pyx_k_https_raw_githubusercontent_com[] = "https://raw.githubusercontent.com/Fall-Xavier/bot_share/main/data/update.txt";
static const char __pyx_k_id_ID_id_q_0_9_en_US_q_0_8_en_q[] = "id-ID,id;q=0.9,en-US;q=0.8,en;q=0.7";
static const char __pyx_k_rm_f_data_token_txt_data_cookie[] = "rm -f data/token.txt data/cookie.txt";
static const char __pyx_k_share_silahkan_jalankan_ulang_t[] = " share, silahkan jalankan ulang tools ini";
static const char __pyx_k_silahkan_jalankan_ulang_tools_i[] = ", silahkan jalankan ulang tools ini";
static const char __pyx_k_text_html_application_xhtml_xml[] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8";
static const char __pyx_k_Mozilla_5_0_X11_Linux_x86_64_App[] = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.66 Safari/537.36";
static const char __pyx_k_berhasil_login_ke_tools_ini_sila[] = "berhasil login ke tools ini, silahkan menunggu proses verifikasi data";
static const char __pyx_k_https_api_proxyscrape_com_reques[] = "https://api.proxyscrape.com/?request=displayproxies&protocol=socks5&timeout=10000&country=all&ssl=all&anonymity=all";
static const char __pyx_k_https_business_facebook_com_busi[] = "https://business.facebook.com/business_locations";
static const char __pyx_k_https_graph_facebook_com_2136141[] = "https://graph.facebook.com/213614107297063/comments/?message=";
static const char __pyx_k_https_graph_facebook_com_me_acce[] = "https://graph.facebook.com/me?access_token=";
static const char __pyx_k_https_graph_facebook_com_v13_0_m[] = "https://graph.facebook.com/v13.0/me/feed?link=";
static const char __pyx_k_koneksi_internet_bermasalah_sila[] = "koneksi internet bermasalah, silahkan cek jaringan internet kamu";
static const char __pyx_k_maaf_script_saat_ini_sedang_main[] = "maaf script saat ini sedang maintenance, silahkan menunggu selesai";
static const char __pyx_k_membagikan_postingan_dengan_id_p[] = "membagikan postingan dengan id post ";
static const char __pyx_k_this_script_only_work_in_Indones[] = "this script only work in Indonesia, please search another script";
#ifdef Py_UNICODE_WIDE
static Py_UNICODE __pyx_k__14[] = { 128532,32,0 };
#else
static Py_UNICODE __pyx_k__14[] = { 55357,56852,32,0 };
#endif
static PyObject *__pyx_kp_u_;
static PyObject *__pyx_kp_u_0;
static PyObject *__pyx_kp_u_000000;
static PyObject *__pyx_kp_u_00C8FF;
static PyObject *__pyx_kp_u_00C8FF_2;
static PyObject *__pyx_kp_u_00FF00;
static PyObject *__pyx_kp_u_00FF00_2;
static PyObject *__pyx_kp_u_00FFFF;
static PyObject *__pyx_kp_u_0m;
static PyObject *__pyx_kp_u_1;
static PyObject *__pyx_kp_u_1_91m;
static PyObject *__pyx_kp_u_1_92m;
static PyObject *__pyx_kp_u_1_93m;
static PyObject *__pyx_kp_u_1_94m;
static PyObject *__pyx_kp_u_1_95m;
static PyObject *__pyx_kp_u_1_96m;
static PyObject *__pyx_kp_u_1_97m;
static PyObject *__pyx_n_s_A2;
static PyObject *__pyx_kp_u_AAAAAA;
static PyObject *__pyx_kp_u_AF00FF;
static PyObject *__pyx_kp_u_AF00FF_2;
static PyObject *__pyx_n_s_B;
static PyObject *__pyx_n_s_B2;
static PyObject *__pyx_n_s_BarColumn;
static PyObject *__pyx_n_s_BeautifulSoup;
static PyObject *__pyx_kp_u_Bot_Share_Facebook;
static PyObject *__pyx_kp_u_Buatan_Coder;
static PyObject *__pyx_n_s_ConnectionError;
static PyObject *__pyx_n_s_Console;
static PyObject *__pyx_kp_u_EAAG_w;
static PyObject *__pyx_kp_u_FF0000;
static PyObject *__pyx_kp_u_FF0000_2;
static PyObject *__pyx_kp_u_FF00FF;
static PyObject *__pyx_kp_u_FF00FF_2;
static PyObject *__pyx_kp_u_FF8F00;
static PyObject *__pyx_kp_u_FF8F00_2;
static PyObject *__pyx_kp_u_FFFF00;
static PyObject *__pyx_kp_u_FFFF00_2;
static PyObject *__pyx_kp_u_FFFFFF;
static PyObject *__pyx_kp_u_FFFFFF_2;
static PyObject *__pyx_n_s_FileNotFoundError;
static PyObject *__pyx_n_s_H;
static PyObject *__pyx_n_s_H2;
static PyObject *__pyx_n_s_IP;
static PyObject *__pyx_n_u_IP;
static PyObject *__pyx_n_u_Indonesia;
static PyObject *__pyx_n_s_J2;
static PyObject *__pyx_n_s_K;
static PyObject *__pyx_n_s_K2;
static PyObject *__pyx_n_s_List;
static PyObject *__pyx_n_s_M;
static PyObject *__pyx_n_s_M2;
static PyObject *__pyx_kp_u_Mozilla_5_0_Linux_Android_8_1_0;
static PyObject *__pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App;
static PyObject *__pyx_n_s_N;
static PyObject *__pyx_n_s_N2;
static PyObject *__pyx_n_s_O;
static PyObject *__pyx_n_s_O2;
static PyObject *__pyx_n_s_P;
static PyObject *__pyx_n_s_P2;
static PyObject *__pyx_n_s_Panel;
static PyObject *__pyx_n_s_Progress;
static PyObject *__pyx_n_s_Session;
static PyObject *__pyx_n_s_SpinnerColumn;
static PyObject *__pyx_n_s_TextColumn;
static PyObject *__pyx_n_s_Thread;
static PyObject *__pyx_n_s_ThreadPoolExecutor;
static PyObject *__pyx_n_s_TimeElapsedColumn;
static PyObject *__pyx_n_s_Tree;
static PyObject *__pyx_n_s_U;
static PyObject *__pyx_n_s_U2;
static PyObject *__pyx_n_s_Z2;
static PyObject *__pyx_kp_u__18;
static PyObject *__pyx_kp_u__2;
static PyObject *__pyx_kp_u__20;
static PyObject *__pyx_kp_u__21;
static PyObject *__pyx_kp_u__22;
static PyObject *__pyx_kp_u__29;
static PyObject *__pyx_kp_u__3;
static PyObject *__pyx_kp_u__31;
static PyObject *__pyx_kp_u__4;
static PyObject *__pyx_kp_u__5;
static PyObject *__pyx_kp_u__6;
static PyObject *__pyx_kp_u__7;
static PyObject *__pyx_n_u_accept;
static PyObject *__pyx_kp_u_accept_language;
static PyObject *__pyx_kp_u_access_token;
static PyObject *__pyx_n_s_add_task;
static PyObject *__pyx_n_s_advance;
static PyObject *__pyx_n_s_append;
static PyObject *__pyx_n_u_authority;
static PyObject *__pyx_kp_u_berhasil_login_ke_tools_ini_sila;
static PyObject *__pyx_kp_u_berhasil_membagikan_total;
static PyObject *__pyx_kp_u_berhasil_mengubah_tema_menjadi;
static PyObject *__pyx_n_u_biru;
static PyObject *__pyx_n_s_bs4;
static PyObject *__pyx_kp_u_business_facebook_com;
static PyObject *__pyx_kp_u_cache_control;
static PyObject *__pyx_n_s_choices;
static PyObject *__pyx_n_u_clear;
static PyObject *__pyx_n_s_clear_screen;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_u_clock;
static PyObject *__pyx_n_u_close;
static PyObject *__pyx_n_u_cls;
static PyObject *__pyx_n_s_cok;
static PyObject *__pyx_n_s_color_rich;
static PyObject *__pyx_n_s_color_table;
static PyObject *__pyx_n_s_concurrent_futures;
static PyObject *__pyx_n_s_console;
static PyObject *__pyx_kp_u_content_type;
static PyObject *__pyx_n_s_cookie;
static PyObject *__pyx_n_u_cookie;
static PyObject *__pyx_kp_u_cookie_tidak_valid_silahkan_cek;
static PyObject *__pyx_n_s_cookies;
static PyObject *__pyx_n_u_country;
static PyObject *__pyx_kp_u_dan_selamat_menikmati_tools;
static PyObject *__pyx_n_s_data;
static PyObject *__pyx_kp_u_data_color_rich_txt;
static PyObject *__pyx_kp_u_data_color_table_txt;
static PyObject *__pyx_kp_u_data_cookie_txt;
static PyObject *__pyx_kp_u_data_proxy_txt;
static PyObject *__pyx_kp_u_data_token_txt;
static PyObject *__pyx_n_s_date;
static PyObject *__pyx_n_s_datetime;
static PyObject *__pyx_n_s_default;
static PyObject *__pyx_n_s_des;
static PyObject *__pyx_n_s_description;
static PyObject *__pyx_n_s_e;
static PyObject *__pyx_n_s_enter;
static PyObject *__pyx_n_s_exceptions;
static PyObject *__pyx_n_s_exit;
static PyObject *__pyx_n_s_exit_2;
static PyObject *__pyx_n_s_fall;
static PyObject *__pyx_n_s_find_token;
static PyObject *__pyx_kp_u_ganti_tumbal;
static PyObject *__pyx_kp_u_ganti_warna_tema;
static PyObject *__pyx_n_s_get;
static PyObject *__pyx_kp_u_graph_facebook_com;
static PyObject *__pyx_n_s_group;
static PyObject *__pyx_n_s_headers;
static PyObject *__pyx_n_u_hijau;
static PyObject *__pyx_n_u_host;
static PyObject *__pyx_n_s_hour;
static PyObject *__pyx_n_s_hours;
static PyObject *__pyx_n_u_http;
static PyObject *__pyx_kp_u_http_ip_api_com_json;
static PyObject *__pyx_kp_u_https_api_proxyscrape_com_reques;
static PyObject *__pyx_kp_u_https_business_facebook_com;
static PyObject *__pyx_kp_u_https_business_facebook_com_busi;
static PyObject *__pyx_kp_u_https_graph_facebook_com_2136141;
static PyObject *__pyx_kp_u_https_graph_facebook_com_me_acce;
static PyObject *__pyx_kp_u_https_graph_facebook_com_v13_0_m;
static PyObject *__pyx_kp_u_https_raw_githubusercontent_com;
static PyObject *__pyx_kp_u_https_www_facebook_com;
static PyObject *__pyx_n_u_id;
static PyObject *__pyx_kp_u_id_ID_id_q_0_9_en_US_q_0_8_en_q;
static PyObject *__pyx_n_s_idt;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_input;
static PyObject *__pyx_n_s_inquirer;
static PyObject *__pyx_n_u_iya;
static PyObject *__pyx_kp_u_jangan_munculkan_proses_share;
static PyObject *__pyx_n_s_json;
static PyObject *__pyx_kp_u_keluar_tools;
static PyObject *__pyx_kp_u_koneksi_internet_bermasalah_sila;
static PyObject *__pyx_n_u_kuning;
static PyObject *__pyx_n_s_limit;
static PyObject *__pyx_n_u_linux;
static PyObject *__pyx_n_s_loads;
static PyObject *__pyx_n_s_login;
static PyObject *__pyx_n_s_logo;
static PyObject *__pyx_n_s_loop;
static PyObject *__pyx_n_s_lower;
static PyObject *__pyx_kp_u_maaf_script_saat_ini_sedang_main;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_u_main;
static PyObject *__pyx_kp_u_masukan_cookie;
static PyObject *__pyx_kp_u_masukan_limit;
static PyObject *__pyx_kp_u_masukan_link;
static PyObject *__pyx_kp_u_max_age_0;
static PyObject *__pyx_n_s_max_workers;
static PyObject *__pyx_kp_u_membagikan_postingan_dengan_id_p;
static PyObject *__pyx_n_s_men;
static PyObject *__pyx_n_s_menu;
static PyObject *__pyx_n_u_menu;
static PyObject *__pyx_n_u_merah;
static PyObject *__pyx_n_s_message;
static PyObject *__pyx_n_s_mun;
static PyObject *__pyx_n_s_muncul;
static PyObject *__pyx_n_u_muncul;
static PyObject *__pyx_kp_u_munculkan_proses_share;
static PyObject *__pyx_n_s_nama;
static PyObject *__pyx_n_u_name;
static PyObject *__pyx_n_s_name_2;
static PyObject *__pyx_n_s_negara;
static PyObject *__pyx_n_s_now;
static PyObject *__pyx_n_s_open;
static PyObject *__pyx_n_u_oren;
static PyObject *__pyx_n_u_origin;
static PyObject *__pyx_n_s_os;
static PyObject *__pyx_n_s_padding;
static PyObject *__pyx_n_s_parser;
static PyObject *__pyx_kp_u_pilih_menu;
static PyObject *__pyx_kp_u_pilih_warna;
static PyObject *__pyx_n_u_pink;
static PyObject *__pyx_n_s_platform;
static PyObject *__pyx_n_s_post;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_s_prints;
static PyObject *__pyx_n_s_prog;
static PyObject *__pyx_n_s_prompt;
static PyObject *__pyx_kp_u_proses_share;
static PyObject *__pyx_n_s_prox;
static PyObject *__pyx_n_s_proxies;
static PyObject *__pyx_n_s_proxy;
static PyObject *__pyx_kp_u_published_0_access_token;
static PyObject *__pyx_n_u_putih;
static PyObject *__pyx_n_u_query;
static PyObject *__pyx_n_u_r;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_re;
static PyObject *__pyx_n_s_read;
static PyObject *__pyx_n_u_referer;
static PyObject *__pyx_n_s_requests;
static PyObject *__pyx_n_s_reset;
static PyObject *__pyx_n_s_rich;
static PyObject *__pyx_n_s_rich_console;
static PyObject *__pyx_n_s_rich_panel;
static PyObject *__pyx_n_s_rich_progress;
static PyObject *__pyx_n_s_rich_tree;
static PyObject *__pyx_kp_u_rm_f_data_token_txt_data_cookie;
static PyObject *__pyx_n_s_search;
static PyObject *__pyx_kp_u_sec_ch_ua_mobile;
static PyObject *__pyx_kp_u_selamat_malam;
static PyObject *__pyx_kp_u_selamat_pagi;
static PyObject *__pyx_kp_u_selamat_siang;
static PyObject *__pyx_kp_u_selamat_sore;
static PyObject *__pyx_n_s_ses;
static PyObject *__pyx_n_s_share;
static PyObject *__pyx_n_s_share_cepat;
static PyObject *__pyx_n_s_share_lambat;
static PyObject *__pyx_kp_u_share_postingan_cepat;
static PyObject *__pyx_kp_u_share_postingan_lambat;
static PyObject *__pyx_kp_s_share_py;
static PyObject *__pyx_kp_u_share_silahkan_jalankan_ulang_t;
static PyObject *__pyx_kp_u_silahkan_jalankan_ulang_tools_i;
static PyObject *__pyx_n_s_sleep;
static PyObject *__pyx_kp_u_socks5_random_choice_prox;
static PyObject *__pyx_n_s_splitlines;
static PyObject *__pyx_n_s_style;
static PyObject *__pyx_n_s_submit;
static PyObject *__pyx_n_s_subtitle;
static PyObject *__pyx_n_s_sys;
static PyObject *__pyx_n_s_system;
static PyObject *__pyx_n_s_tanya;
static PyObject *__pyx_kp_u_task_description;
static PyObject *__pyx_kp_u_task_percentage_0f;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_text;
static PyObject *__pyx_kp_u_text_html_application_xhtml_xml;
static PyObject *__pyx_kp_u_text_html_charset_utf_8;
static PyObject *__pyx_kp_u_this_script_only_work_in_Indones;
static PyObject *__pyx_n_s_threading;
static PyObject *__pyx_n_s_time;
static PyObject *__pyx_n_s_timenow;
static PyObject *__pyx_n_s_tinyi;
static PyObject *__pyx_n_s_title;
static PyObject *__pyx_n_s_token;
static PyObject *__pyx_n_s_total;
static PyObject *__pyx_n_u_ungu;
static PyObject *__pyx_n_s_update;
static PyObject *__pyx_kp_u_upgrade_insecure_requests;
static PyObject *__pyx_n_s_url;
static PyObject *__pyx_kp_u_user_agent;
static PyObject *__pyx_n_u_w;
static PyObject *__pyx_n_s_waktu;
static PyObject *__pyx_n_s_war;
static PyObject *__pyx_n_s_warna;
static PyObject *__pyx_n_u_warna;
static PyObject *__pyx_n_s_width;
static PyObject *__pyx_n_u_win;
static PyObject *__pyx_n_s_write;
static PyObject *__pyx_n_s_z;
static PyObject *__pyx_pf_5share_clear_screen(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_5share_2waktu(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_5share_4logo(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_5share_6login(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_5share_8menu(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_5share_10share_cepat(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_token, PyObject *__pyx_v_cookie, PyObject *__pyx_v_idt); 
static PyObject *__pyx_pf_5share_12share_lambat(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_token, PyObject *__pyx_v_cookie, PyObject *__pyx_v_idt); 
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_3;
static PyObject *__pyx_int_4;
static PyObject *__pyx_int_5;
static PyObject *__pyx_int_12;
static PyObject *__pyx_int_15;
static PyObject *__pyx_int_18;
static PyObject *__pyx_int_29;
static PyObject *__pyx_int_30;
static PyObject *__pyx_int_80;
static PyObject *__pyx_tuple__8;
static PyObject *__pyx_tuple__9;
static PyObject *__pyx_tuple__10;
static PyObject *__pyx_tuple__11;
static PyObject *__pyx_tuple__12;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__16;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__23;
static PyObject *__pyx_tuple__24;
static PyObject *__pyx_tuple__25;
static PyObject *__pyx_tuple__26;
static PyObject *__pyx_tuple__27;
static PyObject *__pyx_tuple__28;
static PyObject *__pyx_tuple__30;
static PyObject *__pyx_tuple__32;
static PyObject *__pyx_tuple__33;
static PyObject *__pyx_tuple__34;
static PyObject *__pyx_tuple__35;
static PyObject *__pyx_tuple__40;
static PyObject *__pyx_tuple__41;
static PyObject *__pyx_tuple__43;
static PyObject *__pyx_tuple__46;
static PyObject *__pyx_tuple__48;
static PyObject *__pyx_tuple__50;
static PyObject *__pyx_tuple__52;
static PyObject *__pyx_codeobj__42;
static PyObject *__pyx_codeobj__44;
static PyObject *__pyx_codeobj__45;
static PyObject *__pyx_codeobj__47;
static PyObject *__pyx_codeobj__49;
static PyObject *__pyx_codeobj__51;
static PyObject *__pyx_codeobj__53;
static PyObject *__pyx_ustring__13;
static PyObject *__pyx_ustring__17;
static PyObject *__pyx_ustring__36;
static PyObject *__pyx_ustring__37;
static PyObject *__pyx_ustring__38;
static PyObject *__pyx_ustring__39;





static PyObject *__pyx_pw_5share_1clear_screen(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_5share_1clear_screen = {"clear_screen", (PyCFunction)__pyx_pw_5share_1clear_screen, METH_NOARGS, 0};
static PyObject *__pyx_pw_5share_1clear_screen(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("clear_screen (wrapper)", 0);
  __pyx_r = __pyx_pf_5share_clear_screen(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5share_clear_screen(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("clear_screen", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sys); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_platform); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_lower); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_linux, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_5 = (__pyx_t_4 != 0);
  if (__pyx_t_5) {

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_7, &__pyx_t_8);
      __Pyx_XGOTREF(__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_7);
      __Pyx_XGOTREF(__pyx_t_8);
       {
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_os); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 86, __pyx_L4_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_system); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 86, __pyx_L4_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_2)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_2);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_n_u_clear) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_n_u_clear);
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 86, __pyx_L4_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      }
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      goto __pyx_L9_try_end;
      __pyx_L4_error:;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;

      
       {
        __Pyx_ErrRestore(0,0,0);
        goto __pyx_L5_exception_handled;
      }
      __pyx_L5_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_XGIVEREF(__pyx_t_7);
      __Pyx_XGIVEREF(__pyx_t_8);
      __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
      __pyx_L9_try_end:;
    }

    
    goto __pyx_L3;
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_sys); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_platform); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_lower); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_5 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_win, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = (__pyx_t_5 != 0);
  if (__pyx_t_4) {

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_8, &__pyx_t_7, &__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_8);
      __Pyx_XGOTREF(__pyx_t_7);
      __Pyx_XGOTREF(__pyx_t_6);
       {
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_os); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 89, __pyx_L10_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_system); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 89, __pyx_L10_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_n_u_cls) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_n_u_cls);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 89, __pyx_L10_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      }
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L15_try_end;
      __pyx_L10_error:;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;

      
       {
        __Pyx_ErrRestore(0,0,0);
        goto __pyx_L11_exception_handled;
      }
      __pyx_L11_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_8);
      __Pyx_XGIVEREF(__pyx_t_7);
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_7, __pyx_t_6);
      __pyx_L15_try_end:;
    }

    
    goto __pyx_L3;
  }

  
   {
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_7, &__pyx_t_8);
      __Pyx_XGOTREF(__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_7);
      __Pyx_XGOTREF(__pyx_t_8);
       {
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_os); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 92, __pyx_L16_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_system); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 92, __pyx_L16_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_2)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_2);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_n_u_clear) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_n_u_clear);
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 92, __pyx_L16_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      }
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      goto __pyx_L21_try_end;
      __pyx_L16_error:;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;

      
       {
        __Pyx_ErrRestore(0,0,0);
        goto __pyx_L17_exception_handled;
      }
      __pyx_L17_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_XGIVEREF(__pyx_t_7);
      __Pyx_XGIVEREF(__pyx_t_8);
      __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
      __pyx_L21_try_end:;
    }
  }
  __pyx_L3:;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("share.clear_screen", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_5share_3waktu(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_5share_3waktu = {"waktu", (PyCFunction)__pyx_pw_5share_3waktu, METH_NOARGS, 0};
static PyObject *__pyx_pw_5share_3waktu(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("waktu (wrapper)", 0);
  __pyx_r = __pyx_pf_5share_2waktu(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5share_2waktu(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_v_now = NULL;
  PyObject *__pyx_v_hours = NULL;
  PyObject *__pyx_v_timenow = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("waktu", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_datetime); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_now); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_now = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_now, __pyx_n_s_hour); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_hours = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_RichCompare(__pyx_int_4, __pyx_v_hours, Py_LE); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 99, __pyx_L1_error)
  if (__Pyx_PyObject_IsTrue(__pyx_t_1)) {
    __Pyx_DECREF(__pyx_t_1);
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_hours, __pyx_int_12, Py_LT); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 99, __pyx_L1_error)
  }
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_4) {
    __Pyx_INCREF(__pyx_kp_u_selamat_pagi);
    __pyx_v_timenow = __pyx_kp_u_selamat_pagi;
    goto __pyx_L3;
  }

  
  __pyx_t_1 = PyObject_RichCompare(__pyx_int_12, __pyx_v_hours, Py_LE); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 100, __pyx_L1_error)
  if (__Pyx_PyObject_IsTrue(__pyx_t_1)) {
    __Pyx_DECREF(__pyx_t_1);
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_hours, __pyx_int_15, Py_LT); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 100, __pyx_L1_error)
  }
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_4) {
    __Pyx_INCREF(__pyx_kp_u_selamat_siang);
    __pyx_v_timenow = __pyx_kp_u_selamat_siang;
    goto __pyx_L3;
  }

  
  __pyx_t_1 = PyObject_RichCompare(__pyx_int_15, __pyx_v_hours, Py_LE); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 101, __pyx_L1_error)
  if (__Pyx_PyObject_IsTrue(__pyx_t_1)) {
    __Pyx_DECREF(__pyx_t_1);
    __pyx_t_1 = PyObject_RichCompare(__pyx_v_hours, __pyx_int_18, Py_LT); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 101, __pyx_L1_error)
  }
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_4) {
    __Pyx_INCREF(__pyx_kp_u_selamat_sore);
    __pyx_v_timenow = __pyx_kp_u_selamat_sore;
    goto __pyx_L3;
  }

  
   {
    __Pyx_INCREF(__pyx_kp_u_selamat_malam);
    __pyx_v_timenow = __pyx_kp_u_selamat_malam;
  }
  __pyx_L3:;

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_timenow);
  __pyx_r = __pyx_v_timenow;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("share.waktu", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_now);
  __Pyx_XDECREF(__pyx_v_hours);
  __Pyx_XDECREF(__pyx_v_timenow);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_5share_5logo(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_5share_5logo = {"logo", (PyCFunction)__pyx_pw_5share_5logo, METH_NOARGS, 0};
static PyObject *__pyx_pw_5share_5logo(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("logo (wrapper)", 0);
  __pyx_r = __pyx_pf_5share_4logo(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5share_4logo(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  Py_ssize_t __pyx_t_5;
  Py_UCS4 __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("logo", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_clear_screen); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_prints); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Panel); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = PyTuple_New(27); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = 0;
  __pyx_t_6 = 127;
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_color_rich); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u_);
  __pyx_t_5 += 91;
  __Pyx_GIVEREF(__pyx_kp_u_);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_kp_u_);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_M2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 2, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_6 = (65535 > __pyx_t_6) ? 65535 : __pyx_t_6;
  __pyx_t_5 += 22;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_4, 3, __pyx_kp_u__2);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_reset); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 4, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__3);
  __pyx_t_5 += 47;
  __Pyx_GIVEREF(__pyx_kp_u__3);
  PyTuple_SET_ITEM(__pyx_t_4, 5, __pyx_kp_u__3);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_M2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 6, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_6 = (65535 > __pyx_t_6) ? 65535 : __pyx_t_6;
  __pyx_t_5 += 22;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_4, 7, __pyx_kp_u__2);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_reset); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 8, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__4);
  __pyx_t_5 += 47;
  __Pyx_GIVEREF(__pyx_kp_u__4);
  PyTuple_SET_ITEM(__pyx_t_4, 9, __pyx_kp_u__4);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_P2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 10, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_6 = (65535 > __pyx_t_6) ? 65535 : __pyx_t_6;
  __pyx_t_5 += 22;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_4, 11, __pyx_kp_u__2);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_reset); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 12, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__5);
  __pyx_t_5 += 47;
  __Pyx_GIVEREF(__pyx_kp_u__5);
  PyTuple_SET_ITEM(__pyx_t_4, 13, __pyx_kp_u__5);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_P2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 14, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_6 = (65535 > __pyx_t_6) ? 65535 : __pyx_t_6;
  __pyx_t_5 += 22;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_4, 15, __pyx_kp_u__2);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_reset); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 16, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__6);
  __pyx_t_5 += 49;
  __Pyx_GIVEREF(__pyx_kp_u__6);
  PyTuple_SET_ITEM(__pyx_t_4, 17, __pyx_kp_u__6);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_P2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 18, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_Bot_Share_Facebook);
  __pyx_t_5 += 19;
  __Pyx_GIVEREF(__pyx_kp_u_Bot_Share_Facebook);
  PyTuple_SET_ITEM(__pyx_t_4, 19, __pyx_kp_u_Bot_Share_Facebook);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_reset); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 20, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__7);
  __pyx_t_5 += 47;
  __Pyx_GIVEREF(__pyx_kp_u__7);
  PyTuple_SET_ITEM(__pyx_t_4, 21, __pyx_kp_u__7);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_P2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 22, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_Buatan_Coder);
  __pyx_t_5 += 13;
  __Pyx_GIVEREF(__pyx_kp_u_Buatan_Coder);
  PyTuple_SET_ITEM(__pyx_t_4, 23, __pyx_kp_u_Buatan_Coder);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_M2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 24, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_n_u_Indonesia);
  __pyx_t_5 += 9;
  __Pyx_GIVEREF(__pyx_n_u_Indonesia);
  PyTuple_SET_ITEM(__pyx_t_4, 25, __pyx_n_u_Indonesia);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_reset); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 26, __pyx_t_7);
  __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_4, 27, __pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_7);
  __pyx_t_7 = 0;

  
  __pyx_t_7 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_color_table); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_9 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_style, __pyx_t_9) < 0) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

  
  __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_4, __pyx_t_7); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_7, __pyx_t_9) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_9);
  __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_prints); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_Panel); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_P2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_IP); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyUnicode_Concat(__pyx_t_4, __pyx_t_3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_7);
  __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_padding, __pyx_tuple__8) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_P2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyUnicode_Concat(__pyx_t_8, __pyx_n_u_IP); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_title, __pyx_t_4) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_H2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_negara); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyUnicode_Concat(__pyx_t_8, __pyx_t_10); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_subtitle, __pyx_t_4) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_color_table); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_style, __pyx_t_10) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_3, __pyx_t_7); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_7, __pyx_t_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_10);
  __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_AddTraceback("share.logo", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_5share_7login(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_5share_7login = {"login", (PyCFunction)__pyx_pw_5share_7login, METH_NOARGS, 0};
static PyObject *__pyx_pw_5share_7login(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("login (wrapper)", 0);
  __pyx_r = __pyx_pf_5share_6login(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5share_6login(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_v_cookie = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_v_find_token = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  Py_ssize_t __pyx_t_10;
  Py_UCS4 __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("login", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_logo); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__9, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_cookie = __pyx_t_1;
  __pyx_t_1 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_4, &__pyx_t_5, &__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_6);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_ses); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_get); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_3 = __Pyx_PyDict_NewPresized(9); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (PyDict_SetItem(__pyx_t_3, __pyx_kp_u_user_agent, __pyx_kp_u_Mozilla_5_0_Linux_Android_8_1_0) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_referer, __pyx_kp_u_https_www_facebook_com) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_host, __pyx_kp_u_business_facebook_com) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_origin, __pyx_kp_u_https_business_facebook_com) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_kp_u_upgrade_insecure_requests, __pyx_kp_u_1) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_kp_u_accept_language, __pyx_kp_u_id_ID_id_q_0_9_en_US_q_0_8_en_q) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_kp_u_cache_control, __pyx_kp_u_max_age_0) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_accept, __pyx_kp_u_text_html_application_xhtml_xml) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_kp_u_content_type, __pyx_kp_u_text_html_charset_utf_8) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_headers, __pyx_t_3) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_cookie, __pyx_v_cookie) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_cookies, __pyx_t_3) < 0) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__10, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 122, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_v_data = __pyx_t_3;
      __pyx_t_3 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_re); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 123, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_search); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 123, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_data, __pyx_n_s_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 123, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_7 = NULL;
      __pyx_t_8 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_2, function);
          __pyx_t_8 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_2)) {
        PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_kp_u_EAAG_w, __pyx_t_1};
        __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 123, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
        PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_kp_u_EAAG_w, __pyx_t_1};
        __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 123, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      {
        __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 123, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        if (__pyx_t_7) {
          __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
        }
        __Pyx_INCREF(__pyx_kp_u_EAAG_w);
        __Pyx_GIVEREF(__pyx_kp_u_EAAG_w);
        PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_kp_u_EAAG_w);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_t_1);
        __pyx_t_1 = 0;
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 123, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_v_find_token = __pyx_t_3;
      __pyx_t_3 = 0;

      
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__11, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 124, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_write); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 124, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_find_token, __pyx_n_s_group); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 124, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_7 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_7, __pyx_int_1) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_int_1);
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 124, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_9, __pyx_t_1, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_9, __pyx_t_2);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 124, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_9 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__12, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 125, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_9, __pyx_n_s_write); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 125, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
        __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_2);
        if (likely(__pyx_t_9)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
          __Pyx_INCREF(__pyx_t_9);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_2, function);
        }
      }
      __pyx_t_3 = (__pyx_t_9) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_9, __pyx_v_cookie) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_cookie);
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 125, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ses); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_post); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = PyTuple_New(4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_10 = 0;
      __pyx_t_11 = 127;
      __Pyx_INCREF(__pyx_kp_u_https_graph_facebook_com_2136141);
      __pyx_t_10 += 61;
      __Pyx_GIVEREF(__pyx_kp_u_https_graph_facebook_com_2136141);
      PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_https_graph_facebook_com_2136141);
      __pyx_t_9 = __Pyx_PyObject_FormatSimple(__pyx_v_cookie, __pyx_empty_unicode); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_9) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_9) : __pyx_t_11;
      __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_9);
      __Pyx_GIVEREF(__pyx_t_9);
      PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_9);
      __pyx_t_9 = 0;
      __Pyx_INCREF(__pyx_kp_u_access_token);
      __pyx_t_10 += 14;
      __Pyx_GIVEREF(__pyx_kp_u_access_token);
      PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_access_token);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_find_token, __pyx_n_s_group); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_7 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_9 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_7, __pyx_int_1) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_int_1);
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_9, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_11;
      __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
      __Pyx_GIVEREF(__pyx_t_1);
      PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_1);
      __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_3, 4, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_1);
      PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
      __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_9 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_cookie, __pyx_v_cookie) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_cookies, __pyx_t_9) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prints); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Panel); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_H2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyUnicode_Concat(__pyx_t_7, __pyx_kp_u_berhasil_login_ke_tools_ini_sila); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = PyTuple_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_color_table); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_12);
      __pyx_t_13 = __Pyx_PyObject_FormatSimple(__pyx_t_12, __pyx_empty_unicode); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_13);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_style, __pyx_t_13) < 0) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      __pyx_t_13 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_7, __pyx_t_2); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_13);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_2)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_2);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_9 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_2, __pyx_t_13) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_13);
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sleep); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 128, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_13 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_13)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_13);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_9 = (__pyx_t_13) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_13, __pyx_int_5) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_int_5);
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 128, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_menu); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 129, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_13 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_13)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_13);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_9 = (__pyx_t_13) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_13) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 129, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

    
     {
      __Pyx_AddTraceback("share.login", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_9, &__pyx_t_1, &__pyx_t_13) < 0) __PYX_ERR(0, 130, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_13);

      
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_os); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 131, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_system); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 131, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_7, __pyx_kp_u_rm_f_data_token_txt_data_cookie) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_u_rm_f_data_token_txt_data_cookie);
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 131, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_prints); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Panel); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_12 = PyTuple_New(3); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_12);
      __pyx_t_10 = 0;
      __pyx_t_11 = 127;
      __Pyx_INCREF(__pyx_ustring__13);
      __pyx_t_11 = (1114111 > __pyx_t_11) ? 1114111 : __pyx_t_11;
      __pyx_t_10 += 2;
      __Pyx_GIVEREF(__pyx_ustring__13);
      PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_ustring__13);
      __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_M2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_15);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) : __pyx_t_11;
      __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_15);
      __Pyx_GIVEREF(__pyx_t_15);
      PyTuple_SET_ITEM(__pyx_t_12, 1, __pyx_t_15);
      __pyx_t_15 = 0;
      __Pyx_INCREF(__pyx_kp_u_cookie_tidak_valid_silahkan_cek);
      __pyx_t_10 += 66;
      __Pyx_GIVEREF(__pyx_kp_u_cookie_tidak_valid_silahkan_cek);
      PyTuple_SET_ITEM(__pyx_t_12, 2, __pyx_kp_u_cookie_tidak_valid_silahkan_cek);
      __pyx_t_15 = __Pyx_PyUnicode_Join(__pyx_t_12, 3, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_15);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __pyx_t_12 = PyTuple_New(1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_12);
      __Pyx_GIVEREF(__pyx_t_15);
      PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_15);
      __pyx_t_15 = 0;
      __pyx_t_15 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_15);
      if (PyDict_SetItem(__pyx_t_15, __pyx_n_s_width, __pyx_int_80) < 0) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_color_table); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (PyDict_SetItem(__pyx_t_15, __pyx_n_s_style, __pyx_t_16) < 0) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __pyx_t_16 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_12, __pyx_t_15); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
      __pyx_t_15 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_15)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_15);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_2 = (__pyx_t_15) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_15, __pyx_t_16) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_16);
      __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 132, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
      __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 133, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      goto __pyx_L4_exception_handled;
    }
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
    __pyx_L8_try_end:;
  }

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_AddTraceback("share.login", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_cookie);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XDECREF(__pyx_v_find_token);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_5share_9menu(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_5share_9menu = {"menu", (PyCFunction)__pyx_pw_5share_9menu, METH_NOARGS, 0};
static PyObject *__pyx_pw_5share_9menu(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("menu (wrapper)", 0);
  __pyx_r = __pyx_pf_5share_8menu(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5share_8menu(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_v_ses = NULL;
  PyObject *__pyx_v_token = NULL;
  PyObject *__pyx_v_cok = NULL;
  PyObject *__pyx_v_cookie = NULL;
  PyObject *__pyx_v_nama = NULL;
  CYTHON_UNUSED PyObject *__pyx_v_e = NULL;
  PyObject *__pyx_v_men = NULL;
  PyObject *__pyx_v_tanya = NULL;
  PyObject *__pyx_v_idt = NULL;
  PyObject *__pyx_v_mun = NULL;
  PyObject *__pyx_v_tinyi = NULL;
  PyObject *__pyx_v_fall = NULL;
  CYTHON_UNUSED PyObject *__pyx_v_z = NULL;
  PyObject *__pyx_v_war = NULL;
  PyObject *__pyx_v_warna = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_t_9;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  Py_ssize_t __pyx_t_12;
  Py_UCS4 __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  int __pyx_t_17;
  char const *__pyx_t_18;
  PyObject *__pyx_t_19 = NULL;
  PyObject *__pyx_t_20 = NULL;
  PyObject *__pyx_t_21 = NULL;
  PyObject *__pyx_t_22 = NULL;
  PyObject *__pyx_t_23 = NULL;
  PyObject *__pyx_t_24 = NULL;
  int __pyx_t_25;
  int __pyx_t_26;
  int __pyx_t_27;
  PyObject *(*__pyx_t_28)(PyObject *);
  PyObject *__pyx_t_29 = NULL;
  PyObject *__pyx_t_30 = NULL;
  Py_ssize_t __pyx_t_31;
  PyObject *__pyx_t_32 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("menu", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_logo); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 138, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 138, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_4, &__pyx_t_5, &__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_6);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_requests); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 140, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 140, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_2)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_2);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 140, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_ses = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__15, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 141, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_read); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 141, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
        __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
        if (likely(__pyx_t_3)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
          __Pyx_INCREF(__pyx_t_3);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_2, function);
        }
      }
      __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 141, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_v_token = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__16, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 142, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_read); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 142, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_2)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_2);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 142, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_cok = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 143, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_cookie, __pyx_v_cok) < 0) __PYX_ERR(0, 143, __pyx_L3_error)
      __pyx_v_cookie = ((PyObject*)__pyx_t_1);
      __pyx_t_1 = 0;

      
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_get); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_token, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_7 = __Pyx_PyUnicode_Concat(__pyx_kp_u_https_graph_facebook_com_me_acce, __pyx_t_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_7);
      __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_cookies, __pyx_v_cookie) < 0) __PYX_ERR(0, 144, __pyx_L3_error)
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_2, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_json); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __pyx_t_8 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_8)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_8);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
        }
      }
      __pyx_t_1 = (__pyx_t_8) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_8) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_name); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 144, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_v_nama = __pyx_t_7;
      __pyx_t_7 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

    
    __pyx_t_9 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_9) {
      __Pyx_AddTraceback("share.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_7, &__pyx_t_1, &__pyx_t_8) < 0) __PYX_ERR(0, 145, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_1);
      __pyx_v_e = __pyx_t_1;
       {

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_os); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_system); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 146, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_10);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_10);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_10, function);
          }
        }
        __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_10, __pyx_t_3, __pyx_kp_u_rm_f_data_token_txt_data_cookie) : __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_kp_u_rm_f_data_token_txt_data_cookie);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 146, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_prints); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_10);
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Panel); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_11 = PyTuple_New(3); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_11);
        __pyx_t_12 = 0;
        __pyx_t_13 = 127;
        __Pyx_INCREF(__pyx_ustring__17);
        __pyx_t_13 = (1114111 > __pyx_t_13) ? 1114111 : __pyx_t_13;
        __pyx_t_12 += 2;
        __Pyx_GIVEREF(__pyx_ustring__17);
        PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_ustring__17);
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_M2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_15);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) : __pyx_t_13;
        __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_15);
        __Pyx_GIVEREF(__pyx_t_15);
        PyTuple_SET_ITEM(__pyx_t_11, 1, __pyx_t_15);
        __pyx_t_15 = 0;
        __Pyx_INCREF(__pyx_kp_u_cookie_tidak_valid_silahkan_cek);
        __pyx_t_12 += 66;
        __Pyx_GIVEREF(__pyx_kp_u_cookie_tidak_valid_silahkan_cek);
        PyTuple_SET_ITEM(__pyx_t_11, 2, __pyx_kp_u_cookie_tidak_valid_silahkan_cek);
        __pyx_t_15 = __Pyx_PyUnicode_Join(__pyx_t_11, 3, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_15);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        __pyx_t_11 = PyTuple_New(1); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_11);
        __Pyx_GIVEREF(__pyx_t_15);
        PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_t_15);
        __pyx_t_15 = 0;
        __pyx_t_15 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_15);
        if (PyDict_SetItem(__pyx_t_15, __pyx_n_s_width, __pyx_int_80) < 0) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_color_table); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        if (PyDict_SetItem(__pyx_t_15, __pyx_n_s_style, __pyx_t_16) < 0) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_16 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_11, __pyx_t_15); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
        __pyx_t_15 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
          __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_10);
          if (likely(__pyx_t_15)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
            __Pyx_INCREF(__pyx_t_15);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_10, function);
          }
        }
        __pyx_t_2 = (__pyx_t_15) ? __Pyx_PyObject_Call2Args(__pyx_t_10, __pyx_t_15, __pyx_t_16) : __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_t_16);
        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 147, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_sleep); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 148, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_16 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
          __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_10);
          if (likely(__pyx_t_16)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
            __Pyx_INCREF(__pyx_t_16);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_10, function);
          }
        }
        __pyx_t_2 = (__pyx_t_16) ? __Pyx_PyObject_Call2Args(__pyx_t_10, __pyx_t_16, __pyx_int_3) : __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_int_3);
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 148, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_login); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 149, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_16 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
          __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_10);
          if (likely(__pyx_t_16)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
            __Pyx_INCREF(__pyx_t_16);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_10, function);
          }
        }
        __pyx_t_2 = (__pyx_t_16) ? __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_t_16) : __Pyx_PyObject_CallNoArg(__pyx_t_10);
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 149, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      }

      
       {
        {
          __Pyx_DECREF(__pyx_v_e);
          __pyx_v_e = NULL;
          goto __pyx_L15;
        }
        __pyx_L14_error:;
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __pyx_t_19 = 0; __pyx_t_20 = 0; __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0;
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_22, &__pyx_t_23, &__pyx_t_24);
          if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_19, &__pyx_t_20, &__pyx_t_21) < 0)) __Pyx_ErrFetch(&__pyx_t_19, &__pyx_t_20, &__pyx_t_21);
          __Pyx_XGOTREF(__pyx_t_19);
          __Pyx_XGOTREF(__pyx_t_20);
          __Pyx_XGOTREF(__pyx_t_21);
          __Pyx_XGOTREF(__pyx_t_22);
          __Pyx_XGOTREF(__pyx_t_23);
          __Pyx_XGOTREF(__pyx_t_24);
          __pyx_t_9 = __pyx_lineno; __pyx_t_17 = __pyx_clineno; __pyx_t_18 = __pyx_filename;
          {
            __Pyx_DECREF(__pyx_v_e);
            __pyx_v_e = NULL;
          }
          if (PY_MAJOR_VERSION >= 3) {
            __Pyx_XGIVEREF(__pyx_t_22);
            __Pyx_XGIVEREF(__pyx_t_23);
            __Pyx_XGIVEREF(__pyx_t_24);
            __Pyx_ExceptionReset(__pyx_t_22, __pyx_t_23, __pyx_t_24);
          }
          __Pyx_XGIVEREF(__pyx_t_19);
          __Pyx_XGIVEREF(__pyx_t_20);
          __Pyx_XGIVEREF(__pyx_t_21);
          __Pyx_ErrRestore(__pyx_t_19, __pyx_t_20, __pyx_t_21);
          __pyx_t_19 = 0; __pyx_t_20 = 0; __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0;
          __pyx_lineno = __pyx_t_9; __pyx_clineno = __pyx_t_17; __pyx_filename = __pyx_t_18;
          goto __pyx_L5_except_error;
        }
        __pyx_L15:;
      }
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      goto __pyx_L4_exception_handled;
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
    __pyx_L8_try_end:;
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prints); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Panel); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_2 = PyTuple_New(7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_12 = 0;
  __pyx_t_13 = 127;
  __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_P2); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_10, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_16);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_13;
  __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
  __Pyx_GIVEREF(__pyx_t_16);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_16);
  __pyx_t_16 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_waktu); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_15 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
    __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_10);
    if (likely(__pyx_t_15)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
      __Pyx_INCREF(__pyx_t_15);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_10, function);
    }
  }
  __pyx_t_16 = (__pyx_t_15) ? __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_t_15) : __Pyx_PyObject_CallNoArg(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
  if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_16);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) : __pyx_t_13;
  __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_10);
  __Pyx_GIVEREF(__pyx_t_10);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_10);
  __pyx_t_10 = 0;
  __Pyx_INCREF(__pyx_kp_u__18);
  __pyx_t_12 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__18);
  PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_kp_u__18);
  __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_K2); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_10, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_16);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_13;
  __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
  __Pyx_GIVEREF(__pyx_t_16);
  PyTuple_SET_ITEM(__pyx_t_2, 3, __pyx_t_16);
  __pyx_t_16 = 0;
  if (unlikely(!__pyx_v_nama)) { __Pyx_RaiseUnboundLocalError("nama"); __PYX_ERR(0, 150, __pyx_L1_error) }
  __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_v_nama, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_16);
  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_13;
  __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
  __Pyx_GIVEREF(__pyx_t_16);
  PyTuple_SET_ITEM(__pyx_t_2, 4, __pyx_t_16);
  __pyx_t_16 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_P2); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_16);
  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) : __pyx_t_13;
  __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_10);
  __Pyx_GIVEREF(__pyx_t_10);
  PyTuple_SET_ITEM(__pyx_t_2, 5, __pyx_t_10);
  __pyx_t_10 = 0;
  __Pyx_INCREF(__pyx_kp_u_dan_selamat_menikmati_tools);
  __pyx_t_12 += 28;
  __Pyx_GIVEREF(__pyx_kp_u_dan_selamat_menikmati_tools);
  PyTuple_SET_ITEM(__pyx_t_2, 6, __pyx_kp_u_dan_selamat_menikmati_tools);
  __pyx_t_10 = __Pyx_PyUnicode_Join(__pyx_t_2, 7, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_10);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_10);
  __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_color_table); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_16);
  __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_15);
  __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
  if (PyDict_SetItem(__pyx_t_10, __pyx_n_s_style, __pyx_t_15) < 0) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
  __pyx_t_15 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_2, __pyx_t_10); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_15);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_10)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_10);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_8 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_10, __pyx_t_15) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_15);
  __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
  __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_List); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  if (PyDict_SetItem(__pyx_t_8, __pyx_n_s_message, __pyx_kp_u_pilih_menu) < 0) __PYX_ERR(0, 151, __pyx_L1_error)
  __pyx_t_15 = PyList_New(5); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_15);
  __Pyx_INCREF(__pyx_kp_u_share_postingan_cepat);
  __Pyx_GIVEREF(__pyx_kp_u_share_postingan_cepat);
  PyList_SET_ITEM(__pyx_t_15, 0, __pyx_kp_u_share_postingan_cepat);
  __Pyx_INCREF(__pyx_kp_u_share_postingan_lambat);
  __Pyx_GIVEREF(__pyx_kp_u_share_postingan_lambat);
  PyList_SET_ITEM(__pyx_t_15, 1, __pyx_kp_u_share_postingan_lambat);
  __Pyx_INCREF(__pyx_kp_u_ganti_warna_tema);
  __Pyx_GIVEREF(__pyx_kp_u_ganti_warna_tema);
  PyList_SET_ITEM(__pyx_t_15, 2, __pyx_kp_u_ganti_warna_tema);
  __Pyx_INCREF(__pyx_kp_u_ganti_tumbal);
  __Pyx_GIVEREF(__pyx_kp_u_ganti_tumbal);
  PyList_SET_ITEM(__pyx_t_15, 3, __pyx_kp_u_ganti_tumbal);
  __Pyx_INCREF(__pyx_kp_u_keluar_tools);
  __Pyx_GIVEREF(__pyx_kp_u_keluar_tools);
  PyList_SET_ITEM(__pyx_t_15, 4, __pyx_kp_u_keluar_tools);
  if (PyDict_SetItem(__pyx_t_8, __pyx_n_s_choices, __pyx_t_15) < 0) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
  if (PyDict_SetItem(__pyx_t_8, __pyx_n_s_default, __pyx_kp_u__20) < 0) __PYX_ERR(0, 151, __pyx_L1_error)
  __pyx_t_15 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__19, __pyx_t_8); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_15);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = PyList_New(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_15);
  PyList_SET_ITEM(__pyx_t_8, 0, __pyx_t_15);
  __pyx_t_15 = 0;
  __pyx_v_men = ((PyObject*)__pyx_t_8);
  __pyx_t_8 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_15);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_15, __pyx_n_s_prompt); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
  __pyx_t_15 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_15)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_15);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_8 = (__pyx_t_15) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_15, __pyx_v_men) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_men);
  __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_tanya = __pyx_t_8;
  __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_Dict_GetItem(__pyx_v_tanya, __pyx_n_u_menu); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_25 = (__Pyx_PySequence_ContainsTF(__pyx_kp_u_share_postingan_cepat, __pyx_t_8, Py_EQ)); if (unlikely(__pyx_t_25 < 0)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_26 = (__pyx_t_25 != 0);
  if (__pyx_t_26) {

    
    __pyx_t_8 = PyTuple_New(5); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 154, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_12 = 0;
    __pyx_t_13 = 127;
    __Pyx_INCREF(__pyx_kp_u__21);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__21);
    PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_kp_u__21);
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_H); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 154, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 154, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_15);
    __Pyx_GIVEREF(__pyx_t_15);
    PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_15);
    __pyx_t_15 = 0;
    __Pyx_INCREF(__pyx_kp_u__22);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__22);
    PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_kp_u__22);
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_N); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 154, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_15, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 154, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_8, 3, __pyx_t_1);
    __pyx_t_1 = 0;
    __Pyx_INCREF(__pyx_kp_u_masukan_link);
    __pyx_t_12 += 17;
    __Pyx_GIVEREF(__pyx_kp_u_masukan_link);
    PyTuple_SET_ITEM(__pyx_t_8, 4, __pyx_kp_u_masukan_link);
    __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_8, 5, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 154, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 154, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_v_idt = __pyx_t_8;
    __pyx_t_8 = 0;

    
    __pyx_t_8 = PyTuple_New(5); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_12 = 0;
    __pyx_t_13 = 127;
    __Pyx_INCREF(__pyx_kp_u__21);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__21);
    PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_kp_u__21);
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_H); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_15);
    __Pyx_GIVEREF(__pyx_t_15);
    PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_15);
    __pyx_t_15 = 0;
    __Pyx_INCREF(__pyx_kp_u__22);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__22);
    PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_kp_u__22);
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_N); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_15, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_8, 3, __pyx_t_1);
    __pyx_t_1 = 0;
    __Pyx_INCREF(__pyx_kp_u_masukan_limit);
    __pyx_t_12 += 18;
    __Pyx_GIVEREF(__pyx_kp_u_masukan_limit);
    PyTuple_SET_ITEM(__pyx_t_8, 4, __pyx_kp_u_masukan_limit);
    __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_8, 5, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyNumber_Int(__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_limit, __pyx_t_1) < 0) __PYX_ERR(0, 155, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_List); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_message, __pyx_kp_u_pilih_menu) < 0) __PYX_ERR(0, 156, __pyx_L1_error)
    __pyx_t_15 = PyList_New(2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_INCREF(__pyx_kp_u_munculkan_proses_share);
    __Pyx_GIVEREF(__pyx_kp_u_munculkan_proses_share);
    PyList_SET_ITEM(__pyx_t_15, 0, __pyx_kp_u_munculkan_proses_share);
    __Pyx_INCREF(__pyx_kp_u_jangan_munculkan_proses_share);
    __Pyx_GIVEREF(__pyx_kp_u_jangan_munculkan_proses_share);
    PyList_SET_ITEM(__pyx_t_15, 1, __pyx_kp_u_jangan_munculkan_proses_share);
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_choices, __pyx_t_15) < 0) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_default, __pyx_kp_u__20) < 0) __PYX_ERR(0, 156, __pyx_L1_error)
    __pyx_t_15 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_tuple__23, __pyx_t_1); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_15);
    PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_15);
    __pyx_t_15 = 0;
    __pyx_v_mun = ((PyObject*)__pyx_t_1);
    __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 157, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_15, __pyx_n_s_prompt); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 157, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    __pyx_t_15 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
      __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_8);
      if (likely(__pyx_t_15)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
        __Pyx_INCREF(__pyx_t_15);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_8, function);
      }
    }
    __pyx_t_1 = (__pyx_t_15) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_15, __pyx_v_mun) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_v_mun);
    __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 157, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_v_tinyi = __pyx_t_1;
    __pyx_t_1 = 0;

    
    __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_tinyi, __pyx_n_u_muncul); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 158, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_kp_u_munculkan_proses_share, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 158, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_25 = (__pyx_t_26 != 0);
    if (__pyx_t_25) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_muncul); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 159, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_27 = __Pyx_PyObject_Append(__pyx_t_1, __pyx_n_u_iya); if (unlikely(__pyx_t_27 == ((int)-1))) __PYX_ERR(0, 159, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      
    }

    
    __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_Progress); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_SpinnerColumn); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_10);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_10, function);
      }
    }
    __pyx_t_15 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_10, __pyx_t_2, __pyx_n_u_clock) : __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_n_u_clock);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_TextColumn); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_10 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_7, __pyx_kp_u_task_description) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_u_task_description);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_BarColumn); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_16 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_16)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_16);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_2 = (__pyx_t_16) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_16) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_TextColumn); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __pyx_t_11 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_16))) {
      __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_16);
      if (likely(__pyx_t_11)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
        __Pyx_INCREF(__pyx_t_11);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_16, function);
      }
    }
    __pyx_t_7 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_11, __pyx_kp_u_task_percentage_0f) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_kp_u_task_percentage_0f);
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_TimeElapsedColumn); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __pyx_t_3 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_11);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_11, function);
      }
    }
    __pyx_t_16 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_11);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __pyx_t_11 = NULL;
    __pyx_t_17 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
      __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_8);
      if (likely(__pyx_t_11)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
        __Pyx_INCREF(__pyx_t_11);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_8, function);
        __pyx_t_17 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_8)) {
      PyObject *__pyx_temp[6] = {__pyx_t_11, __pyx_t_15, __pyx_t_10, __pyx_t_2, __pyx_t_7, __pyx_t_16};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_17, 5+__pyx_t_17); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
      PyObject *__pyx_temp[6] = {__pyx_t_11, __pyx_t_15, __pyx_t_10, __pyx_t_2, __pyx_t_7, __pyx_t_16};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_17, 5+__pyx_t_17); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
    } else
    #endif
    {
      __pyx_t_3 = PyTuple_New(5+__pyx_t_17); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 160, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (__pyx_t_11) {
        __Pyx_GIVEREF(__pyx_t_11); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_11); __pyx_t_11 = NULL;
      }
      __Pyx_GIVEREF(__pyx_t_15);
      PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_17, __pyx_t_15);
      __Pyx_GIVEREF(__pyx_t_10);
      PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_17, __pyx_t_10);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_3, 2+__pyx_t_17, __pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_3, 3+__pyx_t_17, __pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_16);
      PyTuple_SET_ITEM(__pyx_t_3, 4+__pyx_t_17, __pyx_t_16);
      __pyx_t_15 = 0;
      __pyx_t_10 = 0;
      __pyx_t_2 = 0;
      __pyx_t_7 = 0;
      __pyx_t_16 = 0;
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_3, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    }
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_prog, __pyx_t_1) < 0) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prog); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_add_task); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_limit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_total, __pyx_t_3) < 0) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_tuple__24, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_des, __pyx_t_3) < 0) __PYX_ERR(0, 161, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
     {
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_prog); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 162, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_6 = __Pyx_PyObject_LookupSpecial(__pyx_t_3, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 162, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_8 = __Pyx_PyObject_LookupSpecial(__pyx_t_3, __pyx_n_s_enter); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 162, __pyx_L22_error)
      __Pyx_GOTREF(__pyx_t_8);
      __pyx_t_16 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
        __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_8);
        if (likely(__pyx_t_16)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
          __Pyx_INCREF(__pyx_t_16);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_8, function);
        }
      }
      __pyx_t_1 = (__pyx_t_16) ? __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_16) : __Pyx_PyObject_CallNoArg(__pyx_t_8);
      __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L22_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
       {
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_5, &__pyx_t_4, &__pyx_t_24);
          __Pyx_XGOTREF(__pyx_t_5);
          __Pyx_XGOTREF(__pyx_t_4);
          __Pyx_XGOTREF(__pyx_t_24);
           {

            
             {
              __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ThreadPoolExecutor); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 163, __pyx_L26_error)
              __Pyx_GOTREF(__pyx_t_3);
              __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 163, __pyx_L26_error)
              __Pyx_GOTREF(__pyx_t_1);
              if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_max_workers, __pyx_int_30) < 0) __PYX_ERR(0, 163, __pyx_L26_error)
              __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 163, __pyx_L26_error)
              __Pyx_GOTREF(__pyx_t_8);
              __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
              __pyx_t_23 = __Pyx_PyObject_LookupSpecial(__pyx_t_8, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_23)) __PYX_ERR(0, 163, __pyx_L26_error)
              __Pyx_GOTREF(__pyx_t_23);
              __pyx_t_3 = __Pyx_PyObject_LookupSpecial(__pyx_t_8, __pyx_n_s_enter); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 163, __pyx_L32_error)
              __Pyx_GOTREF(__pyx_t_3);
              __pyx_t_16 = NULL;
              if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
                __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_3);
                if (likely(__pyx_t_16)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
                  __Pyx_INCREF(__pyx_t_16);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_3, function);
                }
              }
              __pyx_t_1 = (__pyx_t_16) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_16) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
              __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
              if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 163, __pyx_L32_error)
              __Pyx_GOTREF(__pyx_t_1);
              __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
              __pyx_t_3 = __pyx_t_1;
              __pyx_t_1 = 0;
              __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
               {
                {
                  __Pyx_PyThreadState_declare
                  __Pyx_PyThreadState_assign
                  __Pyx_ExceptionSave(&__pyx_t_22, &__pyx_t_21, &__pyx_t_20);
                  __Pyx_XGOTREF(__pyx_t_22);
                  __Pyx_XGOTREF(__pyx_t_21);
                  __Pyx_XGOTREF(__pyx_t_20);
                   {
                    __pyx_v_fall = __pyx_t_3;
                    __pyx_t_3 = 0;

                    
                    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_limit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 164, __pyx_L36_error)
                    __Pyx_GOTREF(__pyx_t_3);
                    __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L36_error)
                    __Pyx_GOTREF(__pyx_t_8);
                    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
                    if (likely(PyList_CheckExact(__pyx_t_8)) || PyTuple_CheckExact(__pyx_t_8)) {
                      __pyx_t_3 = __pyx_t_8; __Pyx_INCREF(__pyx_t_3); __pyx_t_12 = 0;
                      __pyx_t_28 = NULL;
                    } else {
                      __pyx_t_12 = -1; __pyx_t_3 = PyObject_GetIter(__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 164, __pyx_L36_error)
                      __Pyx_GOTREF(__pyx_t_3);
                      __pyx_t_28 = Py_TYPE(__pyx_t_3)->tp_iternext; if (unlikely(!__pyx_t_28)) __PYX_ERR(0, 164, __pyx_L36_error)
                    }
                    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
                    for (;;) {
                      if (likely(!__pyx_t_28)) {
                        if (likely(PyList_CheckExact(__pyx_t_3))) {
                          if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_3)) break;
                          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                          __pyx_t_8 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_8); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 164, __pyx_L36_error)
                          #else
                          __pyx_t_8 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L36_error)
                          __Pyx_GOTREF(__pyx_t_8);
                          #endif
                        } else {
                          if (__pyx_t_12 >= PyTuple_GET_SIZE(__pyx_t_3)) break;
                          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                          __pyx_t_8 = PyTuple_GET_ITEM(__pyx_t_3, __pyx_t_12); __Pyx_INCREF(__pyx_t_8); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 164, __pyx_L36_error)
                          #else
                          __pyx_t_8 = PySequence_ITEM(__pyx_t_3, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L36_error)
                          __Pyx_GOTREF(__pyx_t_8);
                          #endif
                        }
                      } else {
                        __pyx_t_8 = __pyx_t_28(__pyx_t_3);
                        if (unlikely(!__pyx_t_8)) {
                          PyObject* exc_type = PyErr_Occurred();
                          if (exc_type) {
                            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                            else __PYX_ERR(0, 164, __pyx_L36_error)
                          }
                          break;
                        }
                        __Pyx_GOTREF(__pyx_t_8);
                      }
                      __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_8);
                      __pyx_t_8 = 0;

                      
                      {
                        __Pyx_PyThreadState_declare
                        __Pyx_PyThreadState_assign
                        __Pyx_ExceptionSave(&__pyx_t_19, &__pyx_t_29, &__pyx_t_30);
                        __Pyx_XGOTREF(__pyx_t_19);
                        __Pyx_XGOTREF(__pyx_t_29);
                        __Pyx_XGOTREF(__pyx_t_30);
                         {

                          
                          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_fall, __pyx_n_s_submit); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 166, __pyx_L44_error)
                          __Pyx_GOTREF(__pyx_t_1);
                          __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_share_cepat); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 166, __pyx_L44_error)
                          __Pyx_GOTREF(__pyx_t_16);
                          if (unlikely(!__pyx_v_token)) { __Pyx_RaiseUnboundLocalError("token"); __PYX_ERR(0, 166, __pyx_L44_error) }
                          if (unlikely(!__pyx_v_cookie)) { __Pyx_RaiseUnboundLocalError("cookie"); __PYX_ERR(0, 166, __pyx_L44_error) }
                          __pyx_t_7 = NULL;
                          __pyx_t_17 = 0;
                          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
                            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
                            if (likely(__pyx_t_7)) {
                              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                              __Pyx_INCREF(__pyx_t_7);
                              __Pyx_INCREF(function);
                              __Pyx_DECREF_SET(__pyx_t_1, function);
                              __pyx_t_17 = 1;
                            }
                          }
                          #if CYTHON_FAST_PYCALL
                          if (PyFunction_Check(__pyx_t_1)) {
                            PyObject *__pyx_temp[5] = {__pyx_t_7, __pyx_t_16, __pyx_v_token, __pyx_v_cookie, __pyx_v_idt};
                            __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_17, 4+__pyx_t_17); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 166, __pyx_L44_error)
                            __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
                            __Pyx_GOTREF(__pyx_t_8);
                            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
                          } else
                          #endif
                          #if CYTHON_FAST_PYCCALL
                          if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
                            PyObject *__pyx_temp[5] = {__pyx_t_7, __pyx_t_16, __pyx_v_token, __pyx_v_cookie, __pyx_v_idt};
                            __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_17, 4+__pyx_t_17); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 166, __pyx_L44_error)
                            __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
                            __Pyx_GOTREF(__pyx_t_8);
                            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
                          } else
                          #endif
                          {
                            __pyx_t_2 = PyTuple_New(4+__pyx_t_17); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 166, __pyx_L44_error)
                            __Pyx_GOTREF(__pyx_t_2);
                            if (__pyx_t_7) {
                              __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_7); __pyx_t_7 = NULL;
                            }
                            __Pyx_GIVEREF(__pyx_t_16);
                            PyTuple_SET_ITEM(__pyx_t_2, 0+__pyx_t_17, __pyx_t_16);
                            __Pyx_INCREF(__pyx_v_token);
                            __Pyx_GIVEREF(__pyx_v_token);
                            PyTuple_SET_ITEM(__pyx_t_2, 1+__pyx_t_17, __pyx_v_token);
                            __Pyx_INCREF(__pyx_v_cookie);
                            __Pyx_GIVEREF(__pyx_v_cookie);
                            PyTuple_SET_ITEM(__pyx_t_2, 2+__pyx_t_17, __pyx_v_cookie);
                            __Pyx_INCREF(__pyx_v_idt);
                            __Pyx_GIVEREF(__pyx_v_idt);
                            PyTuple_SET_ITEM(__pyx_t_2, 3+__pyx_t_17, __pyx_v_idt);
                            __pyx_t_16 = 0;
                            __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_2, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 166, __pyx_L44_error)
                            __Pyx_GOTREF(__pyx_t_8);
                            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                          }
                          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

                          
                        }
                        __Pyx_XDECREF(__pyx_t_19); __pyx_t_19 = 0;
                        __Pyx_XDECREF(__pyx_t_29); __pyx_t_29 = 0;
                        __Pyx_XDECREF(__pyx_t_30); __pyx_t_30 = 0;
                        goto __pyx_L51_try_end;
                        __pyx_L44_error:;
                        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
                        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
                        __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
                        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
                        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
                        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
                        __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

                        
                         {
                          __Pyx_AddTraceback("share.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
                          if (__Pyx_GetException(&__pyx_t_8, &__pyx_t_1, &__pyx_t_2) < 0) __PYX_ERR(0, 167, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_8);
                          __Pyx_GOTREF(__pyx_t_1);
                          __Pyx_GOTREF(__pyx_t_2);

                          
                          __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_prints); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_7);
                          __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_Panel); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_10);
                          __pyx_t_15 = PyTuple_New(6); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_15);
                          __pyx_t_31 = 0;
                          __pyx_t_13 = 127;
                          __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_P2); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_11);
                          __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_11, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_14);
                          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
                          __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_14) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_14) : __pyx_t_13;
                          __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_14);
                          __Pyx_GIVEREF(__pyx_t_14);
                          PyTuple_SET_ITEM(__pyx_t_15, 0, __pyx_t_14);
                          __pyx_t_14 = 0;
                          __Pyx_INCREF(__pyx_kp_u_berhasil_membagikan_total);
                          __pyx_t_31 += 26;
                          __Pyx_GIVEREF(__pyx_kp_u_berhasil_membagikan_total);
                          PyTuple_SET_ITEM(__pyx_t_15, 1, __pyx_kp_u_berhasil_membagikan_total);
                          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_H2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_14);
                          __pyx_t_11 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_11);
                          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                          __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) : __pyx_t_13;
                          __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_11);
                          __Pyx_GIVEREF(__pyx_t_11);
                          PyTuple_SET_ITEM(__pyx_t_15, 2, __pyx_t_11);
                          __pyx_t_11 = 0;
                          __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_loop); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_11);
                          __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_11, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_14);
                          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
                          __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_14) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_14) : __pyx_t_13;
                          __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_14);
                          __Pyx_GIVEREF(__pyx_t_14);
                          PyTuple_SET_ITEM(__pyx_t_15, 3, __pyx_t_14);
                          __pyx_t_14 = 0;
                          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_P2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_14);
                          __pyx_t_11 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_11);
                          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                          __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) : __pyx_t_13;
                          __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_11);
                          __Pyx_GIVEREF(__pyx_t_11);
                          PyTuple_SET_ITEM(__pyx_t_15, 4, __pyx_t_11);
                          __pyx_t_11 = 0;
                          __Pyx_INCREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
                          __pyx_t_31 += 41;
                          __Pyx_GIVEREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
                          PyTuple_SET_ITEM(__pyx_t_15, 5, __pyx_kp_u_share_silahkan_jalankan_ulang_t);
                          __pyx_t_11 = __Pyx_PyUnicode_Join(__pyx_t_15, 6, __pyx_t_31, __pyx_t_13); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_11);
                          __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
                          __pyx_t_15 = PyTuple_New(1); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_15);
                          __Pyx_GIVEREF(__pyx_t_11);
                          PyTuple_SET_ITEM(__pyx_t_15, 0, __pyx_t_11);
                          __pyx_t_11 = 0;
                          __pyx_t_11 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_11);
                          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_color_table); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_14);
                          __pyx_t_32 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_32);
                          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                          if (PyDict_SetItem(__pyx_t_11, __pyx_n_s_style, __pyx_t_32) < 0) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
                          __pyx_t_32 = __Pyx_PyObject_Call(__pyx_t_10, __pyx_t_15, __pyx_t_11); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_32);
                          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
                          __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
                          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
                          __pyx_t_11 = NULL;
                          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
                            __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_7);
                            if (likely(__pyx_t_11)) {
                              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
                              __Pyx_INCREF(__pyx_t_11);
                              __Pyx_INCREF(function);
                              __Pyx_DECREF_SET(__pyx_t_7, function);
                            }
                          }
                          __pyx_t_16 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_11, __pyx_t_32) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_32);
                          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
                          __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
                          if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 168, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_16);
                          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
                          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;

                          
                          __pyx_t_16 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 169, __pyx_L46_except_error)
                          __Pyx_GOTREF(__pyx_t_16);
                          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
                          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
                          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                          goto __pyx_L45_exception_handled;
                        }
                        __pyx_L46_except_error:;

                        
                        __Pyx_XGIVEREF(__pyx_t_19);
                        __Pyx_XGIVEREF(__pyx_t_29);
                        __Pyx_XGIVEREF(__pyx_t_30);
                        __Pyx_ExceptionReset(__pyx_t_19, __pyx_t_29, __pyx_t_30);
                        goto __pyx_L36_error;
                        __pyx_L45_exception_handled:;
                        __Pyx_XGIVEREF(__pyx_t_19);
                        __Pyx_XGIVEREF(__pyx_t_29);
                        __Pyx_XGIVEREF(__pyx_t_30);
                        __Pyx_ExceptionReset(__pyx_t_19, __pyx_t_29, __pyx_t_30);
                        __pyx_L51_try_end:;
                      }

                      
                    }
                    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

                    
                  }
                  __Pyx_XDECREF(__pyx_t_22); __pyx_t_22 = 0;
                  __Pyx_XDECREF(__pyx_t_21); __pyx_t_21 = 0;
                  __Pyx_XDECREF(__pyx_t_20); __pyx_t_20 = 0;
                  goto __pyx_L41_try_end;
                  __pyx_L36_error:;
                  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                  __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
                  __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
                  __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
                  __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
                  __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
                  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                  __Pyx_XDECREF(__pyx_t_32); __pyx_t_32 = 0;
                  __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
                  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
                   {
                    __Pyx_AddTraceback("share.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
                    if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_2, &__pyx_t_1) < 0) __PYX_ERR(0, 163, __pyx_L38_except_error)
                    __Pyx_GOTREF(__pyx_t_3);
                    __Pyx_GOTREF(__pyx_t_2);
                    __Pyx_GOTREF(__pyx_t_1);
                    __pyx_t_8 = PyTuple_Pack(3, __pyx_t_3, __pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 163, __pyx_L38_except_error)
                    __Pyx_GOTREF(__pyx_t_8);
                    __pyx_t_30 = __Pyx_PyObject_Call(__pyx_t_23, __pyx_t_8, NULL);
                    __Pyx_DECREF(__pyx_t_23); __pyx_t_23 = 0;
                    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
                    if (unlikely(!__pyx_t_30)) __PYX_ERR(0, 163, __pyx_L38_except_error)
                    __Pyx_GOTREF(__pyx_t_30);
                    __pyx_t_25 = __Pyx_PyObject_IsTrue(__pyx_t_30);
                    __Pyx_DECREF(__pyx_t_30); __pyx_t_30 = 0;
                    if (__pyx_t_25 < 0) __PYX_ERR(0, 163, __pyx_L38_except_error)
                    __pyx_t_26 = ((!(__pyx_t_25 != 0)) != 0);
                    if (__pyx_t_26) {
                      __Pyx_GIVEREF(__pyx_t_3);
                      __Pyx_GIVEREF(__pyx_t_2);
                      __Pyx_XGIVEREF(__pyx_t_1);
                      __Pyx_ErrRestoreWithState(__pyx_t_3, __pyx_t_2, __pyx_t_1);
                      __pyx_t_3 = 0; __pyx_t_2 = 0; __pyx_t_1 = 0; 
                      __PYX_ERR(0, 163, __pyx_L38_except_error)
                    }
                    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                    goto __pyx_L37_exception_handled;
                  }
                  __pyx_L38_except_error:;
                  __Pyx_XGIVEREF(__pyx_t_22);
                  __Pyx_XGIVEREF(__pyx_t_21);
                  __Pyx_XGIVEREF(__pyx_t_20);
                  __Pyx_ExceptionReset(__pyx_t_22, __pyx_t_21, __pyx_t_20);
                  goto __pyx_L26_error;
                  __pyx_L37_exception_handled:;
                  __Pyx_XGIVEREF(__pyx_t_22);
                  __Pyx_XGIVEREF(__pyx_t_21);
                  __Pyx_XGIVEREF(__pyx_t_20);
                  __Pyx_ExceptionReset(__pyx_t_22, __pyx_t_21, __pyx_t_20);
                  __pyx_L41_try_end:;
                }
              }
               {
                {
                  if (__pyx_t_23) {
                    __pyx_t_20 = __Pyx_PyObject_Call(__pyx_t_23, __pyx_tuple__25, NULL);
                    __Pyx_DECREF(__pyx_t_23); __pyx_t_23 = 0;
                    if (unlikely(!__pyx_t_20)) __PYX_ERR(0, 163, __pyx_L26_error)
                    __Pyx_GOTREF(__pyx_t_20);
                    __Pyx_DECREF(__pyx_t_20); __pyx_t_20 = 0;
                  }
                  goto __pyx_L35;
                }
                __pyx_L35:;
              }
              goto __pyx_L57;
              __pyx_L32_error:;
              __Pyx_DECREF(__pyx_t_23); __pyx_t_23 = 0;
              goto __pyx_L26_error;
              __pyx_L57:;
            }

            
          }
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_24); __pyx_t_24 = 0;
          goto __pyx_L31_try_end;
          __pyx_L26_error:;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_32); __pyx_t_32 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
           {
            __Pyx_AddTraceback("share.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3) < 0) __PYX_ERR(0, 162, __pyx_L28_except_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_GOTREF(__pyx_t_3);
            __pyx_t_8 = PyTuple_Pack(3, __pyx_t_1, __pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 162, __pyx_L28_except_error)
            __Pyx_GOTREF(__pyx_t_8);
            __pyx_t_23 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_8, NULL);
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
            if (unlikely(!__pyx_t_23)) __PYX_ERR(0, 162, __pyx_L28_except_error)
            __Pyx_GOTREF(__pyx_t_23);
            __pyx_t_26 = __Pyx_PyObject_IsTrue(__pyx_t_23);
            __Pyx_DECREF(__pyx_t_23); __pyx_t_23 = 0;
            if (__pyx_t_26 < 0) __PYX_ERR(0, 162, __pyx_L28_except_error)
            __pyx_t_25 = ((!(__pyx_t_26 != 0)) != 0);
            if (__pyx_t_25) {
              __Pyx_GIVEREF(__pyx_t_1);
              __Pyx_GIVEREF(__pyx_t_2);
              __Pyx_XGIVEREF(__pyx_t_3);
              __Pyx_ErrRestoreWithState(__pyx_t_1, __pyx_t_2, __pyx_t_3);
              __pyx_t_1 = 0; __pyx_t_2 = 0; __pyx_t_3 = 0; 
              __PYX_ERR(0, 162, __pyx_L28_except_error)
            }
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            goto __pyx_L27_exception_handled;
          }
          __pyx_L28_except_error:;
          __Pyx_XGIVEREF(__pyx_t_5);
          __Pyx_XGIVEREF(__pyx_t_4);
          __Pyx_XGIVEREF(__pyx_t_24);
          __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_4, __pyx_t_24);
          goto __pyx_L1_error;
          __pyx_L27_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_5);
          __Pyx_XGIVEREF(__pyx_t_4);
          __Pyx_XGIVEREF(__pyx_t_24);
          __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_4, __pyx_t_24);
          __pyx_L31_try_end:;
        }
      }
       {
        {
          if (__pyx_t_6) {
            __pyx_t_24 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__25, NULL);
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (unlikely(!__pyx_t_24)) __PYX_ERR(0, 162, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_24);
            __Pyx_DECREF(__pyx_t_24); __pyx_t_24 = 0;
          }
          goto __pyx_L25;
        }
        __pyx_L25:;
      }
      goto __pyx_L61;
      __pyx_L22_error:;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L1_error;
      __pyx_L61:;
    }

    
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_prints); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Panel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = PyTuple_New(6); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_12 = 0;
    __pyx_t_13 = 127;
    __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_P2); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_7);
    __pyx_t_7 = 0;
    __Pyx_INCREF(__pyx_kp_u_berhasil_membagikan_total);
    __pyx_t_12 += 26;
    __Pyx_GIVEREF(__pyx_kp_u_berhasil_membagikan_total);
    PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_kp_u_berhasil_membagikan_total);
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_H2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
    __Pyx_GIVEREF(__pyx_t_16);
    PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_t_16);
    __pyx_t_16 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_loop); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_8, 3, __pyx_t_7);
    __pyx_t_7 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_P2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
    __Pyx_GIVEREF(__pyx_t_16);
    PyTuple_SET_ITEM(__pyx_t_8, 4, __pyx_t_16);
    __pyx_t_16 = 0;
    __Pyx_INCREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
    __pyx_t_12 += 41;
    __Pyx_GIVEREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
    PyTuple_SET_ITEM(__pyx_t_8, 5, __pyx_kp_u_share_silahkan_jalankan_ulang_t);
    __pyx_t_16 = __Pyx_PyUnicode_Join(__pyx_t_8, 6, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = PyTuple_New(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_GIVEREF(__pyx_t_16);
    PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_16);
    __pyx_t_16 = 0;
    __pyx_t_16 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_color_table); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_32 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (PyDict_SetItem(__pyx_t_16, __pyx_n_s_style, __pyx_t_32) < 0) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
    __pyx_t_32 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_8, __pyx_t_16); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
    __pyx_t_16 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_16)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_16);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_3 = (__pyx_t_16) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_16, __pyx_t_32) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_32);
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 170, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    __pyx_t_3 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    goto __pyx_L20;
  }

  
  __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_tanya, __pyx_n_u_menu); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 172, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_25 = (__Pyx_PySequence_ContainsTF(__pyx_kp_u_share_postingan_lambat, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_25 < 0)) __PYX_ERR(0, 172, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_26 = (__pyx_t_25 != 0);
  if (__pyx_t_26) {

    
    __pyx_t_3 = PyTuple_New(5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 173, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_12 = 0;
    __pyx_t_13 = 127;
    __Pyx_INCREF(__pyx_kp_u__21);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__21);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u__21);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_H); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 173, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_32 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 173, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_32) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_32) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_32);
    __Pyx_GIVEREF(__pyx_t_32);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_32);
    __pyx_t_32 = 0;
    __Pyx_INCREF(__pyx_kp_u__22);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__22);
    PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u__22);
    __Pyx_GetModuleGlobalName(__pyx_t_32, __pyx_n_s_N); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 173, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_32, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 173, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_2);
    __pyx_t_2 = 0;
    __Pyx_INCREF(__pyx_kp_u_masukan_link);
    __pyx_t_12 += 17;
    __Pyx_GIVEREF(__pyx_kp_u_masukan_link);
    PyTuple_SET_ITEM(__pyx_t_3, 4, __pyx_kp_u_masukan_link);
    __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_3, 5, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 173, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 173, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_v_idt = __pyx_t_3;
    __pyx_t_3 = 0;

    
    __pyx_t_3 = PyTuple_New(5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_12 = 0;
    __pyx_t_13 = 127;
    __Pyx_INCREF(__pyx_kp_u__21);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__21);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u__21);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_H); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_32 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_32) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_32) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_32);
    __Pyx_GIVEREF(__pyx_t_32);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_32);
    __pyx_t_32 = 0;
    __Pyx_INCREF(__pyx_kp_u__22);
    __pyx_t_12 += 1;
    __Pyx_GIVEREF(__pyx_kp_u__22);
    PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u__22);
    __Pyx_GetModuleGlobalName(__pyx_t_32, __pyx_n_s_N); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_32, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_2);
    __pyx_t_2 = 0;
    __Pyx_INCREF(__pyx_kp_u_masukan_limit);
    __pyx_t_12 += 18;
    __Pyx_GIVEREF(__pyx_kp_u_masukan_limit);
    PyTuple_SET_ITEM(__pyx_t_3, 4, __pyx_kp_u_masukan_limit);
    __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_3, 5, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyNumber_Int(__pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_limit, __pyx_t_2) < 0) __PYX_ERR(0, 174, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 175, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_List); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 175, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 175, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_message, __pyx_kp_u_pilih_menu) < 0) __PYX_ERR(0, 175, __pyx_L1_error)
    __pyx_t_32 = PyList_New(2); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 175, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __Pyx_INCREF(__pyx_kp_u_munculkan_proses_share);
    __Pyx_GIVEREF(__pyx_kp_u_munculkan_proses_share);
    PyList_SET_ITEM(__pyx_t_32, 0, __pyx_kp_u_munculkan_proses_share);
    __Pyx_INCREF(__pyx_kp_u_jangan_munculkan_proses_share);
    __Pyx_GIVEREF(__pyx_kp_u_jangan_munculkan_proses_share);
    PyList_SET_ITEM(__pyx_t_32, 1, __pyx_kp_u_jangan_munculkan_proses_share);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_choices, __pyx_t_32) < 0) __PYX_ERR(0, 175, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_default, __pyx_kp_u__20) < 0) __PYX_ERR(0, 175, __pyx_L1_error)
    __pyx_t_32 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_tuple__23, __pyx_t_2); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 175, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 175, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_32);
    PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_32);
    __pyx_t_32 = 0;
    __pyx_v_mun = ((PyObject*)__pyx_t_2);
    __pyx_t_2 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_32, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 176, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_32, __pyx_n_s_prompt); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 176, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
    __pyx_t_32 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_32 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_32)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_32);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_32) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_32, __pyx_v_mun) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_mun);
    __Pyx_XDECREF(__pyx_t_32); __pyx_t_32 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 176, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_tinyi = __pyx_t_2;
    __pyx_t_2 = 0;

    
    __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_v_tinyi, __pyx_n_u_muncul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 177, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_kp_u_munculkan_proses_share, __pyx_t_2, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 177, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_25 = (__pyx_t_26 != 0);
    if (__pyx_t_25) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_muncul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 178, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_27 = __Pyx_PyObject_Append(__pyx_t_2, __pyx_n_u_iya); if (unlikely(__pyx_t_27 == ((int)-1))) __PYX_ERR(0, 178, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
    }

    
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Progress); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_SpinnerColumn); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_16))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_16);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_16, function);
      }
    }
    __pyx_t_32 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_8, __pyx_n_u_clock) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_n_u_clock);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_32);
    __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_TextColumn); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_8);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_8, function);
      }
    }
    __pyx_t_16 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_1, __pyx_kp_u_task_description) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_kp_u_task_description);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_16);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_BarColumn); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_8 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_TextColumn); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_11 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_11)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_11);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_1 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_11, __pyx_kp_u_task_percentage_0f) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_kp_u_task_percentage_0f);
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_TimeElapsedColumn); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __pyx_t_15 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
      __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_11);
      if (likely(__pyx_t_15)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
        __Pyx_INCREF(__pyx_t_15);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_11, function);
      }
    }
    __pyx_t_7 = (__pyx_t_15) ? __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_15) : __Pyx_PyObject_CallNoArg(__pyx_t_11);
    __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
    if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __pyx_t_11 = NULL;
    __pyx_t_17 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_11)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_11);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
        __pyx_t_17 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_3)) {
      PyObject *__pyx_temp[6] = {__pyx_t_11, __pyx_t_32, __pyx_t_16, __pyx_t_8, __pyx_t_1, __pyx_t_7};
      __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_17, 5+__pyx_t_17); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 179, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
      PyObject *__pyx_temp[6] = {__pyx_t_11, __pyx_t_32, __pyx_t_16, __pyx_t_8, __pyx_t_1, __pyx_t_7};
      __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_17, 5+__pyx_t_17); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 179, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    } else
    #endif
    {
      __pyx_t_15 = PyTuple_New(5+__pyx_t_17); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 179, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_15);
      if (__pyx_t_11) {
        __Pyx_GIVEREF(__pyx_t_11); PyTuple_SET_ITEM(__pyx_t_15, 0, __pyx_t_11); __pyx_t_11 = NULL;
      }
      __Pyx_GIVEREF(__pyx_t_32);
      PyTuple_SET_ITEM(__pyx_t_15, 0+__pyx_t_17, __pyx_t_32);
      __Pyx_GIVEREF(__pyx_t_16);
      PyTuple_SET_ITEM(__pyx_t_15, 1+__pyx_t_17, __pyx_t_16);
      __Pyx_GIVEREF(__pyx_t_8);
      PyTuple_SET_ITEM(__pyx_t_15, 2+__pyx_t_17, __pyx_t_8);
      __Pyx_GIVEREF(__pyx_t_1);
      PyTuple_SET_ITEM(__pyx_t_15, 3+__pyx_t_17, __pyx_t_1);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_15, 4+__pyx_t_17, __pyx_t_7);
      __pyx_t_32 = 0;
      __pyx_t_16 = 0;
      __pyx_t_8 = 0;
      __pyx_t_1 = 0;
      __pyx_t_7 = 0;
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_15, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 179, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_prog, __pyx_t_2) < 0) __PYX_ERR(0, 179, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_prog); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 180, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_add_task); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 180, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 180, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_limit); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 180, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_total, __pyx_t_15) < 0) __PYX_ERR(0, 180, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    __pyx_t_15 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_tuple__24, __pyx_t_2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 180, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_des, __pyx_t_15) < 0) __PYX_ERR(0, 180, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;

    
     {
      __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_prog); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 181, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_15);
      __pyx_t_6 = __Pyx_PyObject_LookupSpecial(__pyx_t_15, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 181, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_3 = __Pyx_PyObject_LookupSpecial(__pyx_t_15, __pyx_n_s_enter); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 181, __pyx_L63_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_7 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 181, __pyx_L63_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
       {
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_24, &__pyx_t_4, &__pyx_t_5);
          __Pyx_XGOTREF(__pyx_t_24);
          __Pyx_XGOTREF(__pyx_t_4);
          __Pyx_XGOTREF(__pyx_t_5);
           {

            
            __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_limit); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 182, __pyx_L67_error)
            __Pyx_GOTREF(__pyx_t_15);
            __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_15); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 182, __pyx_L67_error)
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
            if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
              __pyx_t_15 = __pyx_t_2; __Pyx_INCREF(__pyx_t_15); __pyx_t_12 = 0;
              __pyx_t_28 = NULL;
            } else {
              __pyx_t_12 = -1; __pyx_t_15 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 182, __pyx_L67_error)
              __Pyx_GOTREF(__pyx_t_15);
              __pyx_t_28 = Py_TYPE(__pyx_t_15)->tp_iternext; if (unlikely(!__pyx_t_28)) __PYX_ERR(0, 182, __pyx_L67_error)
            }
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            for (;;) {
              if (likely(!__pyx_t_28)) {
                if (likely(PyList_CheckExact(__pyx_t_15))) {
                  if (__pyx_t_12 >= PyList_GET_SIZE(__pyx_t_15)) break;
                  #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                  __pyx_t_2 = PyList_GET_ITEM(__pyx_t_15, __pyx_t_12); __Pyx_INCREF(__pyx_t_2); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 182, __pyx_L67_error)
                  #else
                  __pyx_t_2 = PySequence_ITEM(__pyx_t_15, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 182, __pyx_L67_error)
                  __Pyx_GOTREF(__pyx_t_2);
                  #endif
                } else {
                  if (__pyx_t_12 >= PyTuple_GET_SIZE(__pyx_t_15)) break;
                  #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                  __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_15, __pyx_t_12); __Pyx_INCREF(__pyx_t_2); __pyx_t_12++; if (unlikely(0 < 0)) __PYX_ERR(0, 182, __pyx_L67_error)
                  #else
                  __pyx_t_2 = PySequence_ITEM(__pyx_t_15, __pyx_t_12); __pyx_t_12++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 182, __pyx_L67_error)
                  __Pyx_GOTREF(__pyx_t_2);
                  #endif
                }
              } else {
                __pyx_t_2 = __pyx_t_28(__pyx_t_15);
                if (unlikely(!__pyx_t_2)) {
                  PyObject* exc_type = PyErr_Occurred();
                  if (exc_type) {
                    if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                    else __PYX_ERR(0, 182, __pyx_L67_error)
                  }
                  break;
                }
                __Pyx_GOTREF(__pyx_t_2);
              }
              __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_2);
              __pyx_t_2 = 0;

              
              {
                __Pyx_PyThreadState_declare
                __Pyx_PyThreadState_assign
                __Pyx_ExceptionSave(&__pyx_t_23, &__pyx_t_20, &__pyx_t_21);
                __Pyx_XGOTREF(__pyx_t_23);
                __Pyx_XGOTREF(__pyx_t_20);
                __Pyx_XGOTREF(__pyx_t_21);
                 {

                  
                  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_share_lambat); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 184, __pyx_L75_error)
                  __Pyx_GOTREF(__pyx_t_3);
                  if (unlikely(!__pyx_v_token)) { __Pyx_RaiseUnboundLocalError("token"); __PYX_ERR(0, 184, __pyx_L75_error) }
                  if (unlikely(!__pyx_v_cookie)) { __Pyx_RaiseUnboundLocalError("cookie"); __PYX_ERR(0, 184, __pyx_L75_error) }
                  __pyx_t_7 = NULL;
                  __pyx_t_17 = 0;
                  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
                    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
                    if (likely(__pyx_t_7)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
                      __Pyx_INCREF(__pyx_t_7);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_3, function);
                      __pyx_t_17 = 1;
                    }
                  }
                  #if CYTHON_FAST_PYCALL
                  if (PyFunction_Check(__pyx_t_3)) {
                    PyObject *__pyx_temp[4] = {__pyx_t_7, __pyx_v_token, __pyx_v_cookie, __pyx_v_idt};
                    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_17, 3+__pyx_t_17); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L75_error)
                    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
                    __Pyx_GOTREF(__pyx_t_2);
                  } else
                  #endif
                  #if CYTHON_FAST_PYCCALL
                  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
                    PyObject *__pyx_temp[4] = {__pyx_t_7, __pyx_v_token, __pyx_v_cookie, __pyx_v_idt};
                    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_17, 3+__pyx_t_17); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L75_error)
                    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
                    __Pyx_GOTREF(__pyx_t_2);
                  } else
                  #endif
                  {
                    __pyx_t_1 = PyTuple_New(3+__pyx_t_17); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 184, __pyx_L75_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    if (__pyx_t_7) {
                      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_7); __pyx_t_7 = NULL;
                    }
                    __Pyx_INCREF(__pyx_v_token);
                    __Pyx_GIVEREF(__pyx_v_token);
                    PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_17, __pyx_v_token);
                    __Pyx_INCREF(__pyx_v_cookie);
                    __Pyx_GIVEREF(__pyx_v_cookie);
                    PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_17, __pyx_v_cookie);
                    __Pyx_INCREF(__pyx_v_idt);
                    __Pyx_GIVEREF(__pyx_v_idt);
                    PyTuple_SET_ITEM(__pyx_t_1, 2+__pyx_t_17, __pyx_v_idt);
                    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_1, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L75_error)
                    __Pyx_GOTREF(__pyx_t_2);
                    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                  }
                  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
                  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

                  
                }
                __Pyx_XDECREF(__pyx_t_23); __pyx_t_23 = 0;
                __Pyx_XDECREF(__pyx_t_20); __pyx_t_20 = 0;
                __Pyx_XDECREF(__pyx_t_21); __pyx_t_21 = 0;
                goto __pyx_L82_try_end;
                __pyx_L75_error:;
                __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
                __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
                __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
                __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
                __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                __Pyx_XDECREF(__pyx_t_32); __pyx_t_32 = 0;
                __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
                __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

                
                 {
                  __Pyx_AddTraceback("share.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
                  if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_1) < 0) __PYX_ERR(0, 185, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_2);
                  __Pyx_GOTREF(__pyx_t_3);
                  __Pyx_GOTREF(__pyx_t_1);

                  
                  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_prints); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_8);
                  __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_Panel); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_16);
                  __pyx_t_32 = PyTuple_New(6); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_32);
                  __pyx_t_31 = 0;
                  __pyx_t_13 = 127;
                  __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_P2); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_11);
                  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_t_11, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_10);
                  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
                  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) : __pyx_t_13;
                  __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_10);
                  __Pyx_GIVEREF(__pyx_t_10);
                  PyTuple_SET_ITEM(__pyx_t_32, 0, __pyx_t_10);
                  __pyx_t_10 = 0;
                  __Pyx_INCREF(__pyx_kp_u_berhasil_membagikan_total);
                  __pyx_t_31 += 26;
                  __Pyx_GIVEREF(__pyx_kp_u_berhasil_membagikan_total);
                  PyTuple_SET_ITEM(__pyx_t_32, 1, __pyx_kp_u_berhasil_membagikan_total);
                  __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_H2); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_10);
                  __pyx_t_11 = __Pyx_PyObject_FormatSimple(__pyx_t_10, __pyx_empty_unicode); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_11);
                  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
                  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) : __pyx_t_13;
                  __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_11);
                  __Pyx_GIVEREF(__pyx_t_11);
                  PyTuple_SET_ITEM(__pyx_t_32, 2, __pyx_t_11);
                  __pyx_t_11 = 0;
                  __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_loop); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_11);
                  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_t_11, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_10);
                  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
                  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) : __pyx_t_13;
                  __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_10);
                  __Pyx_GIVEREF(__pyx_t_10);
                  PyTuple_SET_ITEM(__pyx_t_32, 3, __pyx_t_10);
                  __pyx_t_10 = 0;
                  __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_P2); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_10);
                  __pyx_t_11 = __Pyx_PyObject_FormatSimple(__pyx_t_10, __pyx_empty_unicode); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_11);
                  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
                  __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) : __pyx_t_13;
                  __pyx_t_31 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_11);
                  __Pyx_GIVEREF(__pyx_t_11);
                  PyTuple_SET_ITEM(__pyx_t_32, 4, __pyx_t_11);
                  __pyx_t_11 = 0;
                  __Pyx_INCREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
                  __pyx_t_31 += 41;
                  __Pyx_GIVEREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
                  PyTuple_SET_ITEM(__pyx_t_32, 5, __pyx_kp_u_share_silahkan_jalankan_ulang_t);
                  __pyx_t_11 = __Pyx_PyUnicode_Join(__pyx_t_32, 6, __pyx_t_31, __pyx_t_13); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_11);
                  __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
                  __pyx_t_32 = PyTuple_New(1); if (unlikely(!__pyx_t_32)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_32);
                  __Pyx_GIVEREF(__pyx_t_11);
                  PyTuple_SET_ITEM(__pyx_t_32, 0, __pyx_t_11);
                  __pyx_t_11 = 0;
                  __pyx_t_11 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_11);
                  __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_color_table); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_10);
                  __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_10, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_14);
                  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
                  if (PyDict_SetItem(__pyx_t_11, __pyx_n_s_style, __pyx_t_14) < 0) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                  __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_16, __pyx_t_32, __pyx_t_11); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_14);
                  __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
                  __Pyx_DECREF(__pyx_t_32); __pyx_t_32 = 0;
                  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
                  __pyx_t_11 = NULL;
                  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
                    __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_8);
                    if (likely(__pyx_t_11)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
                      __Pyx_INCREF(__pyx_t_11);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_8, function);
                    }
                  }
                  __pyx_t_7 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_11, __pyx_t_14) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_14);
                  __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
                  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                  if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 186, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_7);
                  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
                  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

                  
                  __pyx_t_7 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 187, __pyx_L77_except_error)
                  __Pyx_GOTREF(__pyx_t_7);
                  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
                  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                  goto __pyx_L76_exception_handled;
                }
                __pyx_L77_except_error:;

                
                __Pyx_XGIVEREF(__pyx_t_23);
                __Pyx_XGIVEREF(__pyx_t_20);
                __Pyx_XGIVEREF(__pyx_t_21);
                __Pyx_ExceptionReset(__pyx_t_23, __pyx_t_20, __pyx_t_21);
                goto __pyx_L67_error;
                __pyx_L76_exception_handled:;
                __Pyx_XGIVEREF(__pyx_t_23);
                __Pyx_XGIVEREF(__pyx_t_20);
                __Pyx_XGIVEREF(__pyx_t_21);
                __Pyx_ExceptionReset(__pyx_t_23, __pyx_t_20, __pyx_t_21);
                __pyx_L82_try_end:;
              }

              
            }
            __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;

            
          }
          __Pyx_XDECREF(__pyx_t_24); __pyx_t_24 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          goto __pyx_L72_try_end;
          __pyx_L67_error:;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_32); __pyx_t_32 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
           {
            __Pyx_AddTraceback("share.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_15, &__pyx_t_1, &__pyx_t_3) < 0) __PYX_ERR(0, 181, __pyx_L69_except_error)
            __Pyx_GOTREF(__pyx_t_15);
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_GOTREF(__pyx_t_3);
            __pyx_t_2 = PyTuple_Pack(3, __pyx_t_15, __pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 181, __pyx_L69_except_error)
            __Pyx_GOTREF(__pyx_t_2);
            __pyx_t_21 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_2, NULL);
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            if (unlikely(!__pyx_t_21)) __PYX_ERR(0, 181, __pyx_L69_except_error)
            __Pyx_GOTREF(__pyx_t_21);
            __pyx_t_25 = __Pyx_PyObject_IsTrue(__pyx_t_21);
            __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
            if (__pyx_t_25 < 0) __PYX_ERR(0, 181, __pyx_L69_except_error)
            __pyx_t_26 = ((!(__pyx_t_25 != 0)) != 0);
            if (__pyx_t_26) {
              __Pyx_GIVEREF(__pyx_t_15);
              __Pyx_GIVEREF(__pyx_t_1);
              __Pyx_XGIVEREF(__pyx_t_3);
              __Pyx_ErrRestoreWithState(__pyx_t_15, __pyx_t_1, __pyx_t_3);
              __pyx_t_15 = 0; __pyx_t_1 = 0; __pyx_t_3 = 0; 
              __PYX_ERR(0, 181, __pyx_L69_except_error)
            }
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            goto __pyx_L68_exception_handled;
          }
          __pyx_L69_except_error:;
          __Pyx_XGIVEREF(__pyx_t_24);
          __Pyx_XGIVEREF(__pyx_t_4);
          __Pyx_XGIVEREF(__pyx_t_5);
          __Pyx_ExceptionReset(__pyx_t_24, __pyx_t_4, __pyx_t_5);
          goto __pyx_L1_error;
          __pyx_L68_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_24);
          __Pyx_XGIVEREF(__pyx_t_4);
          __Pyx_XGIVEREF(__pyx_t_5);
          __Pyx_ExceptionReset(__pyx_t_24, __pyx_t_4, __pyx_t_5);
          __pyx_L72_try_end:;
        }
      }
       {
        {
          if (__pyx_t_6) {
            __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__25, NULL);
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 181, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
          }
          goto __pyx_L66;
        }
        __pyx_L66:;
      }
      goto __pyx_L88;
      __pyx_L63_error:;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L1_error;
      __pyx_L88:;
    }

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prints); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_Panel); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __pyx_t_2 = PyTuple_New(6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_12 = 0;
    __pyx_t_13 = 127;
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_P2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
    __Pyx_GIVEREF(__pyx_t_8);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_8);
    __pyx_t_8 = 0;
    __Pyx_INCREF(__pyx_kp_u_berhasil_membagikan_total);
    __pyx_t_12 += 26;
    __Pyx_GIVEREF(__pyx_kp_u_berhasil_membagikan_total);
    PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_kp_u_berhasil_membagikan_total);
    __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_H2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_t_7);
    __pyx_t_7 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_loop); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
    __Pyx_GIVEREF(__pyx_t_8);
    PyTuple_SET_ITEM(__pyx_t_2, 3, __pyx_t_8);
    __pyx_t_8 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_P2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_2, 4, __pyx_t_7);
    __pyx_t_7 = 0;
    __Pyx_INCREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
    __pyx_t_12 += 41;
    __Pyx_GIVEREF(__pyx_kp_u_share_silahkan_jalankan_ulang_t);
    PyTuple_SET_ITEM(__pyx_t_2, 5, __pyx_kp_u_share_silahkan_jalankan_ulang_t);
    __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_2, 6, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_7);
    __pyx_t_7 = 0;
    __pyx_t_7 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_color_table); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_style, __pyx_t_14) < 0) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_15, __pyx_t_2, __pyx_t_7); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_3 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_7, __pyx_t_14) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_14);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    __pyx_t_3 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 189, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    goto __pyx_L20;
  }

  
  __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_tanya, __pyx_n_u_menu); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 190, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_kp_u_ganti_warna_tema, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 190, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_25 = (__pyx_t_26 != 0);
  if (__pyx_t_25) {

    
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 191, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_List); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 191, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 191, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_message, __pyx_kp_u_pilih_warna) < 0) __PYX_ERR(0, 191, __pyx_L1_error)
    __pyx_t_14 = PyList_New(8); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 191, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __Pyx_INCREF(__pyx_n_u_merah);
    __Pyx_GIVEREF(__pyx_n_u_merah);
    PyList_SET_ITEM(__pyx_t_14, 0, __pyx_n_u_merah);
    __Pyx_INCREF(__pyx_n_u_biru);
    __Pyx_GIVEREF(__pyx_n_u_biru);
    PyList_SET_ITEM(__pyx_t_14, 1, __pyx_n_u_biru);
    __Pyx_INCREF(__pyx_n_u_hijau);
    __Pyx_GIVEREF(__pyx_n_u_hijau);
    PyList_SET_ITEM(__pyx_t_14, 2, __pyx_n_u_hijau);
    __Pyx_INCREF(__pyx_n_u_kuning);
    __Pyx_GIVEREF(__pyx_n_u_kuning);
    PyList_SET_ITEM(__pyx_t_14, 3, __pyx_n_u_kuning);
    __Pyx_INCREF(__pyx_n_u_pink);
    __Pyx_GIVEREF(__pyx_n_u_pink);
    PyList_SET_ITEM(__pyx_t_14, 4, __pyx_n_u_pink);
    __Pyx_INCREF(__pyx_n_u_putih);
    __Pyx_GIVEREF(__pyx_n_u_putih);
    PyList_SET_ITEM(__pyx_t_14, 5, __pyx_n_u_putih);
    __Pyx_INCREF(__pyx_n_u_oren);
    __Pyx_GIVEREF(__pyx_n_u_oren);
    PyList_SET_ITEM(__pyx_t_14, 6, __pyx_n_u_oren);
    __Pyx_INCREF(__pyx_n_u_ungu);
    __Pyx_GIVEREF(__pyx_n_u_ungu);
    PyList_SET_ITEM(__pyx_t_14, 7, __pyx_n_u_ungu);
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_choices, __pyx_t_14) < 0) __PYX_ERR(0, 191, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_default, __pyx_kp_u__20) < 0) __PYX_ERR(0, 191, __pyx_L1_error)
    __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__26, __pyx_t_3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 191, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = PyList_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 191, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_14);
    PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_14);
    __pyx_t_14 = 0;
    __pyx_v_war = ((PyObject*)__pyx_t_3);
    __pyx_t_3 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_inquirer); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 192, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_prompt); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 192, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    __pyx_t_14 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_14)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_14);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_v_war) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_war);
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 192, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_v_warna = __pyx_t_3;
    __pyx_t_3 = 0;

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 193, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_25 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_merah, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_25 < 0)) __PYX_ERR(0, 193, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_26 = (__pyx_t_25 != 0);
    if (__pyx_t_26) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 194, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 194, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_FF0000) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_FF0000);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 194, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 195, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 195, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_FF0000_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_FF0000_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 195, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      goto __pyx_L89;
    }

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 196, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_biru, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 196, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_25 = (__pyx_t_26 != 0);
    if (__pyx_t_25) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 197, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 197, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_00C8FF) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_00C8FF);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 197, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 198, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_00C8FF_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_00C8FF_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      goto __pyx_L89;
    }

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 199, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_25 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_hijau, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_25 < 0)) __PYX_ERR(0, 199, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_26 = (__pyx_t_25 != 0);
    if (__pyx_t_26) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 200, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 200, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_00FF00) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_00FF00);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 200, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 201, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 201, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_00FF00_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_00FF00_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 201, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      goto __pyx_L89;
    }

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 202, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_kuning, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 202, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_25 = (__pyx_t_26 != 0);
    if (__pyx_t_25) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 203, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 203, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_FFFF00) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_FFFF00);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 203, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 204, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 204, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_FFFF00_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_FFFF00_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 204, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      goto __pyx_L89;
    }

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 205, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_25 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_pink, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_25 < 0)) __PYX_ERR(0, 205, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_26 = (__pyx_t_25 != 0);
    if (__pyx_t_26) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 206, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 206, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_FF00FF) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_FF00FF);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 206, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 207, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_FF00FF_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_FF00FF_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 207, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      goto __pyx_L89;
    }

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 208, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_putih, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 208, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_25 = (__pyx_t_26 != 0);
    if (__pyx_t_25) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 209, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 209, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_FFFFFF) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_FFFFFF);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 209, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 210, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_FFFFFF_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_FFFFFF_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 210, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      goto __pyx_L89;
    }

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 211, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_25 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_oren, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_25 < 0)) __PYX_ERR(0, 211, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_26 = (__pyx_t_25 != 0);
    if (__pyx_t_26) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 212, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 212, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_FF8F00) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_FF8F00);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 212, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 213, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 213, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_FF8F00_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_FF8F00_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 213, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      goto __pyx_L89;
    }

    
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_ungu, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_25 = (__pyx_t_26 != 0);
    if (__pyx_t_25) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 215, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_write); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 215, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
        }
      }
      __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_1, __pyx_kp_u_AF00FF) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_kp_u_AF00FF);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 215, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 216, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 216, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_kp_u_AF00FF_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u_AF00FF_2);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 216, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
    }
    __pyx_L89:;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prints); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_Panel); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __pyx_t_7 = PyTuple_New(6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_12 = 0;
    __pyx_t_13 = 127;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_P2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_15);
    __Pyx_GIVEREF(__pyx_t_15);
    PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_15);
    __pyx_t_15 = 0;
    __Pyx_INCREF(__pyx_kp_u_berhasil_mengubah_tema_menjadi);
    __pyx_t_12 += 31;
    __Pyx_GIVEREF(__pyx_kp_u_berhasil_mengubah_tema_menjadi);
    PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_kp_u_berhasil_mengubah_tema_menjadi);
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_H2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_15, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_t_2);
    __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_v_warna, __pyx_n_u_warna); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_15) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_15);
    __Pyx_GIVEREF(__pyx_t_15);
    PyTuple_SET_ITEM(__pyx_t_7, 3, __pyx_t_15);
    __pyx_t_15 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_P2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_15, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    __pyx_t_13 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_13) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_13;
    __pyx_t_12 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_7, 4, __pyx_t_2);
    __pyx_t_2 = 0;
    __Pyx_INCREF(__pyx_kp_u_silahkan_jalankan_ulang_tools_i);
    __pyx_t_12 += 35;
    __Pyx_GIVEREF(__pyx_kp_u_silahkan_jalankan_ulang_tools_i);
    PyTuple_SET_ITEM(__pyx_t_7, 5, __pyx_kp_u_silahkan_jalankan_ulang_tools_i);
    __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_7, 6, __pyx_t_12, __pyx_t_13); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_7 = PyTuple_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_2);
    __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_color_table); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_15, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_style, __pyx_t_8) < 0) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_t_7, __pyx_t_2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_2, __pyx_t_8) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_8);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    __pyx_t_3 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 218, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    goto __pyx_L20;
  }

  
  __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_tanya, __pyx_n_u_menu); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 219, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_25 = (__Pyx_PySequence_ContainsTF(__pyx_kp_u_ganti_tumbal, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_25 < 0)) __PYX_ERR(0, 219, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_26 = (__pyx_t_25 != 0);
  if (__pyx_t_26) {

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_os); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 220, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_system); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 220, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_8);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_8, function);
      }
    }
    __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_1, __pyx_kp_u_rm_f_data_token_txt_data_cookie) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_kp_u_rm_f_data_token_txt_data_cookie);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 220, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_login); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_8);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_8, function);
      }
    }
    __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_8);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    goto __pyx_L20;
  }

  
  __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_v_tanya, __pyx_n_u_menu); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_26 = (__Pyx_PySequence_ContainsTF(__pyx_kp_u_keluar_tools, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_25 = (__pyx_t_26 != 0);
  if (__pyx_t_25) {

    
    __pyx_t_3 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 223, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
  }
  __pyx_L20:;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_XDECREF(__pyx_t_32);
  __Pyx_AddTraceback("share.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_ses);
  __Pyx_XDECREF(__pyx_v_token);
  __Pyx_XDECREF(__pyx_v_cok);
  __Pyx_XDECREF(__pyx_v_cookie);
  __Pyx_XDECREF(__pyx_v_nama);
  __Pyx_XDECREF(__pyx_v_e);
  __Pyx_XDECREF(__pyx_v_men);
  __Pyx_XDECREF(__pyx_v_tanya);
  __Pyx_XDECREF(__pyx_v_idt);
  __Pyx_XDECREF(__pyx_v_mun);
  __Pyx_XDECREF(__pyx_v_tinyi);
  __Pyx_XDECREF(__pyx_v_fall);
  __Pyx_XDECREF(__pyx_v_z);
  __Pyx_XDECREF(__pyx_v_war);
  __Pyx_XDECREF(__pyx_v_warna);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_5share_11share_cepat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_5share_11share_cepat = {"share_cepat", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5share_11share_cepat, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5share_11share_cepat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_token = 0;
  PyObject *__pyx_v_cookie = 0;
  PyObject *__pyx_v_idt = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("share_cepat (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_token,&__pyx_n_s_cookie,&__pyx_n_s_idt,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_token)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_cookie)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("share_cepat", 1, 3, 3, 1); __PYX_ERR(0, 226, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_idt)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("share_cepat", 1, 3, 3, 2); __PYX_ERR(0, 226, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "share_cepat") < 0)) __PYX_ERR(0, 226, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_token = values[0];
    __pyx_v_cookie = values[1];
    __pyx_v_idt = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("share_cepat", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 226, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("share.share_cepat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5share_10share_cepat(__pyx_self, __pyx_v_token, __pyx_v_cookie, __pyx_v_idt);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5share_10share_cepat(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_token, PyObject *__pyx_v_cookie, PyObject *__pyx_v_idt) {
  CYTHON_UNUSED PyObject *__pyx_v_prox = NULL;
  PyObject *__pyx_v_ses = NULL;
  PyObject *__pyx_v_proxy = NULL;
  PyObject *__pyx_v_post = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  Py_ssize_t __pyx_t_5;
  Py_UCS4 __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  PyObject *__pyx_t_19 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("share_cepat", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prog); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_update); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_des); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyTuple_New(5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = 0;
  __pyx_t_6 = 127;
  __Pyx_INCREF(__pyx_kp_u_proses_share);
  __pyx_t_5 += 13;
  __Pyx_GIVEREF(__pyx_kp_u_proses_share);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_kp_u_proses_share);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_loop); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__29);
  __pyx_t_5 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__29);
  PyTuple_SET_ITEM(__pyx_t_4, 2, __pyx_kp_u__29);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_limit); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 3, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_N); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 4, __pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyUnicode_Join(__pyx_t_4, 5, __pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_description, __pyx_t_8) < 0) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prog); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_advance); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_des); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_8 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__30, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_read); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_splitlines); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_8 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_prox = __pyx_t_8;
  __pyx_t_8 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
    __Pyx_XGOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_t_10);
    __Pyx_XGOTREF(__pyx_t_11);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_requests); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 232, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 232, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_2)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_2);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_8 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 232, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_ses = __pyx_t_8;
      __pyx_t_8 = 0;

      
      __pyx_t_8 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 233, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (PyDict_SetItem(__pyx_t_8, __pyx_n_u_http, __pyx_kp_u_socks5_random_choice_prox) < 0) __PYX_ERR(0, 233, __pyx_L3_error)
      __pyx_v_proxy = ((PyObject*)__pyx_t_8);
      __pyx_t_8 = 0;

      
      __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_post); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      __pyx_t_3 = PyTuple_New(4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = 0;
      __pyx_t_6 = 127;
      __Pyx_INCREF(__pyx_kp_u_https_graph_facebook_com_v13_0_m);
      __pyx_t_5 += 46;
      __Pyx_GIVEREF(__pyx_kp_u_https_graph_facebook_com_v13_0_m);
      PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_https_graph_facebook_com_v13_0_m);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_idt, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_6;
      __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_INCREF(__pyx_kp_u_published_0_access_token);
      __pyx_t_5 += 26;
      __Pyx_GIVEREF(__pyx_kp_u_published_0_access_token);
      PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_published_0_access_token);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_token, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_6;
      __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_2);
      __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_3, 4, __pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_1 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_authority, __pyx_kp_u_graph_facebook_com) < 0) __PYX_ERR(0, 234, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_kp_u_cache_control, __pyx_kp_u_max_age_0) < 0) __PYX_ERR(0, 234, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_kp_u_sec_ch_ua_mobile, __pyx_kp_u_0) < 0) __PYX_ERR(0, 234, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_kp_u_user_agent, __pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App) < 0) __PYX_ERR(0, 234, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_headers, __pyx_t_1) < 0) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_cookies, __pyx_v_cookie) < 0) __PYX_ERR(0, 234, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_proxies, __pyx_v_proxy) < 0) __PYX_ERR(0, 234, __pyx_L3_error)
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 234, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_v_post = __pyx_t_2;
      __pyx_t_2 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_json); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 235, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_loads); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 235, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_1, __pyx_v_post) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_post);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 235, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_data = __pyx_t_2;
      __pyx_t_2 = 0;

      
      __pyx_t_12 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_id, __pyx_v_post, Py_EQ)); if (unlikely(__pyx_t_12 < 0)) __PYX_ERR(0, 236, __pyx_L3_error)
      __pyx_t_13 = (__pyx_t_12 != 0);
      if (__pyx_t_13) {

        
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_muncul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 237, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_13 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_iya, __pyx_t_2, Py_EQ)); if (unlikely(__pyx_t_13 < 0)) __PYX_ERR(0, 237, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_12 = (__pyx_t_13 != 0);
        if (__pyx_t_12) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_prints); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Panel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_8 = PyTuple_New(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_5 = 0;
          __pyx_t_6 = 127;
          __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_H2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
          __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u_membagikan_postingan_dengan_id_p);
          __pyx_t_5 += 36;
          __Pyx_GIVEREF(__pyx_kp_u_membagikan_postingan_dengan_id_p);
          PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_kp_u_membagikan_postingan_dengan_id_p);
          __pyx_t_7 = __Pyx_PyObject_Dict_GetItem(__pyx_v_data, __pyx_n_u_id); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_6;
          __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
          __Pyx_GIVEREF(__pyx_t_4);
          PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_t_4);
          __pyx_t_4 = 0;
          __pyx_t_4 = __Pyx_PyUnicode_Join(__pyx_t_8, 3, __pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = PyTuple_New(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_GIVEREF(__pyx_t_4);
          PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_4);
          __pyx_t_4 = 0;
          __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_color_table); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_style, __pyx_t_14) < 0) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_8, __pyx_t_4); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __pyx_t_4 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_4)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_4);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_t_14) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_14);
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 238, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
        }

        
        goto __pyx_L9;
      }

      
       {
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17);
          __Pyx_XGOTREF(__pyx_t_15);
          __Pyx_XGOTREF(__pyx_t_16);
          __Pyx_XGOTREF(__pyx_t_17);
           {

            
            __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 241, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

            
          }
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
          goto __pyx_L16_try_end;
          __pyx_L11_error:;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

          
           {
            __Pyx_AddTraceback("share.share_cepat", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_14) < 0) __PYX_ERR(0, 242, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GOTREF(__pyx_t_14);

            
            __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_sys); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 243, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_8);
            __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_exit); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 243, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
            __pyx_t_8 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
              __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_1);
              if (likely(__pyx_t_8)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                __Pyx_INCREF(__pyx_t_8);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_1, function);
              }
            }
            __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_8) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
            __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
            if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 243, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_4);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
            __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
            goto __pyx_L12_exception_handled;
          }
          __pyx_L13_except_error:;

          
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          goto __pyx_L3_error;
          __pyx_L12_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          __pyx_L16_try_end:;
        }
      }
      __pyx_L9:;

      
    }
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

    
     {
      __Pyx_AddTraceback("share.share_cepat", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_14, &__pyx_t_3, &__pyx_t_2) < 0) __PYX_ERR(0, 244, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_2);

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_17, &__pyx_t_16, &__pyx_t_15);
        __Pyx_XGOTREF(__pyx_t_17);
        __Pyx_XGOTREF(__pyx_t_16);
        __Pyx_XGOTREF(__pyx_t_15);
         {

          
          __pyx_t_4 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 246, __pyx_L21_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

          
        }
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
        goto __pyx_L28_try_end;
        __pyx_L21_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

        
         {
          __Pyx_AddTraceback("share.share_cepat", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_4, &__pyx_t_1, &__pyx_t_8) < 0) __PYX_ERR(0, 247, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_8);

          
          __Pyx_GetModuleGlobalName(__pyx_t_18, __pyx_n_s_sys); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 248, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_18);
          __pyx_t_19 = __Pyx_PyObject_GetAttrStr(__pyx_t_18, __pyx_n_s_exit); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 248, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_19);
          __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
          __pyx_t_18 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_19))) {
            __pyx_t_18 = PyMethod_GET_SELF(__pyx_t_19);
            if (likely(__pyx_t_18)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_19);
              __Pyx_INCREF(__pyx_t_18);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_19, function);
            }
          }
          __pyx_t_7 = (__pyx_t_18) ? __Pyx_PyObject_CallOneArg(__pyx_t_19, __pyx_t_18) : __Pyx_PyObject_CallNoArg(__pyx_t_19);
          __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
          if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 248, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
          goto __pyx_L22_exception_handled;
        }
        __pyx_L23_except_error:;

        
        __Pyx_XGIVEREF(__pyx_t_17);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_ExceptionReset(__pyx_t_17, __pyx_t_16, __pyx_t_15);
        goto __pyx_L5_except_error;
        __pyx_L22_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_17);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_ExceptionReset(__pyx_t_17, __pyx_t_16, __pyx_t_15);
        __pyx_L28_try_end:;
      }
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      goto __pyx_L4_exception_handled;
    }
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    __pyx_L8_try_end:;
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_loop); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 250, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyInt_AddObjC(__pyx_t_2, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 250, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_loop, __pyx_t_3) < 0) __PYX_ERR(0, 250, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_18);
  __Pyx_XDECREF(__pyx_t_19);
  __Pyx_AddTraceback("share.share_cepat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_prox);
  __Pyx_XDECREF(__pyx_v_ses);
  __Pyx_XDECREF(__pyx_v_proxy);
  __Pyx_XDECREF(__pyx_v_post);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_5share_13share_lambat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_5share_13share_lambat = {"share_lambat", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5share_13share_lambat, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5share_13share_lambat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_token = 0;
  PyObject *__pyx_v_cookie = 0;
  PyObject *__pyx_v_idt = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("share_lambat (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_token,&__pyx_n_s_cookie,&__pyx_n_s_idt,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_token)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_cookie)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("share_lambat", 1, 3, 3, 1); __PYX_ERR(0, 252, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_idt)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("share_lambat", 1, 3, 3, 2); __PYX_ERR(0, 252, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "share_lambat") < 0)) __PYX_ERR(0, 252, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_token = values[0];
    __pyx_v_cookie = values[1];
    __pyx_v_idt = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("share_lambat", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 252, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("share.share_lambat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5share_12share_lambat(__pyx_self, __pyx_v_token, __pyx_v_cookie, __pyx_v_idt);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5share_12share_lambat(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_token, PyObject *__pyx_v_cookie, PyObject *__pyx_v_idt) {
  CYTHON_UNUSED PyObject *__pyx_v_prox = NULL;
  PyObject *__pyx_v_ses = NULL;
  PyObject *__pyx_v_proxy = NULL;
  PyObject *__pyx_v_post = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  Py_ssize_t __pyx_t_5;
  Py_UCS4 __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  PyObject *__pyx_t_19 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("share_lambat", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prog); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_update); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_des); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyTuple_New(5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = 0;
  __pyx_t_6 = 127;
  __Pyx_INCREF(__pyx_kp_u_proses_share);
  __pyx_t_5 += 13;
  __Pyx_GIVEREF(__pyx_kp_u_proses_share);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_kp_u_proses_share);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_loop); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__29);
  __pyx_t_5 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__29);
  PyTuple_SET_ITEM(__pyx_t_4, 2, __pyx_kp_u__29);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_limit); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_4, 3, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_N); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_6;
  __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 4, __pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyUnicode_Join(__pyx_t_4, 5, __pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_description, __pyx_t_8) < 0) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_prog); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_advance); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_des); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_8 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__30, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_read); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_splitlines); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_8 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_prox = __pyx_t_8;
  __pyx_t_8 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
    __Pyx_XGOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_t_10);
    __Pyx_XGOTREF(__pyx_t_11);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_requests); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 258, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 258, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_2)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_2);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_8 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 258, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_ses = __pyx_t_8;
      __pyx_t_8 = 0;

      
      __pyx_t_8 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 259, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (PyDict_SetItem(__pyx_t_8, __pyx_n_u_http, __pyx_kp_u_socks5_random_choice_prox) < 0) __PYX_ERR(0, 259, __pyx_L3_error)
      __pyx_v_proxy = ((PyObject*)__pyx_t_8);
      __pyx_t_8 = 0;

      
      __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_post); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      __pyx_t_3 = PyTuple_New(4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = 0;
      __pyx_t_6 = 127;
      __Pyx_INCREF(__pyx_kp_u_https_graph_facebook_com_v13_0_m);
      __pyx_t_5 += 46;
      __Pyx_GIVEREF(__pyx_kp_u_https_graph_facebook_com_v13_0_m);
      PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_https_graph_facebook_com_v13_0_m);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_idt, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_6;
      __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_INCREF(__pyx_kp_u_published_0_access_token);
      __pyx_t_5 += 26;
      __Pyx_GIVEREF(__pyx_kp_u_published_0_access_token);
      PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_published_0_access_token);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_token, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_6;
      __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_2);
      __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_3, 4, __pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_1 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_authority, __pyx_kp_u_graph_facebook_com) < 0) __PYX_ERR(0, 260, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_kp_u_cache_control, __pyx_kp_u_max_age_0) < 0) __PYX_ERR(0, 260, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_kp_u_sec_ch_ua_mobile, __pyx_kp_u_0) < 0) __PYX_ERR(0, 260, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_kp_u_user_agent, __pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App) < 0) __PYX_ERR(0, 260, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_headers, __pyx_t_1) < 0) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_cookies, __pyx_v_cookie) < 0) __PYX_ERR(0, 260, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_proxies, __pyx_v_proxy) < 0) __PYX_ERR(0, 260, __pyx_L3_error)
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 260, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_v_post = __pyx_t_2;
      __pyx_t_2 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_json); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 261, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_loads); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 261, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_1, __pyx_v_post) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_post);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 261, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_data = __pyx_t_2;
      __pyx_t_2 = 0;

      
      __pyx_t_12 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_id, __pyx_v_post, Py_EQ)); if (unlikely(__pyx_t_12 < 0)) __PYX_ERR(0, 262, __pyx_L3_error)
      __pyx_t_13 = (__pyx_t_12 != 0);
      if (__pyx_t_13) {

        
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_muncul); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 263, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_13 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_iya, __pyx_t_2, Py_EQ)); if (unlikely(__pyx_t_13 < 0)) __PYX_ERR(0, 263, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_12 = (__pyx_t_13 != 0);
        if (__pyx_t_12) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_prints); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Panel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_8 = PyTuple_New(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_5 = 0;
          __pyx_t_6 = 127;
          __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_H2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_6;
          __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u_membagikan_postingan_dengan_id_p);
          __pyx_t_5 += 36;
          __Pyx_GIVEREF(__pyx_kp_u_membagikan_postingan_dengan_id_p);
          PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_kp_u_membagikan_postingan_dengan_id_p);
          __pyx_t_7 = __Pyx_PyObject_Dict_GetItem(__pyx_v_data, __pyx_n_u_id); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_6 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_6) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_6;
          __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
          __Pyx_GIVEREF(__pyx_t_4);
          PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_t_4);
          __pyx_t_4 = 0;
          __pyx_t_4 = __Pyx_PyUnicode_Join(__pyx_t_8, 3, __pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = PyTuple_New(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_GIVEREF(__pyx_t_4);
          PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_4);
          __pyx_t_4 = 0;
          __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_color_table); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_style, __pyx_t_14) < 0) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_8, __pyx_t_4); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __pyx_t_4 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_4)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_4);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_t_14) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_14);
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 264, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
        }

        
        goto __pyx_L9;
      }

      
       {
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17);
          __Pyx_XGOTREF(__pyx_t_15);
          __Pyx_XGOTREF(__pyx_t_16);
          __Pyx_XGOTREF(__pyx_t_17);
           {

            
            __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 267, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

            
          }
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
          goto __pyx_L16_try_end;
          __pyx_L11_error:;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

          
           {
            __Pyx_AddTraceback("share.share_lambat", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_14) < 0) __PYX_ERR(0, 268, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GOTREF(__pyx_t_14);

            
            __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_sys); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 269, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_8);
            __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_exit); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 269, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
            __pyx_t_8 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
              __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_1);
              if (likely(__pyx_t_8)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                __Pyx_INCREF(__pyx_t_8);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_1, function);
              }
            }
            __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_8) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
            __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
            if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 269, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_4);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
            __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
            goto __pyx_L12_exception_handled;
          }
          __pyx_L13_except_error:;

          
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          goto __pyx_L3_error;
          __pyx_L12_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          __pyx_L16_try_end:;
        }
      }
      __pyx_L9:;

      
    }
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

    
     {
      __Pyx_AddTraceback("share.share_lambat", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_14, &__pyx_t_3, &__pyx_t_2) < 0) __PYX_ERR(0, 270, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_2);

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_17, &__pyx_t_16, &__pyx_t_15);
        __Pyx_XGOTREF(__pyx_t_17);
        __Pyx_XGOTREF(__pyx_t_16);
        __Pyx_XGOTREF(__pyx_t_15);
         {

          
          __pyx_t_4 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 272, __pyx_L21_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

          
        }
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
        goto __pyx_L28_try_end;
        __pyx_L21_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

        
         {
          __Pyx_AddTraceback("share.share_lambat", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_4, &__pyx_t_1, &__pyx_t_8) < 0) __PYX_ERR(0, 273, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_8);

          
          __Pyx_GetModuleGlobalName(__pyx_t_18, __pyx_n_s_sys); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 274, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_18);
          __pyx_t_19 = __Pyx_PyObject_GetAttrStr(__pyx_t_18, __pyx_n_s_exit); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 274, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_19);
          __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
          __pyx_t_18 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_19))) {
            __pyx_t_18 = PyMethod_GET_SELF(__pyx_t_19);
            if (likely(__pyx_t_18)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_19);
              __Pyx_INCREF(__pyx_t_18);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_19, function);
            }
          }
          __pyx_t_7 = (__pyx_t_18) ? __Pyx_PyObject_CallOneArg(__pyx_t_19, __pyx_t_18) : __Pyx_PyObject_CallNoArg(__pyx_t_19);
          __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
          if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 274, __pyx_L23_except_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
          goto __pyx_L22_exception_handled;
        }
        __pyx_L23_except_error:;

        
        __Pyx_XGIVEREF(__pyx_t_17);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_ExceptionReset(__pyx_t_17, __pyx_t_16, __pyx_t_15);
        goto __pyx_L5_except_error;
        __pyx_L22_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_17);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_ExceptionReset(__pyx_t_17, __pyx_t_16, __pyx_t_15);
        __pyx_L28_try_end:;
      }
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      goto __pyx_L4_exception_handled;
    }
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    __pyx_L8_try_end:;
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_loop); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyInt_AddObjC(__pyx_t_2, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_loop, __pyx_t_3) < 0) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_18);
  __Pyx_XDECREF(__pyx_t_19);
  __Pyx_AddTraceback("share.share_lambat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_prox);
  __Pyx_XDECREF(__pyx_v_ses);
  __Pyx_XDECREF(__pyx_v_proxy);
  __Pyx_XDECREF(__pyx_v_post);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); 
static int __pyx_pymod_exec_share(PyObject* module); 
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_share},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "share",
    0, 
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, 
  #else
    -1, 
  #endif
    __pyx_methods ,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, 
  #else
    NULL, 
  #endif
    NULL, 
    NULL, 
    NULL 
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_u_, __pyx_k_, sizeof(__pyx_k_), 0, 1, 0, 0},
  {&__pyx_kp_u_0, __pyx_k_0, sizeof(__pyx_k_0), 0, 1, 0, 0},
  {&__pyx_kp_u_000000, __pyx_k_000000, sizeof(__pyx_k_000000), 0, 1, 0, 0},
  {&__pyx_kp_u_00C8FF, __pyx_k_00C8FF, sizeof(__pyx_k_00C8FF), 0, 1, 0, 0},
  {&__pyx_kp_u_00C8FF_2, __pyx_k_00C8FF_2, sizeof(__pyx_k_00C8FF_2), 0, 1, 0, 0},
  {&__pyx_kp_u_00FF00, __pyx_k_00FF00, sizeof(__pyx_k_00FF00), 0, 1, 0, 0},
  {&__pyx_kp_u_00FF00_2, __pyx_k_00FF00_2, sizeof(__pyx_k_00FF00_2), 0, 1, 0, 0},
  {&__pyx_kp_u_00FFFF, __pyx_k_00FFFF, sizeof(__pyx_k_00FFFF), 0, 1, 0, 0},
  {&__pyx_kp_u_0m, __pyx_k_0m, sizeof(__pyx_k_0m), 0, 1, 0, 0},
  {&__pyx_kp_u_1, __pyx_k_1, sizeof(__pyx_k_1), 0, 1, 0, 0},
  {&__pyx_kp_u_1_91m, __pyx_k_1_91m, sizeof(__pyx_k_1_91m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_92m, __pyx_k_1_92m, sizeof(__pyx_k_1_92m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_93m, __pyx_k_1_93m, sizeof(__pyx_k_1_93m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_94m, __pyx_k_1_94m, sizeof(__pyx_k_1_94m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_95m, __pyx_k_1_95m, sizeof(__pyx_k_1_95m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_96m, __pyx_k_1_96m, sizeof(__pyx_k_1_96m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_97m, __pyx_k_1_97m, sizeof(__pyx_k_1_97m), 0, 1, 0, 0},
  {&__pyx_n_s_A2, __pyx_k_A2, sizeof(__pyx_k_A2), 0, 0, 1, 1},
  {&__pyx_kp_u_AAAAAA, __pyx_k_AAAAAA, sizeof(__pyx_k_AAAAAA), 0, 1, 0, 0},
  {&__pyx_kp_u_AF00FF, __pyx_k_AF00FF, sizeof(__pyx_k_AF00FF), 0, 1, 0, 0},
  {&__pyx_kp_u_AF00FF_2, __pyx_k_AF00FF_2, sizeof(__pyx_k_AF00FF_2), 0, 1, 0, 0},
  {&__pyx_n_s_B, __pyx_k_B, sizeof(__pyx_k_B), 0, 0, 1, 1},
  {&__pyx_n_s_B2, __pyx_k_B2, sizeof(__pyx_k_B2), 0, 0, 1, 1},
  {&__pyx_n_s_BarColumn, __pyx_k_BarColumn, sizeof(__pyx_k_BarColumn), 0, 0, 1, 1},
  {&__pyx_n_s_BeautifulSoup, __pyx_k_BeautifulSoup, sizeof(__pyx_k_BeautifulSoup), 0, 0, 1, 1},
  {&__pyx_kp_u_Bot_Share_Facebook, __pyx_k_Bot_Share_Facebook, sizeof(__pyx_k_Bot_Share_Facebook), 0, 1, 0, 0},
  {&__pyx_kp_u_Buatan_Coder, __pyx_k_Buatan_Coder, sizeof(__pyx_k_Buatan_Coder), 0, 1, 0, 0},
  {&__pyx_n_s_ConnectionError, __pyx_k_ConnectionError, sizeof(__pyx_k_ConnectionError), 0, 0, 1, 1},
  {&__pyx_n_s_Console, __pyx_k_Console, sizeof(__pyx_k_Console), 0, 0, 1, 1},
  {&__pyx_kp_u_EAAG_w, __pyx_k_EAAG_w, sizeof(__pyx_k_EAAG_w), 0, 1, 0, 0},
  {&__pyx_kp_u_FF0000, __pyx_k_FF0000, sizeof(__pyx_k_FF0000), 0, 1, 0, 0},
  {&__pyx_kp_u_FF0000_2, __pyx_k_FF0000_2, sizeof(__pyx_k_FF0000_2), 0, 1, 0, 0},
  {&__pyx_kp_u_FF00FF, __pyx_k_FF00FF, sizeof(__pyx_k_FF00FF), 0, 1, 0, 0},
  {&__pyx_kp_u_FF00FF_2, __pyx_k_FF00FF_2, sizeof(__pyx_k_FF00FF_2), 0, 1, 0, 0},
  {&__pyx_kp_u_FF8F00, __pyx_k_FF8F00, sizeof(__pyx_k_FF8F00), 0, 1, 0, 0},
  {&__pyx_kp_u_FF8F00_2, __pyx_k_FF8F00_2, sizeof(__pyx_k_FF8F00_2), 0, 1, 0, 0},
  {&__pyx_kp_u_FFFF00, __pyx_k_FFFF00, sizeof(__pyx_k_FFFF00), 0, 1, 0, 0},
  {&__pyx_kp_u_FFFF00_2, __pyx_k_FFFF00_2, sizeof(__pyx_k_FFFF00_2), 0, 1, 0, 0},
  {&__pyx_kp_u_FFFFFF, __pyx_k_FFFFFF, sizeof(__pyx_k_FFFFFF), 0, 1, 0, 0},
  {&__pyx_kp_u_FFFFFF_2, __pyx_k_FFFFFF_2, sizeof(__pyx_k_FFFFFF_2), 0, 1, 0, 0},
  {&__pyx_n_s_FileNotFoundError, __pyx_k_FileNotFoundError, sizeof(__pyx_k_FileNotFoundError), 0, 0, 1, 1},
  {&__pyx_n_s_H, __pyx_k_H, sizeof(__pyx_k_H), 0, 0, 1, 1},
  {&__pyx_n_s_H2, __pyx_k_H2, sizeof(__pyx_k_H2), 0, 0, 1, 1},
  {&__pyx_n_s_IP, __pyx_k_IP, sizeof(__pyx_k_IP), 0, 0, 1, 1},
  {&__pyx_n_u_IP, __pyx_k_IP, sizeof(__pyx_k_IP), 0, 1, 0, 1},
  {&__pyx_n_u_Indonesia, __pyx_k_Indonesia, sizeof(__pyx_k_Indonesia), 0, 1, 0, 1},
  {&__pyx_n_s_J2, __pyx_k_J2, sizeof(__pyx_k_J2), 0, 0, 1, 1},
  {&__pyx_n_s_K, __pyx_k_K, sizeof(__pyx_k_K), 0, 0, 1, 1},
  {&__pyx_n_s_K2, __pyx_k_K2, sizeof(__pyx_k_K2), 0, 0, 1, 1},
  {&__pyx_n_s_List, __pyx_k_List, sizeof(__pyx_k_List), 0, 0, 1, 1},
  {&__pyx_n_s_M, __pyx_k_M, sizeof(__pyx_k_M), 0, 0, 1, 1},
  {&__pyx_n_s_M2, __pyx_k_M2, sizeof(__pyx_k_M2), 0, 0, 1, 1},
  {&__pyx_kp_u_Mozilla_5_0_Linux_Android_8_1_0, __pyx_k_Mozilla_5_0_Linux_Android_8_1_0, sizeof(__pyx_k_Mozilla_5_0_Linux_Android_8_1_0), 0, 1, 0, 0},
  {&__pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App, __pyx_k_Mozilla_5_0_X11_Linux_x86_64_App, sizeof(__pyx_k_Mozilla_5_0_X11_Linux_x86_64_App), 0, 1, 0, 0},
  {&__pyx_n_s_N, __pyx_k_N, sizeof(__pyx_k_N), 0, 0, 1, 1},
  {&__pyx_n_s_N2, __pyx_k_N2, sizeof(__pyx_k_N2), 0, 0, 1, 1},
  {&__pyx_n_s_O, __pyx_k_O, sizeof(__pyx_k_O), 0, 0, 1, 1},
  {&__pyx_n_s_O2, __pyx_k_O2, sizeof(__pyx_k_O2), 0, 0, 1, 1},
  {&__pyx_n_s_P, __pyx_k_P, sizeof(__pyx_k_P), 0, 0, 1, 1},
  {&__pyx_n_s_P2, __pyx_k_P2, sizeof(__pyx_k_P2), 0, 0, 1, 1},
  {&__pyx_n_s_Panel, __pyx_k_Panel, sizeof(__pyx_k_Panel), 0, 0, 1, 1},
  {&__pyx_n_s_Progress, __pyx_k_Progress, sizeof(__pyx_k_Progress), 0, 0, 1, 1},
  {&__pyx_n_s_Session, __pyx_k_Session, sizeof(__pyx_k_Session), 0, 0, 1, 1},
  {&__pyx_n_s_SpinnerColumn, __pyx_k_SpinnerColumn, sizeof(__pyx_k_SpinnerColumn), 0, 0, 1, 1},
  {&__pyx_n_s_TextColumn, __pyx_k_TextColumn, sizeof(__pyx_k_TextColumn), 0, 0, 1, 1},
  {&__pyx_n_s_Thread, __pyx_k_Thread, sizeof(__pyx_k_Thread), 0, 0, 1, 1},
  {&__pyx_n_s_ThreadPoolExecutor, __pyx_k_ThreadPoolExecutor, sizeof(__pyx_k_ThreadPoolExecutor), 0, 0, 1, 1},
  {&__pyx_n_s_TimeElapsedColumn, __pyx_k_TimeElapsedColumn, sizeof(__pyx_k_TimeElapsedColumn), 0, 0, 1, 1},
  {&__pyx_n_s_Tree, __pyx_k_Tree, sizeof(__pyx_k_Tree), 0, 0, 1, 1},
  {&__pyx_n_s_U, __pyx_k_U, sizeof(__pyx_k_U), 0, 0, 1, 1},
  {&__pyx_n_s_U2, __pyx_k_U2, sizeof(__pyx_k_U2), 0, 0, 1, 1},
  {&__pyx_n_s_Z2, __pyx_k_Z2, sizeof(__pyx_k_Z2), 0, 0, 1, 1},
  {&__pyx_kp_u__18, __pyx_k__18, sizeof(__pyx_k__18), 0, 1, 0, 0},
  {&__pyx_kp_u__2, __pyx_k__2, sizeof(__pyx_k__2), 0, 1, 0, 0},
  {&__pyx_kp_u__20, __pyx_k__20, sizeof(__pyx_k__20), 0, 1, 0, 0},
  {&__pyx_kp_u__21, __pyx_k__21, sizeof(__pyx_k__21), 0, 1, 0, 0},
  {&__pyx_kp_u__22, __pyx_k__22, sizeof(__pyx_k__22), 0, 1, 0, 0},
  {&__pyx_kp_u__29, __pyx_k__29, sizeof(__pyx_k__29), 0, 1, 0, 0},
  {&__pyx_kp_u__3, __pyx_k__3, sizeof(__pyx_k__3), 0, 1, 0, 0},
  {&__pyx_kp_u__31, __pyx_k__31, sizeof(__pyx_k__31), 0, 1, 0, 0},
  {&__pyx_kp_u__4, __pyx_k__4, sizeof(__pyx_k__4), 0, 1, 0, 0},
  {&__pyx_kp_u__5, __pyx_k__5, sizeof(__pyx_k__5), 0, 1, 0, 0},
  {&__pyx_kp_u__6, __pyx_k__6, sizeof(__pyx_k__6), 0, 1, 0, 0},
  {&__pyx_kp_u__7, __pyx_k__7, sizeof(__pyx_k__7), 0, 1, 0, 0},
  {&__pyx_n_u_accept, __pyx_k_accept, sizeof(__pyx_k_accept), 0, 1, 0, 1},
  {&__pyx_kp_u_accept_language, __pyx_k_accept_language, sizeof(__pyx_k_accept_language), 0, 1, 0, 0},
  {&__pyx_kp_u_access_token, __pyx_k_access_token, sizeof(__pyx_k_access_token), 0, 1, 0, 0},
  {&__pyx_n_s_add_task, __pyx_k_add_task, sizeof(__pyx_k_add_task), 0, 0, 1, 1},
  {&__pyx_n_s_advance, __pyx_k_advance, sizeof(__pyx_k_advance), 0, 0, 1, 1},
  {&__pyx_n_s_append, __pyx_k_append, sizeof(__pyx_k_append), 0, 0, 1, 1},
  {&__pyx_n_u_authority, __pyx_k_authority, sizeof(__pyx_k_authority), 0, 1, 0, 1},
  {&__pyx_kp_u_berhasil_login_ke_tools_ini_sila, __pyx_k_berhasil_login_ke_tools_ini_sila, sizeof(__pyx_k_berhasil_login_ke_tools_ini_sila), 0, 1, 0, 0},
  {&__pyx_kp_u_berhasil_membagikan_total, __pyx_k_berhasil_membagikan_total, sizeof(__pyx_k_berhasil_membagikan_total), 0, 1, 0, 0},
  {&__pyx_kp_u_berhasil_mengubah_tema_menjadi, __pyx_k_berhasil_mengubah_tema_menjadi, sizeof(__pyx_k_berhasil_mengubah_tema_menjadi), 0, 1, 0, 0},
  {&__pyx_n_u_biru, __pyx_k_biru, sizeof(__pyx_k_biru), 0, 1, 0, 1},
  {&__pyx_n_s_bs4, __pyx_k_bs4, sizeof(__pyx_k_bs4), 0, 0, 1, 1},
  {&__pyx_kp_u_business_facebook_com, __pyx_k_business_facebook_com, sizeof(__pyx_k_business_facebook_com), 0, 1, 0, 0},
  {&__pyx_kp_u_cache_control, __pyx_k_cache_control, sizeof(__pyx_k_cache_control), 0, 1, 0, 0},
  {&__pyx_n_s_choices, __pyx_k_choices, sizeof(__pyx_k_choices), 0, 0, 1, 1},
  {&__pyx_n_u_clear, __pyx_k_clear, sizeof(__pyx_k_clear), 0, 1, 0, 1},
  {&__pyx_n_s_clear_screen, __pyx_k_clear_screen, sizeof(__pyx_k_clear_screen), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_u_clock, __pyx_k_clock, sizeof(__pyx_k_clock), 0, 1, 0, 1},
  {&__pyx_n_u_close, __pyx_k_close, sizeof(__pyx_k_close), 0, 1, 0, 1},
  {&__pyx_n_u_cls, __pyx_k_cls, sizeof(__pyx_k_cls), 0, 1, 0, 1},
  {&__pyx_n_s_cok, __pyx_k_cok, sizeof(__pyx_k_cok), 0, 0, 1, 1},
  {&__pyx_n_s_color_rich, __pyx_k_color_rich, sizeof(__pyx_k_color_rich), 0, 0, 1, 1},
  {&__pyx_n_s_color_table, __pyx_k_color_table, sizeof(__pyx_k_color_table), 0, 0, 1, 1},
  {&__pyx_n_s_concurrent_futures, __pyx_k_concurrent_futures, sizeof(__pyx_k_concurrent_futures), 0, 0, 1, 1},
  {&__pyx_n_s_console, __pyx_k_console, sizeof(__pyx_k_console), 0, 0, 1, 1},
  {&__pyx_kp_u_content_type, __pyx_k_content_type, sizeof(__pyx_k_content_type), 0, 1, 0, 0},
  {&__pyx_n_s_cookie, __pyx_k_cookie, sizeof(__pyx_k_cookie), 0, 0, 1, 1},
  {&__pyx_n_u_cookie, __pyx_k_cookie, sizeof(__pyx_k_cookie), 0, 1, 0, 1},
  {&__pyx_kp_u_cookie_tidak_valid_silahkan_cek, __pyx_k_cookie_tidak_valid_silahkan_cek, sizeof(__pyx_k_cookie_tidak_valid_silahkan_cek), 0, 1, 0, 0},
  {&__pyx_n_s_cookies, __pyx_k_cookies, sizeof(__pyx_k_cookies), 0, 0, 1, 1},
  {&__pyx_n_u_country, __pyx_k_country, sizeof(__pyx_k_country), 0, 1, 0, 1},
  {&__pyx_kp_u_dan_selamat_menikmati_tools, __pyx_k_dan_selamat_menikmati_tools, sizeof(__pyx_k_dan_selamat_menikmati_tools), 0, 1, 0, 0},
  {&__pyx_n_s_data, __pyx_k_data, sizeof(__pyx_k_data), 0, 0, 1, 1},
  {&__pyx_kp_u_data_color_rich_txt, __pyx_k_data_color_rich_txt, sizeof(__pyx_k_data_color_rich_txt), 0, 1, 0, 0},
  {&__pyx_kp_u_data_color_table_txt, __pyx_k_data_color_table_txt, sizeof(__pyx_k_data_color_table_txt), 0, 1, 0, 0},
  {&__pyx_kp_u_data_cookie_txt, __pyx_k_data_cookie_txt, sizeof(__pyx_k_data_cookie_txt), 0, 1, 0, 0},
  {&__pyx_kp_u_data_proxy_txt, __pyx_k_data_proxy_txt, sizeof(__pyx_k_data_proxy_txt), 0, 1, 0, 0},
  {&__pyx_kp_u_data_token_txt, __pyx_k_data_token_txt, sizeof(__pyx_k_data_token_txt), 0, 1, 0, 0},
  {&__pyx_n_s_date, __pyx_k_date, sizeof(__pyx_k_date), 0, 0, 1, 1},
  {&__pyx_n_s_datetime, __pyx_k_datetime, sizeof(__pyx_k_datetime), 0, 0, 1, 1},
  {&__pyx_n_s_default, __pyx_k_default, sizeof(__pyx_k_default), 0, 0, 1, 1},
  {&__pyx_n_s_des, __pyx_k_des, sizeof(__pyx_k_des), 0, 0, 1, 1},
  {&__pyx_n_s_description, __pyx_k_description, sizeof(__pyx_k_description), 0, 0, 1, 1},
  {&__pyx_n_s_e, __pyx_k_e, sizeof(__pyx_k_e), 0, 0, 1, 1},
  {&__pyx_n_s_enter, __pyx_k_enter, sizeof(__pyx_k_enter), 0, 0, 1, 1},
  {&__pyx_n_s_exceptions, __pyx_k_exceptions, sizeof(__pyx_k_exceptions), 0, 0, 1, 1},
  {&__pyx_n_s_exit, __pyx_k_exit, sizeof(__pyx_k_exit), 0, 0, 1, 1},
  {&__pyx_n_s_exit_2, __pyx_k_exit_2, sizeof(__pyx_k_exit_2), 0, 0, 1, 1},
  {&__pyx_n_s_fall, __pyx_k_fall, sizeof(__pyx_k_fall), 0, 0, 1, 1},
  {&__pyx_n_s_find_token, __pyx_k_find_token, sizeof(__pyx_k_find_token), 0, 0, 1, 1},
  {&__pyx_kp_u_ganti_tumbal, __pyx_k_ganti_tumbal, sizeof(__pyx_k_ganti_tumbal), 0, 1, 0, 0},
  {&__pyx_kp_u_ganti_warna_tema, __pyx_k_ganti_warna_tema, sizeof(__pyx_k_ganti_warna_tema), 0, 1, 0, 0},
  {&__pyx_n_s_get, __pyx_k_get, sizeof(__pyx_k_get), 0, 0, 1, 1},
  {&__pyx_kp_u_graph_facebook_com, __pyx_k_graph_facebook_com, sizeof(__pyx_k_graph_facebook_com), 0, 1, 0, 0},
  {&__pyx_n_s_group, __pyx_k_group, sizeof(__pyx_k_group), 0, 0, 1, 1},
  {&__pyx_n_s_headers, __pyx_k_headers, sizeof(__pyx_k_headers), 0, 0, 1, 1},
  {&__pyx_n_u_hijau, __pyx_k_hijau, sizeof(__pyx_k_hijau), 0, 1, 0, 1},
  {&__pyx_n_u_host, __pyx_k_host, sizeof(__pyx_k_host), 0, 1, 0, 1},
  {&__pyx_n_s_hour, __pyx_k_hour, sizeof(__pyx_k_hour), 0, 0, 1, 1},
  {&__pyx_n_s_hours, __pyx_k_hours, sizeof(__pyx_k_hours), 0, 0, 1, 1},
  {&__pyx_n_u_http, __pyx_k_http, sizeof(__pyx_k_http), 0, 1, 0, 1},
  {&__pyx_kp_u_http_ip_api_com_json, __pyx_k_http_ip_api_com_json, sizeof(__pyx_k_http_ip_api_com_json), 0, 1, 0, 0},
  {&__pyx_kp_u_https_api_proxyscrape_com_reques, __pyx_k_https_api_proxyscrape_com_reques, sizeof(__pyx_k_https_api_proxyscrape_com_reques), 0, 1, 0, 0},
  {&__pyx_kp_u_https_business_facebook_com, __pyx_k_https_business_facebook_com, sizeof(__pyx_k_https_business_facebook_com), 0, 1, 0, 0},
  {&__pyx_kp_u_https_business_facebook_com_busi, __pyx_k_https_business_facebook_com_busi, sizeof(__pyx_k_https_business_facebook_com_busi), 0, 1, 0, 0},
  {&__pyx_kp_u_https_graph_facebook_com_2136141, __pyx_k_https_graph_facebook_com_2136141, sizeof(__pyx_k_https_graph_facebook_com_2136141), 0, 1, 0, 0},
  {&__pyx_kp_u_https_graph_facebook_com_me_acce, __pyx_k_https_graph_facebook_com_me_acce, sizeof(__pyx_k_https_graph_facebook_com_me_acce), 0, 1, 0, 0},
  {&__pyx_kp_u_https_graph_facebook_com_v13_0_m, __pyx_k_https_graph_facebook_com_v13_0_m, sizeof(__pyx_k_https_graph_facebook_com_v13_0_m), 0, 1, 0, 0},
  {&__pyx_kp_u_https_raw_githubusercontent_com, __pyx_k_https_raw_githubusercontent_com, sizeof(__pyx_k_https_raw_githubusercontent_com), 0, 1, 0, 0},
  {&__pyx_kp_u_https_www_facebook_com, __pyx_k_https_www_facebook_com, sizeof(__pyx_k_https_www_facebook_com), 0, 1, 0, 0},
  {&__pyx_n_u_id, __pyx_k_id, sizeof(__pyx_k_id), 0, 1, 0, 1},
  {&__pyx_kp_u_id_ID_id_q_0_9_en_US_q_0_8_en_q, __pyx_k_id_ID_id_q_0_9_en_US_q_0_8_en_q, sizeof(__pyx_k_id_ID_id_q_0_9_en_US_q_0_8_en_q), 0, 1, 0, 0},
  {&__pyx_n_s_idt, __pyx_k_idt, sizeof(__pyx_k_idt), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_input, __pyx_k_input, sizeof(__pyx_k_input), 0, 0, 1, 1},
  {&__pyx_n_s_inquirer, __pyx_k_inquirer, sizeof(__pyx_k_inquirer), 0, 0, 1, 1},
  {&__pyx_n_u_iya, __pyx_k_iya, sizeof(__pyx_k_iya), 0, 1, 0, 1},
  {&__pyx_kp_u_jangan_munculkan_proses_share, __pyx_k_jangan_munculkan_proses_share, sizeof(__pyx_k_jangan_munculkan_proses_share), 0, 1, 0, 0},
  {&__pyx_n_s_json, __pyx_k_json, sizeof(__pyx_k_json), 0, 0, 1, 1},
  {&__pyx_kp_u_keluar_tools, __pyx_k_keluar_tools, sizeof(__pyx_k_keluar_tools), 0, 1, 0, 0},
  {&__pyx_kp_u_koneksi_internet_bermasalah_sila, __pyx_k_koneksi_internet_bermasalah_sila, sizeof(__pyx_k_koneksi_internet_bermasalah_sila), 0, 1, 0, 0},
  {&__pyx_n_u_kuning, __pyx_k_kuning, sizeof(__pyx_k_kuning), 0, 1, 0, 1},
  {&__pyx_n_s_limit, __pyx_k_limit, sizeof(__pyx_k_limit), 0, 0, 1, 1},
  {&__pyx_n_u_linux, __pyx_k_linux, sizeof(__pyx_k_linux), 0, 1, 0, 1},
  {&__pyx_n_s_loads, __pyx_k_loads, sizeof(__pyx_k_loads), 0, 0, 1, 1},
  {&__pyx_n_s_login, __pyx_k_login, sizeof(__pyx_k_login), 0, 0, 1, 1},
  {&__pyx_n_s_logo, __pyx_k_logo, sizeof(__pyx_k_logo), 0, 0, 1, 1},
  {&__pyx_n_s_loop, __pyx_k_loop, sizeof(__pyx_k_loop), 0, 0, 1, 1},
  {&__pyx_n_s_lower, __pyx_k_lower, sizeof(__pyx_k_lower), 0, 0, 1, 1},
  {&__pyx_kp_u_maaf_script_saat_ini_sedang_main, __pyx_k_maaf_script_saat_ini_sedang_main, sizeof(__pyx_k_maaf_script_saat_ini_sedang_main), 0, 1, 0, 0},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_u_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 1, 0, 1},
  {&__pyx_kp_u_masukan_cookie, __pyx_k_masukan_cookie, sizeof(__pyx_k_masukan_cookie), 0, 1, 0, 0},
  {&__pyx_kp_u_masukan_limit, __pyx_k_masukan_limit, sizeof(__pyx_k_masukan_limit), 0, 1, 0, 0},
  {&__pyx_kp_u_masukan_link, __pyx_k_masukan_link, sizeof(__pyx_k_masukan_link), 0, 1, 0, 0},
  {&__pyx_kp_u_max_age_0, __pyx_k_max_age_0, sizeof(__pyx_k_max_age_0), 0, 1, 0, 0},
  {&__pyx_n_s_max_workers, __pyx_k_max_workers, sizeof(__pyx_k_max_workers), 0, 0, 1, 1},
  {&__pyx_kp_u_membagikan_postingan_dengan_id_p, __pyx_k_membagikan_postingan_dengan_id_p, sizeof(__pyx_k_membagikan_postingan_dengan_id_p), 0, 1, 0, 0},
  {&__pyx_n_s_men, __pyx_k_men, sizeof(__pyx_k_men), 0, 0, 1, 1},
  {&__pyx_n_s_menu, __pyx_k_menu, sizeof(__pyx_k_menu), 0, 0, 1, 1},
  {&__pyx_n_u_menu, __pyx_k_menu, sizeof(__pyx_k_menu), 0, 1, 0, 1},
  {&__pyx_n_u_merah, __pyx_k_merah, sizeof(__pyx_k_merah), 0, 1, 0, 1},
  {&__pyx_n_s_message, __pyx_k_message, sizeof(__pyx_k_message), 0, 0, 1, 1},
  {&__pyx_n_s_mun, __pyx_k_mun, sizeof(__pyx_k_mun), 0, 0, 1, 1},
  {&__pyx_n_s_muncul, __pyx_k_muncul, sizeof(__pyx_k_muncul), 0, 0, 1, 1},
  {&__pyx_n_u_muncul, __pyx_k_muncul, sizeof(__pyx_k_muncul), 0, 1, 0, 1},
  {&__pyx_kp_u_munculkan_proses_share, __pyx_k_munculkan_proses_share, sizeof(__pyx_k_munculkan_proses_share), 0, 1, 0, 0},
  {&__pyx_n_s_nama, __pyx_k_nama, sizeof(__pyx_k_nama), 0, 0, 1, 1},
  {&__pyx_n_u_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 1, 0, 1},
  {&__pyx_n_s_name_2, __pyx_k_name_2, sizeof(__pyx_k_name_2), 0, 0, 1, 1},
  {&__pyx_n_s_negara, __pyx_k_negara, sizeof(__pyx_k_negara), 0, 0, 1, 1},
  {&__pyx_n_s_now, __pyx_k_now, sizeof(__pyx_k_now), 0, 0, 1, 1},
  {&__pyx_n_s_open, __pyx_k_open, sizeof(__pyx_k_open), 0, 0, 1, 1},
  {&__pyx_n_u_oren, __pyx_k_oren, sizeof(__pyx_k_oren), 0, 1, 0, 1},
  {&__pyx_n_u_origin, __pyx_k_origin, sizeof(__pyx_k_origin), 0, 1, 0, 1},
  {&__pyx_n_s_os, __pyx_k_os, sizeof(__pyx_k_os), 0, 0, 1, 1},
  {&__pyx_n_s_padding, __pyx_k_padding, sizeof(__pyx_k_padding), 0, 0, 1, 1},
  {&__pyx_n_s_parser, __pyx_k_parser, sizeof(__pyx_k_parser), 0, 0, 1, 1},
  {&__pyx_kp_u_pilih_menu, __pyx_k_pilih_menu, sizeof(__pyx_k_pilih_menu), 0, 1, 0, 0},
  {&__pyx_kp_u_pilih_warna, __pyx_k_pilih_warna, sizeof(__pyx_k_pilih_warna), 0, 1, 0, 0},
  {&__pyx_n_u_pink, __pyx_k_pink, sizeof(__pyx_k_pink), 0, 1, 0, 1},
  {&__pyx_n_s_platform, __pyx_k_platform, sizeof(__pyx_k_platform), 0, 0, 1, 1},
  {&__pyx_n_s_post, __pyx_k_post, sizeof(__pyx_k_post), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_s_prints, __pyx_k_prints, sizeof(__pyx_k_prints), 0, 0, 1, 1},
  {&__pyx_n_s_prog, __pyx_k_prog, sizeof(__pyx_k_prog), 0, 0, 1, 1},
  {&__pyx_n_s_prompt, __pyx_k_prompt, sizeof(__pyx_k_prompt), 0, 0, 1, 1},
  {&__pyx_kp_u_proses_share, __pyx_k_proses_share, sizeof(__pyx_k_proses_share), 0, 1, 0, 0},
  {&__pyx_n_s_prox, __pyx_k_prox, sizeof(__pyx_k_prox), 0, 0, 1, 1},
  {&__pyx_n_s_proxies, __pyx_k_proxies, sizeof(__pyx_k_proxies), 0, 0, 1, 1},
  {&__pyx_n_s_proxy, __pyx_k_proxy, sizeof(__pyx_k_proxy), 0, 0, 1, 1},
  {&__pyx_kp_u_published_0_access_token, __pyx_k_published_0_access_token, sizeof(__pyx_k_published_0_access_token), 0, 1, 0, 0},
  {&__pyx_n_u_putih, __pyx_k_putih, sizeof(__pyx_k_putih), 0, 1, 0, 1},
  {&__pyx_n_u_query, __pyx_k_query, sizeof(__pyx_k_query), 0, 1, 0, 1},
  {&__pyx_n_u_r, __pyx_k_r, sizeof(__pyx_k_r), 0, 1, 0, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_re, __pyx_k_re, sizeof(__pyx_k_re), 0, 0, 1, 1},
  {&__pyx_n_s_read, __pyx_k_read, sizeof(__pyx_k_read), 0, 0, 1, 1},
  {&__pyx_n_u_referer, __pyx_k_referer, sizeof(__pyx_k_referer), 0, 1, 0, 1},
  {&__pyx_n_s_requests, __pyx_k_requests, sizeof(__pyx_k_requests), 0, 0, 1, 1},
  {&__pyx_n_s_reset, __pyx_k_reset, sizeof(__pyx_k_reset), 0, 0, 1, 1},
  {&__pyx_n_s_rich, __pyx_k_rich, sizeof(__pyx_k_rich), 0, 0, 1, 1},
  {&__pyx_n_s_rich_console, __pyx_k_rich_console, sizeof(__pyx_k_rich_console), 0, 0, 1, 1},
  {&__pyx_n_s_rich_panel, __pyx_k_rich_panel, sizeof(__pyx_k_rich_panel), 0, 0, 1, 1},
  {&__pyx_n_s_rich_progress, __pyx_k_rich_progress, sizeof(__pyx_k_rich_progress), 0, 0, 1, 1},
  {&__pyx_n_s_rich_tree, __pyx_k_rich_tree, sizeof(__pyx_k_rich_tree), 0, 0, 1, 1},
  {&__pyx_kp_u_rm_f_data_token_txt_data_cookie, __pyx_k_rm_f_data_token_txt_data_cookie, sizeof(__pyx_k_rm_f_data_token_txt_data_cookie), 0, 1, 0, 0},
  {&__pyx_n_s_search, __pyx_k_search, sizeof(__pyx_k_search), 0, 0, 1, 1},
  {&__pyx_kp_u_sec_ch_ua_mobile, __pyx_k_sec_ch_ua_mobile, sizeof(__pyx_k_sec_ch_ua_mobile), 0, 1, 0, 0},
  {&__pyx_kp_u_selamat_malam, __pyx_k_selamat_malam, sizeof(__pyx_k_selamat_malam), 0, 1, 0, 0},
  {&__pyx_kp_u_selamat_pagi, __pyx_k_selamat_pagi, sizeof(__pyx_k_selamat_pagi), 0, 1, 0, 0},
  {&__pyx_kp_u_selamat_siang, __pyx_k_selamat_siang, sizeof(__pyx_k_selamat_siang), 0, 1, 0, 0},
  {&__pyx_kp_u_selamat_sore, __pyx_k_selamat_sore, sizeof(__pyx_k_selamat_sore), 0, 1, 0, 0},
  {&__pyx_n_s_ses, __pyx_k_ses, sizeof(__pyx_k_ses), 0, 0, 1, 1},
  {&__pyx_n_s_share, __pyx_k_share, sizeof(__pyx_k_share), 0, 0, 1, 1},
  {&__pyx_n_s_share_cepat, __pyx_k_share_cepat, sizeof(__pyx_k_share_cepat), 0, 0, 1, 1},
  {&__pyx_n_s_share_lambat, __pyx_k_share_lambat, sizeof(__pyx_k_share_lambat), 0, 0, 1, 1},
  {&__pyx_kp_u_share_postingan_cepat, __pyx_k_share_postingan_cepat, sizeof(__pyx_k_share_postingan_cepat), 0, 1, 0, 0},
  {&__pyx_kp_u_share_postingan_lambat, __pyx_k_share_postingan_lambat, sizeof(__pyx_k_share_postingan_lambat), 0, 1, 0, 0},
  {&__pyx_kp_s_share_py, __pyx_k_share_py, sizeof(__pyx_k_share_py), 0, 0, 1, 0},
  {&__pyx_kp_u_share_silahkan_jalankan_ulang_t, __pyx_k_share_silahkan_jalankan_ulang_t, sizeof(__pyx_k_share_silahkan_jalankan_ulang_t), 0, 1, 0, 0},
  {&__pyx_kp_u_silahkan_jalankan_ulang_tools_i, __pyx_k_silahkan_jalankan_ulang_tools_i, sizeof(__pyx_k_silahkan_jalankan_ulang_tools_i), 0, 1, 0, 0},
  {&__pyx_n_s_sleep, __pyx_k_sleep, sizeof(__pyx_k_sleep), 0, 0, 1, 1},
  {&__pyx_kp_u_socks5_random_choice_prox, __pyx_k_socks5_random_choice_prox, sizeof(__pyx_k_socks5_random_choice_prox), 0, 1, 0, 0},
  {&__pyx_n_s_splitlines, __pyx_k_splitlines, sizeof(__pyx_k_splitlines), 0, 0, 1, 1},
  {&__pyx_n_s_style, __pyx_k_style, sizeof(__pyx_k_style), 0, 0, 1, 1},
  {&__pyx_n_s_submit, __pyx_k_submit, sizeof(__pyx_k_submit), 0, 0, 1, 1},
  {&__pyx_n_s_subtitle, __pyx_k_subtitle, sizeof(__pyx_k_subtitle), 0, 0, 1, 1},
  {&__pyx_n_s_sys, __pyx_k_sys, sizeof(__pyx_k_sys), 0, 0, 1, 1},
  {&__pyx_n_s_system, __pyx_k_system, sizeof(__pyx_k_system), 0, 0, 1, 1},
  {&__pyx_n_s_tanya, __pyx_k_tanya, sizeof(__pyx_k_tanya), 0, 0, 1, 1},
  {&__pyx_kp_u_task_description, __pyx_k_task_description, sizeof(__pyx_k_task_description), 0, 1, 0, 0},
  {&__pyx_kp_u_task_percentage_0f, __pyx_k_task_percentage_0f, sizeof(__pyx_k_task_percentage_0f), 0, 1, 0, 0},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 0, 1, 1},
  {&__pyx_kp_u_text_html_application_xhtml_xml, __pyx_k_text_html_application_xhtml_xml, sizeof(__pyx_k_text_html_application_xhtml_xml), 0, 1, 0, 0},
  {&__pyx_kp_u_text_html_charset_utf_8, __pyx_k_text_html_charset_utf_8, sizeof(__pyx_k_text_html_charset_utf_8), 0, 1, 0, 0},
  {&__pyx_kp_u_this_script_only_work_in_Indones, __pyx_k_this_script_only_work_in_Indones, sizeof(__pyx_k_this_script_only_work_in_Indones), 0, 1, 0, 0},
  {&__pyx_n_s_threading, __pyx_k_threading, sizeof(__pyx_k_threading), 0, 0, 1, 1},
  {&__pyx_n_s_time, __pyx_k_time, sizeof(__pyx_k_time), 0, 0, 1, 1},
  {&__pyx_n_s_timenow, __pyx_k_timenow, sizeof(__pyx_k_timenow), 0, 0, 1, 1},
  {&__pyx_n_s_tinyi, __pyx_k_tinyi, sizeof(__pyx_k_tinyi), 0, 0, 1, 1},
  {&__pyx_n_s_title, __pyx_k_title, sizeof(__pyx_k_title), 0, 0, 1, 1},
  {&__pyx_n_s_token, __pyx_k_token, sizeof(__pyx_k_token), 0, 0, 1, 1},
  {&__pyx_n_s_total, __pyx_k_total, sizeof(__pyx_k_total), 0, 0, 1, 1},
  {&__pyx_n_u_ungu, __pyx_k_ungu, sizeof(__pyx_k_ungu), 0, 1, 0, 1},
  {&__pyx_n_s_update, __pyx_k_update, sizeof(__pyx_k_update), 0, 0, 1, 1},
  {&__pyx_kp_u_upgrade_insecure_requests, __pyx_k_upgrade_insecure_requests, sizeof(__pyx_k_upgrade_insecure_requests), 0, 1, 0, 0},
  {&__pyx_n_s_url, __pyx_k_url, sizeof(__pyx_k_url), 0, 0, 1, 1},
  {&__pyx_kp_u_user_agent, __pyx_k_user_agent, sizeof(__pyx_k_user_agent), 0, 1, 0, 0},
  {&__pyx_n_u_w, __pyx_k_w, sizeof(__pyx_k_w), 0, 1, 0, 1},
  {&__pyx_n_s_waktu, __pyx_k_waktu, sizeof(__pyx_k_waktu), 0, 0, 1, 1},
  {&__pyx_n_s_war, __pyx_k_war, sizeof(__pyx_k_war), 0, 0, 1, 1},
  {&__pyx_n_s_warna, __pyx_k_warna, sizeof(__pyx_k_warna), 0, 0, 1, 1},
  {&__pyx_n_u_warna, __pyx_k_warna, sizeof(__pyx_k_warna), 0, 1, 0, 1},
  {&__pyx_n_s_width, __pyx_k_width, sizeof(__pyx_k_width), 0, 0, 1, 1},
  {&__pyx_n_u_win, __pyx_k_win, sizeof(__pyx_k_win), 0, 1, 0, 1},
  {&__pyx_n_s_write, __pyx_k_write, sizeof(__pyx_k_write), 0, 0, 1, 1},
  {&__pyx_n_s_z, __pyx_k_z, sizeof(__pyx_k_z), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_open = __Pyx_GetBuiltinName(__pyx_n_s_open); if (!__pyx_builtin_open) __PYX_ERR(0, 49, __pyx_L1_error)
  __pyx_builtin_exit = __Pyx_GetBuiltinName(__pyx_n_s_exit); if (!__pyx_builtin_exit) __PYX_ERR(0, 62, __pyx_L1_error)
  __pyx_builtin_input = __Pyx_GetBuiltinName(__pyx_n_s_input); if (!__pyx_builtin_input) __PYX_ERR(0, 120, __pyx_L1_error)
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 164, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  
  __pyx_tuple__8 = PyTuple_Pack(2, __pyx_int_0, __pyx_int_29); if (unlikely(!__pyx_tuple__8)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__8);
  __Pyx_GIVEREF(__pyx_tuple__8);

  
  __pyx_tuple__9 = PyTuple_Pack(1, __pyx_kp_u_masukan_cookie); if (unlikely(!__pyx_tuple__9)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__9);
  __Pyx_GIVEREF(__pyx_tuple__9);

  
  __pyx_tuple__10 = PyTuple_Pack(1, __pyx_kp_u_https_business_facebook_com_busi); if (unlikely(!__pyx_tuple__10)) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__10);
  __Pyx_GIVEREF(__pyx_tuple__10);

  
  __pyx_tuple__11 = PyTuple_Pack(2, __pyx_kp_u_data_token_txt, __pyx_n_u_w); if (unlikely(!__pyx_tuple__11)) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__11);
  __Pyx_GIVEREF(__pyx_tuple__11);

  
  __pyx_tuple__12 = PyTuple_Pack(2, __pyx_kp_u_data_cookie_txt, __pyx_n_u_w); if (unlikely(!__pyx_tuple__12)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__12);
  __Pyx_GIVEREF(__pyx_tuple__12);

  
  __pyx_ustring__13 = PyUnicode_FromUnicode(__pyx_k__14, (sizeof(__pyx_k__14) / sizeof(Py_UNICODE))-1); if (unlikely(!__pyx_ustring__13)) __PYX_ERR(0, 132, __pyx_L1_error)
  if (__Pyx_PyUnicode_READY(__pyx_ustring__13) < 0) __PYX_ERR(0, 132, __pyx_L1_error)

  
  __pyx_tuple__15 = PyTuple_Pack(2, __pyx_kp_u_data_token_txt, __pyx_n_u_r); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 141, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);

  
  __pyx_tuple__16 = PyTuple_Pack(2, __pyx_kp_u_data_cookie_txt, __pyx_n_u_r); if (unlikely(!__pyx_tuple__16)) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__16);
  __Pyx_GIVEREF(__pyx_tuple__16);

  
  __pyx_ustring__17 = PyUnicode_FromUnicode(__pyx_k__14, (sizeof(__pyx_k__14) / sizeof(Py_UNICODE))-1); if (unlikely(!__pyx_ustring__17)) __PYX_ERR(0, 147, __pyx_L1_error)
  if (__Pyx_PyUnicode_READY(__pyx_ustring__17) < 0) __PYX_ERR(0, 147, __pyx_L1_error)

  
  __pyx_tuple__19 = PyTuple_Pack(1, __pyx_n_u_menu); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 151, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);

  
  __pyx_tuple__23 = PyTuple_Pack(1, __pyx_n_u_muncul); if (unlikely(!__pyx_tuple__23)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__23);
  __Pyx_GIVEREF(__pyx_tuple__23);

  
  __pyx_tuple__24 = PyTuple_Pack(1, __pyx_kp_u__20); if (unlikely(!__pyx_tuple__24)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__24);
  __Pyx_GIVEREF(__pyx_tuple__24);

  
  __pyx_tuple__25 = PyTuple_Pack(3, Py_None, Py_None, Py_None); if (unlikely(!__pyx_tuple__25)) __PYX_ERR(0, 163, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__25);
  __Pyx_GIVEREF(__pyx_tuple__25);

  
  __pyx_tuple__26 = PyTuple_Pack(1, __pyx_n_u_warna); if (unlikely(!__pyx_tuple__26)) __PYX_ERR(0, 191, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__26);
  __Pyx_GIVEREF(__pyx_tuple__26);

  
  __pyx_tuple__27 = PyTuple_Pack(2, __pyx_kp_u_data_color_rich_txt, __pyx_n_u_w); if (unlikely(!__pyx_tuple__27)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__27);
  __Pyx_GIVEREF(__pyx_tuple__27);

  
  __pyx_tuple__28 = PyTuple_Pack(2, __pyx_kp_u_data_color_table_txt, __pyx_n_u_w); if (unlikely(!__pyx_tuple__28)) __PYX_ERR(0, 195, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__28);
  __Pyx_GIVEREF(__pyx_tuple__28);

  
  __pyx_tuple__30 = PyTuple_Pack(2, __pyx_kp_u_data_proxy_txt, __pyx_n_u_r); if (unlikely(!__pyx_tuple__30)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__30);
  __Pyx_GIVEREF(__pyx_tuple__30);

  
  __pyx_tuple__32 = PyTuple_Pack(1, __pyx_kp_u_http_ip_api_com_json); if (unlikely(!__pyx_tuple__32)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__32);
  __Pyx_GIVEREF(__pyx_tuple__32);

  
  __pyx_tuple__33 = PyTuple_Pack(2, __pyx_kp_u_data_color_rich_txt, __pyx_n_u_r); if (unlikely(!__pyx_tuple__33)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__33);
  __Pyx_GIVEREF(__pyx_tuple__33);

  
  __pyx_tuple__34 = PyTuple_Pack(2, __pyx_kp_u_data_color_table_txt, __pyx_n_u_r); if (unlikely(!__pyx_tuple__34)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__34);
  __Pyx_GIVEREF(__pyx_tuple__34);

  
  __pyx_tuple__35 = PyTuple_Pack(1, __pyx_kp_u_https_raw_githubusercontent_com); if (unlikely(!__pyx_tuple__35)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__35);
  __Pyx_GIVEREF(__pyx_tuple__35);

  
  __pyx_ustring__36 = PyUnicode_FromUnicode(__pyx_k__14, (sizeof(__pyx_k__14) / sizeof(Py_UNICODE))-1); if (unlikely(!__pyx_ustring__36)) __PYX_ERR(0, 61, __pyx_L1_error)
  if (__Pyx_PyUnicode_READY(__pyx_ustring__36) < 0) __PYX_ERR(0, 61, __pyx_L1_error)

  
  __pyx_ustring__37 = PyUnicode_FromUnicode(__pyx_k__14, (sizeof(__pyx_k__14) / sizeof(Py_UNICODE))-1); if (unlikely(!__pyx_ustring__37)) __PYX_ERR(0, 64, __pyx_L1_error)
  if (__Pyx_PyUnicode_READY(__pyx_ustring__37) < 0) __PYX_ERR(0, 64, __pyx_L1_error)

  
  __pyx_ustring__38 = PyUnicode_FromUnicode(__pyx_k__14, (sizeof(__pyx_k__14) / sizeof(Py_UNICODE))-1); if (unlikely(!__pyx_ustring__38)) __PYX_ERR(0, 71, __pyx_L1_error)
  if (__Pyx_PyUnicode_READY(__pyx_ustring__38) < 0) __PYX_ERR(0, 71, __pyx_L1_error)

  
  __pyx_ustring__39 = PyUnicode_FromUnicode(__pyx_k__14, (sizeof(__pyx_k__14) / sizeof(Py_UNICODE))-1); if (unlikely(!__pyx_ustring__39)) __PYX_ERR(0, 73, __pyx_L1_error)
  if (__Pyx_PyUnicode_READY(__pyx_ustring__39) < 0) __PYX_ERR(0, 73, __pyx_L1_error)

  
  __pyx_tuple__40 = PyTuple_Pack(1, __pyx_kp_u_https_api_proxyscrape_com_reques); if (unlikely(!__pyx_tuple__40)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__40);
  __Pyx_GIVEREF(__pyx_tuple__40);

  
  __pyx_tuple__41 = PyTuple_Pack(2, __pyx_kp_u_data_proxy_txt, __pyx_n_u_w); if (unlikely(!__pyx_tuple__41)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__41);
  __Pyx_GIVEREF(__pyx_tuple__41);

  
  __pyx_codeobj__42 = (PyObject*)__Pyx_PyCode_New(0, 0, 0, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_share_py, __pyx_n_s_clear_screen, 84, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__42)) __PYX_ERR(0, 84, __pyx_L1_error)

  
  __pyx_tuple__43 = PyTuple_Pack(3, __pyx_n_s_now, __pyx_n_s_hours, __pyx_n_s_timenow); if (unlikely(!__pyx_tuple__43)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__43);
  __Pyx_GIVEREF(__pyx_tuple__43);
  __pyx_codeobj__44 = (PyObject*)__Pyx_PyCode_New(0, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__43, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_share_py, __pyx_n_s_waktu, 96, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__44)) __PYX_ERR(0, 96, __pyx_L1_error)

  
  __pyx_codeobj__45 = (PyObject*)__Pyx_PyCode_New(0, 0, 0, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_share_py, __pyx_n_s_logo, 106, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__45)) __PYX_ERR(0, 106, __pyx_L1_error)

  
  __pyx_tuple__46 = PyTuple_Pack(3, __pyx_n_s_cookie, __pyx_n_s_data, __pyx_n_s_find_token); if (unlikely(!__pyx_tuple__46)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__46);
  __Pyx_GIVEREF(__pyx_tuple__46);
  __pyx_codeobj__47 = (PyObject*)__Pyx_PyCode_New(0, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__46, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_share_py, __pyx_n_s_login, 118, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__47)) __PYX_ERR(0, 118, __pyx_L1_error)

  
  __pyx_tuple__48 = PyTuple_Pack(15, __pyx_n_s_ses, __pyx_n_s_token, __pyx_n_s_cok, __pyx_n_s_cookie, __pyx_n_s_nama, __pyx_n_s_e, __pyx_n_s_men, __pyx_n_s_tanya, __pyx_n_s_idt, __pyx_n_s_mun, __pyx_n_s_tinyi, __pyx_n_s_fall, __pyx_n_s_z, __pyx_n_s_war, __pyx_n_s_warna); if (unlikely(!__pyx_tuple__48)) __PYX_ERR(0, 136, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__48);
  __Pyx_GIVEREF(__pyx_tuple__48);
  __pyx_codeobj__49 = (PyObject*)__Pyx_PyCode_New(0, 0, 15, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__48, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_share_py, __pyx_n_s_menu, 136, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__49)) __PYX_ERR(0, 136, __pyx_L1_error)

  
  __pyx_tuple__50 = PyTuple_Pack(8, __pyx_n_s_token, __pyx_n_s_cookie, __pyx_n_s_idt, __pyx_n_s_prox, __pyx_n_s_ses, __pyx_n_s_proxy, __pyx_n_s_post, __pyx_n_s_data); if (unlikely(!__pyx_tuple__50)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__50);
  __Pyx_GIVEREF(__pyx_tuple__50);
  __pyx_codeobj__51 = (PyObject*)__Pyx_PyCode_New(3, 0, 8, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__50, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_share_py, __pyx_n_s_share_cepat, 226, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__51)) __PYX_ERR(0, 226, __pyx_L1_error)

  
  __pyx_tuple__52 = PyTuple_Pack(8, __pyx_n_s_token, __pyx_n_s_cookie, __pyx_n_s_idt, __pyx_n_s_prox, __pyx_n_s_ses, __pyx_n_s_proxy, __pyx_n_s_post, __pyx_n_s_data); if (unlikely(!__pyx_tuple__52)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__52);
  __Pyx_GIVEREF(__pyx_tuple__52);
  __pyx_codeobj__53 = (PyObject*)__Pyx_PyCode_New(3, 0, 8, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__52, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_share_py, __pyx_n_s_share_lambat, 252, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__53)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_3 = PyInt_FromLong(3); if (unlikely(!__pyx_int_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4 = PyInt_FromLong(4); if (unlikely(!__pyx_int_4)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_5 = PyInt_FromLong(5); if (unlikely(!__pyx_int_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_12 = PyInt_FromLong(12); if (unlikely(!__pyx_int_12)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_15 = PyInt_FromLong(15); if (unlikely(!__pyx_int_15)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_18 = PyInt_FromLong(18); if (unlikely(!__pyx_int_18)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_29 = PyInt_FromLong(29); if (unlikely(!__pyx_int_29)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_30 = PyInt_FromLong(30); if (unlikely(!__pyx_int_30)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_80 = PyInt_FromLong(80); if (unlikely(!__pyx_int_80)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); 

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initshare(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC initshare(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_share(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC PyInit_share(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_share(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  int __pyx_t_9;
  int __pyx_t_10;
  Py_ssize_t __pyx_t_11;
  Py_UCS4 __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'share' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_share(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  
  
  #if defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  #ifdef WITH_THREAD 
  PyEval_InitThreads();
  #endif
  #endif
  
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("share", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_share) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name_2, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "share")) {
      if (unlikely(PyDict_SetItemString(modules, "share", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  (void)__Pyx_modinit_type_init_code();
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_os, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_os, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sys, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sys, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_re, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_re, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_requests, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_requests, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_json, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_json, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_bs4, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_bs4, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_threading, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_threading, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_datetime, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_datetime, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_time, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_time, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_inquirer, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_inquirer, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_date);
  __Pyx_GIVEREF(__pyx_n_s_date);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_date);
  __Pyx_INCREF(__pyx_n_s_datetime);
  __Pyx_GIVEREF(__pyx_n_s_datetime);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_datetime);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_datetime, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_date); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_date, __pyx_t_1) < 0) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_datetime); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_datetime, __pyx_t_1) < 0) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_ThreadPoolExecutor);
  __Pyx_GIVEREF(__pyx_n_s_ThreadPoolExecutor);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_ThreadPoolExecutor);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_concurrent_futures, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_ThreadPoolExecutor); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ThreadPoolExecutor, __pyx_t_2) < 0) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_sleep);
  __Pyx_GIVEREF(__pyx_n_s_sleep);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_sleep);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_time, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_sleep); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sleep, __pyx_t_1) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_Thread);
  __Pyx_GIVEREF(__pyx_n_s_Thread);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_Thread);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_threading, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_Thread); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Thread, __pyx_t_2) < 0) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_BeautifulSoup);
  __Pyx_GIVEREF(__pyx_n_s_BeautifulSoup);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_BeautifulSoup);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_bs4, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_BeautifulSoup); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_parser, __pyx_t_1) < 0) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_requests); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ses, __pyx_t_2) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_Panel);
  __Pyx_GIVEREF(__pyx_n_s_Panel);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_Panel);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_rich_panel, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_Panel); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Panel, __pyx_t_2) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Tree);
  __Pyx_GIVEREF(__pyx_n_s_Tree);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Tree);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_rich_tree, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Tree); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Tree, __pyx_t_1) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_print);
  __Pyx_GIVEREF(__pyx_n_s_print);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_print);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_rich, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_print); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_prints, __pyx_t_2) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Console);
  __Pyx_GIVEREF(__pyx_n_s_Console);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Console);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_rich_console, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Console); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Console, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_Progress);
  __Pyx_GIVEREF(__pyx_n_s_Progress);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_Progress);
  __Pyx_INCREF(__pyx_n_s_SpinnerColumn);
  __Pyx_GIVEREF(__pyx_n_s_SpinnerColumn);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_n_s_SpinnerColumn);
  __Pyx_INCREF(__pyx_n_s_BarColumn);
  __Pyx_GIVEREF(__pyx_n_s_BarColumn);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_n_s_BarColumn);
  __Pyx_INCREF(__pyx_n_s_TextColumn);
  __Pyx_GIVEREF(__pyx_n_s_TextColumn);
  PyList_SET_ITEM(__pyx_t_2, 3, __pyx_n_s_TextColumn);
  __Pyx_INCREF(__pyx_n_s_TimeElapsedColumn);
  __Pyx_GIVEREF(__pyx_n_s_TimeElapsedColumn);
  PyList_SET_ITEM(__pyx_t_2, 4, __pyx_n_s_TimeElapsedColumn);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_rich_progress, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_Progress); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Progress, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_SpinnerColumn); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_SpinnerColumn, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_BarColumn); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_BarColumn, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_TextColumn); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TextColumn, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_TimeElapsedColumn); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TimeElapsedColumn, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Console); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_console, __pyx_t_2) < 0) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_P, __pyx_kp_u_1_97m) < 0) __PYX_ERR(0, 19, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_M, __pyx_kp_u_1_91m) < 0) __PYX_ERR(0, 20, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_H, __pyx_kp_u_1_92m) < 0) __PYX_ERR(0, 21, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_K, __pyx_kp_u_1_93m) < 0) __PYX_ERR(0, 22, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_B, __pyx_kp_u_1_94m) < 0) __PYX_ERR(0, 23, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_U, __pyx_kp_u_1_95m) < 0) __PYX_ERR(0, 24, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_O, __pyx_kp_u_1_96m) < 0) __PYX_ERR(0, 25, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_N, __pyx_kp_u_0m) < 0) __PYX_ERR(0, 26, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Z2, __pyx_kp_u_000000) < 0) __PYX_ERR(0, 29, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_M2, __pyx_kp_u_FF0000) < 0) __PYX_ERR(0, 30, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_H2, __pyx_kp_u_00FF00) < 0) __PYX_ERR(0, 31, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_K2, __pyx_kp_u_FFFF00) < 0) __PYX_ERR(0, 32, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_B2, __pyx_kp_u_00C8FF) < 0) __PYX_ERR(0, 33, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_U2, __pyx_kp_u_AF00FF) < 0) __PYX_ERR(0, 34, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_N2, __pyx_kp_u_FF00FF) < 0) __PYX_ERR(0, 35, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_O2, __pyx_kp_u_00FFFF) < 0) __PYX_ERR(0, 36, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_P2, __pyx_kp_u_FFFFFF) < 0) __PYX_ERR(0, 37, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_J2, __pyx_kp_u_FF8F00) < 0) __PYX_ERR(0, 38, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_A2, __pyx_kp_u_AAAAAA) < 0) __PYX_ERR(0, 39, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_loop, __pyx_int_0) < 0) __PYX_ERR(0, 42, __pyx_L1_error)

  
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_muncul, __pyx_t_2) < 0) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_reset, __pyx_kp_u__31) < 0) __PYX_ERR(0, 44, __pyx_L1_error)

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_requests); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_json); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_query); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_IP, __pyx_t_1) < 0) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_3, &__pyx_t_4, &__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
     {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__33, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 49, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_read); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 49, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 49, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_color_rich, __pyx_t_1) < 0) __PYX_ERR(0, 49, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    goto __pyx_L7_try_end;
    __pyx_L2_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;

    
    __Pyx_ErrFetch(&__pyx_t_1, &__pyx_t_2, &__pyx_t_6);
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_FileNotFoundError); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 50, __pyx_L4_except_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_8 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_1, __pyx_t_7);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_ErrRestore(__pyx_t_1, __pyx_t_2, __pyx_t_6);
    __pyx_t_1 = 0; __pyx_t_2 = 0; __pyx_t_6 = 0;
    if (__pyx_t_8) {
      __Pyx_AddTraceback("share", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_6, &__pyx_t_2, &__pyx_t_1) < 0) __PYX_ERR(0, 50, __pyx_L4_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_1);

      
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_color_rich, __pyx_kp_u_00C8FF) < 0) __PYX_ERR(0, 51, __pyx_L4_except_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L3_exception_handled;
    }
    goto __pyx_L4_except_error;
    __pyx_L4_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    goto __pyx_L1_error;
    __pyx_L3_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    __pyx_L7_try_end:;
  }

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_5, &__pyx_t_4, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_3);
     {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_read); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 53, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_color_table, __pyx_t_1) < 0) __PYX_ERR(0, 53, __pyx_L10_error)
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L15_try_end;
    __pyx_L10_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
    __Pyx_ErrFetch(&__pyx_t_1, &__pyx_t_2, &__pyx_t_6);
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_FileNotFoundError); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 54, __pyx_L12_except_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_8 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_1, __pyx_t_7);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_ErrRestore(__pyx_t_1, __pyx_t_2, __pyx_t_6);
    __pyx_t_1 = 0; __pyx_t_2 = 0; __pyx_t_6 = 0;
    if (__pyx_t_8) {
      __Pyx_AddTraceback("share", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_6, &__pyx_t_2, &__pyx_t_1) < 0) __PYX_ERR(0, 54, __pyx_L12_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_1);

      
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_color_table, __pyx_kp_u_00C8FF_2) < 0) __PYX_ERR(0, 55, __pyx_L12_except_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L11_exception_handled;
    }
    goto __pyx_L12_except_error;
    __pyx_L12_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_4, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L11_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_4, __pyx_t_3);
    __pyx_L15_try_end:;
  }

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_3, &__pyx_t_4, &__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_requests); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 59, __pyx_L18_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_get); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 59, __pyx_L18_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__35, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 59, __pyx_L18_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 59, __pyx_L18_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_data, __pyx_t_2) < 0) __PYX_ERR(0, 59, __pyx_L18_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 60, __pyx_L18_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_close, __pyx_t_2, Py_EQ)); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 60, __pyx_L18_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_10 = (__pyx_t_9 != 0);
      if (__pyx_t_10) {

        
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_prints); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Panel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_6 = PyTuple_New(3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_11 = 0;
        __pyx_t_12 = 127;
        __Pyx_INCREF(__pyx_ustring__36);
        __pyx_t_12 = (1114111 > __pyx_t_12) ? 1114111 : __pyx_t_12;
        __pyx_t_11 += 2;
        __Pyx_GIVEREF(__pyx_ustring__36);
        PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_ustring__36);
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_M2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_13 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_12 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_13) > __pyx_t_12) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_13) : __pyx_t_12;
        __pyx_t_11 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_13);
        __Pyx_GIVEREF(__pyx_t_13);
        PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_13);
        __pyx_t_13 = 0;
        __Pyx_INCREF(__pyx_kp_u_maaf_script_saat_ini_sedang_main);
        __pyx_t_11 += 66;
        __Pyx_GIVEREF(__pyx_kp_u_maaf_script_saat_ini_sedang_main);
        PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_kp_u_maaf_script_saat_ini_sedang_main);
        __pyx_t_13 = __Pyx_PyUnicode_Join(__pyx_t_6, 3, __pyx_t_11, __pyx_t_12); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __pyx_t_6 = PyTuple_New(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_GIVEREF(__pyx_t_13);
        PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_13);
        __pyx_t_13 = 0;
        __pyx_t_13 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_13);
        if (PyDict_SetItem(__pyx_t_13, __pyx_n_s_width, __pyx_int_80) < 0) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_color_table); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (PyDict_SetItem(__pyx_t_13, __pyx_n_s_style, __pyx_t_14) < 0) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_6, __pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
        __pyx_t_13 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_14); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 61, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;

        
        __pyx_t_13 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 62, __pyx_L18_error)
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;

        
      }

      
    }
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    goto __pyx_L23_try_end;
    __pyx_L18_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
    __Pyx_ErrFetch(&__pyx_t_13, &__pyx_t_14, &__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_requests); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 63, __pyx_L20_except_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_exceptions); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L20_except_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_ConnectionError); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 63, __pyx_L20_except_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_8 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_13, __pyx_t_6);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_ErrRestore(__pyx_t_13, __pyx_t_14, __pyx_t_2);
    __pyx_t_13 = 0; __pyx_t_14 = 0; __pyx_t_2 = 0;
    if (__pyx_t_8) {
      __Pyx_AddTraceback("share", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_14, &__pyx_t_13) < 0) __PYX_ERR(0, 63, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_GOTREF(__pyx_t_13);

      
      __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_prints); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Panel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_7 = PyTuple_New(3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_11 = 0;
      __pyx_t_12 = 127;
      __Pyx_INCREF(__pyx_ustring__37);
      __pyx_t_12 = (1114111 > __pyx_t_12) ? 1114111 : __pyx_t_12;
      __pyx_t_11 += 2;
      __Pyx_GIVEREF(__pyx_ustring__37);
      PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_ustring__37);
      __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_M2); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_15);
      __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_15, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
      __pyx_t_12 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_12) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_12;
      __pyx_t_11 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
      __Pyx_GIVEREF(__pyx_t_16);
      PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_16);
      __pyx_t_16 = 0;
      __Pyx_INCREF(__pyx_kp_u_koneksi_internet_bermasalah_sila);
      __pyx_t_11 += 64;
      __Pyx_GIVEREF(__pyx_kp_u_koneksi_internet_bermasalah_sila);
      PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_kp_u_koneksi_internet_bermasalah_sila);
      __pyx_t_16 = __Pyx_PyUnicode_Join(__pyx_t_7, 3, __pyx_t_11, __pyx_t_12); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = PyTuple_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_16);
      PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_16);
      __pyx_t_16 = 0;
      __pyx_t_16 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      if (PyDict_SetItem(__pyx_t_16, __pyx_n_s_width, __pyx_int_80) < 0) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_color_table); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_15);
      __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_t_15, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_17);
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
      if (PyDict_SetItem(__pyx_t_16, __pyx_n_s_style, __pyx_t_17) < 0) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
      __pyx_t_17 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_7, __pyx_t_16); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_17);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __pyx_t_16 = __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_17); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 64, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;

      
      __pyx_t_16 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 65, __pyx_L20_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      goto __pyx_L19_exception_handled;
    }
    goto __pyx_L20_except_error;
    __pyx_L20_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    goto __pyx_L1_error;
    __pyx_L19_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    __pyx_L23_try_end:;
  }

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_5, &__pyx_t_4, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_3);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_13, __pyx_n_s_requests); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 69, __pyx_L27_error)
      __Pyx_GOTREF(__pyx_t_13);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_13, __pyx_n_s_get); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 69, __pyx_L27_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      __pyx_t_13 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 69, __pyx_L27_error)
      __Pyx_GOTREF(__pyx_t_13);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_13, __pyx_n_s_json); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 69, __pyx_L27_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      __pyx_t_13 = __Pyx_PyObject_CallNoArg(__pyx_t_14); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 69, __pyx_L27_error)
      __Pyx_GOTREF(__pyx_t_13);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = __Pyx_PyObject_Dict_GetItem(__pyx_t_13, __pyx_n_u_country); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 69, __pyx_L27_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_negara, __pyx_t_14) < 0) __PYX_ERR(0, 69, __pyx_L27_error)
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_negara); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 70, __pyx_L27_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_10 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_Indonesia, __pyx_t_14, Py_NE)); if (unlikely(__pyx_t_10 < 0)) __PYX_ERR(0, 70, __pyx_L27_error)
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_9 = (__pyx_t_10 != 0);
      if (__pyx_t_9) {

        
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_prints); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_GetModuleGlobalName(__pyx_t_13, __pyx_n_s_Panel); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_13);
        __pyx_t_2 = PyTuple_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_11 = 0;
        __pyx_t_12 = 127;
        __Pyx_INCREF(__pyx_ustring__38);
        __pyx_t_12 = (1114111 > __pyx_t_12) ? 1114111 : __pyx_t_12;
        __pyx_t_11 += 2;
        __Pyx_GIVEREF(__pyx_ustring__38);
        PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_ustring__38);
        __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_M2); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_16);
        __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_17);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_12 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_12) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_12;
        __pyx_t_11 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
        __Pyx_GIVEREF(__pyx_t_17);
        PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_17);
        __pyx_t_17 = 0;
        __Pyx_INCREF(__pyx_kp_u_this_script_only_work_in_Indones);
        __pyx_t_11 += 64;
        __Pyx_GIVEREF(__pyx_kp_u_this_script_only_work_in_Indones);
        PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_kp_u_this_script_only_work_in_Indones);
        __pyx_t_17 = __Pyx_PyUnicode_Join(__pyx_t_2, 3, __pyx_t_11, __pyx_t_12); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_17);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_GIVEREF(__pyx_t_17);
        PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_17);
        __pyx_t_17 = 0;
        __pyx_t_17 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_17);
        if (PyDict_SetItem(__pyx_t_17, __pyx_n_s_width, __pyx_int_80) < 0) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_color_table); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_16);
        __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (PyDict_SetItem(__pyx_t_17, __pyx_n_s_style, __pyx_t_6) < 0) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_13, __pyx_t_2, __pyx_t_17); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
        __pyx_t_17 = __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_6); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 71, __pyx_L27_error)
        __Pyx_GOTREF(__pyx_t_17);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;

        
      }

      
    }
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L32_try_end;
    __pyx_L27_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
    __Pyx_ErrFetch(&__pyx_t_17, &__pyx_t_6, &__pyx_t_14);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_requests); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 72, __pyx_L29_except_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_13 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_exceptions); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 72, __pyx_L29_except_error)
    __Pyx_GOTREF(__pyx_t_13);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_13, __pyx_n_s_ConnectionError); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 72, __pyx_L29_except_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
    __pyx_t_8 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_17, __pyx_t_2);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_ErrRestore(__pyx_t_17, __pyx_t_6, __pyx_t_14);
    __pyx_t_17 = 0; __pyx_t_6 = 0; __pyx_t_14 = 0;
    if (__pyx_t_8) {
      __Pyx_AddTraceback("share", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_14, &__pyx_t_6, &__pyx_t_17) < 0) __PYX_ERR(0, 72, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_17);

      
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_prints); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GetModuleGlobalName(__pyx_t_13, __pyx_n_s_Panel); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_13);
      __pyx_t_16 = PyTuple_New(3); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __pyx_t_11 = 0;
      __pyx_t_12 = 127;
      __Pyx_INCREF(__pyx_ustring__39);
      __pyx_t_12 = (1114111 > __pyx_t_12) ? 1114111 : __pyx_t_12;
      __pyx_t_11 += 2;
      __Pyx_GIVEREF(__pyx_ustring__39);
      PyTuple_SET_ITEM(__pyx_t_16, 0, __pyx_ustring__39);
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_M2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_12 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_12) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_12;
      __pyx_t_11 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
      __Pyx_GIVEREF(__pyx_t_1);
      PyTuple_SET_ITEM(__pyx_t_16, 1, __pyx_t_1);
      __pyx_t_1 = 0;
      __Pyx_INCREF(__pyx_kp_u_koneksi_internet_bermasalah_sila);
      __pyx_t_11 += 64;
      __Pyx_GIVEREF(__pyx_kp_u_koneksi_internet_bermasalah_sila);
      PyTuple_SET_ITEM(__pyx_t_16, 2, __pyx_kp_u_koneksi_internet_bermasalah_sila);
      __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_16, 3, __pyx_t_11, __pyx_t_12); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __pyx_t_16 = PyTuple_New(1); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_GIVEREF(__pyx_t_1);
      PyTuple_SET_ITEM(__pyx_t_16, 0, __pyx_t_1);
      __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_width, __pyx_int_80) < 0) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_color_table); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_15 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_15);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_style, __pyx_t_15) < 0) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
      __pyx_t_15 = __Pyx_PyObject_Call(__pyx_t_13, __pyx_t_16, __pyx_t_1); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_15);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 73, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      
      __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 74, __pyx_L29_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
      goto __pyx_L28_exception_handled;
    }
    goto __pyx_L29_except_error;
    __pyx_L29_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_4, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L28_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_5, __pyx_t_4, __pyx_t_3);
    __pyx_L32_try_end:;
  }

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_3, &__pyx_t_4, &__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_17, __pyx_n_s_ses); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 78, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_17);
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_17, __pyx_n_s_get); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 78, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
      __pyx_t_17 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__40, NULL); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 78, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_17);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_17, __pyx_n_s_text); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 78, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_url, __pyx_t_6) < 0) __PYX_ERR(0, 78, __pyx_L36_error)
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

      
      __pyx_t_6 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__41, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 79, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_17 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_write); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 79, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_17);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_url); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 79, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_14 = __Pyx_PyObject_CallOneArg(__pyx_t_17, __pyx_t_6); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 79, __pyx_L36_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    goto __pyx_L41_try_end;
    __pyx_L36_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
     {
      __Pyx_ErrRestore(0,0,0);
      goto __pyx_L37_exception_handled;
    }
    __pyx_L37_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    __pyx_L41_try_end:;
  }

  
  __pyx_t_14 = __Pyx_CyFunction_New(&__pyx_mdef_5share_1clear_screen, 0, __pyx_n_s_clear_screen, NULL, __pyx_n_s_share, __pyx_d, ((PyObject *)__pyx_codeobj__42)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_clear_screen, __pyx_t_14) < 0) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  
  __pyx_t_14 = __Pyx_CyFunction_New(&__pyx_mdef_5share_3waktu, 0, __pyx_n_s_waktu, NULL, __pyx_n_s_share, __pyx_d, ((PyObject *)__pyx_codeobj__44)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_waktu, __pyx_t_14) < 0) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  
  __pyx_t_14 = __Pyx_CyFunction_New(&__pyx_mdef_5share_5logo, 0, __pyx_n_s_logo, NULL, __pyx_n_s_share, __pyx_d, ((PyObject *)__pyx_codeobj__45)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_logo, __pyx_t_14) < 0) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  
  __pyx_t_14 = __Pyx_CyFunction_New(&__pyx_mdef_5share_7login, 0, __pyx_n_s_login, NULL, __pyx_n_s_share, __pyx_d, ((PyObject *)__pyx_codeobj__47)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_login, __pyx_t_14) < 0) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  
  __pyx_t_14 = __Pyx_CyFunction_New(&__pyx_mdef_5share_9menu, 0, __pyx_n_s_menu, NULL, __pyx_n_s_share, __pyx_d, ((PyObject *)__pyx_codeobj__49)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 136, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_menu, __pyx_t_14) < 0) __PYX_ERR(0, 136, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  
  __pyx_t_14 = __Pyx_CyFunction_New(&__pyx_mdef_5share_11share_cepat, 0, __pyx_n_s_share_cepat, NULL, __pyx_n_s_share, __pyx_d, ((PyObject *)__pyx_codeobj__51)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_share_cepat, __pyx_t_14) < 0) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  
  __pyx_t_14 = __Pyx_CyFunction_New(&__pyx_mdef_5share_13share_lambat, 0, __pyx_n_s_share_lambat, NULL, __pyx_n_s_share, __pyx_d, ((PyObject *)__pyx_codeobj__53)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_share_lambat, __pyx_t_14) < 0) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_name_2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 279, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  __pyx_t_9 = (__Pyx_PyUnicode_Equals(__pyx_t_14, __pyx_n_u_main, Py_EQ)); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 279, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
  if (__pyx_t_9) {

    
    __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_menu); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 280, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __pyx_t_6 = __Pyx_PyObject_CallNoArg(__pyx_t_14); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 280, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

    
  }

  
  __pyx_t_6 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_6) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

  

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_XDECREF(__pyx_t_17);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init share", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init share");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}



#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif


#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}


#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = func->ob_type->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#ifdef __Pyx_CyFunction_USED
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (PyCFunction_GET_FLAGS(func) & METH_FASTCALL) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      CYTHON_UNUSED Py_UCS4 max_char) {
#if CYTHON_USE_UNICODE_INTERNALS && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    PyObject *result_uval;
    int result_ukind;
    Py_ssize_t i, char_pos;
    void *result_udata;
#if CYTHON_PEP393_ENABLED
    result_uval = PyUnicode_New(result_ulength, max_char);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = (max_char <= 255) ? PyUnicode_1BYTE_KIND : (max_char <= 65535) ? PyUnicode_2BYTE_KIND : PyUnicode_4BYTE_KIND;
    result_udata = PyUnicode_DATA(result_uval);
#else
    result_uval = PyUnicode_FromUnicode(NULL, result_ulength);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = sizeof(Py_UNICODE);
    result_udata = PyUnicode_AS_UNICODE(result_uval);
#endif
    char_pos = 0;
    for (i=0; i < value_count; i++) {
        int ukind;
        Py_ssize_t ulength;
        void *udata;
        PyObject *uval = PyTuple_GET_ITEM(value_tuple, i);
        if (unlikely(__Pyx_PyUnicode_READY(uval)))
            goto bad;
        ulength = __Pyx_PyUnicode_GET_LENGTH(uval);
        if (unlikely(!ulength))
            continue;
        if (unlikely(char_pos + ulength < 0))
            goto overflow;
        ukind = __Pyx_PyUnicode_KIND(uval);
        udata = __Pyx_PyUnicode_DATA(uval);
        if (!CYTHON_PEP393_ENABLED || ukind == result_ukind) {
            memcpy((char *)result_udata + char_pos * result_ukind, udata, (size_t) (ulength * result_ukind));
        } else {
            #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030300F0 || defined(_PyUnicode_FastCopyCharacters)
            _PyUnicode_FastCopyCharacters(result_uval, char_pos, uval, 0, ulength);
            #else
            Py_ssize_t j;
            for (j=0; j < ulength; j++) {
                Py_UCS4 uchar = __Pyx_PyUnicode_READ(ukind, udata, j);
                __Pyx_PyUnicode_WRITE(result_ukind, result_udata, char_pos+j, uchar);
            }
            #endif
        }
        char_pos += ulength;
    }
    return result_uval;
overflow:
    PyErr_SetString(PyExc_OverflowError, "join() result is too long for a Python string");
bad:
    Py_DECREF(result_uval);
    return NULL;
#else
    result_ulength++;
    value_count++;
    return PyUnicode_Join(__pyx_empty_unicode, value_tuple);
#endif
}


#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key) {
    PyObject *value;
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (!PyErr_Occurred()) {
            if (unlikely(PyTuple_Check(key))) {
                PyObject* args = PyTuple_Pack(1, key);
                if (likely(args)) {
                    PyErr_SetObject(PyExc_KeyError, args);
                    Py_DECREF(args);
                }
            } else {
                PyErr_SetObject(PyExc_KeyError, key);
            }
        }
        return NULL;
    }
    Py_INCREF(value);
    return value;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx_PyErr_ExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        if (__Pyx_PyErr_GivenExceptionMatches(exc_type, PyTuple_GET_ITEM(tuple, i))) return 1;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err) {
    PyObject *exc_type = tstate->curexc_type;
    if (exc_type == err) return 1;
    if (unlikely(!exc_type)) return 0;
    if (unlikely(PyTuple_Check(err)))
        return __Pyx_PyErr_ExceptionMatchesTuple(exc_type, err);
    return __Pyx_PyErr_GivenExceptionMatches(exc_type, err);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif


static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname) {
    PyErr_Format(PyExc_UnboundLocalError, "local variable '%s' referenced before assignment", varname);
}


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}


static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x) {
    if (likely(PyList_CheckExact(L))) {
        if (unlikely(__Pyx_PyList_Append(L, x) < 0)) return -1;
    } else {
        PyObject* retval = __Pyx_PyObject_CallMethod1(L, __pyx_n_s_append, x);
        if (unlikely(!retval))
            return -1;
        Py_DECREF(retval);
    }
    return 0;
}


static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}


static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}


static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a + b);
            if (likely((x^a) >= 0 || (x^b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_add(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_add(op1, op2);
            }
        }
                x = a + b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla + llb;
            return PyLong_FromLongLong(llx);
#endif
        
        
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("add", return NULL)
            result = ((double)a) + (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceAdd : PyNumber_Add)(op1, op2);
}
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}


static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name) {
    PyObject* value = __Pyx_PyObject_GetAttrStr(module, name);
    if (unlikely(!value) && PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Format(PyExc_ImportError,
        #if PY_MAJOR_VERSION < 3
            "cannot import name %.230s", PyString_AS_STRING(name));
        #else
            "cannot import name %S", name);
        #endif
    }
    return value;
}


#if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}


#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromString(m->func.m_ml->ml_name);
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    if (unlikely(op == NULL))
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults_size = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
    if (s1 == s2) {
        return (equals == Py_EQ);
    } else if (PyBytes_CheckExact(s1) & PyBytes_CheckExact(s2)) {
        const char *ps1, *ps2;
        Py_ssize_t length = PyBytes_GET_SIZE(s1);
        if (length != PyBytes_GET_SIZE(s2))
            return (equals == Py_NE);
        ps1 = PyBytes_AS_STRING(s1);
        ps2 = PyBytes_AS_STRING(s2);
        if (ps1[0] != ps2[0]) {
            return (equals == Py_NE);
        } else if (length == 1) {
            return (equals == Py_EQ);
        } else {
            int result;
#if CYTHON_USE_UNICODE_INTERNALS
            Py_hash_t hash1, hash2;
            hash1 = ((PyBytesObject*)s1)->ob_shash;
            hash2 = ((PyBytesObject*)s2)->ob_shash;
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                return (equals == Py_NE);
            }
#endif
            result = memcmp(ps1, ps2, (size_t)length);
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & PyBytes_CheckExact(s2)) {
        return (equals == Py_NE);
    } else if ((s2 == Py_None) & PyBytes_CheckExact(s1)) {
        return (equals == Py_NE);
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
#endif
}


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
#if PY_MAJOR_VERSION < 3
    PyObject* owned_ref = NULL;
#endif
    int s1_is_unicode, s2_is_unicode;
    if (s1 == s2) {
        goto return_eq;
    }
    s1_is_unicode = PyUnicode_CheckExact(s1);
    s2_is_unicode = PyUnicode_CheckExact(s2);
#if PY_MAJOR_VERSION < 3
    if ((s1_is_unicode & (!s2_is_unicode)) && PyString_CheckExact(s2)) {
        owned_ref = PyUnicode_FromObject(s2);
        if (unlikely(!owned_ref))
            return -1;
        s2 = owned_ref;
        s2_is_unicode = 1;
    } else if ((s2_is_unicode & (!s1_is_unicode)) && PyString_CheckExact(s1)) {
        owned_ref = PyUnicode_FromObject(s1);
        if (unlikely(!owned_ref))
            return -1;
        s1 = owned_ref;
        s1_is_unicode = 1;
    } else if (((!s2_is_unicode) & (!s1_is_unicode))) {
        return __Pyx_PyBytes_Equals(s1, s2, equals);
    }
#endif
    if (s1_is_unicode & s2_is_unicode) {
        Py_ssize_t length;
        int kind;
        void *data1, *data2;
        if (unlikely(__Pyx_PyUnicode_READY(s1) < 0) || unlikely(__Pyx_PyUnicode_READY(s2) < 0))
            return -1;
        length = __Pyx_PyUnicode_GET_LENGTH(s1);
        if (length != __Pyx_PyUnicode_GET_LENGTH(s2)) {
            goto return_ne;
        }
#if CYTHON_USE_UNICODE_INTERNALS
        {
            Py_hash_t hash1, hash2;
        #if CYTHON_PEP393_ENABLED
            hash1 = ((PyASCIIObject*)s1)->hash;
            hash2 = ((PyASCIIObject*)s2)->hash;
        #else
            hash1 = ((PyUnicodeObject*)s1)->hash;
            hash2 = ((PyUnicodeObject*)s2)->hash;
        #endif
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                goto return_ne;
            }
        }
#endif
        kind = __Pyx_PyUnicode_KIND(s1);
        if (kind != __Pyx_PyUnicode_KIND(s2)) {
            goto return_ne;
        }
        data1 = __Pyx_PyUnicode_DATA(s1);
        data2 = __Pyx_PyUnicode_DATA(s2);
        if (__Pyx_PyUnicode_READ(kind, data1, 0) != __Pyx_PyUnicode_READ(kind, data2, 0)) {
            goto return_ne;
        } else if (length == 1) {
            goto return_eq;
        } else {
            int result = memcmp(data1, data2, (size_t)(length * kind));
            #if PY_MAJOR_VERSION < 3
            Py_XDECREF(owned_ref);
            #endif
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & s2_is_unicode) {
        goto return_ne;
    } else if ((s2 == Py_None) & s1_is_unicode) {
        goto return_ne;
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        #if PY_MAJOR_VERSION < 3
        Py_XDECREF(owned_ref);
        #endif
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
return_eq:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_EQ);
return_ne:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_NE);
#endif
}


#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_NCP_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif


static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}


#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        py_srcfile,   
        py_funcname,  
        py_line,
        __pyx_empty_bytes  
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            
        py_code,           
        __pyx_d,    
        0                  
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}


#ifdef __FreeBSD__
#include <floatingpoint.h>
#endif
#if PY_MAJOR_VERSION < 3
int main(int argc, char** argv) {
#elif defined(WIN32) || defined(MS_WINDOWS)
int wmain(int argc, wchar_t **argv) {
#else
static int __Pyx_main(int argc, wchar_t **argv) {
#endif
    /* 754 requires that FP exceptions run in "no stop" mode by default,
     * and until C vendors implement C99's ways to control FP exceptions,
     * Python requires non-stop mode.  Alas, some platforms enable FP
     * exceptions by default.  Here we disable them.
     */
#ifdef __FreeBSD__
    fp_except_t m;
    m = fpgetmask();
    fpsetmask(m & ~FP_X_OFL);
#endif
    if (argc && argv)
        Py_SetProgramName(argv[0]);
    Py_Initialize();
    if (argc && argv)
        PySys_SetArgv(argc, argv);
    {
      PyObject* m = NULL;
      __pyx_module_is_main_share = 1;
      #if PY_MAJOR_VERSION < 3
          initshare();
      #elif CYTHON_PEP489_MULTI_PHASE_INIT
          m = PyInit_share();
          if (!PyModule_Check(m)) {
              PyModuleDef *mdef = (PyModuleDef *) m;
              PyObject *modname = PyUnicode_FromString("__main__");
              m = NULL;
              if (modname) {
                  m = PyModule_NewObject(modname);
                  Py_DECREF(modname);
                  if (m) PyModule_ExecDef(m, mdef);
              }
          }
      #else
          m = PyInit_share();
      #endif
      if (PyErr_Occurred()) {
          PyErr_Print();
          #if PY_MAJOR_VERSION < 3
          if (Py_FlushLine()) PyErr_Clear();
          #endif
          return 1;
      }
      Py_XDECREF(m);
    }
    Py_Finalize();
    return 0;
}
#if PY_MAJOR_VERSION >= 3 && !defined(WIN32) && !defined(MS_WINDOWS)
#include <locale.h>
static wchar_t*
__Pyx_char2wchar(char* arg)
{
    wchar_t *res;
#ifdef HAVE_BROKEN_MBSTOWCS
    /* Some platforms have a broken implementation of
     * mbstowcs which does not count the characters that
     * would result from conversion.  Use an upper bound.
     */
    size_t argsize = strlen(arg);
#else
    size_t argsize = mbstowcs(NULL, arg, 0);
#endif
    size_t count;
    unsigned char *in;
    wchar_t *out;
#ifdef HAVE_MBRTOWC
    mbstate_t mbs;
#endif
    if (argsize != (size_t)-1) {
        res = (wchar_t *)malloc((argsize+1)*sizeof(wchar_t));
        if (!res)
            goto oom;
        count = mbstowcs(res, arg, argsize+1);
        if (count != (size_t)-1) {
            wchar_t *tmp;
            /* Only use the result if it contains no
               surrogate characters. */
            for (tmp = res; *tmp != 0 &&
                     (*tmp < 0xd800 || *tmp > 0xdfff); tmp++)
                ;
            if (*tmp == 0)
                return res;
        }
        free(res);
    }
#ifdef HAVE_MBRTOWC
    /* Overallocate; as multi-byte characters are in the argument, the
       actual output could use less memory. */
    argsize = strlen(arg) + 1;
    res = (wchar_t *)malloc(argsize*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    memset(&mbs, 0, sizeof mbs);
    while (argsize) {
        size_t converted = mbrtowc(out, (char*)in, argsize, &mbs);
        if (converted == 0)
            break;
        if (converted == (size_t)-2) {
            /* Incomplete character. This should never happen,
               since we provide everything that we have -
               unless there is a bug in the C library, or I
               misunderstood how mbrtowc works. */
            fprintf(stderr, "unexpected mbrtowc result -2\\n");
            free(res);
            return NULL;
        }
        if (converted == (size_t)-1) {
            /* Conversion error. Escape as UTF-8b, and start over
               in the initial shift state. */
            *out++ = 0xdc00 + *in++;
            argsize--;
            memset(&mbs, 0, sizeof mbs);
            continue;
        }
        if (*out >= 0xd800 && *out <= 0xdfff) {
            /* Surrogate character.  Escape the original
               byte sequence with surrogateescape. */
            argsize -= converted;
            while (converted--)
                *out++ = 0xdc00 + *in++;
            continue;
        }
        in += converted;
        argsize -= converted;
        out++;
    }
#else
    /* Cannot use C locale for escaping; manually escape as if charset
       is ASCII (i.e. escape all bytes > 128. This will still roundtrip
       correctly in the locale's charset, which must be an ASCII superset. */
    res = (wchar_t *)malloc((strlen(arg)+1)*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    while(*in)
        if(*in < 128)
            *out++ = *in++;
        else
            *out++ = 0xdc00 + *in++;
    *out = 0;
#endif
    return res;
oom:
    fprintf(stderr, "out of memory\\n");
    return NULL;
}
int
main(int argc, char **argv)
{
    if (!argc) {
        return __Pyx_main(0, NULL);
    }
    else {
        int i, res;
        wchar_t **argv_copy = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        wchar_t **argv_copy2 = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        char *oldloc = strdup(setlocale(LC_ALL, NULL));
        if (!argv_copy || !argv_copy2 || !oldloc) {
            fprintf(stderr, "out of memory\\n");
            free(argv_copy);
            free(argv_copy2);
            free(oldloc);
            return 1;
        }
        res = 0;
        setlocale(LC_ALL, "");
        for (i = 0; i < argc; i++) {
            argv_copy2[i] = argv_copy[i] = __Pyx_char2wchar(argv[i]);
            if (!argv_copy[i]) res = 1;
        }
        setlocale(LC_ALL, oldloc);
        free(oldloc);
        if (res == 0)
            res = __Pyx_main(argc, argv_copy);
        for (i = 0; i < argc; i++) {
            free(argv_copy2[i]);
        }
        free(argv_copy);
        free(argv_copy2);
        return res;
    }
}
#endif


    static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}


    #define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }


    static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}


    static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
    const int neg_one = (int) ((int) 0 - (int) 1), const_zero = (int) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}


    static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}


    static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif 
