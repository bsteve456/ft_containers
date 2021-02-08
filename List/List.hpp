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

# include "Node.hpp"

template < class T, class Alloc = std::allocator<T> >
class List
{
	private:
		struct Node<T> *p;
	public:
		List(void) : p(0) {}
		List<T>(int n, T elem)
		{
			p = 0;
			for (int i = 0; i < n; i++)
				this->push_back(elem);
		}
/*		List<T>(List<T> const &l)
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
		}*/
		void push_back(T elem)
		{
			ft_lstadd_back<T>(&(this->p), ft_lstnew(elem));
		}
		void	getAllElem(void) const
		{
			Node<T> *tmp = p;
			while(tmp)
			{
				std::cout << p->elem << std::endl;
				tmp = tmp->next;
			}
		}
};


#endif
