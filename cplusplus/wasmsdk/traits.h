#ifndef _WASMSDK_TRAITS_H_
#define _WASMSDK_TRAITS_H_

#include "define.h"

WASMSDK_BEGIN_NS

/**
 * Removes reference from type
 *
 * @tparam T
 */
template<class T>
struct remove_reference {
    typedef T type;
};
template<class T>
struct remove_reference<T &> {
    typedef T type;
};
template<class T>
struct remove_reference<T &&> {
    typedef T type;
};

template<class T>
struct remove_const {
    typedef T type;
};
template<class T>
struct remove_const<const T> {
    typedef T type;
};

/**
 * Removes pointer from type
 *
 * @tparam T
 */
template<class T>
struct remove_pointer {
    typedef T type;
};
template<class T>
struct remove_pointer<T *> {
    typedef T type;
};

/**
 * Clears type from qualifiers
 *
 * @tparam T
 */
template <typename T>
struct clear_type {
    using type = typename remove_const<typename remove_pointer<typename remove_reference<T>::type>::type>::type;
};

/**
 * Returns true if reference type specified
 *
 * @tparam T
 */
template<class T>
struct is_reference {
    static const bool value = false;
};
template<class T>
struct is_reference<T &> {
    static const bool value = true;
};
template<class T>
struct is_reference<T &&> {
    static const bool value = true;
};

/**
 * Returns true if const type specified
 *
 * @tparam T
 */
template<class T>
struct is_const {
    static const bool value = false;
};
template<class T>
struct is_const<const T> {
    static const bool value = true;
};

WASMSDK_END_NS

#endif // ~_WASMSDK_TRAITS_H_