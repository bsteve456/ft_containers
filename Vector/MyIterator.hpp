#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "vector.hpp"
# include "../iterator_tag.hpp"

namespace ft
{
	template <class T, class Alloc> class vector;
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
				MyIterator(MyIterator<Category, T, false> const & mit) : p(mit.p)
			{}
				MyIterator & operator = (MyIterator const & mit)
				{
					p = mit.p;
					return *this;
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
				bool operator<(const MyIterator &rhs) const
				{
					return p<rhs.p;
				}
				bool operator>(const MyIterator &rhs) const
				{
					return p>rhs.p;
				}
				bool operator<=(const MyIterator &rhs) const
				{
					return p<=rhs.p;
				}
				bool operator>=(const MyIterator &rhs) const
				{
					return p>=rhs.p;
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
				MyIterator	operator+=(int n)
				{
					operator+(n);
					return *this;
				}
				MyIterator	operator-=(int n)
				{
					operator-(n);
					return *this;
				}
				int			operator-(MyIterator mit)
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
					friend MyIterator<Categ, Tp, isconsta> operator+ (typename MyIterator<Categ, Tp, isconsta>::difference_type n, const MyIterator<Categ, Tp, isconsta>& it);
			private:
				nodeptr				p;
				template <class, class> friend class vector;
		};
		template <class Category, class T, bool isconst>
			MyIterator<Category, T, isconst> operator+ (typename MyIterator<Category, T, isconst>::difference_type n, const MyIterator<Category, T, isconst>& it)
			{
				return it.p + n;
			}

};

#endif
