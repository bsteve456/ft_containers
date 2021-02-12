#ifndef NODE_HPP
#define NODE_HPP


# include <iostream>
# include "../iterator_tag.hpp"
namespace ft
{
	template < typename T >
		struct Node
		{
			T elem;
			struct Node<T> *next;
			struct Node<T> *prev;
		};

	template < typename T >
		Node<T> *ft_lstnew(T elem)
		{
			Node<T> *new1;

			new1 = new Node<T>();
			new1->elem = elem;
			new1->prev = 0;
			new1->next = 0;
			return (new1);
		}
};
#endif
