/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:30:56 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/19 16:03:44 by nsouza-o         ###   ########.fr       */
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
	// std::cout << "\n\n" << vec.size() << "\n\n" << std::endl;

	_rangeSize = vec.size();
	_printContainer(vec, BOLD_GREEN, "Before:");
	_jacobsthalSequence(vec.size());
	_fordJohnsonAlgorithm(vec, 1);
	if (!is_sorted(vec))
        std::cout << "Vector was not sorted properly.\n";
	if (vec.size() != _rangeSize)
        std::cout << "Vector was not properly.\n";

	_printContainer(vec, BOLD_GREEN, "After:");	

	clock_t endVec = clock();
	double elapsedVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
	
	std::cout << BOLD_RED << "Time to process" << " a range of " << _rangeSize << " elements with std::vector: " << RESET << elapsedVec << " us" << std::endl;
}

void PmergeMe::sortDeque(char **argv)
{
	std::deque<int> deq;
	
    // std::cout << "\n!!!!\n";
	clock_t startDeq = clock();
	
    // std::cout << "\n----\n";
	_populateContainer(deq, argv);

	// std::cout << "\n\n" << deq.size() << "\n\n" << std::endl;
	
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
	
	std::cout << BOLD_RED << "Time to process" << " a range of " << _rangeSize << " elements with std::deque: " << RESET << elapsedDeq << " us" << std::endl;
}
