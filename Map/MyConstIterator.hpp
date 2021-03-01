#ifndef MYCONSTITERATOR_HPP
# define MYCONSTITERATOR_HPP

#include "Node.hpp"
namespace ft
{
	template< class Category, class T>
		class MyConstIterator
		{
			private:
				Node<T>				*p;
			public:
				typedef T				value_type;
				typedef std::ptrdiff_t	difference_type;
				typedef T *				pointer;
				typedef	T &				reference;
				typedef Category		iterator_category;
				MyConstIterator() : p(0)
				{}
				MyConstIterator(struct Node<T> * x) : p(x)
			{}
				MyConstIterator(MyConstIterator const & mit) : p(mit.p)
			{}
				MyConstIterator & operator = (MyConstIterator const & mit)
				{
					p = mit.p;
					return *this;
				}
				~MyConstIterator(){}
				MyConstIterator & operator++()
				{
					if(p && p->next)
						p = p->next;
					return *this;
				}
				MyConstIterator & operator--()
				{
					if(p && p->prev)
						p = p->prev;
					return *this;
				}
				MyConstIterator operator++(int n)
				{
					(void)n;
					MyConstIterator tmp(*this);
					operator++();
					return tmp;
				}
				MyConstIterator operator--(int n)
				{
					(void)n;
					MyConstIterator tmp(*this);
					operator--();
					return tmp;
				}
				pointer operator->() const
				{
					return &(operator *());
				}
				bool operator==(const MyConstIterator &rhs) const
				{
					return p==rhs.p;
				}
				bool operator!=(const MyConstIterator &rhs) const
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
