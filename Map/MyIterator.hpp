#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "Node.hpp"
namespace ft
{
	template< class Category, class T>
		class MyIterator
		{
			private:
				Node<T>				*p;
			public:
				typedef T				value_type;
				typedef std::ptrdiff_t	difference_type;
				typedef T *				pointer;
				typedef	T &				reference;
				typedef Category		iterator_category;
				MyIterator() : p(0)
				{}
				MyIterator(struct Node<T> * x) : p(x)
			{}
				MyIterator(MyIterator const & mit) : p(mit.p)
			{}
				MyIterator & operator = (MyIterator const & mit)
				{
					p = mit.p;
					return *this;
				}
				~MyIterator(){}
				MyIterator & operator++()
				{
					if(p && p->next)
						p = p->next;
					return *this;
				}
				MyIterator & operator--()
				{
					if(p && p->prev)
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
				T	& operator *() const
				{
					return *(p->value);
				}
				T	& operator *(T & elem)
				{
					p->value = elem;
					return *(p->value);
				}
		};
};

#endif
