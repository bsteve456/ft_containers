#include <iostream>
#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main ()
{
	std::map<char,int> first;
	std::map<char,int> five;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	for (std::map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::map<char,int> second (first.begin(),first.end());
	for (std::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::map<char,int> third (second);
	for (std::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	first.clear();
	first['c']=50;
	first['d']=70;
	for (std::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << first.max_size() << std::endl;

	five=first;                // second now contains 3 ints
	first=std::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << five.size() << '\n';

	for (std::map<char, int>::reverse_iterator it=second.rbegin(); it!=second.rend(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	typedef std::map<char, int>::iterator iter_type;
	std::reverse_iterator<iter_type> rev_end (second.begin());
	std::reverse_iterator<iter_type> rev_begin (second.end());

	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
/*		mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting*/
	
	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
/*		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);
	std::map<char,int>::iterator ite = foo.end();
	ite--;
	ite++;

	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=ite; ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::map<char,int>::key_compare mycomp = mymap.key_comp();
	char highest = mymap.rbegin()->first;

	std::cout << "key comp" << std::endl;
	it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << '\n';

	std::cout << "value comp" << std::endl;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "vc : mymap contains:\n";

	std::pair<char,int> highest1 = *mymap.rbegin();          // last element

	std::map<char,int>::iterator it1 = mymap.begin();
	do {
		std::cout << it1->first << " => " << it1->second << '\n';
	} while ( mymap.value_comp()(*it1++, highest1) );

	char c;
	for (c='a'; c<'z'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}

	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b

	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret1;
	ret1 = mymap.equal_range('a');

	std::cout << "lower bound points to: ";
	std::cout << ret1.first->first << " => " << ret1.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret1.second->first << " => " << ret1.second->second << '\n';
	for (std::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
