#ifndef MAP_HPP
# define MAP_HPP

# include "Node.hpp"
# include <functional>
# include <utility>
# include "MyIterator.hpp"
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
						 void	sort_by_key()
						 {
							 Node<std::pair<const Key, T> > *tmp = this->p;
							 Node<std::pair<const Key, T> > *tmp1 = 0;
							 Node<std::pair<const Key, T> > *prev = 0;
							 Node<std::pair<const Key, T> > *next = 0;

							 while(tmp)
							 {
								 tmp1 = this->p;
								 while(tmp1 && tmp1->next)
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
											 tmp1->next = next->next;
										 else
											 tmp1->next = 0;
										 next->next = tmp1;
									 }
									 tmp1 = tmp1->next;
								 }
								 tmp = tmp->next;
							 }
						 }
					 public:
						 typedef Key																	key_type;
						 typedef	T																	mapped_type;
						 typedef std::pair<const key_type, mapped_type>								value_type;
						 typedef	Compare																key_compare;
						 typedef	Alloc																allocator_type;
						 typedef value_type&															reference;
						 typedef	const value_type&													const_reference;
						 typedef value_type *														pointer;
						 typedef const value_type *													const_pointer;
						 typedef	MyIterator<bidirectional_iterator_tag, value_type>					iterator;
						 typedef	MyIterator<bidirectional_iterator_tag, const value_type>			const_iterator;
						 typedef	MyReverseIterator<iterator>											reverse_iterator;
						 typedef	MyReverseIterator<const iterator>									const_reverse_iterator;
						 typedef	size_t																size_type;
						 typedef	std::ptrdiff_t														difference_type;
						 Map () : p(0)
					 {}
						 Map (const Map &x) : p(0)
					 {
						 this->clear();
						 for(const_iterator it = x.begin(); it != x.end(); it++)
							 (*this)[it->first] = it->second;
					 }
						 template <class InputIterator>
							 Map (InputIterator first, InputIterator last) : p(0)
						 {
							 for(iterator it = first; it != last; it++)
								 (*this)[it->first] = it->second;
						 }
						 Map& operator= (const Map& x)
						 {
							 this->clear();
							 for(const_iterator it = x.begin(); it != x.end(); it++)
								 (*this)[it->first] = it->second;
							 return *this;
						 }
						 ~Map()
						 {
							 this->clear();
						 }
						 mapped_type& operator[] (const key_type& k)
						 {
							 Node<value_type> *tmp;
							 Node<value_type> *new1 = 0;
							 Node<value_type> *tmp1 = 0;

							 tmp = this->p;
							 tmp1 = tmp;
							 while(tmp)
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
								 while(tmp1->next)
									 tmp1 = tmp1->next;
								 tmp1->next = new1;
								 new1->prev = tmp1;
								 new1->next = 0;
							 }
							 this->sort_by_key();
							 return new1->value->second;
						 }
						 iterator begin()
						 {
							 return iterator(this->p);
						 }
						 const_iterator begin() const
						 {
							 Node<const value_type> *tmp = reinterpret_cast<Node<const value_type> *>(this->p);
							 return const_iterator(tmp);
						 }
						 reverse_iterator rbegin()
						 {
							 Node<value_type> *tmp = this->p;

							 while(tmp->next)
								 tmp = tmp->next;
							 return reverse_iterator(tmp);
						 }
						 const_reverse_iterator rbegin() const
						 {
							 Node<const value_type> *tmp = reinterpret_cast<Node<const value_type> *>(this->p);

							 while(tmp->next)
								 tmp = tmp->next;
							 return const_reverse_iterator(tmp);
						 }
						 iterator end()
						 {
							 return iterator();
						 }
						 const_iterator end() const
						 {
							 return const_iterator();
						 }
						 reverse_iterator rend()
						 {
							 return reverse_iterator();
						 }
						 const_reverse_iterator rend() const
						 {
							 return const_reverse_iterator();
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
							 while(tmp)
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
							 Node<value_type> *prev = 0;
							 while(!this->empty())
							 {
								 tmp = this->p;
								 t = tmp;
								 if(!tmp)
									 return;
								 while(tmp->next)
									 tmp = tmp->next;
								 if(t == this->p)
									 this->p = 0;
								 t->next = 0;
								 prev = t->prev;
								 if (this->p)
									 prev->next = 0;
								 delete(tmp->value);
								 delete(tmp);
							 }
						 }
						 std::pair<iterator,bool> insert (const value_type& val)
						 {
							 Node<value_type> *tmp = this->p;
							 std::pair<iterator, bool> ret;
							 int n = 0;

							 while(tmp)
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
/*						 iterator insert (iterator position, const value_type& val)
						 {
							 (void)position;
							 (*this)[val.first] = val.second;
							 iterator ret;

							 for(iterator it = this->begin(); it != this->end(); ++it)
								 ret = it;
							 this->sort_by_key();
							 return iterator(ret);
						 }*/
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

							while(tmp)
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

							while(tmp)
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
							for (iterator it = first; it != last; ++it)
								erase(it);
						}
						void swap (Map& x)
						{
							std::swap(*this, x);
						}
				 };
};

#endif
