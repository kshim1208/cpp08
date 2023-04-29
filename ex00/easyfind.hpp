#ifndef easyfind_HPP
# define easyfind_HPP

# include <memory>
# include <algorithm>
# include <iterator>
# include <stdexcept>

template<template <typename ELEM, typename = std::allocator<ELEM> > class T>
int	easyfind(T<int>& type, int num)
{
	typename T<int>::iterator	iter = std::find(type.begin(), type.end(), num);
	if (iter == type.end())
		throw std::invalid_argument("no where. because no same value in container");
	return (std::distance(type.begin(), iter));
}


#endif
