#ifndef MYREVERSEITERATOR_HPP
# define MYREVERSEITERATOR_HPP

#include "Node.hpp"
#include "MyIterator.hpp"

namespace ft
{
	template< class T >
		class MyReverseIterator : public MyIterator<T>
	{
		private:
			Node<T>				*p1;
			using	MyIterator<T>::p;
		public:
			typedef T			value_type;
			typedef ptrdiff_t	difference_type;
			typedef T *			pointer;
			typedef	T &			reference;
			MyReverseIterator(struct Node<T> * x) : MyIterator<T>(x), p1(x)
		{}
			MyReverseIterator(MyReverseIterator const & mit) : MyIterator<T>(mit.p1), p1(mit.p1)
		{}
			MyReverseIterator & operator = (MyReverseIterator const & mit)
			{
				p1 = mit.p1;
				p = mit.p1;
				return *this;
			}
			~MyReverseIterator(){}
			MyReverseIterator & operator++()
			{
				if(p1 && p1->prev)
					p1 = p1->prev;
				else if(p1)
					p1 = p1->past_the_end;
				return *this;
			}
			MyReverseIterator & operator--()
			{
				if (p1 && p1->next)
					p1 = p1->next;
				else if(p)
					p1 = p1->past_the_end;
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
				return p1 ==rhs.p1;
			}
			bool operator!=(const MyReverseIterator &rhs) const
			{
				return p1!=rhs.p1;
			}
			T	& operator *() const
			{
				return p1->elem;
			}
			T	& operator *(T & elem)
			{
				p1->elem = elem;
				return p1->elem;
			}
	};
};

#endif
