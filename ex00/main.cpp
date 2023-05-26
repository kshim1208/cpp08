#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>
#include <random>

#include <iostream>


int main()
{
	std::vector<int>	vector_a;
	std::deque<int>		deque_a;
	std::list<int>		list_a;
	
	int					target = 10;

	try
	{
		for (int iter = 0; iter < 100; iter++)
		{
			vector_a.push_back(std::rand() % 20);
			deque_a.push_back(std::rand() % 20);
			list_a.push_back(std::rand() % 20);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << target << " occured at - " << easyfind<std::vector>(vector_a, target) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << target << " occured at - " << easyfind<std::deque>(deque_a, target) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << target << " occured at - " << easyfind<std::list>(list_a, target) << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}