#ifndef MYMAPITERATOR_HPP
# define MYMAPITERATOR_HPP

#include "Node.hpp"
namespace ft
{
	template< class Category, class T, bool isconst = false>
		class MyMapIterator
		{
			public:
				typedef typename choose<isconst, const T, T>::type				value_type;
				typedef std::ptrdiff_t	difference_type;
				typedef typename choose<isconst, const T *, T *>::type	pointer;
				typedef	typename choose<isconst, const T &, T &>::type	reference;
				typedef typename choose<isconst, const Node<T> *, Node<T> * >::type nodeptr;
				typedef Category		iterator_category;

				MyMapIterator() : p(0)
				{}
				MyMapIterator(struct Node<T> * x) : p(x)
			{}
				MyMapIterator(MyMapIterator<Category, T, false> const & mit) : p(mit.getn())
			{
			
			}
				MyMapIterator & operator = (MyMapIterator const & mit)
				{
					p = mit.getn();
					return *this;
				}
				nodeptr		getn() const
				{
					return p;
				}
				~MyMapIterator(){}
				MyMapIterator & operator++()
				{
					if(p && p->next)
						p = p->next;
					return *this;
				}
				MyMapIterator & operator--()
				{
					if(p && p->prev)
						p = p->prev;
					return *this;
				}
				MyMapIterator operator++(int n)
				{
					(void)n;
					MyMapIterator tmp(*this);
					operator++();
					return tmp;
				}
				MyMapIterator operator--(int n)
				{
					(void)n;
					MyMapIterator tmp(*this);
					operator--();
					return tmp;
				}
				pointer operator->() const
				{
					return &(operator *());
				}
				bool operator==(const MyMapIterator &rhs) const
				{
					return p==rhs.p;
				}
				bool operator!=(const MyMapIterator &rhs) const
				{
					return p!=rhs.p;
				}
				reference operator *() const
				{
					return *(p->value);
				}
				pointer operator *(T & elem)
				{
					p->value = elem;
					return *(p->value);
				}
			protected:
				nodeptr				p;

		};
};

#endif
