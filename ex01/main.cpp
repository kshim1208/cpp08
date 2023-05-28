#include "Span.hpp"

#include <iostream>

int main()
{
	try
	{
		Span	a(10);

		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;

		Span	b(20);

		std::cout << b.shortestSpan() << std::endl;
		std::cout << b.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}