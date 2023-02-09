// include in vector header (custom)

# ifndef FT_VECTOR
#define FT_VECTOR

#include <iostream>
#include "ft_iterator.hpp"
#include "ft_utils.hpp"
#include <string>
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
          _begin = _alloc.allocate(n, NULL);
          _end = _begin;
          _end_cap = _begin + n;
        }

        vector(size_type n, const value_type& value, const allocator_type& = allocator_type())  // 98
        {
          std::cout << "vector intergral constructor call " << std::endl;
          _begin = _alloc.allocate(n, NULL);
          _end = _begin;
          _end_cap = _begin + n;
          
          for (int i=0; i<n; ++i)
          {
            _alloc.construct(_end, value);
            _end++;
          }
        }

        template <class InputIterator> 
        vector(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0, const allocator_type& = allocator_type())
        {
          std::cout << "vector InputIterator constructor call " << std::endl;
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
          { return size_type(_end - _begin); } // end와 begin은 random access 라서 가능!!
        size_type max_size() const
          { return size_type(-1) / sizeof(T); }
        // void reserve(size_type n);
        size_type capacity() const {return size_type(_end_cap - _begin);}

        // // Element access:
        reference       operator[](size_type n)
        {
            if (n >= _end_cap - _begin || n < 0)
            return *(_begin);
          return reference(*(_begin + n));
        }
        const_reference operator[](size_type n) const
        {
          if (n >= _end_cap - _begin || n < 0)
            return *(_begin);
          return const_reference(*(_begin + n));
        }
        reference       at(size_type n)
        {
          if (n >= _end_cap - _begin || n < 0)
            return *(_begin);
          return reference(*(_begin + n));
        }
        const_reference at(size_type n) const
        {
          if (n >= _end_cap - _begin || n < 0)
            return *(_begin);
          return const_reference(*(_begin + n));
        }

        reference       front()
        {
          return reference(*(_begin));
        }
        const_reference front() const
        {
          return const_reference(*(_begin));
          
        }
        reference       back()
        {
          return reference(*(_end - 1));

        }
        const_reference back() const
        {
          return const_reference(*(_end - 1));
        }

        pointer       data()
        {
          if (_begin == _end_cap)
            return NULL;
          return pointer(_begin);
        }
        const const_pointer data() const
        {
          if (_begin == _end_cap)
            return NULL;
          return const_pointer(_begin);
        }

        // // Modifiers:
        void clear() 
        {
          if (_begin == _end)
            return ;
          for (pointer i = _begin; i != _end; ++i)
            _alloc.destroy(i);
          _end = _begin;
        }

        void _insert_pos_copy(unsigned int& pos, const value_type& x)
        {
          _alloc.construct(_end, 0);
          for (pointer i = _end; i != _begin + pos; --i)
            *i = *(i - 1);
          *(_begin + pos) = x;
        }

        void _insert_pos_copy(unsigned int& pos, size_type size, const value_type& x)
        {
          for (int i = 0; i < size; ++i)
          {
            _alloc.construct(_end, 0);
            _end++;
          }
          for (pointer i = _end - 1; i != _begin + pos + size - 1; --i)
          {
            *i = *(i - size);
            std::cout << *i << " " << *(i - size) << std::endl;
          }
          for (int i = 0; i < size; ++i)
            *(_begin + pos + i) = x;
        }

        iterator insert(const_iterator position, const value_type& x)
        {
          unsigned int pos = position - begin();
          if (_end != _end_cap)
          {
            _insert_pos_copy(pos, x);
            ++_end;
          }
          else
          {
            _increase_cap();
            _insert_pos_copy(pos, x);
            ++_end;
          }
          return iterator (_begin + pos);
        }

        iterator insert(const_iterator position, size_type n, const value_type& x)
        {
          unsigned int insert_size = size() + n;
          unsigned int pos = position - begin();
          if (insert_size < capacity())
          {
            _insert_pos_copy(pos, n, x);
          }
          else
          {
            _increase_cap(insert_size);
            _insert_pos_copy(pos, n, x);
          }
          return iterator(_begin + pos);
        }
        
        template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
        {
          unsigned int pos = position - begin();
          for(InputIterator i = first; i != last; ++i)
          {
            insert(position, *i);
            ++position;
          }
          return iterator(_begin + pos);
        }
        // poinstert 가 iterator 고 iterator rk Pointer의 추상화
        iterator erase(iterator position)
        {
          unsigned int pos = position - begin();
          for(pointer i = _begin + pos; i != _end - 1; ++i)
          {
            *i = *(i + 1);
          }
          --_end;
          _alloc.destroy(_end);
          return iterator(_begin + pos);
        }
        iterator erase(iterator first, iterator last)
        {
          unsigned int pos = last - first;
          for (iterator it = last; last != end(); ++it)
          {
            *(begin() + first) = *it;
          }
          for(int i=0; i<pos; ++i)
          {
            _alloc.destroy(_end);
            --_end;
          }
          return iterator(_begin);
        }
        
        // iterator 3 4 5
        // 1 2 3 4 5 6 7 8
        void _copy_mem(pointer __temp_begin, pointer __temp_end, pointer& _current_end)
        {
          for (pointer t_begin = __temp_begin; t_begin != __temp_end; ++t_begin)
          {
            _alloc.construct(_current_end, *t_begin);
            _current_end++;
          }
        }

        void _copy_value(pointer& __temp_begin, pointer& __temp_end, value_type& value)
        {
          for (pointer t_begin = __temp_begin; t_begin != __temp_end; ++t_begin)
            t_begin = value;
        }

        void _increase_cap()
        {
          size_type __old_size = size();
          size_type __new_size = __old_size != 0 ? 2 * __old_size : 1;

          pointer __temp_begin = _begin;
          pointer __temp_end = _end;
          pointer __temp_end_cap = _end_cap;
          allocator_type __temp_alloc = _alloc;

          _begin = _alloc.allocate(__new_size, NULL);
          _end = _begin;
          _end_cap = _begin + __new_size;
          _copy_mem(__temp_begin, __temp_end, _end);
          __temp_alloc.deallocate(__temp_begin, __temp_end_cap - __temp_begin);
        }

        void _increase_cap(unsigned int new_size)
        {
          size_type __old_size = size();
          size_type __new_size = new_size;

          pointer __temp_begin = _begin;
          pointer __temp_end = _end;
          pointer __temp_end_cap = _end_cap;
          allocator_type __temp_alloc = _alloc;

          _begin = _alloc.allocate(__new_size, NULL);
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
        
        void pop_back()
        {
          if (_begin == _end)
            return ;
          _alloc.destroy(_end);
          --_end;
        }

        // void resize(size_type count, value_type val = value_type())
        // {
        //   if (this.size() >= count)
        //   {
        //     _alloc.deallocate(_begin, this.capacity());
        //     _begin = _alloc.allocate(count, NULL);
        //     _end = _begin;
        //     _end_cap = _begin + count;
        //     _copy_value(__temp_begin, __temp_end, _end);
        //   }
        //   else 
        //   {
            
        //   }
        // }

        // void swap(vector& other)
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




#endif