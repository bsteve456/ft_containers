#ifndef ITERATOR_TAG
# define ITERATOR_TAG

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template<bool flag, class IsTrue, class IsFalse>
struct choose;

template <class IsTrue, class IsFalse>
struct choose<true, IsTrue, IsFalse>
{
	typedef IsTrue type;
};
template <class IsTrue, class IsFalse>
struct choose<false, IsTrue, IsFalse>
{
	typedef IsFalse type;
};

template <typename T>
struct is_integral_float
{
	static const bool value = false;
};

template<>
struct is_integral_float<int>
{
	static const bool value = true;
};

template<>
struct is_integral_float<char>
{
	static const bool value = true;
};

template<>
struct is_integral_float<long>
{
	static const bool value = true;
};

template<>
struct is_integral_float<short>
{
	static const bool value = true;
};

template<>
struct is_integral_float<double>
{
	static const bool value = true;
};

template<>
struct is_integral_float<float>
{
	static const bool value = true;
};

template<>
struct is_integral_float<bool>
{
	static const bool value = true;
};


template <bool, typename T = void>
struct enable_if
{};

template <typename T>
struct enable_if<true, T> {
	typedef T type;
};

template <typename T, typename = void>
struct is_iterator
{
	static const bool value = false;
};

template<typename T>
struct is_iterator<T *>
{
	static const bool value = true;
};
template <class U, class T>
struct is_same
{
	static const bool value = false;
};

template <class U>
struct is_same<U, U>
{
	static const bool value = true;
};

/*template <class U>
struct is_input_iterator<U>
{
	static const bool value = is_same<U::iterator_category,input_iterator_tag>::value;
};
template <class U>
struct is_forward_iterator<U>
{
	static const bool value = is_same<U::iterator_category,forward_iterator_tag>;
};*/

template <bool, class U>
struct is_bidirectional_iterator
{
	static const bool value = false;
};

template <class U>
struct is_bidirectional_iterator<false, U>
{
	static const bool value = is_same<typename U::iterator_category,bidirectional_iterator_tag>::value;
};
/*template <class U>
struct is_random_access_iterator<U>
{
	static const bool value = is_same<U::iterator_category,random_access_iterator_tag>;
};*/


#endif
