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
# include "MyReverseIterator.hpp"
# include <limits>
# include <algorithm>

namespace ft
{
	template < class T, class Alloc = std::allocator< T > >
		class List
		{
			private:
				Node<T>						*p;
				Node<T>						*Helem;
				Node<T>						*Last() const
				{
					Node<T> *tmp = this->p;
					if(!tmp)
						return (0);
					while(tmp->next && tmp->next != this->Helem)
						tmp = tmp->next;
					return tmp;
				}
				Node<T>					*init_last()
				{
					Node<T> *hollow_elem;
					value_type random = 0;
					hollow_elem = ft_lstnew(random);
					hollow_elem->prev = this->Last();
					hollow_elem->next = this->p;
					return hollow_elem;
				}
			public:
				typedef T													value_type;
				typedef std::allocator< T >									allocator_type;
				typedef std::allocator< Node< T > >							node_allocator_type;
				typedef	value_type&											reference;
				typedef	const	value_type&									const_reference;
				typedef	value_type *										pointer;
				typedef	const value_type *									const_pointer;
				typedef	MyIterator<bidirectional_iterator_tag, T>			iterator;
				typedef	MyIterator<bidirectional_iterator_tag, const T>		const_iterator;
				typedef MyReverseIterator<iterator>							reverse_iterator;
				typedef MyReverseIterator<const_iterator>					const_reverse_iterator;
				typedef	size_t												size_type;
				typedef	std::ptrdiff_t											difference_type;
				List<value_type>(void)  : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());
			}
				List<value_type>(int n) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				for (int i = 0; i < n; i++)
					this->push_back(0);
			}
				List<value_type>(int n, value_type elem) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				for (int i = 0; i < n; i++)
					this->push_back(elem);
//				assign(n, elem);
			}
				List<value_type>(List<value_type> const &l) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				*this = l;
			}
				List<value_type>(iterator first, iterator last) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				this->assign(first, last);
			}
				List<value_type> & operator = (List<value_type> const &l)
				{
					if (this != &l)
					{
						this->clear();
						delete Helem;
						Helem = this->init_last();
						if(!l.empty())
						{
							const_iterator it = l.begin();
							const_iterator ite = l.end();
							this->assign(it, ite);
						}
					}
					return (*this);
				}
				~List()
				{
					delete Helem;
					this->clear();
				}
				void push_back(const value_type &elem)
				{
					Node<T> *lst;
					Node<T> *new1 = ft_lstnew(elem);

					lst = this->p;
					if(!lst)
						this->p = new1;
					else
					{
						while(lst->next && this->Helem != lst->next)
							lst = lst->next;
						new1->prev = lst;
						lst->next = new1;
					}
					this->Last()->next = this->Helem;
					this->p->prev = this->Helem;
					this->Helem->prev = this->Last();
					this->Helem->next = this->p;
				}
				void push_front (const value_type& val)
				{
					Node<T> *new1 = ft_lstnew(val);
					Node<T> *lst  = this->p;
					if(!lst)
						this->p = new1;
					else
					{
						lst->prev = new1;
						new1->next = lst;
						this->p = new1;
					}
					this->p->prev = this->Helem;
					this->Helem->prev = this->Last();
					this->Helem->next = this->p;
				}

				size_type	size(void) const
				{
					Node<T> *tmp = this->p;
					size_type count = 0;

					if(p == 0)
						return (0);
					while(tmp && tmp != this->Helem)
					{
						count++;
						tmp = tmp->next;
					}
					return count;
				}
				bool empty() const
				{
					if(this->size())
						return 0;
					return 1;
				}
				void pop_back()
				{
					Node<value_type> *tmp = this->p;
					Node<value_type> *t = tmp;
					if(!tmp)
						return ;
					while(tmp->next != this->Helem)
					{
						t = tmp;
						tmp = tmp->next;
					}
					if(t == this->p)
						this->p = 0;
					t->next = 0;
					if(this->p)
					{
						this->Last()->next = this->Helem;
						this->Helem->prev = this->Last();
					}
					delete(tmp);
				}
				void pop_front()
				{
					Node<value_type> *tmp = this->p;
					if(this->p->next != this->Helem)
					{
						this->p = this->p->next;
						this->p->prev = this->Helem;
					}
					else
						this->p = 0;
					this->Helem->next = this->p;
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
					return iterator(this->Helem);
				}
				const_iterator end() const
				{
					Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->Helem);

					return const_iterator(tmp);
				}
				reverse_iterator rbegin()
				{
					return reverse_iterator(iterator(this->Last()));
				}
				const_reverse_iterator rbegin() const
				{
					Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->Last());
					return const_reverse_iterator(const_iterator(tmp));
				}
				reverse_iterator rend()
				{
					return reverse_iterator(iterator(this->Helem));
				}
				const_reverse_iterator rend() const
				{
					Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->Helem);
					return const_reverse_iterator(const_iterator(tmp));
				}
				template < class InputIterator >
					void assign(InputIterator first, InputIterator last)
					{
						for (InputIterator it = first; it != last; it++)
							this->push_back(*it);
					}
/*				void assign(size_type n, const value_type &val)
				{
					for (size_type i = 0; i < n; i++)
						this->push_back(val);
				}*/
				void clear()
				{
					while(!this->empty())
						this->pop_back();
				}
				reference front()
				{
					return this->p->elem;
				}
				const_reference front() const
				{
					Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->p);
					return tmp->elem;
				}
				reference back()
				{
					Node<T> *tmp;

					tmp = this->p;
					while(tmp->next)
						tmp = tmp->next;
					return tmp->elem;
				}
				const_reference back() const
				{
					Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->p);

					tmp = this->p;
					while(tmp->next)
						tmp = tmp->next;
					return tmp->elem;
				}
				size_type max_size() const
				{
					return (node_allocator_type().max_size());
				}
				iterator insert(iterator position, const value_type& val)
				{
					Node<T> *tmp = this->p;
					Node<T> *new1 = ft_lstnew(val);
					Node<T> *prev;
					iterator it = this->begin();
					size_t i = 0;
					while(it != this->end() && it != position)
					{
						it++;
						i++;
					}
					if(it == this->end())
						return position;
					for(size_t j = 0; j < i; j++)
						tmp = tmp->next;
					prev = tmp->prev;
					prev->next = new1;
					new1->prev = prev;
					new1->next = tmp;
					tmp->prev = new1;
					return position;
				}
				void insert (iterator position, size_type n, const value_type& val)
				{
						for(size_type i = 0; i < n; i++)
							insert(position, val);
				}
/*				template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last)
				{
					for(InputIterator it = first; it != last; it++)
						insert(position, *it);
				}*/
				iterator erase (iterator position)
				{
					Node<T> *tmp = this->p;
					Node<T> *next;
					Node<T> *prev;
					iterator it = this->begin();
					size_t i = 0;
					while(it != this->end() && it != position)
					{
						it++;
						i++;
					}
					for(size_t j = 0; j < i; j++)
						tmp = tmp->next;
					if(tmp == this->Helem)
					{
						this->p = 0;
						return position;
					}
					position++;
					prev = tmp->prev;
					next = tmp->next;
					prev->next = next;
					next->prev = prev;
					if (this->p == tmp)
						this->p = this->p->next;
					delete(tmp);
					return position;
				}
				iterator erase (iterator first, iterator last)
				{
					while(first != last)
					{
						first = erase(first);
					}
					return first;
				}
				void swap (List& x)
				{
					std::swap(*this, x);
				}
		};
};

#endif
