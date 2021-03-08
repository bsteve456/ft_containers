#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector

int main ()
{
	std::vector<int> myvector (2,200);        // vector with 2 elements

	std::stack<int> first;                    // empty stack

	std::stack<int,std::vector<int> > third;  // empty stack using vector
	std::stack<int,std::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	std::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "total: " << sum << '\n';
	std::stack<int> a, b, c;
	a.push(10);
	a.push(20);
	a.push(30);
	b.push(10);
	b.push(20);
	b.push(30);
	c.push(10);
	c.push(20);
	c.push(30);
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	return 0;
}
