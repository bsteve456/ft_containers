/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <stbaleba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:54:47 by stbaleba          #+#    #+#             */
/*   Updated: 2021/03/10 14:02:39 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "Node.hpp"
# include "MyListIterator.hpp"
# include "MyReverseIterator.hpp"
# include <limits>
# include <algorithm>
# include <typeinfo>

namespace ft
{
	template < class T, class Alloc = std::allocator< T > >
		class list
		{
			private:
				template <class Tp, class Allocs>
					friend bool operator== (const list<Tp,Allocs>& lhs, const list<Tp,Allocs>& rhs);
				template <class Tp, class Allocs>
					friend bool operator!= (const list<Tp,Allocs>& lhs, const list<Tp,Allocs>& rhs);
				template <class Tp, class Allocs>
					friend bool operator<  (const list<Tp,Allocs>& lhs, const list<Tp,Allocs>& rhs);
				template <class Tp, class Allocs>
					friend bool operator>  (const list<Tp,Allocs>& lhs, const list<Tp,Allocs>& rhs);
				template <class Tp, class Allocs>
					friend bool operator<=  (const list<Tp,Allocs>& lhs, const list<Tp,Allocs>& rhs);
				template <class Tp, class Allocs>
					friend bool operator>=  (const list<Tp,Allocs>& lhs, const list<Tp,Allocs>& rhs);
				template <class Tp, class Allocs>
					void swap (list<Tp,Allocs>& x, list<Tp,Allocs>& y);
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
					value_type random = T();
					hollow_elem = ft_lstnew(random);
					hollow_elem->prev = this->Last();
					hollow_elem->next = this->p;
					return hollow_elem;
				}
			public:
				typedef T													value_type;
				typedef std::allocator< T >									allocator_type;
				typedef	value_type&											reference;
				typedef	const	value_type&									const_reference;
				typedef	value_type *										pointer;
				typedef	const value_type *									const_pointer;
				typedef	MyListIterator<bidirectional_iterator_tag, T, false>			iterator;
				typedef	MyListIterator<bidirectional_iterator_tag, T, true>		const_iterator;
				typedef MyReverseIterator<iterator>							reverse_iterator;
				typedef MyReverseIterator<const_iterator>					const_reverse_iterator;
				typedef	size_t												size_type;
				typedef	std::ptrdiff_t										difference_type;
				list<value_type>(void)  : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());
			}
				list<value_type>(int n) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				for (int i = 0; i < n; i++)
					this->push_back(0);
			}
				list<value_type>(int n, value_type elem) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				for (int i = 0; i < n; i++)
					this->push_back(elem);
				//				assign(n, elem);
			}
				list<value_type>(list<value_type> const &l) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				*this = l;
			}
				template <class InputIterator>
				list<value_type>(InputIterator first, typename enable_if<is_pointer<InputIterator>::value | is_input_iterator<is_integral_float<InputIterator>::value | is_pointer<InputIterator>::value, InputIterator>::value, InputIterator>::type last) : p(0)
			{
				this->Helem = 0;
				this->Helem = (this->init_last());

				this->assign(first, last);
			}
				list<value_type> & operator = (list<value_type> const &l)
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
				~list()
				{
					this->clear();
					delete Helem;
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
					{
						this->p = new1;
						this->p->next = this->Helem;
					}
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
					if(tmp == this->p)
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
					if(this->p != 0)
						return iterator(this->p);
					else
						return iterator(this->Helem);
				}
				const_iterator begin() const
				{
					if(this->p != 0)
						return iterator(this->p);
					else
						return iterator(this->Helem);
				}
				iterator end()
				{
					return iterator(this->Helem);
				}
				const_iterator end() const
				{
					return iterator(this->Helem);
				}
				reverse_iterator rbegin()
				{
					return reverse_iterator(iterator(this->Last()));
				}
				const_reverse_iterator rbegin() const
				{
					return const_reverse_iterator(const_iterator(this->Last()));
				}
				reverse_iterator rend()
				{
					return reverse_iterator(iterator(this->Helem));
				}
				const_reverse_iterator rend() const
				{
					return const_reverse_iterator(const_iterator(this->Helem));
				}
				template < class InputIterator >
					void assign(InputIterator first, typename enable_if<is_pointer<InputIterator>::value | is_input_iterator<is_integral_float<InputIterator>::value | is_pointer<InputIterator>::value, InputIterator>::value, InputIterator>::type last)
					{
						this->clear();
						for (InputIterator it = first; it != last; it++)
							this->push_back(*it);
					}
				void assign(size_type n, const value_type &val)
				{
					this->clear();
					for (size_type i = 0; i < n; i++)
						this->push_back(val);
				}
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
					while(tmp->next != this->Helem)
						tmp = tmp->next;
					return tmp->elem;
				}
				const_reference back() const
				{
					Node<const T> *tmp = reinterpret_cast<Node<const T> *>(this->p);

					tmp = this->p;
					while(tmp->next != this->Helem)
						tmp = tmp->next;
					return tmp->elem;
				}
				size_type max_size() const
				{
					return (std::allocator< Node< T > >().max_size());
				}
				iterator insert(iterator position, const value_type& val)
				{
					Node<T> *tmp = this->p;
					Node<T> *new1 = ft_lstnew(val);
					Node<T> *prev;
					iterator it = this->begin();
					size_t i = 0;
					if(this->p == 0)
					{
						this->p = new1;
						this->p->prev = this->Helem;
						this->p->next = this->Helem;
						this->Helem->prev = this->Last();
						this->Helem->next = this->p;
					}
					else
					{
						while(it != this->end() && it != position)
						{
							it++;
							i++;
						}
						for(size_t j = 0; j < i; j++)
							tmp = tmp->next;
						prev = tmp->prev;
						prev->next = new1;
						new1->prev = prev;
						new1->next = tmp;
						tmp->prev = new1;
						if(tmp == this->p)
							this->p = new1;
					}
					return iterator(new1);
				}
				void insert (iterator position, size_type n, const value_type& val)
				{
					for(size_type i = 0; i < n; i++)
						insert(position, val);
				}
				template <class InputIterator>
					void insert (iterator position, InputIterator first, /*InputIterator*/ typename enable_if<is_pointer<InputIterator>::value | is_input_iterator<is_integral_float<InputIterator>::value | is_pointer<InputIterator>::value, InputIterator>::value, InputIterator>::type last)
					{
						for(InputIterator it = first; it != last; it++)
							insert(position, *it);
					}
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
						first = erase(first);
					return first;
				}
				void swap (list& x)
				{
					std::swap(*this, x);
				}
				void resize (size_type n, value_type val = value_type())
				{
					while (this->size() > n)
						this->pop_back();
					while (this->size() < n)
						this->push_back(val);
				}
				void splice (iterator position, list& x)
				{
					for (iterator it = x.begin(); it != x.end(); ++it)
						this->insert(position, *it);
					x.clear();
				}
				void splice (iterator position, list& x, iterator i)
				{
					this->insert(position, *i);
					x.erase(i);
				}
				void splice (iterator position, list& x, iterator first, iterator last)
				{
					iterator tmp;
					while(first != last)
					{
						tmp = first;
						this->insert(position, *first);
						first++;
						x.erase(tmp);
					}
				}
				void remove (const value_type& val)
				{
					for (iterator it = this->begin(); it != this->end(); it++)
					{
						if (*it == val)
						{
							it = erase(it);
							it--;
						}
					}
				}
				template <class Predicate>
					void remove_if (Predicate pred)
					{
						for (iterator it = this->begin(); it != this->end(); it++)
						{
							if (pred(*it) == true)
							{
								it = erase(it);
								it--;
							}
						}
					}
				void unique()
				{
					iterator jt;
					iterator tmp;
					for(iterator it = this->begin(); it != this->end(); it++)
					{
						jt = it;
						jt++;
						while(jt != this->end())
						{
							tmp = jt;
							if(*jt == *it)
							{
								jt++;
								this->erase(tmp);
							}
							else
								jt++;
						}
					}
				}
				template <class BinaryPredicate>
					void unique (BinaryPredicate binary_pred)
					{
						iterator jt;
						iterator tmp;
						for(iterator it = this->begin(); it != this->end(); it++)
						{
							jt = it;
							jt++;
							while(jt != this->end())
							{
								tmp = jt;
								if(binary_pred(*it, *jt) == true)
								{
									jt++;
									this->erase(tmp);
								}
								else
									jt++;
							}
						}
					}
				void sort()
				{
					Node<T> *i;
					Node<T> *j;
					i = this->p;
					while(i != this->Helem)
					{
						j = this->p;
						while(j != this->Helem)
						{
							if(i->elem < j->elem)
								std::swap(i->elem, j->elem);
							j = j->next;
						}
						i = i->next;
					}
				}
				template <class Compare>
					void sort (Compare comp)
					{
						Node<T> *i;
						Node<T> *j;
						T tmp;
						i = this->p;
						while(i != this->Helem)
						{
							j = this->p;
							while(j != this->Helem)
							{
								if(comp(i->elem, j->elem) == true)
									std::swap(i->elem, j->elem);
								j = j->next;
							}
							i = i->next;
						}
					}
				void merge (list& x)
				{
					if(this != &x)
					{
						for(iterator it = x.begin(); it != x.end(); it++)
						{
							for (iterator it2 = this->begin(); it2 != this->end(); it2++)
							{
								if(*it < *it2)
								{
									this->insert(it2, *it);
									break;
								}
								else
								{
									it2++;
									if(it2 == this->end())
										this->insert(it2, *it);
									it2--;
								}
							}
						}
						x.clear();
					}
				}
				template <class Compare>
					void merge (list& x, Compare comp)
					{
						if(this != &x)
						{
							for(iterator it = x.begin(); it != x.end(); it++)
							{
								for (iterator it2 = this->begin(); it2 != this->end(); it2++)
								{
									if(comp(*it, *it2) == true)
									{
										this->insert(it2, *it);
										break;
									}
									else
									{
										it2++;
										if(it2 == this->end())
											this->insert(it2, *it);
										it2--;
									}
								}
							}
							x.clear();
						}
					}
				void reverse()
				{
					Node<T> *i;
					Node<T> *j;
					i = this->p;
					j = i;
					while(j->next != this->Helem)
						j = j->next;
					while(i != j)
					{
						std::swap(i->elem, j->elem);
						i = i->next;
						j = j->prev;
					}
				}
		};
	template <class T, class Alloc>
		bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if(lhs.size() != rhs.size())
				return false;
			if(std::equal(lhs.begin(), lhs.end(), rhs.begin()) == true)
				return true;
			return false;
		}
	template <class T, class Alloc>
		bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if(lhs.size() != rhs.size())
				return true;
			if(std::equal(lhs.begin(), lhs.end(), rhs.begin()) == false)
				return true;
			return false;
		}
	template <class T, class Alloc>
		bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if(std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true)
				return true;
			return false;
		}
	template <class T, class Alloc>
		bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if(std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) == true)
				return true;
			return false;
		}
	template <class T, class Alloc>
		bool operator<=  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if(std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) == false)
				return true;
			return false;
		}
	template <class T, class Alloc>
		bool operator>=  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if(std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == false)
				return true;
			return false;
		}
	template <class T, class Alloc>
		void swap (list<T,Alloc>& x, list<T,Alloc>& y)
		{
			x.swap(y);
		}
};

#endif
