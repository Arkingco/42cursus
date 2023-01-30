#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <stddef.h>

namespace ft
{

  ///  Marking input iterators.
  struct input_iterator_tag {};
  ///  Marking output iterators.
  struct output_iterator_tag {};
  /// Forward iterators support a superset of input iterator operations.
  struct forward_iterator_tag : public input_iterator_tag {};
  /// Bidirectional iterators support a superset of forward iterator operations.
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  /// Random-access iterators support a superset of bidirectional iterator operations.
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};
  //@}

  /**
   *  This class does nothing but define nested typedefs.  Iterator classes
   *  can inherit from this class to save some work.  The typedefs are then
   *  used in specializations and overloading.
  */
  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
	   typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator {
      /// One of the @link iterator_tags tag types@endlink.
      typedef _Category  iterator_category;
      /// The type "pointed to" by the iterator.
      typedef _Tp        value_type;
      /// Distance between iterators is represented as this type.
      typedef _Distance  difference_type;
      /// This type represents a pointer-to-value_type.
      typedef _Pointer   pointer;
      /// This type represents a reference-to-value_type.
      typedef _Reference reference;
    };

  /**
   *  This class does nothing but define nested typedefs.  The general
   *  version simply "forwards" the nested typedefs from the Iterator
   *  argument.  Specialized versions for pointers and pointers-to-const
   *  provide tighter, more correct semantics.
  */
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

  /**
   *  @maint
   *  This function is not a part of the C++ standard but is syntactic
   *  sugar for internal library use only.
   *  @endmaint
  */
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
            inline __normal_iterator(const __normal_iterator<_Iter, _Container>& __i)
	            : _M_current(__i.base()) { }


            const _Iterator& 
            base() const { return _M_current; }     
    };
}




#endif 