#ifndef MAP_HPP
# define MAP_HPP

# include "Node.hpp"
# include <functional>
# include <utility>
# include "MyMapIterator.hpp"
# include "MyReverseIterator.hpp"

namespace ft
{
	template < class Key,                                  // map::key_type
			 class T,                                       // map::mapped_type
			 class Compare = std::less<Key>,                    // map::key_compare
			 class Alloc = std::allocator<std::pair<const Key,T> >  // map::allocator_type
				 >
				 class Map
				 {
					 private:
						 Node<std::pair<const Key, T> > *p;
						 Node<std::pair<const Key, T> > *Helem;
						 Node<std::pair<const Key, T> >	*Last() const
						 {
							 Node<std::pair<const Key, T> > *tmp = this->p;
							 if(!tmp)
								 return (0);
							 while(tmp->next && tmp->next != this->Helem)
								 tmp = tmp->next;
							 return tmp;
						 }
						 Node<std::pair<const Key,T> >	*init_last()
						 {
							 Node<std::pair<const Key, T> > *hollow_elem;
							 std::pair<const key_type, mapped_type> *c = new std::pair<const Key, T>(std::make_pair(Key(), T()));
							 hollow_elem = ft_lstnew(c);
							 hollow_elem->prev = this->Last();
							 hollow_elem->next = this->p;
							 return hollow_elem;
						 }
						 void print()
						 {
							 std::cerr << "--------------" << std::endl;
							 Node<std::pair<const Key, T> > *tmp = this->p;
							 while(tmp)
							 {
								 std::cerr << tmp->value->first << std::endl;
								 tmp = tmp->next;
							 }
						 }
						 void	sort_by_key()
						 {
							 Node<std::pair<const Key, T> > *tmp = this->p;
							 Node<std::pair<const Key, T> > *tmp1 = 0;
							 Node<std::pair<const Key, T> > *prev = 0;
							 Node<std::pair<const Key, T> > *next = 0;

							 while(tmp && tmp != this->Helem)
							 {
								 tmp1 = this->p;
								 while(tmp1 && tmp1->next != this->Helem)
								 {
									 if(tmp1->value->first > tmp1->next->value->first)
									 {
										 prev = tmp1->prev;
										 next = tmp1->next;
										 if(prev)
											 prev->next = next;
										 next->prev = prev;
										 tmp1->prev = next;
										 if(next->next)
										 {
											 tmp1->next = next->next;
											 next->next->prev = tmp1;
										 }
										 else
											 tmp1->next = 0;
										 next->next = tmp1;
									 }
									 tmp1 = tmp1->next;
								 }
								 tmp = tmp->next;
							 }
							 this->Last()->next = this->Helem;
							 this->p->prev = this->Helem;
							 this->Helem->prev = this->Last();
							 this->Helem->next = this->p;
						 }
					 public:
						 typedef Key																	key_type;
						 typedef	T																	mapped_type;
						 typedef std::pair<const key_type, mapped_type>								value_type;
						 typedef	Compare																key_compare;
						 class value_compare : public std::binary_function<value_type,value_type,bool>
					 {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
						 //							 friend class Map;
						 protected:
							 Compare comp;
						 public:
							 value_compare (Compare c = Compare()) : comp(c) {}  // constructed with map's comparison object
							 typedef bool result_type;
							 typedef value_type first_argument_type;
							 typedef value_type second_argument_type;
							 bool operator() (const value_type& x, const value_type& y) const
							 {
								 return comp(x.first, y.first);
							 }
					 };
						 typedef	Alloc																allocator_type;
						 typedef value_type&															reference;
						 typedef	const value_type&													const_reference;
						 typedef value_type *														pointer;
						 typedef const value_type *													const_pointer;
						 typedef	MyMapIterator<bidirectional_iterator_tag, value_type>					iterator;
						 typedef	MyMapIterator<bidirectional_iterator_tag, value_type, true>		const_iterator;
						 typedef	MyReverseIterator<iterator>											reverse_iterator;
						 typedef	MyReverseIterator<const_iterator>									const_reverse_iterator;
						 typedef	size_t																size_type;
						 typedef	std::ptrdiff_t														difference_type;
						 Map (const key_compare& comp = key_compare()) : p(0)
					 {
						 (void)comp;
						 this->Helem = 0;
						 this->Helem = (this->init_last());
					 }
						 Map (const Map &x) : p(0)
					 {
						 this->Helem = 0;
						 this->Helem = (this->init_last());

						 for(const_iterator it = x.begin(); it != x.end(); it++)
							 (*this)[it->first] = it->second;
					 }
						 template <class InputIterator>
							 Map (InputIterator first, InputIterator last) : p(0)
						 {
							 this->Helem = 0;
							 this->Helem = (this->init_last());

							 for(iterator it = first; it != last; it++)
								 (*this)[it->first] = it->second;
						 }
						 Map& operator= (const Map& x)
						 {
							 this->clear();
							 delete Helem;
							 this->Helem = (this->init_last());
							 for(const_iterator it = x.begin(); it != x.end(); it++)
								 (*this)[it->first] = it->second;
							 return *this;
						 }
						 ~Map()
						 {
							 this->clear();
							 delete Helem;
						 }
						 mapped_type& operator[] (const key_type& k)
						 {
							 Node<value_type> *tmp;
							 Node<value_type> *new1 = 0;
							 Node<value_type> *tmp1 = 0;

							 tmp = this->p;
							 tmp1 = tmp;
							 while(tmp && tmp != this->Helem)
							 {
								 if(tmp->value->first == k)
									 return tmp->value->second;
								 tmp = tmp->next;
							 }
							 std::pair<const key_type, mapped_type> *c = new std::pair<const Key, T>(std::make_pair(k, T()));
							 new1 = ft_lstnew(c);
							 if(!tmp1)
								 this->p = new1;
							 else
							 {
								 while(tmp1->next && this->Helem != tmp1->next)
									 tmp1 = tmp1->next;
								 tmp1->next = new1;
								 new1->prev = tmp1;
							 }
							 this->Last()->next = this->Helem;
							 this->p->prev = this->Helem;
							 this->Helem->prev = this->Last();
							 this->Helem->next = this->p;
							 this->sort_by_key();
							 return new1->value->second;
						 }
						 iterator begin()
						 {
							 if (this->p != 0)
								 return iterator(this->p);
							 else
								 return iterator(this->Helem);
						 }
						 const_iterator begin() const
						 {
							 if (this->p != 0)
								 return iterator(this->p);
							 else
								 return iterator(this->Helem);

						 }
						 reverse_iterator rbegin()
						 {
							 return reverse_iterator(iterator(this->Last()));
						 }
						 const_reverse_iterator rbegin() const
						 {
							 return const_reverse_iterator(const_reverse_iterator(this->Last()));
						 }
						 iterator end()
						 {
							 return iterator(this->Helem);
						 }
						 const_iterator end() const
						 {
							 return iterator(this->Helem);
						 }
						 reverse_iterator rend()
						 {
							 return reverse_iterator(iterator(this->Helem));
						 }
						 const_reverse_iterator rend() const
						 {
							 return const_reverse_iterator(const_iterator(this->Helem));
						 }

