#include <iostream>
#include <list>
#include <iterator>
#include <vector>

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
	for (int i=1; i<=6; ++i)
		mylist.push_back(i);
	for (std::list<int>::reverse_iterator it=mylist.rbegin(); it!=mylist.rend(); ++it)
		std::cout << *it << std::endl;

	typedef std::list<int>::iterator iter_type;
	std::reverse_iterator<iter_type> rev_end (mylist.begin());
	std::reverse_iterator<iter_type> rev_begin (mylist.end());
	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Maximum size of a 'list' is " << mylist.max_size() << "\n";

	mylist.push_front(300);
	mylist.push_front(200);
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "Popping out the elements in mylist:";
	while (!mylist.empty())
	{
		std::cout << ' ' << mylist.front();
		mylist.pop_front();
	}
	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';

	mylist.push_back(3500);
	mylist.push_back(100);
	ite = mylist.begin();
	++ite;
	mylist.insert (ite,10);
	mylist.insert (ite, 1 , 5);
	mylist.insert (ite, 1 , 7);
	//	std::vector<int> myvector (2,30);
	//	mylist.insert (ite,myvector.begin(),myvector.end());
	for (ite=mylist.begin(); ite!=mylist.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';

	std::list<int>::iterator it1, it2;
	it1 = mylist.begin();
	it2 = mylist.end();
	--it2;
	it2 = mylist.erase (it2);
	it1 = mylist.erase (it1);

	++it1;
	--it2;

	for (ite=mylist.begin(); ite!=mylist.end(); ite++)
		std::cout << ' ' << *ite;
	std::cout << '\n';

	mylist.erase (it1,it2);

	for (ite=mylist.begin(); ite!=mylist.end(); ite++)
		std::cout << ' ' << *ite;
	std::cout << '\n';

	std::list<int> first (5,200);  // five ints with a value of 200

	mylist.swap(first);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "first contains:";
	for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << "\nsize of first is " << first.size() << '\n';
	first.clear();
	std::cout << "\nsize of first is " << first.size() << '\n';
	for (int i = 1; i <= 4; ++i)
		first.push_back(i * 10);
	ite = mylist.begin();
	++ite;
	mylist.splice(ite, first);
	first.splice(first.begin(), mylist, ite);
	ite = mylist.begin();
	ite++;
	++ite;
	ite++;
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.splice (mylist.begin(), mylist, ite, mylist.end());
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	for (std::list<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

