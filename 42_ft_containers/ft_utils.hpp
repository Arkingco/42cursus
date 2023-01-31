#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

template <bool, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
  typedef T type;
};

#endif