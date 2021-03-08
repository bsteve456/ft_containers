#include <iostream>       // std::cout
#include "../queue.hpp"

int main ()
{
	ft::List<int> mylist (2,200);         // list with 2 elements

	ft::queue<int> first;                 // empty queue

	ft::queue<int,ft::List<int> > third; // empty queue with list as underlying container
	ft::queue<int,ft::List<int> > fourth (mylist);

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
	return 0;
}
