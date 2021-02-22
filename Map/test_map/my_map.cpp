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

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
//	ft::Map<char,int>::iterator it=first.end();
	for (ft::Map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

/*	ft::Map<char,int> second (first.begin(),first.end());
	for (ft::Map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::Map<char,int> third (second);
	for (ft::Map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::Map<char,int,classcomp> fourth;                 // class as Compare
	for (ft::Map<char,int>::iterator it=fourth.begin(); it!=fourth.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	bool(*fn_pt)(char,char) = fncomp;
	ft::Map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	for (ft::Map<char,int>::iterator it=fifth.begin(); it!=fifth.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/

	return 0;
}
