#ifndef Span_HPP
# define Span_HPP

# include <vector>

class Span
{
	private:
		unsigned int		N_;
		std::vector<int>	stored_;
		Span(/* args*/){};

	public:
		Span(unsigned int num);
		~Span();
		Span(const Span& source);
		Span& operator=(const Span& source);

		void	addNumber(unsigned int num);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void	printElements()	const;
};

#endif