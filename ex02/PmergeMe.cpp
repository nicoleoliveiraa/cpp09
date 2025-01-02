/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:30:56 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/01 13:45:07 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;	
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::_jacobsthalSequence(size_t size)
{
	if (!_jacobsthalNumbers.empty())
		_jacobsthalNumbers.clear();

	size_t i = 1;
	// size_t j;	
	for (size_t j = 3; j <= size; )
	{
		_jacobsthalNumbers.push_back(j);
		size_t aux = i;
		i = j;
		j = i + (aux * 2);
	}
}


void PmergeMe::_sortVector(char **argv)
{
	std::vector<int> vec;

	int i = 1;
	while (argv[i])
	{
		vec.push_back(atoi(argv[i]));
		i++;		
	}

	_jacobsthalSequence(vec.size());
	
	// for (size_t i = 0; i < _jacobsthalNumbers.size(); i++)
	// 	std::cout << _jacobsthalNumbers[i] << std::endl;
	
	_fordJohnsonAlgorithm(vec, 2);


	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "-> " << vec[i] << std::endl;
}
