// include in vector header (custom)

#include <__config>
#include <iosfwd> // for forward declaration of vector
#include <__bit_reference>
#include <type_traits>
#include <climits>
#include <limits>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <cstring>
#include <__cxx_version>
#include <__split_buffer>
#include <__functional_base>

#include <__debug>
///////////////////////////////////////////

// my include
#include <iostream>
#include "ft_iterator.hpp"
#include ""
namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector
{
    private:
      typedef vector<T, Allocator> vector_type;
    public:
      typedef Allocator                                  allocator_type;
      typedef T                                          value_type;
      typedef value_type*                                pointer;
      typedef const value_type*                          const_pointer;
      typedef value_type&                                reference;
      typedef const value_type&                          const_reference;
      typedef size_t                                     size_type;
      typedef ptrdiff_t                                  difference_type;
      typedef ft::__vector_iterator<pointer, vector_type>      iterator;
      typedef ft::__vector_iterator<const_pointer, vector_type>      const_iterator;
      typedef std::reverse_iterator<iterator>            reverse_iterator;
      typedef std::reverse_iterator<const_iterator>      const_reverse_iterator;

    private:
      pointer			_begin;         // = _Vector_alloc_base::_M_start in c++98(gcc)
      pointer			_end;           // = _Vector_alloc_base::_M_finish in c++98(gcc)
      pointer			_end_cap;       // = _Vector_alloc_base::_M_end_of_storage in c++98(gcc)
      allocator_type _alloc;      // = _Vector_alloc_base::_M_data_allocator in c++98(gcc)

    public:
    // Member functions;
        // constructor
        vector() : _begin(0), _end(0), _end_cap(0)
        {
          std::cout << "ft_vector default constructor" << std::endl;
        }    

        explicit vector(const allocator_type& __a) : _alloc(__a), _begin(0), _end(0), _end_cap(0)
        {
          std::cout << "ft_vector default constructor" << std::endl;
        }
        
        explicit vector(size_type n)
        {
          _begin = _alloc.allocate(n, nullptr);
          _end = _begin;
          _end_cap = _begin + n;
        }

        vector(size_type n, const value_type& value, const allocator_type& = allocator_type())  // 98
        {
          _begin = _alloc.allocate(n, nullptr);
          _end = _begin;
          _end_cap = _begin + n;
          
          for (int i=0; i<n; ++i)
          {
            *_end = value;
            _end++;
          }
        }

        template <class InputIterator> 
        vector(enable_if<>InputIterator first, InputIterator last, const allocator_type& = allocator_type())
        {
        
        }

        // vector(const vector& x)
        // {

        // }
        
        // // destructor
        // ~vector();

        // // operator
        // vector& operator=(const vector& x);

        // // assign
        // template <class InputIterator>
        //     void assign(InputIterator first, InputIterator last);
        // void assign(size_type n, const value_type& u);

        // // get_allocator:
        // allocator_type get_allocator() const

        // // Iterstors
        iterator               begin() { return iterator (_begin); }
        const_iterator         begin() const { return const_iterator (_begin); }
        iterator               end() { return iterator (_end); }
        const_iterator         end() const { return const_iterator (_end); } 

        // reverse_iterator       rbegin();
        // const_reverse_iterator rbegin() const;
        // reverse_iterator       rend();
        // const_reverse_iterator rend() const;

        // const_iterator         cbegin()  const;
        // const_iterator         cend()    const;
        // const_reverse_iterator crbegin() const;
        // const_reverse_iterator crend()   const;


        // // Capacity:
        // bool empty() const;
        size_type size() const
          { return size_type(_end_cap - _begin); } // end와 begin은 random access 라서 가능!!
        size_type max_size() const
          { return size_type(-1) / sizeof(T); }
        // void reserve(size_type n);
        size_type capacity() const {return size_type(_end_cap - _begin);}

        // // Element access:
        // reference       operator[](size_type n);
        // const_reference operator[](size_type n) const;
        // reference       at(size_type n);
        // const_reference at(size_type n) const;

        // reference       front();
        // const_reference front() const;
        // reference       back();
        // const_reference back() const;

        // value_type*       data();
        // const value_type* data() const;

        // // Modifiers:
        // void clear();
        // iterator insert(const_iterator position, const value_type& x);
        // iterator insert(const_iterator position, value_type&& x);
        // iterator insert(const_iterator position, size_type n, const value_type& x);
        // template <class InputIterator>
        //     iterator insert(const_iterator position, InputIterator first, InputIterator last);
        // iterator erase(iterator position);
        // iterator erase(iterator first, iterator last);

        void _copy_mem(pointer __temp_begin, pointer __temp_end, pointer& _current_end)
        {
          for (pointer t_begin = __temp_begin; t_begin != __temp_end; ++t_begin)
          {
            std::cout << "copy " << *t_begin << std::endl;
            *_current_end = *t_begin;
            _current_end++;
          }
        }

        void _increase_cap()
        {
          size_type __old_size = size();
          size_type __new_size = __old_size != 0 ? 2 * __old_size : 1;

          pointer __temp_begin = _begin;
          pointer __temp_end = _end;
          pointer __temp_end_cap = _end_cap;
          allocator_type __temp_alloc = _alloc;

          _begin = _alloc.allocate(__new_size, nullptr);
          _end = _begin;
          _end_cap = _begin + __new_size;
          _copy_mem(__temp_begin, __temp_end, _end);
          __temp_alloc.deallocate(__temp_begin, __temp_end_cap - __temp_begin);
        }

        void push_back(const value_type& x)
        {
          if (_end != _end_cap)
          {
            _alloc.construct(_end, x);
            ++_end;
          }
          else
          {
            _increase_cap();
            _alloc.construct(_end, x);
            ++_end;
          }
        }
        
        // void pop_back();
        // void resize(size_type sz);
        // void resize( size_type count, value_type val = value_type());
        // void swap(vector& other)

        // bool __invariants() const; // ?? where use?
};

    // // Non-member functions
    // template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    // template <class T, class Allocator> bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    // template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    // template <class T, class Allocator> bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    // template <class T, class Allocator> bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    // template <class T, class Allocator> bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

    // template <class T, class Allocator>
    //     void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);

    // template <class T, class Allocator, class Predicate>
    // void erase_if(vector<T, Allocator>& c, Predicate pred);    // C++20 this Non-member function can not use c++98 but we have to implement

}

























