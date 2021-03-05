#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "vector.hpp"
# include "../iterator_tag.hpp"

namespace ft
{
	template< class Category, class T, bool isconst = false >
		class MyIterator
		{
			public:
				typedef typename choose<isconst, const T, T>::type				value_type;
				typedef std::ptrdiff_t	difference_type;
				typedef typename choose<isconst, const T *, T*>::type				pointer;
				typedef	typename choose<isconst, const T &, T&>::type				reference;
				typedef Category		iterator_category;
				typedef typename choose<isconst, const T * , T *>::type nodeptr;
				MyIterator() : p(0) {}
				MyIterator(T *x) : p(x)
			{}
				MyIterator(MyIterator<Category, T, false> const & mit) : p(mit.getn())
			{}
				MyIterator & operator = (MyIterator const & mit)
				{
					p = mit.getn();
					return *this;
				}
				nodeptr getn() const
				{
					return p;
				}
				~MyIterator(){}
				MyIterator & operator++()
				{
					p++;
					return *this;
				}
				MyIterator & operator--()
				{
					p--;
					return *this;
				}
				MyIterator operator++(int n)
				{
					(void)n;
					MyIterator tmp(*this);
					operator++();
					return tmp;
				}
				MyIterator operator--(int n)
				{
					(void)n;
					MyIterator tmp(*this);
					operator--();
					return tmp;
				}
				pointer operator->() const
				{
					return &(operator *());
				}
				bool operator==(const MyIterator &rhs) const
				{
					return p==rhs.p;
				}
				bool operator!=(const MyIterator &rhs) const
				{
					return p!=rhs.p;
				}
				MyIterator	operator+(int n)
				{
					this->p = this->p + n;
					return *this;
				}
				MyIterator	operator-(int n)
				{
					this->p = this->p - n;
					return *this;
				}
				reference operator *() const
				{
					return *p;
				}
/*				reference operator *(T & elem)
				{
					p->elem = elem;
					return p->elem;
				}*/
			private:
				nodeptr				p;

		};
};

#endif
