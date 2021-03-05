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

	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';

	std::vector<int> f;

	f.push_back(78);
	f.push_back(16);

	// now front equals 78, and back 16

	f.front() -= f.back();
	std::cout << "f.front() is now " << f.front() << '\n';

	std::cout << "Size of first: " << int (first.size()) << '\n';
	first.assign (7,100);
	std::cout << "Size of first: " << int (first.size()) << '\n';

	std::vector<int> myvec (3,100);
	std::vector<int>::iterator ita;

	ita = myvec.begin();
	ita = myvec.insert ( ita , 200 );

	myvec.insert (ita,2,300);

	// "it" no longer valid, get a new one:
	ita = myvec.begin();

	std::cout << "myvector contains:";
	for (ita=myvec.begin(); ita<myvec.end(); ita++)
		std::cout << ' ' << *ita;
	std::cout << '\n';

	myvector.clear();
	for (int i=1; i<=10; i++) myvector.push_back(i);

	ita = myvector.begin();

	// erase the 6th element
	myvector.erase (ita + 5);
	ita = myvector.begin();
	std::cout << "myvector contains:";
	for (unsigned i=0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	// erase the first 3 elements:
	myvector.erase (myvector.begin(), ita + 3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::vector<int> fo (3,100);   // three ints with a value of 100
	std::vector<int> ba (5,200);   // five ints with a value of 200

	fo.swap(ba);

	std::cout << "fo contains:";
	for (unsigned i=0; i<fo.size(); i++)
		std::cout << ' ' << fo[i];
	std::cout << '\n';

	std::cout << "ba contains:";
	for (unsigned i=0; i<ba.size(); i++)
		std::cout << ' ' << ba[i];
	std::cout << '\n';

	std::vector<int> faa (3,100);   // three ints with a value of 100
	std::vector<int> bur (2,200);   // two ints with a value of 200

	if (faa==bur) std::cout << "faa and bur are equal\n";
	if (faa!=bur) std::cout << "faa and bur are not equal\n";
	if (faa< bur) std::cout << "faa is less than bur\n";
	if (faa> bur) std::cout << "faa is greater than bur\n";
	if (faa<=bur) std::cout << "faa is less than or equal to bur\n";
	if (faa>=bur) std::cout << "faa is greater than or equal to bur\n";

	int n = faa.begin() - faa.end();
	std::cout << "n : " << n << std::endl;

	ita = myvector.begin();
	ita += 4;
	for(std::vector<int>::iterator it = myvector.begin(); it != ita; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ita = myvector.begin();
	ita[2] = 30;
	for(std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	typedef std::vector<int>::iterator iter_type;

	std::reverse_iterator<iter_type> rev_it;

	rev_it = myvector.rbegin() +3;

	std::cout << "The fourth element from the end is: " << *rev_it << '\n';

	std::reverse_iterator<iter_type> rev_iterator;

	rev_iterator = myvector.rend() - 3;

	std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
}
