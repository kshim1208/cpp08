#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <stack>
#include <iterator>

#include <deque>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void)
		{
			return (this->c.begin());
		}
		iterator end(void)
		{
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin(void)
		{
			return (this->c.cbegin());
		}
		const_iterator cend(void)
		{
			return (this->c.cend());
		}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin(void)
		{
			return (this->c.crbegin());
		}
		const_reverse_iterator crend(void)
		{
			return (this->c.crend());
		}


	public:
		MutantStack(/* args*/)
		{};

		~MutantStack()
		{};
		
		MutantStack(const MutantStack& source)
		{
			this->c.resize(source.c.size());
			std::copy(source.c.begin(), source.c.end(), this->c.begin());
		}

		MutantStack& operator=(const MutantStack& source)
		{
			this->c.resize(source.c.size());
			std::copy(source.c.begin(), source.c.end(), this->c.begin());
			return (*this);
		}
};

#endif