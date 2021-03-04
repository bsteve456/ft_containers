#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "MyIterator.hpp"
# include "MyReverseIterator.hpp"
# include "../iterator_tag.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			private:
				T *p;
				size_t s;
				size_t cap;
			public:
				typedef T													value_type;
				typedef std::allocator< T >									allocator_type;
				typedef	value_type&											reference;
				typedef	const	value_type&									const_reference;
				typedef	value_type *										pointer;
				typedef	const value_type *									const_pointer;
				typedef	MyIterator<random_access_iterator_tag, T>			iterator;
				typedef	MyIterator<bidirectional_iterator_tag, T, true>		const_iterator;
				typedef MyReverseIterator<iterator>							reverse_iterator;
				typedef MyReverseIterator<const_iterator>					const_reverse_iterator;
				typedef	size_t												size_type;
				typedef	std::ptrdiff_t										difference_type;
				vector<value_type>(void) : p(0), s(0)
			{}
				vector<value_type>(size_type n, const value_type &val) : p(0), s(0)
			{
				this->p = new T[n + 20];
				this->s = 0;
				this->cap = n + 20;
				for (size_t i = 0; i < this->cap; i++)
				{
					if(i < n)
						this->push_back(val);
					else
						(*this)[i] = 0;
				}
			}
				vector<value_type> (const vector &x) : p(0), s(0)
			{
					*this = x;
			}
				vector<value_type> & operator = (vector<value_type> const &x)
				{
					if(this != &x)
					{
						this->clear();
						this->p = new T[x.capacity()];
						this->s = x.size();
						this->cap = x.capacity();
						if (!x.empty())
						{
							for(size_type i = 0; i < x.capacity(); i++)
								(*this)[i] = x[i];
						}
					}
					return *this;
				}
				~vector()
				{
					this->clear();
				}
				reference operator[] (size_type n)
				{
					return this->p[n];
				}
				const_reference operator[] (size_type n) const
				{
					return this->p[n];
				}
				size_type		size() const
				{
					return (this->s);
				}
				size_type capacity() const
				{
					return (this->cap);
				}
				void push_back (const value_type& val)
				{
					T *tmp;
					size_type tp;
					size_type tv;
					if (this->s < this->cap)
					{
						(*this)[this->s] = val;
						this->s += 1;
					}
					else
					{
						if(this->cap == 0)
							this->cap = 1;
						this->cap *= 2;
						tmp = new T[this->cap];
						for (size_type i = 0; i < this->s; i++)
							tmp[i] = this->p[i];
						tmp[this->s] = val;
						this->s += 1;
						tp = this->s;
						tv = this->cap;
						this->clear();
						this->p = tmp;
						this->s = tp;
						this->cap = tv;
					}
				}
				void pop_back()
				{
					if(this->s != 0)
					{
						(*this)[this->s - 1] = 0;
						this->s -= 1;
					}
				}
				bool empty() const
				{
					if(this->size())
						return 0;
					return 1;
				}
				size_type max_size() const
				{
					return (std::allocator< T >().max_size());
				}
				iterator begin()
				{
					return iterator(this->p);
				}
				iterator end()
				{
					return iterator(this->p + this->s);
				}
				const_iterator begin() const
				{
					return const_iterator(this->p);
				}
				const_iterator end() const
				{
					return const_iterator(this->p + this->s);
				}
				reverse_iterator rbegin()
				{
					return reverse_iterator(iterator(this->p + this->s - 1));
				}
				reverse_iterator rend()
				{
					return reverse_iterator(iterator(this->p - 1));
				}
				const_reverse_iterator rbegin() const
				{
					return reverse_const_iterator(const_iterator(this->p + this->s - 1));
				}
				const_reverse_iterator rend() const
				{
					return reverse_const_iterator(const_iterator(this->p - 1));
				}
				void resize (size_type n, value_type val = value_type())
				{
					while (this->size() > n)
						this->pop_back();
					while (this->size() < n)
						this->push_back(val);
				}
				void clear()
				{
					delete [] this->p;
					this->p = 0;
					this->s = 0;
					this->cap = 0;
				}
		};
};


#endif
