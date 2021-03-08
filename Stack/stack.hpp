#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "../Vector/vector.hpp"

namespace ft
{
	template < class T, class Container = vector<T> >
		class stack
		{
			private:
				Container c;
			public:
				typedef T 			value_type;
				typedef Container	container_type;
				typedef size_t		size_type;
				explicit stack (const container_type& ctnr = container_type())
				{
					this->c = ctnr;
				}
				size_type size() const
				{
					return c.size();
				}
				bool empty() const
				{
					return c.empty();
				}
				value_type& top()
				{
					return c.back();
				}
				const value_type& top() const
				{
					return c.back();
				}
				void push (const value_type& val)
				{
					c.push_back(val);
				}
				void pop()
				{
					c.pop_back();
				}
		};
};

#endif
