#include "Span.hpp"
#include "Span.h"

#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <numeric>


// resize와 reserve의 기능상 차이점
Span::Span(unsigned int num)
{
	this->N_ = num;
	this->stored_.resize(num);
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::generate(this->stored_.begin(), this->stored_.end(), random_number);
	// resize exception
}

Span::~Span()
{
	// vector 종료
}

Span::Span(const Span& source)
{
	this->N_ = source.N_;
	this->stored_.resize(this->N_);
	std::copy(source.stored_.begin(), source.stored_.end(), this->stored_.begin());
	// resize exception
	// copy exception
}

Span& Span::operator=(const Span& source)
{
	this->N_ = source.N_;
	this->stored_.resize(this->N_);
	std::copy(source.stored_.begin(), source.stored_.end(), this->stored_.begin());
	// resize exception
	// copy exception
	return (*this);
}

void	Span::addNumber(unsigned int num)
{
	if (this->stored_.size() >= this->N_)
		throw std::invalid_argument("maximum size reached");
	this->stored_.push_back(num);
}

unsigned int Span::shortestSpan() const
{
	std::vector<int>					tmp(this->stored_);

	if (this->N_ <= 1)
		throw std::invalid_argument("one or no numbers stored");
	std::adjacent_difference(std::begin(tmp), std::end(tmp), std::begin(tmp));
	// tmp에서 제일 작은 것 찾기 (절대값 고려)
	return (span);
}

unsigned int Span::longestSpan() const
{
	std::vector<int>					tmp(this->stored_);

	if (this->N_ <= 1)
		throw std::invalid_argument("one or no numbers stored");
	std::adjacent_difference(std::begin(tmp), std::end(tmp), std::begin(tmp));
	// tmp에서 제일 큰 것 찾기 (절대값 고려)
	return (span);
}

int		random_number(void)
{
	return (std::rand() / 10000);
}

unsigned int	check_span(int a, int b)
{
	// int를 unsigned int로 적절하게 변환할 필요 있어보임.
	return (static_cast<unsigned int>(std::max(a, b) - std::min(a, b)));
}