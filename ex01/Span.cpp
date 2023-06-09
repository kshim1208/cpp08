#include "Span.hpp"
#include "Span.h"

#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <numeric>

#include <iostream>

Span::Span(unsigned int num)
{
	this->N_ = num;
	this->stored_.resize(num);
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::generate(this->stored_.begin(), this->stored_.end(), random_number);
}

Span::~Span()
{
	// vector 종료??
}

Span::Span(const Span& source)
{
	this->N_ = source.N_;
	this->stored_.resize(this->N_);
	std::copy(source.stored_.begin(), source.stored_.end(), this->stored_.begin());
}

Span& Span::operator=(const Span& source)
{
	this->N_ = source.N_;
	this->stored_.resize(this->N_);
	std::copy(source.stored_.begin(), source.stored_.end(), this->stored_.begin());
	return (*this);
}

// need to make addNumber add numbers without if-else or loop
void	Span::addNumber(unsigned int num)
{
	if (this->stored_.size() >= this->N_)
		throw std::invalid_argument("maximum size reached");
	this->stored_.push_back(num);
}

unsigned int Span::shortestSpan() const
{
	std::vector<unsigned int>					tmp(this->N_);

	if (this->N_ <= 1)
		throw std::invalid_argument("one or no numbers stored");
	std::adjacent_difference(this->stored_.begin(), this->stored_.end(), tmp.begin());
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), static_cast<int (*)(int)>(&std::abs));
	std::sort(tmp.begin() + 1, tmp.end());
	return (tmp[2]);
}

unsigned int Span::longestSpan() const
{
	std::vector<unsigned int>					tmp(this->N_);

	if (this->N_ <= 1)
		throw std::invalid_argument("one or no numbers stored");
	std::adjacent_difference(this->stored_.begin(), this->stored_.end(), tmp.begin());
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), static_cast<int (*)(int)>(&std::abs));
	std::sort(tmp.begin() + 1, tmp.end());
	return (tmp.back());
}

void	Span::printElements() const
{ 
	std::for_each(this->stored_.begin(), this->stored_.end(), spanPrint);
}

int		random_number(void)
{
	return (std::rand() % 10000);
}

void	spanPrint(const int	&num)
{
	std::cout << num << std::endl;
}