						 size_type max_size() const
						 {
							 return std::allocator< Node< value_type > >().max_size();
						 }
						 size_t empty() const
						 {
							 if(!this->size())
								 return true;
							 return false;
						 }
						 size_type size() const
						 {
							 Node<value_type> *tmp = this->p;
							 size_type count = 0;
							 while(tmp && tmp != this->Helem)
							 {
								 count++;
								 tmp = tmp->next;
							 }
							 return count;
						 }
						 void clear()
						 {
							 Node<value_type> *tmp = 0;
							 Node<value_type> *t = 0;
							 while(!this->empty())
							 {
								 tmp = this->p;
								 t = tmp;
								 if(!tmp)
									 return ;
								 while(tmp->next != this->Helem)
								 {
									 t = tmp;
									 tmp = tmp->next;
								 }
								 if(t == this->p)
									 this->p = 0;
								 if(t)
									 t->next = 0;
								 if(this->p)
								 {
									 this->Last()->next = this->Helem;
									 this->Helem->prev = this->Last();
								 }
								 delete(tmp->value);
								 delete(tmp);
							 }
						 }
						 std::pair<iterator,bool> insert (const value_type& val)
						 {
							 Node<value_type> *tmp = this->p;
							 std::pair<iterator, bool> ret;
							 int n = 0;

							 while(tmp && tmp != this->Helem)
							 {
								 if(tmp->value->first == val.first)
								 {
									 n = 1;
									 break;
								 }
								 tmp = tmp->next;
							 }
							 if (n == 0)
								 (*this)[val.first] = val.second;
							 for(iterator it = this->begin(); it != this->end(); ++it)
							 {
								 if (it->first == val.first)
								 {
									 ret.first = it;
									 if(n == 1)
										 ret.second = false;
									 else
										 ret.second = true;
									 break;
								 }
							 }
							 return ret;
						 }
						 iterator insert (iterator position, const value_type& val)
						 {
							 (void)position;
							 (*this)[val.first] = val.second;
							 iterator ret;

							 for(iterator it = this->begin(); it != this->end(); ++it)
								 ret = it;
							 this->sort_by_key();
							 return iterator(ret);
						 }
						 template <class InputIterator>
							 void insert (InputIterator first, InputIterator last)
							 {
								 for(iterator it = first; it != last; ++it)
									 (*this)[it->first] = it->second;
								 this->sort_by_key();
							 }
						 iterator find (const key_type& k)
						 {
							 iterator it;
							 for (it = this->begin(); it != this->end(); ++it)
							 {
								 if(it->first == k)
									 return it;
							 }
							 return it;
						 }
						 const_iterator find (const key_type& k) const
						 {
							 const_iterator it;
							 for (it = this->begin(); it != this->end(); ++it)
							 {
								 if(it->first == k)
									 return it;
							 }
							 return it;
						 }
						 void erase (iterator position)
						 {
							 Node<value_type> *tmp = this->p;
							 Node<value_type> *prev = 0;
							 Node<value_type> *next = 0;

							 while(tmp && tmp != this->Helem)
							 {
								 if(tmp->value->first == position->first)
								 {
									 prev = tmp->prev;
									 next = tmp->next;
									 if(prev)
										 prev->next = next;
									 if(next)
										 next->prev = prev;
									 delete(tmp->value);
									 delete(tmp);
									 return ;
								 }
								 tmp = tmp->next;
							 }
						 }
						 size_type erase (const key_type& k)
						 {
							 Node<value_type> *tmp = this->p;
							 Node<value_type> *prev = 0;
							 Node<value_type> *next = 0;

							 while(tmp && tmp != this->Helem)
							 {
								 if(tmp->value->first == k)
								 {
									 prev = tmp->prev;
									 next = tmp->next;
									 if(prev)
										 prev->next = next;
									 if(next)
										 next->prev = prev;
									 delete(tmp->value);
									 delete(tmp);
									 return 1;
								 }
								 tmp = tmp->next;
							 }
							 return 0;
						 }
						 void erase (iterator first, iterator last)
						 {
							 iterator tmp;
							 iterator it = first;
							 while(it != last)
							 {
								 tmp = it;
								 it++;
								 erase(tmp);
							 }
						 }
						 void swap (Map& x)
						 {
							 std::swap(*this, x);
						 }
						 key_compare key_comp() const
						 {
							 return key_compare();
						 }
						 value_compare value_comp() const
						 {
							 return value_compare();
						 }
						 size_type count (const key_type& k) const
						 {
							 for(const_iterator it = this->begin(); it != this->end(); ++it)
							 {
								 if (it->first == k)
									 return (1);
							 }
							 return (0);
						 }
						 iterator lower_bound (const key_type& k)
						 {
							 iterator it;
							 for (it = this->begin(); it != this->end(); ++it)
							 {
								 if (this->key_comp()(it->first, k) == false)
									 return it;
							 }
							 return it;
						 }
						 const_iterator lower_bound (const key_type& k) const
						 {
							 const_iterator it;
							 for (it = this->begin(); it != this->end(); ++it)
							 {
								 if (this->key_comp()(it->first, k) == false)
									 return it;
							 }
							 return it;
						 }
						 iterator upper_bound (const key_type& k)
						 {
							 iterator it;
							 for (it = this->begin(); it != this->end(); ++it)
							 {
								 if (this->key_comp()(k, it->first) == true)
									 return it;
							 }
							 return it;
						 }
						 const_iterator upper_bound (const key_type& k) const
						 {
							 const_iterator it;
							 for (it = this->begin(); it != this->end(); ++it)
							 {
								 if (this->key_comp()(k, it->first) == true)
									 return it;
							 }
							 return it;
						 }
						 std::pair<iterator,iterator> equal_range (const key_type& k)
						 {
							 std::pair<iterator, iterator> ret;
							 ret.first = lower_bound(k);
							 ret.second = upper_bound(k);
							 return ret;
						 }

				 };
};

#endif
