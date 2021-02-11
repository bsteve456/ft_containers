#include <iostream>
#include <list>

int main()
{
	std::list<int> second (4,100);
	std::list<int>::iterator ite = second.end();

	for (std::list<int>::iterator it = second.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	std::list<int> third (second.begin(),second.end());
	ite = third.end();
	for (std::list<int>::iterator it = third.begin(); it != ite; ++it)
		std::cout << *it << std::endl;
	std::list<int> fourth (third);
	ite = fourth.end();
	for (std::list<int>::iterator it = fourth.begin(); it != ite; it++)
		*it = 5;
	for (std::list<int>::iterator it = fourth.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	std::list<int> f (3);      // list of 3 zero-initialized ints
	std::list<int> s (5);     // list of 5 zero-initialized ints

	s = f;
	f = std::list<int>();
	std::cout << "Size of first: " << int (f.size()) << '\n';
	std::cout << "Size of second: " << int (s.size()) << '\n';
	--ite;
	std::cout << *ite << std::endl;
	ite = fourth.begin();
	std::cout << *ite-- << std::endl;
	ite++;
	std::cout << *ite++ << std::endl;
	std::list<int> mylist;
	for (int i=1; i<=5; ++i)
		mylist.push_back(i);

	for (std::list<int>::reverse_iterator it=mylist.rbegin(); it!=mylist.rend(); ++it)
    	std::cout << *it << std::endl;
}

