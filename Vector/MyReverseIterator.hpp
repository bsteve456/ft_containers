#ifndef MYREVERSEITERATOR_HPP
# define MYREVERSEITERATOR_HPP

#include "MyVectorIterator.hpp"

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
				template< class _IT>
					friend bool operator<(const MyReverseIterator<_IT> &lhs, const MyReverseIterator<_IT> &rhs);
				template< class _IT>
					friend bool operator<=(const MyReverseIterator<_IT> &lhs, const MyReverseIterator<_IT> &rhs);
				template< class _IT>
					friend bool operator>=(const MyReverseIterator<_IT> &lhs, const MyReverseIterator<_IT> &rhs);
				template< class _IT>
					friend bool operator>(const MyReverseIterator<_IT> &lhs, const MyReverseIterator<_IT> &rhs);
				template <class _IT>
					friend MyReverseIterator<_IT> operator+ (typename MyReverseIterator<_IT>::difference_type n, const MyReverseIterator<_IT>& rev_it);
				template <class _IT>
					friend typename MyReverseIterator<_IT>::difference_type operator- (
							const MyReverseIterator<_IT>& lhs,
							const MyReverseIterator<_IT>& rhs);
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
					iterator_type tmp = this->base() - 1;
					for (difference_type i = 0; i < n; ++i)
						tmp--;
					return (MyReverseIterator(tmp));
				}
				MyReverseIterator operator- (difference_type n) const
				{
					iterator_type tmp = this->base() - 1;
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
					return this->base()[-n -1];
				}
				iterator_type base() const
				{
					iterator_type t = this->it;
					t++;
					return t;
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
	template < class Iterator >
		bool operator <(const MyReverseIterator<Iterator> &lhs, const MyReverseIterator<Iterator> &rhs)
		{
			return lhs.it < rhs.it;
		}
	template < class Iterator >
		bool operator<=(const MyReverseIterator<Iterator> &lhs, const MyReverseIterator<Iterator> &rhs)
		{
			return lhs.it <= rhs.it;
		}
	template < class Iterator >
		bool operator >=(const MyReverseIterator<Iterator> &lhs, const MyReverseIterator<Iterator> &rhs)
		{
			return lhs.it >= rhs.it;
		}
	template < class Iterator >
		bool operator>(const MyReverseIterator<Iterator> &lhs, const MyReverseIterator<Iterator> &rhs)
		{
			return lhs.it > rhs.it;
		}
	template <class Iterator>
		MyReverseIterator<Iterator> operator+ (
				typename MyReverseIterator<Iterator>::difference_type n,
				const MyReverseIterator<Iterator>& rev_it)
		{
			return rev_it + n;
		}
	template <class Iterator>
		typename MyReverseIterator<Iterator>::difference_type operator- (
				const MyReverseIterator<Iterator>& lhs,
				const MyReverseIterator<Iterator>& rhs)
		{
			return rhs.base() - lhs.base();
		}
};

#endif
