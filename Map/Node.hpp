#ifndef NODE_HPP
#define NODE_HPP


# include <iostream>
# include "../iterator_tag.hpp"
namespace ft
{
	template < typename Key, typename T >
		struct Node
		{
			Key key;
			T value;
			struct Node<Key, T> *next;
			struct Node<Key, T> *prev;
		};

	template < typename Key, typename T >
		Node<Key, T> *ft_lstnew(Key key, T value)
		{
			Node<Key, T> *new1;

			new1 = new Node<Key, T>();
			new1->key = key;
			new1->value = value;
			new1->prev = 0;
			new1->next = 0;
			return (new1);
		}
};
#endif
