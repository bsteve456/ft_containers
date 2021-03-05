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
				vector<value_type>(void) : p(0), s(0), cap(0)
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
				reference at (size_type n)
				{
					return this->p[n];
				}
				const_reference at (size_type n) const
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
						else
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
				void reserve (size_type n)
				{
					T *tmp;
					size_type tp = 0;

					tmp = new T[n];
					for (size_type i = 0; i < this->s; i++)
						tmp[i] = this->p[i];
					tp = this->s;
					this->clear();
					this->p = tmp;
					this->s = tp;
					this->cap = n;
				}
				reference front()
				{
					return *(this->p);
				}
				const_reference front() const
				{
					return *(this->p);
				}
				reference back()
				{
					if(this->size() <= 1)
						return *(this->p);
					else
						return *(this->p + this->s - 1);
				}
				const_reference back() const
				{
					if(this->size() <= 1)
						return *(this->p);
					else
						return *(this->p + this->s - 1);
				}
				void clear()
				{
					delete [] this->p;
					this->p = 0;
					this->s = 0;
					this->cap = 0;
				}
				void assign(size_type n, const value_type &val)
				{
					for (size_type i = 0; i < n; i++)
					{
						this->push_back(val);
					}
				}
				iterator insert (iterator position, const value_type& val)
				{
					T *tmp;
					size_type i = 0;
					size_type tp = 0;
					size_type tv = 0;
					iterator it = this->begin();
					if(this->size() == this->capacity())
						this->resize(this->s + 1);
					tmp = new T[this->capacity()];
					while(it != this->end() && it != position)
					{
						it++;
						i++;
					}
					for (size_type j = 0; j < i; j++)
						tmp[j] = this->p[j];
					 tmp[i] = val;
					 for (size_type j = i + 1; j < this->capacity(); j++)
						 tmp[j] = this->p[j - 1];
					tp = this->size();
					tv = this->capacity();
					this->clear();
					this->p = tmp;
					this->s = tp + 1;
					this->cap = tv;
					return (iterator(this->p + i));
				}
				void insert (iterator position, size_type n, const value_type& val)
				{
					for(size_type i = 0; i < n; i++)
						position = insert(position, val);
				}
				iterator erase (iterator position)
				{
					T *tmp;
					size_type i = 0;
					size_type tp = 0;
					size_type tv = 0;

					iterator it = this->begin();
					tmp = new T[this->capacity()];
					while(it != this->end() && it != position)
					{
						it++;
						i++;
					}
					for (size_type j = 0; j < i; j++)
						tmp[j] = this->p[j];
					 for (size_type j = i; j < this->capacity(); j++)
						 tmp[j] = this->p[j + 1];
					tp = this->size();
					tv = this->capacity();
					position++;
					this->clear();
					this->p = tmp;
					this->s = tp - 1;
					this->cap = tv;
					return (iterator(tmp + i));
				}
				iterator erase (iterator first, iterator last)
				{
					size_type i = 0;
					for(iterator it = first; it != last; ++it)
						i++;
					for(size_type j = 0; j < i; ++j)
						first = erase(first);
					return first;
				}
				void swap (vector& x)
				{
					std::swap(*this, x);
				}
		};
};


#endif
