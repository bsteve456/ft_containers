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
	for (std::list<int>::iterator it = third.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

