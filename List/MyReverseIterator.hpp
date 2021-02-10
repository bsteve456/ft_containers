#ifndef MYREVERSEITERATOR_HPP
# define MYREVERSEITERATOR_HPP

#include "Node.hpp"
namespace ft
{
	template< class T >
		class MyReverseIterator : public iterator
	{
		private:
			Node<T>				*p;
		public:
			typedef T			value_type;
			typedef ptrdiff_t	difference_type;
			typedef T *			pointer;
			typedef	T &			reference;
			MyReverseIterator(struct Node<T> * x) : p(x)
		{}
/*			Node<T> *	getP() const
			{
				return p;
			}*/
			MyReverseIterator(MyReverseIterator const & mit) : p(mit.getP())
		{}
			MyReverseIterator & operator = (MyReverseIterator const & mit)
			{
				p = mit.getP();
				return *this;
			}
			~MyReverseIterator(){}
			MyReverseIterator & operator++()
			{
				if(p && p->next)
					p = p->next;
				else if(p)
					p = p->past_the_end;
				return *this;
			}
			MyReverseIterator & operator--()
			{
				if (p && p->prev)
					p = p->prev;
				else if(p)
					p = p->past_the_end;
				return *this;
			}
			MyReverseIterator operator++(int n)
			{
				(void)n;
				MyReverseIterator tmp(*this);
				operator++();
				return tmp;
			}
			MyReverseIterator operator--(int n)
			{
				(void)n;
				MyReverseIterator tmp(*this);
				operator--();
				return tmp;
			}
			pointer operator->() const
			{
				return &(operator *());
			}
			bool operator==(const MyReverseIterator &rhs) const
			{
				return p==rhs.p;
			}
			bool operator!=(const MyReverseIterator &rhs) const
			{
				return p!=rhs.p;
			}
			T	& operator *() const
			{
				return p->elem;
			}
			T	& operator *(T & elem)
			{
				p->elem = elem;
				return p->elem;
			}
	};
};

#endif
