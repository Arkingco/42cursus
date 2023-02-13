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
      typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef ft::reverse_iterator<iterator> reverse_iterator;

    private:
      pointer			_begin;
      pointer			_end;
      pointer			_end_cap;
      allocator_type _alloc;

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

        vector(const vector& x)
        {
          unsigned int x_capacity = x.capacity();
          _begin = _alloc.allocate(x_capacity, NULL);
          _end = _begin;
          _end_cap = _begin + x_capacity;
          for (int i=0; i<x.size(); ++i)
          {
            *_end = x[i];
            ++_end;
          }
        }
        
        // // destructor
        ~vector()
        {
          std::cout << " destructor call " << std::endl;
          if (capacity() == 0)
            return ;
          clear();
          _alloc.deallocate(_begin, _end_cap - _begin);
        }

        // // operator
        vector& operator=(const vector& other)
        {
          // if (capacity() != 0)
            // this free 작업 진행 해야함
          unsigned int other_capacity = other.capacity();
          _begin = _alloc.allocate(other_capacity, NULL);
          _end = _begin;
          _end_cap = _begin + other_capacity;
          for (int i=0; i<other.size(); ++i)
          {
            *_end = other[i];
            ++_end;
          }
          return *this;
        }

        // // assign
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
        {
          difference_type pos = last - first;
          if (pos > capacity())
            _increase_cap(pos);
          clear();
          for (InputIterator it = first; it != last; ++it)
          {
            _alloc.construct(_end, *it);
            _end++;
          }
        }
        
        void assign(size_type n, const value_type& u)
        {
          if (n > capacity())
            _increase_cap(n);
          clear();
          for (int i=0; i<n; ++i)
          {
            _alloc.construct(_end, u);
            _end++;
          }
        }

        // // get_allocator:
        allocator_type get_allocator() const { return (_alloc); }

        // // Iterstors
        iterator               begin() { return iterator (_begin); }
        const_iterator         begin() const { return const_iterator (_begin); }
        iterator               end() { return iterator (_end); }
        const_iterator         end() const { return const_iterator (_end); } 

        reverse_iterator       rbegin() { return iterator (_end); }
        const_reverse_iterator rbegin() const { return const_iterator (_end); }
        reverse_iterator       rend() { return iterator (_begin); }
        const_reverse_iterator rend() const { return const_iterator (_begin); }

        const_iterator         cbegin()  const { return const_iterator(_begin); }
        const_iterator         cend()    const { return const_iterator(_end); }
        const_reverse_iterator crbegin() const { return const_iterator(_end); }
        const_reverse_iterator crend()   const { return const_iterator(_begin); }

        // // Capacity:
        bool empty() const
        {
          if (capacity() == 0)
            return true;
          return false;
        }
        size_type size() const
          { return size_type(_end - _begin); } // end와 begin은 random access 라서 가능!!
        size_type max_size() const
          { return size_type(-1) / sizeof(T); }
        void reserve(size_type n)
        {
          if (n > capacity())
            _increase_cap(n);
          return ;
        }
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
          difference_type pos = last - first;
          iterator it_begin = begin();
          iterator it_end = end();
          for (iterator it = last; last != it_end; ++it)
          {
            *(first) = *it;
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
          // 
          __temp_alloc.deallocate(__temp_begin, __temp_end_cap - __temp_begin);
        }

        void _increase_cap(unsigned int new_size)
        {
          size_type __new_size = new_size;

          pointer __temp_begin = _begin;
          pointer __temp_end = _end;
          pointer __temp_end_cap = _end_cap;
          allocator_type __temp_alloc = _alloc;

          _begin = _alloc.allocate(__new_size, NULL);
          _end = _begin;
          _end_cap = _begin + __new_size;
          _copy_mem(__temp_begin, __temp_end, _end);
          // _alloc.destroy(i) 추가 
          __temp_alloc.deallocate(__temp_begin, __temp_end_cap - __temp_begin);
        }

        void _decrease_cap(unsigned int new_size)
        {
          size_type __new_size = new_size;

          pointer __temp_begin = _begin;
          pointer __temp_end = _end;
          pointer __temp_end_cap = _end_cap;
          allocator_type __temp_alloc = _alloc;
          _begin = _alloc.allocate(__new_size, NULL);
          _end = _begin;
          _end_cap = _begin + __new_size;
          _copy_mem(__temp_begin, __temp_begin + new_size, _end);
          // _alloc.destroy(i) 추가
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

        void resize(size_type count)
        {
          if (count > size())
          {
            _increase_cap(count);
            for (pointer i = _end; i != _end_cap; ++i)
            {
              _alloc.construct(i, 0);
              _end++;
            }
          }
          else
            _decrease_cap(count);
        }

        void resize(size_type count, value_type value)
        {
          if (count > size())
          {
            _increase_cap(count);
            for (pointer i = _end; i != _end_cap; ++i)
            {
              _alloc.construct(i, value);
              _end++;
            }
          }
          else
            _decrease_cap(count);
        }

        void swap(vector& other)
        {
          pointer __temp_begin = _begin;
          pointer __temp_end = _end;
          pointer __temp_end_cap = _end_cap;
          allocator_type __temp_alloc = _alloc;

          _begin = other._begin;
          _end = other._end;
          _end_cap = other._end_cap;
          _alloc = other._alloc;

          other._begin = __temp_begin; 
          other._end = __temp_end;
          other._end_cap = __temp_end_cap;
          other._alloc = __temp_alloc;
        }
};

  // Non-member functions
  template <class T, class Allocator>
  bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
  {
    if (x.size() != y.size())
      return false;
    for (int i=0; i<x.size(); ++i)
      if (x[i] != y[i])
        return false;
    return true;
  }

  template <class T, class Allocator>
  bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) 
  { return !(x == y); }

  template <class T, class Allocator>
  bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
  { return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }

  template <class T, class Allocator>
  bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
  {
    return !(x > y);
  }

  template <class T, class Allocator>
  bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
  {
    return ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end());
  }

  template <class T, class Allocator>
  bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
  {
    return !(x < y);
  }

}




#endif