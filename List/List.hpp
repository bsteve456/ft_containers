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
# include "MyIterator.hpp"


template < class T, class Alloc = std::allocator<T> >
class List
{
	private:
		Node<T>						*p;
	public:
		typedef T							value_type;
		typedef std::allocator<value_type>	allocator_type;
		typedef	value_type&					reference;
		typedef	const	value_type&			const_reference;
		typedef	value_type *				pointer;
		typedef	const value_type *			const_pointer;
		typedef	MyIterator<T>				iterator;
		typedef	MyIterator<const T>			const_iterator;
		typedef	size_t						size_type;
		typedef	ptrdiff_t					difference_type;
		List<value_type>(void) : p(0) {}
		List<value_type>(int n)
		{
			p = 0;
			for (int i = 0; i < n; i++)
				this->push_back(0);
		}
		List<value_type>(int n, value_type elem)
		{
			p = 0;

			for (int i = 0; i < n; i++)
				this->push_back(elem);
		}
		List<value_type>(List<value_type> const &l)
		{
			p = 0;
			*this = l;
		}
		List<value_type>(iterator first, iterator last)
		{
			p = 0;
			this->assign(first, last);
		}
		List<value_type> & operator = (List<value_type> const &l)
		{
			if (this != &l)
			{
				this->clear();
				const_iterator it = l.begin();
				const_iterator ite = l.end();
				this->assign(it, ite);
			}
			return (*this);
		}
		~List()
		{
			this->clear();
		}
		void push_back(const value_type &elem)
		{
			ft_lstadd_back<value_type>(&(this->p), ft_lstnew(elem));
		}
		size_type	size(void) const
		{
			Node<T> *tmp = this->p;
			size_type count = 0;

			if(p == 0)
				return (0);
			while(tmp)
			{
				count++;
				tmp = tmp->next;
			}
			return count;
		}
		bool empty() const
		{
			if(!this->size())
				return 0;
			return 1;
		}
		void pop_back()
		{
			Node<value_type> *tmp = this->p;
			Node<value_type> *t = tmp;
			if(!tmp)
				return ;
			while(tmp->next)
			{
				t = tmp;
				tmp = tmp->next;
			}
			t->next = 0;
			if(this->size() == 1)
				this->p = 0;
			delete(tmp);
		}
		iterator begin()
		{
			return iterator(this->p);
		}
		const_iterator begin() const
		{
			Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->p);
			return const_iterator(tmp);
		}
		iterator end()
		{
			if(p == 0)
				return begin();
			Node<T> *tmp = this->p;
			while(tmp->next)
				tmp = tmp->next;
			return iterator(tmp->next);
		}
		const_iterator end() const
		{
			if(p == 0)
				return begin();
			Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->p);
			while(tmp->next)
				tmp = tmp->next;
			return const_iterator(tmp->next);
		}
		template < class InputIterator >
		void assign(InputIterator first, InputIterator last)
		{
			for (InputIterator it = first; it != last; it++)
				this->push_back(*it);
		}
		void clear()
		{
			while(this->empty())
				this->pop_back();
		}
};


#endif
