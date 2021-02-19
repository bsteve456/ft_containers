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
           class Alloc = allocator<pair<const Key,T> >  // map::allocator_type
           >
	class Map
	{
		private:
			Node<Key, T> *p;
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



	};
};

#endif
