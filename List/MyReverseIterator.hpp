#ifndef MYREVERSEITERATOR_HPP
# define MYREVERSEITERATOR_HPP

#include "Node.hpp"
#include "MyIterator.hpp"

namespace ft
{
	template< class Iterator >
		class MyReverseIterator
	{
		private:
				Iterator it;
				template< class _IT>
				friend bool operator==(const MyReverseIterator<_IT> &lhs, const MyReverseIterator<_IT> &rhs);
				template< class _IT>
				friend bool operator!=(const MyReverseIterator<_IT> &lhs, const MyReverseIterator<_IT> &rhs);
		public:
			typedef Iterator							iterator_type;
			typedef typename Iterator::value_type		value_type;
			typedef typename Iterator::difference_type	difference_type;
			typedef typename Iterator::pointer			pointer;
			typedef	typename Iterator::reference		reference;
			MyReverseIterator() : it(0) {}
			MyReverseIterator(iterator_type x) : it(x)
		{}
			template<class Iter>
			MyReverseIterator(MyReverseIterator const & mit) : it(mit.it)
		{}
			MyReverseIterator & operator = (MyReverseIterator const & mit)
			{
				it = mit.it;
			}
			~MyReverseIterator(){}
			MyReverseIterator & operator++()
			{
				it--;
				return *this;
			}
			MyReverseIterator & operator--()
			{
				it++;
				return *this;
			}
			MyReverseIterator operator++(int n)
			{
				(void)n;
				MyReverseIterator tmp(*this);
				operator++();
				return tmp;
			}
			MyReverseIterator operator--(int n)
			{
				(void)n;
				MyReverseIterator tmp(*this);
				operator--();
				return tmp;
			}
			pointer operator->() const
			{
				return &(operator *());
			}
			value_type	& operator *() const
			{
				return *it;
			}
			iterator_type base() const
			{
				return it;
			}
	};
	template < class Iterator >
	bool operator ==(const MyReverseIterator<Iterator> &lhs, const MyReverseIterator<Iterator> &rhs)
	{
		return lhs.it == rhs.it;
	}
	template < class Iterator >
	bool operator!=(const MyReverseIterator<Iterator> &lhs, const MyReverseIterator<Iterator> &rhs)
	{
		return lhs.it != rhs.it;
	}

};

#endif
