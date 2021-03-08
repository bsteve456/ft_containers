#include <iostream>       // std::cout
#include <list>           // std::list
#include <queue>          // std::queue

int main ()
{
  std::list<int> mylist (2,200);         // list with 2 elements

  std::queue<int> first;                 // empty queue

  std::queue<int,std::list<int> > third; // empty queue with list as underlying container
  std::queue<int,std::list<int> > fourth (mylist);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}
