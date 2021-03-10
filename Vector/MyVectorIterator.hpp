#ifndef MYVECTORITERATOR_HPP
# define MYVECTORITERATOR_HPP

#include "vector.hpp"
# include "../iterator_tag.hpp"

namespace ft
{
	template< class Category, class T, bool isconst = false >
		class MyVectorIterator
		{
			public:
				typedef typename choose<isconst, const T, T>::type				value_type;
				typedef std::ptrdiff_t	difference_type;
				typedef typename choose<isconst, const T *, T*>::type				pointer;
				typedef	typename choose<isconst, const T &, T&>::type				reference;
				typedef Category		iterator_category;
				typedef typename choose<isconst, const T * , T *>::type nodeptr;
				MyVectorIterator() : p(0) {}
				MyVectorIterator(T *x) : p(x)
			{}
				MyVectorIterator(MyVectorIterator<Category, T, false> const & mit) : p(mit.getn())
			{}
				MyVectorIterator & operator = (MyVectorIterator const & mit)
				{
					p = mit.getn();
					return *this;
				}
				nodeptr getn() const
				{
					return p;
				}
				~MyVectorIterator(){}
				MyVectorIterator & operator++()
				{
					p++;
					return *this;
				}
				MyVectorIterator & operator--()
				{
					p--;
					return *this;
				}
				MyVectorIterator operator++(int n)
				{
					(void)n;
					MyVectorIterator tmp(*this);
					operator++();
					return tmp;
				}
				MyVectorIterator operator--(int n)
				{
					(void)n;
					MyVectorIterator tmp(*this);
					operator--();
					return tmp;
				}
				pointer operator->() const
				{
					return &(operator *());
				}
				bool operator==(const MyVectorIterator &rhs) const
				{
					return p==rhs.p;
				}
				bool operator!=(const MyVectorIterator &rhs) const
				{
					return p!=rhs.p;
				}
				bool operator<(const MyVectorIterator &rhs) const
				{
					return p<rhs.p;
				}
				bool operator>(const MyVectorIterator &rhs) const
				{
					return p>rhs.p;
				}
				bool operator<=(const MyVectorIterator &rhs) const
				{
					return p<=rhs.p;
				}
				bool operator>=(const MyVectorIterator &rhs) const
				{
					return p>=rhs.p;
				}
				MyVectorIterator	operator+(int n)
				{
					this->p = this->p + n;
					return *this;
				}
				MyVectorIterator	operator-(int n)
				{
					this->p = this->p - n;
					return *this;
				}
				MyVectorIterator	operator+=(int n)
				{
					operator+(n);
					return *this;
				}
				MyVectorIterator	operator-=(int n)
				{
					operator-(n);
					return *this;
				}
				int			operator-(MyVectorIterator mit)
				{
					return this->p - mit.p;
				}
				reference operator *() const
				{
					return *p;
				}
				reference operator[] (int n)
				{
					operator+(n);
					return *p;
				}
				template <class Categ, class Tp, bool isconsta>
					friend MyVectorIterator<Categ, Tp, isconsta> operator+ (typename MyVectorIterator<Categ, Tp, isconsta>::difference_type n, const MyVectorIterator<Categ, Tp, isconsta>& it);
			protected:
				nodeptr				p;
		};
	template <class Category, class T, bool isconst>
		MyVectorIterator<Category, T, isconst> operator+ (typename MyVectorIterator<Category, T, isconst>::difference_type n, const MyVectorIterator<Category, T, isconst>& it)
		{
			return it.p + n;
		}

};

#endif
