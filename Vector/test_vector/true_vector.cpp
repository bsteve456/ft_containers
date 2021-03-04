#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>


int main()
{
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	//std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (second);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	//int myints[] = {16,2,77,29};
	//std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::vector<int> myvector;
	myvector = fourth;
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myvector.clear();
	for (int i=1; i<=6; ++i)
		myvector.push_back(i);
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << *it << std::endl;
	for (std::vector<int>::reverse_iterator it=myvector.rbegin(); it!=myvector.rend(); ++it)
		std::cout << *it << std::endl;

	myvector.clear();
	for (int i=0; i<100; i++)
		myvector.push_back(i);
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);
	std::cout << "myvector contains:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}
