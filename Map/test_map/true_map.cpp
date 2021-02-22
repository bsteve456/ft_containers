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

	return 0;
}
