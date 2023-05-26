#include "MutantStack.hpp"

#include <vector>
#include <deque>
#include <list>

#include <cstdlib>
#include <ctime>

#include <iostream>

int main()
{
		MutantStack<int> mstack;
		
		mstack.push(0);
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(4);
		mstack.push(5);

		std::cout << mstack.top() << std::endl;
		std::cout << mstack.size() << std::endl;

		mstack.push(42);
		std::cout << mstack.top() << std::endl;
		mstack.push(4242);
		std::cout << mstack.top() << std::endl;
	
		MutantStack<int>::iterator iter = mstack.begin();
		MutantStack<int>::iterator iter_end = mstack.end();
		
		++iter;
		--iter;

		while (iter != iter_end)
		{
		  std::cout << *iter << std::endl;
		  ++iter;
		}
		return 0;
}

// int	main()
// {
// 	MutantStack<int>		a;
// 	MutantStack<int>		b;
// 	MutantStack<int>		c;

// 	std::srand(std::time(0));
// 	a.push(std::rand() % 100);
// 	a.push(std::rand() % 100);
// 	std::cout << a.top() << std::endl;
// 	a.push(std::rand() % 100);
// 	a.push(std::rand() % 100);
// 	std::cout << a.top() << std::endl;
// 	a.push(std::rand() % 100);
// 	a.push(std::rand() % 100);
// 	a.push(std::rand() % 100);
// 	a.pop();
// 	a.pop();
// 	a.pop();
// 	std::cout << a.top() << std::endl;

// 	b.push(std::rand() % 100);
// 	b.push(std::rand() % 100);
// 	std::cout << b.top() << std::endl;
// 	b.push(std::rand() % 100);
// 	b.push(std::rand() % 100);
// 	std::cout << b.top() << std::endl;
// 	b.push(std::rand() % 100);
// 	b.push(std::rand() % 100);
// 	b.push(std::rand() % 100);
// 	b.pop();
// 	b.pop();
// 	b.pop();
// 	std::cout << b.top() << std::endl;

// 	c.push(std::rand() % 100);
// 	c.push(std::rand() % 100);
// 	std::cout << c.top() << std::endl;
// 	c.push(std::rand() % 100);
// 	c.push(std::rand() % 100);
// 	std::cout << c.top() << std::endl;
// 	c.push(std::rand() % 100);
// 	c.push(std::rand() % 100);
// 	c.push(std::rand() % 100);
// 	c.pop();
// 	c.pop();
// 	c.pop();
// 	std::cout << c.top() << std::endl;

// }
