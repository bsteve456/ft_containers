#ifndef MYREVERSEITERATOR_HPP
# define MYREVERSEITERATOR_HPP

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
				this->it = mit.it;
				return (*this);
			}
			~MyReverseIterator(){}
			MyReverseIterator & operator++()
			{
				this->it--;
				return *this;
			}
			MyReverseIterator & operator--()
			{
				this->it++;
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
			MyReverseIterator operator+ (difference_type n) const
			{
				iterator_type tmp = this->base();
				for (difference_type i = 0; i < n; ++i)
					tmp--;
				return (MyReverseIterator(tmp));
			}
			MyReverseIterator operator- (difference_type n) const
			{
				iterator_type tmp = this->base();
				for (difference_type i = 0; i < n; ++i)
					tmp++;
				return (MyReverseIterator(tmp));
			}
			MyReverseIterator& operator+= (difference_type n)
			{
				for (difference_type i = 0; i < n; ++i)
					this->it--;
				return (*this);
			}
			MyReverseIterator& operator-= (difference_type n)
			{
				for (difference_type i = 0; i < n; ++i)
					this->it++;
				return (*this);
			}
			value_type	& operator *() const
			{
				return *(this->it);
			}
			reference operator[] (difference_type n) const
			{
				return this->base()[-n];
			}
			iterator_type base() const
			{
				return this->it;
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
