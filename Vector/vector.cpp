#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../iterator_tag.hpp"

namespace ft
{
		template < class T, class Alloc = allocator<T> >
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
/*				typedef	MyIterator<bidirectional_iterator_tag, T>			iterator;
				typedef	MyIterator<bidirectional_iterator_tag, T, true>		const_iterator;
				typedef MyReverseIterator<iterator>							reverse_iterator;
				typedef MyReverseIterator<const_iterator>					const_reverse_iterator; */
				typedef	size_t												size_type;
				typedef	std::ptrdiff_t										difference_type;
				vector<value_type>(void) : p(0), s(0)
				{}
				vector<value_type>(size_type n, const value_type &val) : p(0), s(0)
				{
					this->p = new T[n + 20];
					this->s = n;
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
	//				*this = x;
					this->p = new T[v.size()];
					this->s = v.size();
					this->cap = v.capacity();
					for(size_type i = 0; i < v.size(); i++)
						(*this)[i] = v[i];
				}
/*				vector<value_type> & operator = (vector<value_type> const &v)
				{
					if(this != &v)
					{
						this->clear();
						this->p = new T[v.size()];
						for(size_type i = 0; i < v.size(); i++)
							this->p[i] = v[i];
						if(!l.empty())
							this->assign(l.begin(), l.end());
					}
					return *this;
				}*/
				~vector()
				{
					this->clear();
				}
				reference operator[] (size_type n)
				{
					return this->p[n];
				}
				size_value		size() const
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
					if (this->n < this->cap)
					{
						(*this)[this->n] = val;
						this->n += 1;
					}
					else
					{
						tmp = new T[this->n * 2];
						for (size_value i = 0; i < n; i++)
							tmp[i] = this->p[i];
						tmp[this->n] = val;
						this->cap = this->n * 2;
						this->n += 1;
						this->clear();
						this->p = tmp;
					}
				}
		}
};


#endif
