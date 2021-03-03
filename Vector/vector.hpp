#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "MyIterator.hpp"
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
				/*				typedef MyReverseIterator<iterator>							reverse_iterator;
								typedef MyReverseIterator<const_iterator>					const_reverse_iterator; */
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
					if (this->s < this->cap)
					{
						(*this)[this->s] = val;
						this->s += 1;
					}
					else
					{
						tmp = new T[this->s * 2];
						for (size_type i = 0; i < this->s; i++)
							tmp[i] = this->p[i];
						tmp[this->s] = val;
						this->cap = this->s * 2;
						this->s += 1;
						this->clear();
						this->p = tmp;
					}
				}
				bool empty() const
				{
					if(this->size())
						return 0;
					return 1;
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
