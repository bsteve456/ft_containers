#ifndef MAP_HPP
# define MAP_HPP

# include "Node.hpp"
# include <functional>
# include <utility>
# include "MyIterator.hpp"

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
		public:
			typedef Key															key_type;
			typedef	T															mapped_type;
			typedef std::pair<const key_type, mapped_type>						value_type;
			typedef	Compare														key_compare;
			typedef	Alloc														allocator_type;
			typedef value_type&													reference;
			typedef	const value_type&											const_reference;
			typedef value_type *												pointer;
			typedef const value_type *											const_pointer;
			typedef	MyIterator<bidirectional_iterator_tag, value_type>			iterator;
			typedef	MyIterator<bidirectional_iterator_tag, const value_type>	const_iterator;
			typedef	size_t														size_type;
			typedef	std::ptrdiff_t												difference_type;
			Map () : p(0)
			{}
/*			Map (const map &x)
			{
				
			}*/
			template <class InputIterator>
			Map (InputIterator first, InputIterator last) : p(0)
			{
					for(iterator it = first; it != last; it++)
							(*this)[it->first] = it->second;
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
				return new1->value->second;
			}
			iterator begin()
			{
				return iterator(this->p);
			}
			iterator end()
			{
				return iterator();
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
					delete(tmp);
				}
			}
	};
};

#endif
