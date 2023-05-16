#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <stack>
#include <iterator>


template<class T, class CONT>
class MutantStack
{
	public:
		typedef CONT										container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

		class Iterator : public std::iterator<
									std::input_iterator_tag,
									value_type,
									size_type,
									uintptr_t*,
									const_reference
											>{
				//
			public:
				explicit Iterator(){}
				Iterator& operator=(Iterator& rhs) {}
				Iterator& operator++(){}
				Iterator operator++(T){}
				bool operator==(Iterator& rhs) const {}
				bool operator!= (Iterator& rhs) const {}
				reference operator*() const {}
		};
		Iterator begin()
		{
			return Iterator();
		}

		Iterator end()
		{
			return Iterator( /* c의 size 이용? */);
		}

	private:
		container_type	c;

	public:
		MutantStack(/* args*/)
		{
			//container_type initialize?
		};

		~MutantStack(){};
		MutantStack(const MutantStack& source)
		{
			std::copy(source.c.begin(), source.c.end(), this->c.begin());
		}

		MutantStack& operator=(const MutantStack& source)
		{
			std::copy(source.c.begin(), source.c.end(), this->c.begin());
			return (*this);
		}

		const T&	top() const
		{
			return (c.back());
		}

		bool	empty() const
		{
			return (c.empty());
		}

		size_type	size() const
		{
			return (c.size());
		}
	
		void	push(const value_type& value)
		{
			c.push_back(value);
		}

		void	pop()
		{
			c.pop_back();
		}
};


template<class T, class CONT >
bool	operator==(const MutantStack<T, CONT>& lhs,
					const MutantStack<T, CONT>& rhs)
{
	return (lhs.c == rhs.c);
}


template<class T, class CONT >
bool	operator!=(const MutantStack<T, CONT>& lhs,
					const MutantStack<T, CONT>& rhs)
{
	return (lhs.c != rhs.c);
}


template<class T, class CONT >
bool	operator<(const MutantStack<T, CONT>& lhs,
					const MutantStack<T, CONT>& rhs)
{
	return (lhs.c < rhs.c);
}


template<class T, class CONT >
bool	operator<=(const MutantStack<T, CONT>& lhs,
					const MutantStack<T, CONT>& rhs)
{
	return (lhs.c <= rhs.c);
}


template<class T, class CONT >
bool	operator>(const MutantStack<T, CONT>& lhs,
					const MutantStack<T, CONT>& rhs)
{
	return (lhs.c > rhs.c);
}


template<class T, class CONT >
bool	operator>=(const MutantStack<T, CONT>& lhs,
					const MutantStack<T, CONT>& rhs)
{
	return (lhs.c >= rhs.c);
}

#endif