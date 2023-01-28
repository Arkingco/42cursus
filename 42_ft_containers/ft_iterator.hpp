#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <iterator>

template<class _Iter>
struct iterator_traits
{
    typedef typename _Iter::iterator_category iterator_category;
    typedef typename _Iter::value_type value_type;
    typedef typename _Iter::difference_type difference_type;
    typedef difference_type distance_type;
    typedef typename _Iter::pointer pointer;
    typedef typename _Iter::reference reference;
};

template<class _Ty>
struct iterator_traits<_Ty *> // 또는 <const _Ty*>
{      
    // get traits from pointer
 
    // 포인터는 산술연산이 가능하므로, 바로 random_access_iterator_tag를 지정해준다
    typedef random_access_iterator_tag iterator_category;
    typedef _Ty value_type;
    typedef ptrdiff_t difference_type;
    typedef ptrdiff_t distance_type;    // retained
    typedef _Ty *pointer;
    typedef _Ty& reference;
};

#endif