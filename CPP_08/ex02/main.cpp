#include "MutantStack.hpp"
#include <iostream>
#include <list>


int main()
{

std::cout << "MutantStack Tests:" << std::endl;
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << "	" << mstack.top() << std::endl;
mstack.pop();
std::cout << "	" << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::abc();
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << "	" << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
std::cout << "===================================" << std::endl;
std::cout << "List Tests:" << std::endl;
std::list<int> tlist;
tlist.push_back(5);
tlist.push_back(17);
std::cout << "	" << tlist.back() << std::endl;
tlist.pop_back();
std::cout << "	" << tlist.size() << std::endl;
tlist.push_back(3);
tlist.push_back(5);
tlist.push_back(737);
//[...]
tlist.push_back(0);
std::list<int>::iterator lit = tlist.begin();
std::list<int>::iterator lite = tlist.end();
++lit;
--lit;
while (lit != lite)
{
std::cout << "	" << *lit << std::endl;
++lit;
}
std::list<int> ls(tlist);
return 0;
}
