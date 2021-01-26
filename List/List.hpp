/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:54:47 by stbaleba          #+#    #+#             */
/*   Updated: 2021/01/26 15:31:21 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>

template < typename T >
struct dlist
{
		T elem;
		struct dlist *next;
		struct dlist *prev;
};

template < typename T >
dlist *ft_lstnew(T elem)
{
	dlist *new1;

	new1 = new dlist();
	new1->elem = elem;
	new1->prev = 0;
	new1->next = 0;
	return (new1);
}

template < typename T >
void	ft_lstadd_back(dlist **alst, dlist **new1)
{
	dlist *lst;

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

template < class T, class Alloc = allocator<T> >
class List
{
	private:
		dlist *p;
	public:
		List(void) : (0) {}
		List<T>(int n, T elem)
		{
			p = 0;
			for (int i = 0; i < n; i++)
				this->push_back(elem);
		}
		List<T>(List<T> const &l)
		{
			*this = l;
		}
		List<T> & operator = (List<T> const &l)
		{
			if (this != &l)
			{
				while(!this->empty())
					this->pop_back();
				this->assign(l.begin(), l.end());
			}
			return (*this);
		}
		~List()
		{
			while(!this->empty())
				this->pop_back();
		}
		void push_back(T elem)
		{
			ft_lstadd_back(&(this->p), ft_lstnew(elem));
		}
};


#endif
