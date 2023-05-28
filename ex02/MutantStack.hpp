#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <stack>
#include <iterator>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		class iterator : public std::iterator< 				// 상속 받거나 직접 typedef - iterator의 상속에 관한 설명
							std::input_iterator_tag,		// iterator_category ??
							T,								// value_type - 변수 타입
							T,								// difference_type - iterator간 차이 크기 (왠만하면 변수 크기?)
							const T*,						// pointer - iterator가 가리키는 곳의 포인터
							T								// reference - iterator가 가리키는 곳의 참조
			>
		{
			private:
				std::stack<T>	*it_;
				std::stack<T>	*end_;

			public:
				// stack이 만들어질 때 iterator도 자동 생성 필요?
					// 호출할 때 생성하여 값 담아 반환?
				explicit iterator()	// explicit -> 암시적 변환 및 복사 생성 금지
				{
					this->it_ = c.begin();
					this->end_ = c.end();
				}
				iterator& operator=(iterator& rhs)
				{
					this->it_ = rhs->it_;
					this->end_ = rhs->end_;
				}

				iterator& operator++()
				{
					++this->it_;
					return (*this);
				}

				iterator operator++(T)
				{
					iterator	tmp = *this;
					++(*this);
					return (tmp);
				}

				bool operator==(iterator& rhs) const
				{
					return (this->it_ == rhs->it_);
				}

				bool operator!= (iterator& rhs) const
				{
					return (this->it_ != rhs->it_);
				}

				reference operator*() const
				{
					return (*this->it_);
				}
		};

		iterator begin()
		{
			return iterator();
		}

		iterator end()
		{
			return iterator();
		} 

	private:
		std::stack<T>	c;

	public:
		// stack 생성될 때 iterator 생성하는 법?
		MutantStack(/* args*/)
		{
			//stack initialize?
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


template<class T>
bool	operator==(const MutantStack<T>& lhs,
					const MutantStack<T>& rhs)
{
	return (lhs.c == rhs.c);
}


template<class T>
bool	operator!=(const MutantStack<T>& lhs,
					const MutantStack<T>& rhs)
{
	return (lhs.c != rhs.c);
}


template<class T>
bool	operator<(const MutantStack<T>& lhs,
					const MutantStack<T>& rhs)
{
	return (lhs.c < rhs.c);
}


template<class T>
bool	operator<=(const MutantStack<T>& lhs,
					const MutantStack<T>& rhs)
{
	return (lhs.c <= rhs.c);
}


template<class T>
bool	operator>(const MutantStack<T>& lhs,
					const MutantStack<T>& rhs)
{
	return (lhs.c > rhs.c);
}


template<class T>
bool	operator>=(const MutantStack<T>& lhs,
					const MutantStack<T>& rhs)
{
	return (lhs.c >= rhs.c);
}

// template<class T, class CONT>
// class MutantStack
// {
// 	public:
// 		typedef CONT										container_type;
// 		typedef typename container_type::value_type			value_type;
// 		typedef typename container_type::size_type			size_type;
// 		typedef typename container_type::reference			reference;
// 		typedef typename container_type::const_reference	const_reference;

// 		class iterator : public std::iterator<
// 									std::input_iterator_tag,
// 									value_type,
// 									size_type,
// 									uintptr_t*,
// 									const_reference
// 											>{
// 			// 위치 저장
// 				// contaioner_type 따라 다를 것 -> 해당 container의 iteratior를 다시 사용하나?
// 			public:
// 				explicit iterator(){}
// 				iterator& operator=(iterator& rhs) {}
// 				iterator& operator++(){}
// 				iterator operator++(T){}
// 				bool operator==(iterator& rhs) const {}
// 				bool operator!= (iterator& rhs) const {}
// 				reference operator*() const {}
// 		};
// 		iterator begin()
// 		{
// 			return iterator();
// 		}

// 		iterator end()
// 		{
// 			return iterator( /* c의 size 이용? */);
// 		}

// 	private:
// 		container_type	c;

// 	public:
// 		MutantStack(/* args*/)
// 		{
// 			//container_type initialize?
// 		};

// 		~MutantStack(){};
// 		MutantStack(const MutantStack& source)
// 		{
// 			std::copy(source.c.begin(), source.c.end(), this->c.begin());
// 		}

// 		MutantStack& operator=(const MutantStack& source)
// 		{
// 			std::copy(source.c.begin(), source.c.end(), this->c.begin());
// 			return (*this);
// 		}

// 		const T&	top() const
// 		{
// 			return (c.back());
// 		}

// 		bool	empty() const
// 		{
// 			return (c.empty());
// 		}

// 		size_type	size() const
// 		{
// 			return (c.size());
// 		}
	
// 		void	push(const value_type& value)
// 		{
// 			c.push_back(value);
// 		}

// 		void	pop()
// 		{
// 			c.pop_back();
// 		}
// };


// template<class T, class CONT >
// bool	operator==(const MutantStack<T, CONT>& lhs,
// 					const MutantStack<T, CONT>& rhs)
// {
// 	return (lhs.c == rhs.c);
// }


// template<class T, class CONT >
// bool	operator!=(const MutantStack<T, CONT>& lhs,
// 					const MutantStack<T, CONT>& rhs)
// {
// 	return (lhs.c != rhs.c);
// }


// template<class T, class CONT >
// bool	operator<(const MutantStack<T, CONT>& lhs,
// 					const MutantStack<T, CONT>& rhs)
// {
// 	return (lhs.c < rhs.c);
// }


// template<class T, class CONT >
// bool	operator<=(const MutantStack<T, CONT>& lhs,
// 					const MutantStack<T, CONT>& rhs)
// {
// 	return (lhs.c <= rhs.c);
// }


// template<class T, class CONT >
// bool	operator>(const MutantStack<T, CONT>& lhs,
// 					const MutantStack<T, CONT>& rhs)
// {
// 	return (lhs.c > rhs.c);
// }


// template<class T, class CONT >
// bool	operator>=(const MutantStack<T, CONT>& lhs,
// 					const MutantStack<T, CONT>& rhs)
// {
// 	return (lhs.c >= rhs.c);
// }

#endif