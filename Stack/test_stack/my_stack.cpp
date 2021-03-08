#include <iostream>       // std::cout
#include "../stack.hpp"
#include "../../Vector/vector.hpp"

int main ()
{
	ft::stack<int> first;                    // empty stack
	ft::vector<int> myvector (2,200);
	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	ft::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';

}
