#include "MutantStack.hpp"

#include <vector>
#include <deque>
#include <list>

#include <random>

#include <iostream>

int	main()
{
	MutantStack<int, std::vector<int> >		a;
	MutantStack<int, std::deque<int> >		b;
	MutantStack<int, std::list<int> >		c;

	a.push(std::rand() % 100);
	a.push(std::rand() % 100);
	std::cout << a.top() << std::endl;
	a.push(std::rand() % 100);
	a.push(std::rand() % 100);
	std::cout << a.top() << std::endl;
	a.push(std::rand() % 100);
	a.push(std::rand() % 100);
	a.push(std::rand() % 100);
	a.pop();
	a.pop();
	a.pop();
	std::cout << a.top() << std::endl;

	b.push(std::rand() % 100);
	b.push(std::rand() % 100);
	std::cout << b.top() << std::endl;
	b.push(std::rand() % 100);
	b.push(std::rand() % 100);
	std::cout << b.top() << std::endl;
	b.push(std::rand() % 100);
	b.push(std::rand() % 100);
	b.push(std::rand() % 100);
	b.pop();
	b.pop();
	b.pop();
	std::cout << b.top() << std::endl;

	c.push(std::rand() % 100);
	c.push(std::rand() % 100);
	std::cout << c.top() << std::endl;
	c.push(std::rand() % 100);
	c.push(std::rand() % 100);
	std::cout << c.top() << std::endl;
	c.push(std::rand() % 100);
	c.push(std::rand() % 100);
	c.push(std::rand() % 100);
	c.pop();
	c.pop();
	c.pop();
	std::cout << c.top() << std::endl;

}