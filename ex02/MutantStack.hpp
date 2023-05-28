#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <stack>
#include <iterator>


// using을 주로 사용함 typedef는 모던 cpp에서는 deprecated됨. using이 c+98 가능인지 체크

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void) {return this->c.begin();}
		iterator end(void) {return this->c.end();}

		reverse_iterator rbegin(void) {return this->c.rbegin();}
		reverse_iterator rend(void) {return this->c.rend();}

		const_iterator cbegin(void) {return this->c.cbegin();}
		const_iterator cend(void) {return this->c.cend();}

		const_reverse_iterator crbegin(void) {return this->c.crbegin();}
		const_reverse_iterator crend(void) {return this->c.crend();}

	public:
		MutantStack(/* args*/)
		{
		};

		~MutantStack(){};
		MutantStack(const MutantStack& source)
		{
			std::copy(source.begin(), source.end(), this->begin());
		}

		MutantStack& operator=(const MutantStack& source)
		{
			std::copy(source.begin(), source.end(), this->begin());
			return (*this);
		}
};

#endif