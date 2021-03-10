#include <iostream>
#include "../map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main ()
{
	std::cout << "############################" << std::endl;
	std::cout << "##### CONSTRUCTOR TEST #####" << std::endl;
	std::cout << "############################\n" << std::endl;

	ft::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::cout << "The contents of first are: ";
	for (ft::map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::map<char,int> second (first.begin(),first.end());

	std::cout << "\nThe contents of second are: ";
	for (ft::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::map<char,int> third (second);

	std::cout << "\nThe contents of third are: ";
	for (ft::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::map<char,int,classcomp> fourth;

	bool(*fn_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	std::cout << "\n############################" << std::endl;
	std::cout << "##### OPERATOR = TEST ######" << std::endl;
	std::cout << "############################\n" << std::endl;

	ft::map<char, int> five;

	five = first;
	first=ft::map<char,int>();
	std::cout << "\nThe contents of five after operator = are: ";
	for (ft::map<char,int>::iterator it=five.begin(); it!=five.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of five: " << five.size() << '\n';

	std::cout << "\n##################################" << std::endl;
	std::cout << "##### REVERSE ITERATOR TEST ######" << std::endl;
	std::cout << "##################################\n" << std::endl;

	std::cout << "\nThe contents of second are: ";
	for (ft::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\nThe reverse contents of second are: ";
	for (ft::map<char, int>::reverse_iterator it=second.rbegin(); it!=second.rend(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	const ft::map<char, int> test = second;

	std::cout << "\nThe const reverse contents of const second(test) are: ";
	for (ft::map<char, int>::const_reverse_iterator it=test.rbegin(); it!=test.rend(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	typedef ft::map<char, int>::iterator iter_type;
	ft::MyReverseIterator<iter_type> rev_end (second.begin());
	ft::MyReverseIterator<iter_type> rev_begin (second.end());

	std::cout << "\nThe base() contents of second in Reverse Iterator are: ";
	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "\n#######################" << std::endl;
	std::cout << "##### EMPTY TEST ######" << std::endl;
	std::cout << "#######################\n" << std::endl;

	ft::map<char, int> f;

	f['a']=10;
	f['b']=20;
	f['c']=30;

	std::cout << "\nSize of f before empty test: " << f.size() << '\n';
	while (!f.empty())
	{
		std::cout << f.begin()->first << " => " << f.begin()->second << '\n';
		f.erase(f.begin());
	}
	std::cout << "\nSize of f after empty test: " << f.size() << '\n';

	std::cout << "\n##########################" << std::endl;
	std::cout << "##### MAX SIZE TEST ######" << std::endl;
	std::cout << "##########################\n" << std::endl;

	std::cout << "Maximum size of a 'map' is " << f.max_size() << "\n";

	std::cout << "\n#############################" << std::endl;
	std::cout << "##########  INSERT TEST #####" << std::endl;
	std::cout << "#############################\n" << std::endl;

	ft::map<char,int> mymap;

	std::cout << "\nmymap contains are:\n";
	for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );

	std::cout << "\nmymap contains after insert(one parameter) are:\n";
	for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.insert ( std::pair<char,int>('z',200) );

	std::cout << "\nmymap contains after second insert(one parameter) are:\n";
	for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	std::cout << "\n Try to insert an already existing element.\n";
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	std::cout << "\nmymap contains after third insert(one parameter) are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
	std::cout << "\nmymap contains after fourth insert(one parameter) are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));
	std::cout << "\nanothermap contains after insert(range insertion) are:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n############################" << std::endl;
	std::cout << "#####  ERASE SIZE  TEST ####" << std::endl;
	std::cout << "############################\n" << std::endl;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;


	std::cout << "\nmymap contains before erase are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	std::cout << "\nmymap contains after erase by iterator('b') are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.erase ('c');                  // erasing by key
	std::cout << "\nmymap contains after erase by key('c') are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';


	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range
	std::cout << "\nmymap contains after erase by range(start from 'e') are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n###########################" << std::endl;
	std::cout << "#####  SWAP SIZE  TEST ####" << std::endl;
	std::cout << "###########################\n" << std::endl;

	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	std::cout << "foo contains before swap are:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains before swap are:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';


	foo.swap(bar);
	ft::map<char,int>::iterator ite = foo.end();
	ite--;
	ite++;
	std::cout << "foo contains after swap are:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=ite; ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains after swap are:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';


	std::cout << "\n############################" << std::endl;
	std::cout << "#########  CLEAR TEST ######" << std::endl;
	std::cout << "############################\n" << std::endl;

	std::cout << "size of first before clear is " << foo.size() << '\n';
	foo.clear();
	std::cout << "size of first after clear is " << foo.size() << '\n';

	std::cout << "\n###############################" << std::endl;
	std::cout << "#########  KEY COMP TEST ######" << std::endl;
	std::cout << "###############################\n" << std::endl;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	std::cout << "char highest have the highest key(ascii order)." << std::endl;
	char highest = mymap.rbegin()->first;

	std::cout << "Compare highest with all the other keys and display all the keys lower than highest in mymap." << std::endl;
	it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << '\n';

	std::cout << "\n#################################" << std::endl;
	std::cout << "#########  VALUE COMP TEST ######" << std::endl;
	std::cout << "#################################\n" << std::endl;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;


	std::cout << "char highest1 have the last element." << std::endl;
	std::pair<char,int> highest1 = *mymap.rbegin();          // last element


	std::cout << "Compare highest1 with all the other value and display all the value lower than highest1 in mymap." << std::endl;
	ft::map<char,int>::iterator it1 = mymap.begin();
	do {
		std::cout << it1->first << " => " << it1->second << '\n';
	} while ( mymap.value_comp()(*it1++, highest1) );

	std::cout << "\n#################################" << std::endl;
	std::cout << "#########  COUNT TEST ###########" << std::endl;
	std::cout << "#################################\n" << std::endl;

	std::cout << "\nmymap contains are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	char c;
	for (c='a'; c<'z'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}

	std::cout << "\n######################################" << std::endl;
	std::cout << "#########  LOWER AND UPPER TEST ######" << std::endl;
	std::cout << "######################################\n" << std::endl;

	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	std::cout << "\nmymap contains are:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\nlower bound points to b:\n";
	itlow=mymap.lower_bound ('b');  // itlow points to b

	std::cout << "\nupper bound points to e:\n";
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	std::cout << "\nmymap contains after erase [itlow, itup) are:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n######################################" << std::endl;
	std::cout << "#########  EQUAL RANGE TEST ##########" << std::endl;
	std::cout << "######################################\n" << std::endl;

	std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret1;
	std::cout << "Create a pair of two element at most(start from 'a'): ";
	ret1 = mymap.equal_range('a');

	std::cout << "lower bound points to: ";
	std::cout << ret1.first->first << " => " << ret1.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret1.second->first << " => " << ret1.second->second << '\n';

	std::cout << "\n#######################################" << std::endl;
	std::cout << "#########  CONST ITERATOR TEST ########" << std::endl;
	std::cout << "#######################################\n" << std::endl;

	for (ft::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}
