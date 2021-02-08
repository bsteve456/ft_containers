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
}

