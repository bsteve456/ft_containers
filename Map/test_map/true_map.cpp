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

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	for (std::map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

/*	std::map<char,int> second (first.begin(),first.end());
	for (std::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::map<char,int> third (second);
	for (std::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::map<char,int,classcomp> fourth;                 // class as Compare
	for (std::map<char,int>::iterator it=fourth.begin(); it!=fourth.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	for (std::map<char,int>::iterator it=fifth.begin(); it!=fifth.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/

	return 0;
}
