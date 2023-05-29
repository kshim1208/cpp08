#include "Span.hpp"

#include <iostream>

int main()
{
	try
	{
		Span	a(10);

		a.printElements();
		std::cout << std::endl;

		std::cout << "a - shortestSpan : " << a.shortestSpan() << std::endl;
		std::cout << "a - longestSpan : " <<  a.longestSpan() << std::endl;

		std::cout << "------------------" << std::endl;

		Span	b(20);

		b.printElements();
		std::cout << std::endl;

		std::cout << "b - shortestSpan : " << b.shortestSpan() << std::endl;
		std::cout << "b - longestSpan : " <<  b.longestSpan() << std::endl;

		std::cout << "------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}