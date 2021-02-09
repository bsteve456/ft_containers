#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "Node.hpp"

template< class T >
class MyIterator
{
	private:
		Node<T>				*p;
	public:
		typedef T			value_type;
		typedef ptrdiff_t	difference_type;
		typedef T *			pointer;
		typedef	T &			reference;
		MyIterator(struct Node<T> * x) : p(x) {}
		MyIterator(MyIterator const & mit) : p(mit.p) {}
		MyIterator & operator++()
		{
			if (p != 0)
				p = p->next;
			return *this;
		}
		MyIterator & operator--()
		{
			if (p != 0)
				p = p->prev;
			return *this;
		}
		MyIterator operator++(int n)
		{
			(void)n;
			MyIterator tmp(*this);
			operator++();
			return tmp;
		}
		Node<T> *	getP() const
		{
			return p;
		}
		bool operator==(const MyIterator &rhs) const
		{
			return p==rhs.getP();
		}
		bool operator!=(const MyIterator &rhs) const
		{
			return p!=rhs.getP();
		}
		T	& operator *()
		{
			return p->elem;
		}
};


#endif
