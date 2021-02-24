#include <iostream>
#include "../Map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main ()
{
	ft::Map<char,int> first;
	ft::Map<char,int> five;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	for (ft::Map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::Map<char,int> second (first.begin(),first.end());
	for (ft::Map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::Map<char,int> third (second);
	for (ft::Map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	first.clear();
	first['c']=50;
	first['d']=70;
	for (ft::Map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << first.max_size() << std::endl;

	five=first;                // second now contains 3 ints
	first=ft::Map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << five.size() << '\n';

	for (ft::Map<char, int>::reverse_iterator it=second.rbegin(); it!=second.rend(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	typedef ft::Map<char, int>::iterator iter_type;
	ft::MyReverseIterator<iter_type> rev_end (second.begin());
	ft::MyReverseIterator<iter_type> rev_begin (second.end());

	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	ft::Map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<ft::Map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::Map<char,int>::iterator it = mymap.begin();
/*	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
*/
	// third insert function version (range insertion):
	ft::Map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.end());

	// showing contents:
/*	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
