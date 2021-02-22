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
		return 0;
}
