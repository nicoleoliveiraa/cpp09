/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:30:56 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/27 15:43:41 by nsouza-o         ###   ########.fr       */
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

void PmergeMe::_sortVector(char **argv)
{
	std::vector<int> vec;

	int i = 1;
	while (argv[i])
	{
		vec.push_back(atoi(argv[i]));
		i++;		
	}

	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i] << std::endl;
	
	_fordJohnsonAlgorithm(vec, 1);

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "a" << vec[i] << std::endl;
}
