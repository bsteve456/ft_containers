#include <iostream>       // std::cout
#include "../queue.hpp"

int main ()
{
	ft::list<int> mylist (2,200);         // list with 2 elements

	ft::queue<int> first;                 // empty queue

	ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > fourth (mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
	ft::queue<int> myqueue;
	int sum (0);

	for (int i=1;i<=10;i++) myqueue.push(i);

	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}

	std::cout << "total: " << sum << '\n';
	myqueue.push(12);
	myqueue.push(75);   // this is now the back

	myqueue.back() -= myqueue.front();

	std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

	ft::queue<int> a, b, c;
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
