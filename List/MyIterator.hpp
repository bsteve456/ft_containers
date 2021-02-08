#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "Node.hpp"

Template< class T >
class MyIterator
{
	private:
		Node<T>				*p;
	public:
		typedef T			value_type;
		typedef ptrdiff_t	difference_type;
		typedef T *			pointer;
		typedef	T &			reference;
		MyIterator(Node<T> * x) : p(x) {}
		MyIterator(const MyIterator &mit) : p(mit.p) {}
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
