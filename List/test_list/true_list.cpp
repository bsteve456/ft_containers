#include <iostream>
#include <list>
#include <iterator>
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
		std::vector<int> myvector (2,30);
		mylist.insert (ite,myvector.begin(),myvector.end());
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

	mylist.remove(200);
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.push_front(2);
	mylist.push_front(9);
	mylist.push_front(29);
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.remove_if (single_digit);
	mylist.remove_if (is_odd());
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::list<double> doubles;

	doubles.push_back(15.6);
	doubles.push_back(15.6);
	doubles.push_back(15.455);
	doubles.push_back(17.2);
	doubles.push_back(25.6);
	doubles.push_back(25.6);
	doubles.push_back(200.34);
	doubles.push_back(201.5);
	for (std::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	doubles.unique();
	for (std::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	doubles.unique (same_integral_part);
	for (std::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	doubles.unique (is_near());
	for (std::list<double>::iterator it=doubles.begin(); it!=doubles.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::list<std::string> tp;
	std::list<std::string>::iterator it;
	tp.push_back ("one");
	tp.push_back ("two");
	tp.push_back ("Three");
	tp.sort();
	std::cout << "tp contains:";
	for (it=tp.begin(); it!=tp.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	tp.sort(compare_nocase);
	std::cout << "tp contains:";
	for (it=tp.begin(); it!=tp.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::list<double> five, six;
	five.push_back (3.1);
	five.push_back (2.2);
	five.push_back (2.9);
	six.push_back (3.7);
	six.push_back (7.1);
	six.push_back (1.4);
	five.sort();
	six.sort();
	five.merge(six);
	std::cout << "five contains:";
	for (std::list<double>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	six.push_back (2.1);
	five.merge(six,mycomparison);
	std::cout << "five contains:";
	for (std::list<double>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	five.reverse();
	std::cout << "five contains:";
	for (std::list<double>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::list<int> a, b, c;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	b = a;
	c.push_front(10);
	c.push_front(20);
	c.push_front(30);
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	std::list<int> foo (3,100);   // three ints with a value of 100
	std::list<int> bar (5,200);   // five ints with a value of 200
	std::swap(foo,bar);
	std::cout << "foo contains:";
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	for (std::list<int>::const_iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	foo.assign(4, 45);
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	foo.assign(bar.begin(), bar.end());
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	int myints[]={1776,7,4};
	foo.assign (myints,myints+3);
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

