#ifndef easyfind_HPP
# define easyfind_HPP

# include <iterator>

class easyFindFailedNoSameValue : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("no where. because no same value in container");
		}
};

template<template <typename ELEM, typename = std::allocator<ELEM> > class T>
int	easyfind(T<int>& type, int num)
{
	int	ret = 0;

	for (typename T<int>::iterator iter = type.begin(); iter != type.end(); iter++)
	{
		if (*iter == num)
			return (ret);
		ret++;
	}
	throw easyFindFailedNoSameValue();
}


#endif
