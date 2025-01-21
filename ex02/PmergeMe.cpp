/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:30:56 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/21 12:33:17 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src){*this = src;}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		_jacobsthalNumbers = src._jacobsthalNumbers;
		_rangeSize = src._rangeSize;		
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

size_t PmergeMe::getRangeSize(){return(_rangeSize);}

void PmergeMe::_jacobsthalSequence(size_t size)
{
	if (!_jacobsthalNumbers.empty())
		_jacobsthalNumbers.clear();

	size_t i = 1;
	_jacobsthalNumbers.push_back(1);
	for (size_t j = 3; j <= size; )
	{
		_jacobsthalNumbers.push_back(j);
		size_t aux = i;
		i = j;
		j = i + (aux * 2);
	}
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

void PmergeMe::sortVector(char **argv)
{
	std::vector<int> vec;

	clock_t startVec = clock();
	
	_populateContainer(vec, argv);
	_rangeSize = vec.size();
	_printContainer(vec, BOLD_GREEN, "Before:");
	_jacobsthalSequence(vec.size());
	_fordJohnsonAlgorithm(vec, 1);
	_printContainer(vec, BOLD_GREEN, "After:");	
	
	if (!is_sorted(vec))
        std::cout << "Vector was not sorted properly.\n";
	if (vec.size() != _rangeSize)
        std::cout << "Vector was not properly.\n";

	clock_t endVec = clock();
	double elapsedVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
	
	std::cout << BOLD_RED << "Time to process" << " a range of " << _rangeSize 
			<< " elements with std::vector: " << RESET << std::fixed << std::setprecision(6) 
			<< elapsedVec << " us" << std::endl;
}

void PmergeMe::sortDeque(char **argv)
{
	std::deque<int> deq;
	
	clock_t startDeq = clock();
	
	_populateContainer(deq, argv);
	_rangeSize = deq.size();
	// _printContainer(deq, BOLD_YELLOW, "Before:");
	_jacobsthalSequence(deq.size());
	_fordJohnsonAlgorithm(deq, 1);
	// _printContainer(deq, BOLD_YELLOW, "After:");
	
	if (!is_sorted(deq))
        std::cout << "Deque was not sorted properly.\n";
	if (deq.size() != _rangeSize)
        std::cout << "Deque was not properly.\n" << deq.size() << " " << _rangeSize<< std::endl;

	clock_t endDeq = clock();
	double elapsedDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;
	
	std::cout << BOLD_RED << "Time to process" << " a range of " << _rangeSize 
			<< " elements with std::deque:  " << RESET << std::fixed << std::setprecision(6) 
			<< elapsedDeq << " us" << std::endl;
}
