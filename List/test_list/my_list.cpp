#include "../Node.hpp"
#include "../List.hpp"


int main()
{
	ft::List<int> second (4,100);
	ft::List<int>::iterator ite = second.end();

	for (ft::List<int>::iterator it = second.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	ft::List<int> third (second.begin(),second.end());
	ite = third.end();
	for (ft::List<int>::iterator it = third.begin(); it != ite; ++it)
		std::cout << *it << std::endl;
	ft::List<int> fourth (third);
	ite = fourth.end();
	for (ft::List<int>::iterator it = fourth.begin(); it != ite; it++)
		*it = 5;
	for (ft::List<int>::iterator it = fourth.begin(); it != ite; it++)
			std::cout << *it << std::endl;
	ft::List<int> f (3);      // list of 3 zero-initialized ints
	ft::List<int> s (5);     // list of 5 zero-initialized ints

	s = f;
	f = ft::List<int>();
	std::cout << "Size of first: " << int (f.size()) << '\n';
	std::cout << "Size of second: " << int (s.size()) << '\n';
	--ite;
	std::cout << *ite << std::endl;
	ite = fourth.begin();
	std::cout << *ite-- << std::endl;
	ite++;
	ite++;
	std::cout << *ite++ << std::endl;

}

