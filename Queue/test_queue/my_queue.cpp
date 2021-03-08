#include <iostream>       // std::cout
#include "../queue.hpp"

int main ()
{
  ft::List<int> mylist (2,200);         // list with 2 elements

  ft::queue<int> first;                 // empty queue

  ft::queue<int,ft::List<int> > third; // empty queue with list as underlying container
  ft::queue<int,ft::List<int> > fourth (mylist);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}