// what is this?

    // template <class Allocator = allocator<T> >
    // class vector<bool, Allocator>
    // {
    // public:
    //     typedef bool                                     value_type;
    //     typedef Allocator                                allocator_type;
    //     typedef implementation-defined                   iterator;
    //     typedef implementation-defined                   const_iterator;
    //     typedef typename allocator_type::size_type       size_type;
    //     typedef typename allocator_type::difference_type difference_type;
    //     typedef iterator                                 pointer;
    //     typedef const_iterator                           const_pointer;
    //     typedef std::reverse_iterator<iterator>          reverse_iterator;
    //     typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    //     class reference
    //     {
    //     public:
    //         reference(const reference&) noexcept;
    //         operator bool() const noexcept;
    //         reference& operator=(const bool x) noexcept;
    //         reference& operator=(const reference& x) noexcept;
    //         iterator operator&() const noexcept;
    //         void flip() noexcept;
    //     };

    //     class const_reference
    //     {
    //     public:
    //         const_reference(const reference&) noexcept;
    //         operator bool() const noexcept;
    //         const_iterator operator&() const noexcept;
    //     };

    //     vector()
    //         noexcept(is_nothrow_default_constructible<allocator_type>::value);
    //     explicit vector(const allocator_type&);
    //     explicit vector(size_type n, const allocator_type& a = allocator_type()); // C++14
    //     vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    //     template <class InputIterator>
    //         vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    //     vector(const vector& x);
    //     vector(vector&& x)
    //         noexcept(is_nothrow_move_constructible<allocator_type>::value);
    //     vector(initializer_list<value_type> il);
    //     vector(initializer_list<value_type> il, const allocator_type& a);
    //     ~vector();
    //     vector& operator=(const vector& x);
    //     vector& operator=(vector&& x)
    //         noexcept(
    //              allocator_type::propagate_on_container_move_assignment::value ||
    //              allocator_type::is_always_equal::value); // C++17
    //     vector& operator=(initializer_list<value_type> il);
    //     template <class InputIterator>
    //         void assign(InputIterator first, InputIterator last);
    //     void assign(size_type n, const value_type& u);
    //     void assign(initializer_list<value_type> il);

    //     allocator_type get_allocator() const noexcept;

    //     iterator               begin() noexcept;
    //     const_iterator         begin()   const noexcept;
    //     iterator               end() noexcept;
    //     const_iterator         end()     const noexcept;

    //     reverse_iterator       rbegin() noexcept;
    //     const_reverse_iterator rbegin()  const noexcept;
    //     reverse_iterator       rend() noexcept;
    //     const_reverse_iterator rend()    const noexcept;

    //     const_iterator         cbegin()  const noexcept;
    //     const_iterator         cend()    const noexcept;
    //     const_reverse_iterator crbegin() const noexcept;
    //     const_reverse_iterator crend()   const noexcept;

    //     size_type size() const noexcept;
    //     size_type max_size() const noexcept;
    //     size_type capacity() const noexcept;
    //     bool empty() const noexcept;
    //     void reserve(size_type n);
    //     void shrink_to_fit() noexcept;

    //     reference       operator[](size_type n);
    //     const_reference operator[](size_type n) const;
    //     reference       at(size_type n);
    //     const_reference at(size_type n) const;

    //     reference       front();
    //     const_reference front() const;
    //     reference       back();
    //     const_reference back() const;

    //     void push_back(const value_type& x);
    //     template <class... Args> reference emplace_back(Args&&... args);  // C++14; reference in C++17
    //     void pop_back();

    //     template <class... Args> iterator emplace(const_iterator position, Args&&... args);  // C++14
    //     iterator insert(const_iterator position, const value_type& x);
    //     iterator insert(const_iterator position, size_type n, const value_type& x);
    //     template <class InputIterator>
    //         iterator insert(const_iterator position, InputIterator first, InputIterator last);
    //     iterator insert(const_iterator position, initializer_list<value_type> il);

    //     iterator erase(const_iterator position);
    //     iterator erase(const_iterator first, const_iterator last);

    //     void clear() noexcept;

    //     void resize(size_type sz);
    //     void resize(size_type sz, value_type x);

    //     void swap(vector&)
    //         noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
    //                  allocator_traits<allocator_type>::is_always_equal::value);  // C++17
    //     void flip() noexcept;

    //     bool __invariants() const;
// };