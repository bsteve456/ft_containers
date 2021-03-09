#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <iostream>
# include "../List/list.hpp"

namespace ft
{
	template <class T, class Container = list<T> > 
		class queue
		{
			private:
				Container c;
				template <class Tp, class Cont>
					friend bool operator== (const queue<Tp,Cont>& lhs, const queue<Tp,Cont>& rhs);
				template <class Tp, class Cont>
					friend bool operator!= (const queue<Tp,Cont>& lhs, const queue<Tp,Cont>& rhs);
				template <class Tp, class Cont>
					friend bool operator<  (const queue<Tp,Cont>& lhs, const queue<Tp,Cont>& rhs);
				template <class Tp, class Cont>
					friend bool operator<= (const queue<Tp,Cont>& lhs, const queue<Tp,Cont>& rhs);
				template <class Tp, class Cont>
					friend bool operator>  (const queue<Tp,Cont>& lhs, const queue<Tp,Cont>& rhs);
				template <class Tp, class Cont>
					friend bool operator>= (const queue<Tp,Cont>& lhs, const queue<Tp,Cont>& rhs);
			public:
				typedef T 			value_type;
				typedef Container	container_type;
				typedef size_t		size_type;
				explicit queue (const container_type& ctnr = container_type())
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
				value_type& front()
				{
					return c.front();
				}
				const value_type& front() const
				{
					return c.front();
				}
				value_type& back()
				{
					return c.back();
				}
				const value_type& back() const
				{
					return c.back();
				}
				void push (const value_type& val)
				{
					c.push_back(val);
				}
				void pop()
				{
					c.pop_front();
				}
		};
	template <class T, class Container>
		bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}
	template <class T, class Container>
		bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
		{
			return (lhs.c != rhs.c);
		}
	template <class T, class Container>
		bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
		{
			return (lhs.c < rhs.c);
		}
	template <class T, class Container>
		bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
		{
			return (lhs.c <= rhs.c);
		}
	template <class T, class Container>
		bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
		{
			return (lhs.c > rhs.c);
		}
	template <class T, class Container>
		bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
		{
			return (lhs.c >= rhs.c);
		}
};


#endif
