#include "../list.hpp"
#include "../../Vector/vector.hpp"
#include <vector>
#include <cmath>
#include <string>
#include <cctype>


bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

bool single_digit (const int& value) { return (value<10); }

struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main()
{
	ft::list<int>::iterator ite;
	std::cout << "############################" << std::endl;
	std::cout << "##### CONSTRUCTOR TEST #####" << std::endl;
	std::cout << "############################\n" << std::endl;

	ft::list<int> first;
	std::cout << "The contents of first are: ";
	for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ft::list<int> second (4,100);
	std::cout << "The contents of second are: ";
	for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ft::list<int> third (second.begin(),second.end());
	std::cout << "The contents of third are: ";
	for (ft::list<int>::iterator it = third.begin(); it != third.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ft::list<int> fourth (third);
	std::cout << "The contents of fourth are: ";
	for (ft::list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	int myints[] = {16,2,77,29};
	ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "The contents of fifth are: ";
	for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "\n##############################" << std::endl;
	std::cout << "#####  OPERATOR  =  TEST #####" << std::endl;
	std::cout << "##############################\n" << std::endl;

	ft::list<int> f (3);      // list of 3 zero-initialized ints
	ft::list<int> s (5);     // list of 5 zero-initialized ints

	std::cout << "Size of f: " << int (f.size()) << '\n';
	std::cout << "Size of s: " << int (s.size()) << '\n';

	s = f;
	std::cout << "Apply operator = to f and s" << std::endl;
	f = ft::list<int>();

	std::cout << "Size of f: " << int (f.size()) << '\n';
	std::cout << "Size of s: " << int (s.size()) << '\n';

	std::cout << "\n###################################" << std::endl;
	std::cout << "#####  REVERSE ITERATOR  TEST #####" << std::endl;
	std::cout << "###################################\n" << std::endl;

	ft::list<int> mylist;
	for (int i=1; i<=6; ++i)
		mylist.push_back(i);
	std::cout << "The contents of mylist are: ";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "The reverse contents of mylist are: ";
	for (ft::list<int>::reverse_iterator it=mylist.rbegin(); it!=mylist.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	typedef ft::list<int>::iterator iter_type;
	ft::MyReverseIterator<iter_type> rev_end (mylist.begin());
	ft::MyReverseIterator<iter_type> rev_begin (mylist.end());

	std::cout << "The base() contents of mylist in Reverse Iterator are: ";
	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n###########################" << std::endl;
	std::cout << "#####  MAX SIZE  TEST #####" << std::endl;
	std::cout << "###########################\n" << std::endl;

	std::cout << "Maximum size of a 'list' is " << mylist.max_size() << "\n";

	std::cout << "\n#############################" << std::endl;
	std::cout << "#####  EMPTY SIZE  TEST #####" << std::endl;
	std::cout << "#############################\n" << std::endl;

	mylist.push_front(300);
	mylist.push_front(200);
	std::cout << "The contents of mylist are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "Popping out the elements in mylist:";
	while (!mylist.empty())
	{
		std::cout << ' ' << mylist.front();
		mylist.pop_front();
	}
	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';

	std::cout << "\n#############################" << std::endl;
	std::cout << "#######  FRONT BACK TEST ####" << std::endl;
	std::cout << "#############################\n" << std::endl;

	mylist.push_back(77);
	mylist.push_back(22);

	mylist.front() -= mylist.back();

	std::cout << "mylist.front() is now " << mylist.front() << '\n';

	std::cout << "\n#############################" << std::endl;
	std::cout << "##########  INSERT TEST #####" << std::endl;
	std::cout << "#############################\n" << std::endl;

	mylist.push_back(3500);
	mylist.push_back(100);
	std::cout << "The contents of mylist are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ite = mylist.begin();
	++ite;
	mylist.insert (ite,10);

	std::cout << "The contents of mylist after first insert(one value insert) are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	mylist.insert (ite, 1 , 5);

	std::cout << "The contents of mylist after second insert(range insert) are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	mylist.insert (ite, 1 , 7);

	std::cout << "The contents of mylist after third insert(range insert) are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ft::vector<int> myvector (2,30);
	mylist.insert (ite,myvector.begin(),myvector.end());

	std::cout << "The contents of mylist after fourth insert(vector insert) are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	for (ite=mylist.begin(); ite!=mylist.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';

	std::cout << "\n############################" << std::endl;
	std::cout << "#####  ERASE SIZE  TEST ####" << std::endl;
	std::cout << "############################\n" << std::endl;

	ft::list<int>::iterator it1, it2;
	it1 = mylist.begin();
	it2 = mylist.end();
	--it2;
	it2 = mylist.erase (it2);
	std::cout << "The contents of mylist after first erase are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	it1 = mylist.erase (it1);
	std::cout << "The contents of mylist after second erase are: ";
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	++it1;
	--it2;

	mylist.erase (it1,it2);

	std::cout << "The contents of mylist after third erase(range) are: ";
	for (ite=mylist.begin(); ite!=mylist.end(); ite++)
		std::cout << ' ' << *ite;
	std::cout << '\n';

	std::cout << "\n###########################" << std::endl;
	std::cout << "#####  SWAP SIZE  TEST ####" << std::endl;
	std::cout << "###########################\n" << std::endl;

	ft::list<int> fir (5,200);  // five ints with a value of 200

	std::cout << "fir contains before swap:";
	for (ft::list<int>::iterator it=fir.begin(); it!=fir.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';


	mylist.swap(fir);

	std::cout << "mylist contains after swap:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "fir contains after swap:";
	for (ft::list<int>::iterator it=fir.begin(); it!=fir.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n############################" << std::endl;
	std::cout << "#########  RESIZE TEST #####" << std::endl;
	std::cout << "############################\n" << std::endl;

	mylist.resize(5);
	std::cout << "mylist contains after first resize:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.resize(8,100);

	std::cout << "mylist contains after second resize:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.resize(12);

	std::cout << "mylist contains after third resize:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n############################" << std::endl;
	std::cout << "#########  CLEAR TEST ######" << std::endl;
	std::cout << "############################\n" << std::endl;

	first.push_back(100);
	first.push_back(45);
	std::cout << "size of first before clear is " << first.size() << '\n';
	first.clear();
	std::cout << "size of first after clear is " << first.size() << '\n';

	std::cout << "\n############################" << std::endl;
	std::cout << "#########  SPLICE TEST #####" << std::endl;
	std::cout << "############################\n" << std::endl;

	for (int i = 1; i <= 4; ++i)
		first.push_back(i * 10);
	std::cout << "first contains:";
	for (ft::list<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ite = mylist.begin();
	++ite;

	std::cout << "mylist contains before splice:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.splice(ite, first);

	std::cout << "mylist contains after first splice:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	first.splice(first.begin(), mylist, ite);

	std::cout << "first contains after second splice:";
	for (ft::list<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ite = mylist.begin();
	ite++;
	++ite;
	ite++;
	mylist.splice (mylist.begin(), mylist, ite, mylist.end());

	std::cout << "mylist contains after third splice:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n############################" << std::endl;
	std::cout << "#########  REMOVE TEST #####" << std::endl;
	std::cout << "############################\n" << std::endl;

	mylist.remove(200);

	std::cout << "mylist contains after remove:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n###############################" << std::endl;
	std::cout << "#########  REMOVE IF TEST #####" << std::endl;
	std::cout << "###############################\n" << std::endl;

	mylist.push_front(2);
	mylist.push_front(9);
	mylist.push_front(29);
	std::cout << "mylist contains before remove if:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.remove_if (single_digit);

	std::cout << "mylist contains after remove if(single digit):";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.remove_if (is_odd());

	std::cout << "mylist contains after second remove if (is odd):";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n###############################" << std::endl;
	std::cout << "#########  UNIQUE TEST ########" << std::endl;
	std::cout << "###############################\n" << std::endl;

	ft::list<double> doubles;

	doubles.push_back(15.6);
	doubles.push_back(15.6);
	doubles.push_back(15.455);
	doubles.push_back(17.2);
	doubles.push_back(25.6);
	doubles.push_back(25.6);
	doubles.push_back(200.34);
	doubles.push_back(201.5);

	std::cout << "doubles contains before unique:";
	for (ft::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	doubles.unique();

	std::cout << "doubles contains after unique:";
	for (ft::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	doubles.unique (same_integral_part);

	std::cout << "doubles contains after second unique(same integral part):";
	for (ft::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	doubles.unique (is_near());

	std::cout << "doubles contains after second unique(is near):";
	for (ft::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n###############################" << std::endl;
	std::cout << "#########  SORT TEST ##########" << std::endl;
	std::cout << "###############################\n" << std::endl;

	ft::list<std::string> tp;
	tp.push_back ("one");
	tp.push_back ("two");
	tp.push_back ("Three");

	std::cout << "tp contains before sort:";
	for (ft::list<std::string>::iterator it=tp.begin(); it != tp.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	tp.sort();

	std::cout << "tp contains after sort:";
	for (ft::list<std::string>::iterator it=tp.begin(); it != tp.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	tp.sort(compare_nocase);
	std::cout << "tp contains after sort(compare nocase):";
	for (ft::list<std::string>::iterator it=tp.begin(); it != tp.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::cout << "\n################################" << std::endl;
	std::cout << "#########  MERGE TEST ##########" << std::endl;
	std::cout << "################################\n" << std::endl;

	ft::list<double> five, six;
	five.push_back (3.1);
	five.push_back (2.2);
	five.push_back (2.9);

	std::cout << "five contains before :";
	for (ft::list<double>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	six.push_back (3.7);
	six.push_back (7.1);
	six.push_back (1.4);

	std::cout << "six contains before :";
	for (ft::list<double>::iterator it=six.begin(); it!=six.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	five.sort();
	std::cout << "sort five" << std::endl;

	six.sort();
	std::cout << "sort six" << std::endl;

	five.merge(six);

	std::cout << "five contains after merge with six:";
	for (ft::list<double>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	six.push_back (2.1);
	five.merge(six,mycomparison);

	std::cout << "five contains after merge with six + funct compare:";
	for (ft::list<double>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n##################################" << std::endl;
	std::cout << "#########  REVERSE TEST #########" << std::endl;
	std::cout << "##################################\n" << std::endl;

	five.reverse();

	std::cout << "five contains after reverse:";
	for (ft::list<double>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n#######################################" << std::endl;
	std::cout << "#########  RELATION OPERATOR TEST #####" << std::endl;
	std::cout << "#######################################\n" << std::endl;

	ft::list<int> a, b, c;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);

	std::cout << "a contains:";
	for (ft::list<int>::iterator it=a.begin(); it!=a.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	b = a;

	std::cout << "b contains:";
	for (ft::list<int>::iterator it=b.begin(); it!=b.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	c.push_front(10);
	c.push_front(20);
	c.push_front(30);

	std::cout << "c contains:";
	for (ft::list<int>::iterator it=c.begin(); it!=c.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	std::cout << "\n#######################################" << std::endl;
	std::cout << "#########  SWAP NO MEMBER TEST ########" << std::endl;
	std::cout << "#######################################\n" << std::endl;

	ft::list<int> foo (3,100);   // three ints with a value of 100
	ft::list<int> bar (5,200);   // five ints with a value of 200

	std::cout << "foo contains:";
	for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (ft::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::swap(foo,bar);

	std::cout << "foo contains after swap:";
	for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains after swap:";
	for (ft::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n#######################################" << std::endl;
	std::cout << "#########  CONST ITERATOR TEST ########" << std::endl;
	std::cout << "#######################################\n" << std::endl;

	std::cout << "bar contains:";
	for (ft::list<int>::const_iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n###############################" << std::endl;
	std::cout << "#########  ASSIGN TEST ########" << std::endl;
	std::cout << "###############################\n" << std::endl;

	foo.assign(4, 45);

	std::cout << "foo contains after assign:";
	for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "foo contains after assign(bar assign):";
	foo.assign(bar.begin(), bar.end());
	for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	int myint[]={1776,7,4};
	foo.assign (myint,myint+3);

	std::cout << "foo contains after assign(array assign):";
	for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}
