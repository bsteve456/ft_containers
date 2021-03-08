#ifndef MYLISTITERATOR_HPP
# define MYLISTITERATOR_HPP

#include "Node.hpp"
namespace ft
{
	template< class Category, class T, bool isconst = false >
		class MyListIterator
		{
			public:
				typedef typename choose<isconst, const T, T>::type				value_type;
				typedef std::ptrdiff_t	difference_type;
				typedef typename choose<isconst, const T *, T*>::type				pointer;
				typedef	typename choose<isconst, const T &, T&>::type				reference;
				typedef Category		iterator_category;
				typedef typename choose<isconst, const Node<T> *, Node<T> *>::type nodeptr;
				MyListIterator() : p(0) {}
				MyListIterator(struct Node<T> * x) : p(x)
			{}
				MyListIterator(MyListIterator<Category, T, false> const & mit) : p(mit.getn())
			{}
				MyListIterator & operator = (MyListIterator const & mit)
				{
					p = mit.getn();
					return *this;
				}
				nodeptr getn() const
				{
					return p;
				}
				~MyListIterator(){}
				MyListIterator & operator++()
				{
					if(p && p->next)
						p = p->next;
					return *this;
				}
				MyListIterator & operator--()
				{
					if (p && p->prev)
						p = p->prev;
					return *this;
				}
				MyListIterator operator++(int n)
				{
					(void)n;
					MyListIterator tmp(*this);
					operator++();
					return tmp;
				}
				MyListIterator operator--(int n)
				{
					(void)n;
					MyListIterator tmp(*this);
					operator--();
					return tmp;
				}
				pointer operator->() const
				{
					return &(operator *());
				}
				bool operator==(const MyListIterator &rhs) const
				{
					return p==rhs.p;
				}
				bool operator!=(const MyListIterator &rhs) const
				{
					return p!=rhs.p;
				}
				reference operator *() const
				{
					return p->elem;
				}
				reference operator *(T & elem)
				{
					p->elem = elem;
					return p->elem;
				}
			private:
				nodeptr				p;

		};
};

#endif
