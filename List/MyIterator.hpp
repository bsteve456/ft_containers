#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "Node.hpp"
namespace ft
{
	template< class Category, class T, bool isconst = false >
		class MyIterator
		{
			public:
				typedef typename choose<isconst, const T, T>::type				value_type;
				typedef std::ptrdiff_t	difference_type;
				typedef typename choose<isconst, const T *, T*>::type				pointer;
				typedef	typename choose<isconst, const T &, T&>::type				reference;
				typedef Category		iterator_category;
				typedef typename choose<isconst, const Node<T> *, Node<T> *>::type nodeptr;
				MyIterator() : p(0) {}
				MyIterator(struct Node<T> * x) : p(x)
			{}
				MyIterator(MyIterator<Category, T, false> const & mit) : p(mit.getn())
			{}
				MyIterator & operator = (MyIterator const & mit)
				{
					p = mit.getn();
					return *this;
				}
				nodeptr getn() const
				{
					return p;
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
					if (p && p->prev)
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
