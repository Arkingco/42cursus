#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <stddef.h>

namespace ft
{
  
  struct input_iterator_tag {};
  struct output_iterator_tag {};
  struct forward_iterator_tag : public input_iterator_tag {};
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};

  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
	   typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator {
      typedef _Category  iterator_category;
      typedef _Tp        value_type;
      typedef _Distance  difference_type;
      typedef _Pointer   pointer;
      typedef _Reference reference;
    };

  template<typename _Iterator>
    struct iterator_traits {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type        value_type;
      typedef typename _Iterator::difference_type   difference_type;
      typedef typename _Iterator::pointer           pointer;
      typedef typename _Iterator::reference         reference;
    };

  template<typename _Tp>
    struct iterator_traits<_Tp*> {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef _Tp*                        pointer;
      typedef _Tp&                        reference;
    };

  template<typename _Tp>
    struct iterator_traits<const _Tp*> {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef const _Tp*                  pointer;
      typedef const _Tp&                  reference;
    };
  
  template<typename _Iter>
    inline typename iterator_traits<_Iter>::iterator_category
    __iterator_category(const _Iter&)
    { return typename iterator_traits<_Iter>::iterator_category(); }

  template<typename _Iterator, typename _Container>
  class __vector_iterator : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                          typename iterator_traits<_Iterator>::value_type,
                          typename iterator_traits<_Iterator>::difference_type,
                          typename iterator_traits<_Iterator>::pointer,
                          typename iterator_traits<_Iterator>::reference>
  {
    protected:
        _Iterator _current;
    
    public:
        typedef typename iterator_traits<_Iterator>::difference_type difference_type;
        typedef typename iterator_traits<_Iterator>::reference   reference;
        typedef typename iterator_traits<_Iterator>::pointer     pointer;

        __vector_iterator() : _current(_Iterator()) { }

        explicit
        __vector_iterator(const _Iterator& __i) : _current(__i) { }
  
        template<typename _Iter>
        inline __vector_iterator(const __vector_iterator<_Iter, _Container>& __i)
          : _current(__i.base()) { }

        reference
        operator*() const { return *_current; }

        pointer
        operator->() const { return _current; }

        __vector_iterator&
        operator++() { ++_current; return *this; }

        __vector_iterator
        operator++(int) { return __vector_iterator(_current++); }

        __vector_iterator&
        operator--() { --_current; return *this; }
        
        __vector_iterator
        operator--(int) { return __vector_iterator(_current--); }

        reference operator[](const difference_type& __n) const
        { return _current[__n]; }

        __vector_iterator& operator+=(const difference_type& __n)
        { _current += __n; return *this; }

        __vector_iterator& operator+(const difference_type& __n)
        { return __vector_iterator(_current + __n); }

        __vector_iterator& operator-=(const difference_type& __n)
        { _current -= __n; return *this; }

        __vector_iterator& operator-(const difference_type& __n)
        { return __vector_iterator(_current - __n); }

        difference_type operator-(const __vector_iterator& __i)
        { return _current - __i._current; }

        const _Iterator&
        base() const { return _current; }     
  };


 // Forward iterator requirements
  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator==(const __vector_iterator<_IteratorL, _Container>& __lhs,
	     const __vector_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() == __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator!=(const __vector_iterator<_IteratorL, _Container>& __lhs,
	     const __vector_iterator<_IteratorR, _Container>& __rhs)
  { return !(__lhs == __rhs); }

  // Random access iterator requirements
  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool 
  operator<(const __vector_iterator<_IteratorL, _Container>& __lhs,
	    const __vector_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() < __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator>(const __vector_iterator<_IteratorL, _Container>& __lhs,
	    const __vector_iterator<_IteratorR, _Container>& __rhs)
  { return __rhs < __lhs; }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator<=(const __vector_iterator<_IteratorL, _Container>& __lhs,
	     const __vector_iterator<_IteratorR, _Container>& __rhs)
  { return !(__rhs < __lhs); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator>=(const __vector_iterator<_IteratorL, _Container>& __lhs,
	     const __vector_iterator<_IteratorR, _Container>& __rhs)
  { return !(__lhs < __rhs); }

  template<typename _Iterator, typename _Container>
  inline __vector_iterator<_Iterator, _Container>
  operator+(typename __vector_iterator<_Iterator, _Container>::difference_type __n,
	    const __vector_iterator<_Iterator, _Container>& __i)
  { return __vector_iterator<_Iterator, _Container>(__i.base() + __n); }

}

#endif 