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
		MyIterator(struct Node<T> * x) : p(x)
		{}
		Node<T> *	getP() const
		{
			return p;
		}
		MyIterator(MyIterator const & mit) : p(mit.getP())
		{}
		MyIterator & operator++()
		{
			if(p && p->next)
				p = p->next;
			else if(p)
				p = p->past_the_end;
			return *this;
		}
		MyIterator & operator--()
		{
			if (p && p->prev)
				p = p->prev;
			else if(p)
				p = p->past_the_end;
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
