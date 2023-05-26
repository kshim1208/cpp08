#include "Span.hpp"
#include "Span.h"

#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <numeric>

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

// iterator에 증감 연산하는게 올바른 동작인가?
	// 적절한 algorithm이 안보여서 이렇게 만들었는데, 혹시 다른 방법이 있을까?
	// iterator는 증가연산을 구현한다. 따라서 증가 연산을 해도 내부에서 구현된 동작이 수행될 것으로 보인다.
	// !!! 단, 감소 연산은 그렇지 않은 것 같다
		// reverse iterator 사용하기
unsigned int Span::shortestSpan() const
{
	std::vector<int>::const_iterator	start = this->stored_.begin();
	std::vector<int>::const_iterator 	end = this->stored_.end();
	std::vector<int>					tmp(5);

	if (this->N_ <= 1)
		throw std::invalid_argument("one or no numbers stored");
	std::adjacent_difference(start, end, tmp);
	// tmp에서 제일 작은 것 찾기
	return (span);
}

unsigned int Span::longestSpan() const
{
	std::vector<int>::const_iterator	start = this->stored_.begin();
	std::vector<int>::const_iterator 	end = this->stored_.end();
	std::vector<int>					tmp(5);

	if (this->N_ <= 1)
		throw std::invalid_argument("one or no numbers stored");
	std::adjacent_difference(start, end, tmp);
	// tmp에서 제일 작은 것 찾기
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