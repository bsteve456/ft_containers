#include "../vector.hpp"
#include <cmath>
#include <string>
#include <cctype>


int main()
{
	std::cout << "############################" << std::endl;
	std::cout << "##### CONSTRUCTOR TEST #####" << std::endl;
	std::cout << "############################\n" << std::endl;

	ft::vector<int> first;                                // empty vector of ints
	std::cout << "The contents of first are:";
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> second (4,100);                       // four ints with value 100
	std::cout << "The contents of second are:";
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	std::cout << "The contents of third are:";
	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> fourth (second);                       // a copy of third
	std::cout << "The contents of fourth are:";
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n##############################" << std::endl;
	std::cout << "#####  OPERATOR  =  TEST #####" << std::endl;
	std::cout << "##############################\n" << std::endl;


	std::cout << "Create empty vector : myvector:" << std::endl;
	ft::vector<int> myvector;
	myvector = fourth;

	std::cout << "The contents of myvector after operator = (fourth) are:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n###################################" << std::endl;
	std::cout << "#####  REVERSE ITERATOR  TEST #####" << std::endl;
	std::cout << "###################################\n" << std::endl;

	for (int i=1; i<=6; ++i)
		myvector.push_back(i);

	std::cout << "The contents of myvector are:";
	for (ft::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The reverse contents of myvector are:";
	for (ft::vector<int>::reverse_iterator it=myvector.rbegin(); it!=myvector.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	const ft::vector<int> test = myvector;
	std::cout << "The const reverse contents of const myvector(test) are:";
	for (ft::vector<int>::const_reverse_iterator it=test.rbegin(); it!=test.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	typedef ft::vector<int>::iterator iter_type;

	ft::MyReverseIterator<iter_type> rev_it;
	rev_it = 3 + myvector.rbegin();
	std::cout << "The fourth element from the end is: " << *rev_it << '\n';

	ft::MyReverseIterator<iter_type> rev_iterator;
	rev_iterator = myvector.rend() - 3;
	std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';

	rev_it = myvector.rbegin();
	rev_it += 2;
	std::cout << "The third element from the end is: " << *rev_it << '\n';

	rev_iterator = myvector.rend();
	rev_iterator -= 4;
	std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';

	rev_iterator = myvector.rbegin();
	std::cout << "The fourth element from the end is: " << rev_iterator[5] << '\n';

	ft::MyReverseIterator<ft::vector<int>::iterator> from,until;

	from = myvector.rbegin();
	until = myvector.rend();

	std::cout << "The base() contents of myvector in Reverse Iterator are: ";
	for (iter_type it = until.base(); it != from.base(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "myvector has " << (until-from) << " elements.\n";

	std::cout << "\n###################################" << std::endl;
	std::cout << "#########  MAX SIZE TEST ##########" << std::endl;
	std::cout << "###################################\n" << std::endl;

	myvector.clear();
	for (int i=0; i<100; i++)
		myvector.push_back(i);
	std::cout << "The contents of myvector are:";
	for (ft::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";

	std::cout << "\n############################" << std::endl;
	std::cout << "#######  RESIZE TEST #######" << std::endl;
	std::cout << "############################\n" << std::endl;

	myvector.resize(5);
	std::cout << "myvector contains after resize(5):";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.resize(8,100);
	std::cout << "myvector contains after resize(8) with value = 100:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.resize(12);
	std::cout << "myvector contains after resize(12):";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "\n##############################" << std::endl;
	std::cout << "#######  CAPACITY TEST #######" << std::endl;
	std::cout << "##############################\n" << std::endl;

	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "foo capacity: " << sz << std::endl;
	std::cout << "Add value one by one too pass capacity and change it." << std::endl;
	for (size_t i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::cout << "\n##############################" << std::endl;
	std::cout << "#######  RESERVE TEST #######" << std::endl;
	std::cout << "##############################\n" << std::endl;

	ft::vector<int> bar;
	sz = bar.capacity();
	std::cout << "bar capacity: " << sz << std::endl;
	std::cout << "Reserve 100 directly to capacity." << std::endl;
	bar.reserve(100);   // this is the only difference with foo above
	for (size_t i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::cout << "\n#############################" << std::endl;
	std::cout << "#####  EMPTY SIZE  TEST #####" << std::endl;
	std::cout << "#############################\n" << std::endl;

	ft::vector<int> f = myvector;
	int sum (0);

	while (!f.empty())
	{
		sum += f.back();
		f.pop_back();
	}
	std::cout << "total: " << sum << '\n';

	std::cout << "\n###########################" << std::endl;
	std::cout << "#########  AT TEST ########" << std::endl;
	std::cout << "###########################\n" << std::endl;

	std::cout << "myvector contains are:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';

	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains after at: ";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';

	std::cout << "\n#############################" << std::endl;
	std::cout << "#####  FRONT BACK  TEST #####" << std::endl;
	std::cout << "#############################\n" << std::endl;

	ft::vector<int> fv;

	fv.push_back(78);
	fv.push_back(16);

	// now front equals 78, and back 16

	fv.front() -= fv.back();
	std::cout << "fv.front() is now " << fv.front() << '\n';

	std::cout << "\n###############################" << std::endl;
	std::cout << "#########  ASSIGN TEST ########" << std::endl;
	std::cout << "###############################\n" << std::endl;

	first.clear();
	second.clear();
	third.clear();

	first.assign (7,100);             // 7 ints with a value of 100
	std::cout << "The contents of first after assign(range number) are:";
	for (ft::vector<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int>::iterator ith;
	ith=first.begin()+1;

	second.assign (ith,first.end()-1); // the 5 central values of first
	std::cout << "The contents of second after assign(range iterator) are:";
	for (ft::vector<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	int myint[] = {1776,7,4};
	third.assign (myint,myint+3);   // assigning from array.
	std::cout << "The contents of third after (range array) are:";
	for (ft::vector<int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';


	std::cout << "\n#############################" << std::endl;
	std::cout << "##########  INSERT TEST #####" << std::endl;
	std::cout << "#############################\n" << std::endl;

	ft::vector<int> myvec (3,100);
	std::cout << "The contents of myvec are:";
	for (ft::vector<int>::iterator it=myvec.begin(); it!=myvec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int>::iterator ita;
	ita = myvec.begin();

	ita = myvec.insert ( ita , 200 );
	std::cout << "The contents of myvec after insert(one element) are:";
	for (ft::vector<int>::iterator it=myvec.begin(); it!=myvec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myvec.insert (ita,2,300);
	std::cout << "The contents of myvec after insert(one element with value) are:";
	for (ft::vector<int>::iterator it=myvec.begin(); it!=myvec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> anothervector (2,400);
	myvec.insert (ita+2,anothervector.begin(),anothervector.end());
	std::cout << "The contents of myvec after insert(ierator range) are:";
	for (ft::vector<int>::iterator it=myvec.begin(); it!=myvec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	int myarray [] = { 501,502,503 };
	myvec.insert (myvec.begin(), myarray, myarray+3);
	std::cout << "The contents of myvec after insert(array range) are:";
	for (ft::vector<int>::iterator it=myvec.begin(); it!=myvec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n############################" << std::endl;
	std::cout << "########  ERASE TEST #######" << std::endl;
	std::cout << "############################\n" << std::endl;

	myvector.clear();
	for (int i=1; i<=10; i++) myvector.push_back(i);
	std::cout << "myvector contains are:";
	for (unsigned i=0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	// erase the 6th element
	ita = myvector.begin();
	myvector.erase (5 + ita);
	std::cout << "myvector contains after erase(6th element):";
	for (unsigned i=0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	// erase the first 3 elements:
	ita = myvector.begin();
	myvector.erase (myvector.begin(), ita + 3);
	std::cout << "myvector contains after erase(range first 3 elements):";
	for (unsigned i=0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "\n###########################" << std::endl;
	std::cout << "########  SWAP TEST #######" << std::endl;
	std::cout << "###########################\n" << std::endl;

	ft::vector<int> fo (3,100);   // three ints with a value of 100
	ft::vector<int> ba (5,200);   // five ints with a value of 200

	std::cout << "fo contains after swap:";
	for (unsigned i=0; i<fo.size(); i++)
		std::cout << ' ' << fo[i];
	std::cout << '\n';

	std::cout << "ba contains after swap:";
	for (unsigned i=0; i<ba.size(); i++)
		std::cout << ' ' << ba[i];
	std::cout << '\n';

	fo.swap(ba);

	std::cout << "fo contains after swap:";
	for (unsigned i=0; i<fo.size(); i++)
		std::cout << ' ' << fo[i];
	std::cout << '\n';

	std::cout << "ba contains after swap:";
	for (unsigned i=0; i<ba.size(); i++)
		std::cout << ' ' << ba[i];
	std::cout << '\n';

	std::cout << "\n#######################################" << std::endl;
	std::cout << "#########  RELATION OPERATOR TEST #####" << std::endl;
	std::cout << "#######################################\n" << std::endl;

	ft::vector<int> faa (3,100);   // three ints with a value of 100
	ft::vector<int> bur (2,200);   // two ints with a value of 200

	std::cout << "faa contains:";
	for (unsigned i=0; i<faa.size(); i++)
		std::cout << ' ' << faa[i];
	std::cout << '\n';

	std::cout << "bur contains:";
	for (unsigned i=0; i<bur.size(); i++)
		std::cout << ' ' << bur[i];
	std::cout << '\n';

	if (faa==bur) std::cout << "faa and bur are equal\n";
	if (faa!=bur) std::cout << "faa and bur are not equal\n";
	if (faa< bur) std::cout << "faa is less than bur\n";
	if (faa> bur) std::cout << "faa is greater than bur\n";
	if (faa<=bur) std::cout << "faa is less than or equal to bur\n";
	if (faa>=bur) std::cout << "faa is greater than or equal to bur\n";

	std::cout << "\n#######################################" << std::endl;
	std::cout << "#########  CONST ITERATOR TEST ########" << std::endl;
	std::cout << "#######################################\n" << std::endl;

	std::cout << "ba contains:";
	for (ft::vector<int>::const_iterator it = ba.begin(); it!=ba.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n#######################################" << std::endl;
	std::cout << "#########  SOME ITERATOR TEST ########" << std::endl;
	std::cout << "#######################################\n" << std::endl;

	int n = faa.begin() - faa.end();
	std::cout << "found faa size by iterator substract(begin - end) : " << n << std::endl;

	ita = myvector.begin();
	ita += 4;
	std::cout << " += operator iterator(begin() + 4) and display myvector contains until this iterator : " << std::endl;
	for(ft::vector<int>::iterator it = myvector.begin(); it != ita; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ita = myvector.begin();
	ita[2] = 30;
	std::cout << "Change the third value with iterator and display myvector contains: " << std::endl;
	for(ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

}
