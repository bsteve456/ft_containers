#include "../vector.hpp"
#include <cmath>
#include <string>
#include <cctype>


int main()
{
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	//std::vector<int> third (second.begin(),second.end());  // iterating through second
	ft::vector<int> fourth (second);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	//int myints[] = {16,2,77,29};
	//std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> myvector;
	myvector = fourth;
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myvector.clear();
	for (int i=1; i<=6; ++i)
		myvector.push_back(i);
	for (ft::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << *it << std::endl;
	for (ft::vector<int>::reverse_iterator it=myvector.rbegin(); it!=myvector.rend(); ++it)
		std::cout << *it << std::endl;
}
