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
		struct Node<T>						*p;
		typedef T							value_type;
		typedef std::allocator<value_type>	allocator_type;
		typedef	value_type&					reference;
		typedef	const	value_type&			const_reference;
		typedef	value_type *				pointer;
		typedef	const value_type *			const_pointer;
		typedef	MyIterator<value_type>		iterator;
		typdef	MyConstIterator<value_type>	const_iterator;
		typedef	size_t						size_type;
		typedef	ptrdiff_t					difference_type;
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
