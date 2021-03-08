#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector

int main ()
{
  std::vector<int> myvector (2,200);        // vector with 2 elements

  std::stack<int> first;                    // empty stack

  std::stack<int,std::vector<int> > third;  // empty stack using vector
  std::stack<int,std::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}