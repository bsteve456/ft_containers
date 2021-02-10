#ifndef NODE_HPP
#define NODE_HPP


# include <iostream>

template < typename T >
struct Node
{
		T elem;
		struct Node<T> *next;
		struct Node<T> *prev;
		struct Node<T> *past_the_end;
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

template < typename T >
void	ft_lstadd_back(Node<T> **alst, Node<T> *new1)
{
	Node<T> *lst;

	lst = *alst;
	if(!lst)
		*alst = new1;
	else
	{
		while(lst->next)
			lst = lst->next;
		new1->prev = lst;
		lst->next = new1;
	}
}

#endif
