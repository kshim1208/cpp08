#ifndef Span_HPP
# define Span_HPP

class Span
{
	private:
		unsigned int	N;
		Span(/* args*/);
	public:
		Span(unsigned int num);
		~Span();
		Span(const Span& source);
		Span& operator=(const Span& source);

		void	addNumber(unsigned int num);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif