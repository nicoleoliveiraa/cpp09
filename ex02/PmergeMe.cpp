/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:30:56 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/11 17:19:26 by nsouza-o         ###   ########.fr       */
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
	_jacobsthalNumbers.push_back(1);
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
	// {
	// 	std::cout << _jacobsthalNumbers[i] << std::endl;
	// }
	// std::cout << "---" << std::endl;
	// std::cout << findJacobsthalNbr(vec.size(), 0) << " - " << _jacobsthalNumbers[findJacobsthalNbr(vec.size(), 0)] << std::endl;
	// std::cout << findJacobsthalNbr(vec.size(), 1) << " - " << _jacobsthalNumbers[findJacobsthalNbr(vec.size(), 1)] << std::endl;
	// std::cout << findJacobsthalNbr(vec.size(), 2) << " - " << _jacobsthalNumbers[findJacobsthalNbr(vec.size(), 2)] << std::endl;
	// std::cout << findJacobsthalNbr(vec.size(), 3) << " - " << _jacobsthalNumbers[findJacobsthalNbr(vec.size(), 3)] << std::endl;
	
	// for (size_t i = 0; i < _jacobsthalNumbers.size(); i++)
	// 	std::cout << _jacobsthalNumbers[i] << std::endl;
	
	_fordJohnsonAlgorithm(vec, 1);


	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "-> " << vec[i] << std::endl;
}


int PmergeMe::findJacobsthalNbr(int elementCount, int jn)
{
	if (elementCount < 3)
		return (0);
	if (jn == -1)
		return (-1);
	if (jn + 1 < static_cast<int>(_jacobsthalNumbers.size()) && _jacobsthalNumbers[jn + 1] <= elementCount)
		return (jn + 1);
	return (-1);
}