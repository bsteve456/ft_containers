#ifndef NODE_HPP
#define NODE_HPP


# include <iostream>
# include "../iterator_tag.hpp"
# include <utility>
# include <functional>
namespace ft
{
	template < typename Pair>
		struct Node
		{
			Pair *value;
			struct Node<Pair> *next;
			struct Node<Pair> *prev;
		};

	template < typename Pair >
		Node<Pair> *ft_lstnew(Pair * value)
		{
			Node<Pair> *new1;

			new1 = new Node<Pair>();
			new1->value = value;
			new1->prev = 0;
			new1->next = 0;
			return (new1);
		}
};
#endif
