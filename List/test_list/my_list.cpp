#include "../Node.hpp"
#include "../List.hpp"


int main()
{
	List<int> second (4,100);
	List<int>::iterator ite = second.end();

	for (List<int>::iterator it = second.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	List<int> third (second.begin(),second.end());
	ite = third.end();
	for (List<int>::iterator it = third.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	List<int> fourth (third);
	ite = fourth.end();
	for (List<int>::iterator it = fourth.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	List<int> f (3);      // list of 3 zero-initialized ints
	List<int> s (5);     // list of 5 zero-initialized ints

	s = f;
	f = List<int>();
	std::cout << "Size of first: " << int (f.size()) << '\n';
	std::cout << "Size of second: " << int (s.size()) << '\n';
	ite--;
	std::cout << *ite << std::endl;
	ite = fourth.begin();
	ite--;
	ite++;
	std::cout << *ite << std::endl;
}

