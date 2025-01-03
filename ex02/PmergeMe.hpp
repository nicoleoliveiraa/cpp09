/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:17 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/01 13:47:47 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

class PmergeMe {
private:
	std::vector<int> _jacobsthalNumbers;

	template <typename T> void _fordJohnsonAlgorithm(T& container, size_t nbrElem);
	template <typename T> void _swapPairs(T& container, size_t nbrElem);
	template <typename T> void _insertion(T& container, size_t nbrElem);
	// template <typename T> void _jacobsthalInsertion(T& main, T& pend, T& odd, size_t nbrElem);

	void _jacobsthalSequence(size_t size);
	
public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();

	void _sortVector(char **argv);
};

template <typename T> void PmergeMe::_swapPairs(T& container, size_t nbrElem)
{
	typedef typename T::iterator iterator;
	
	int nbrOfElem = container.size() / nbrElem;
	(void)nbrOfElem;
	
	iterator firstBegin = container.begin();
	iterator firstEnd = container.begin() + nbrElem - 1;

	iterator secondBegin = firstEnd + 1;
	iterator secondEnd = secondBegin + nbrElem - 1;

	size_t limit = container.size() % (nbrElem * 2);
	limit = container.size() - limit;
	
	size_t i = 0;
	while (i < limit)
	{
		if (*firstEnd > *secondEnd)
		{
			for (iterator it = firstBegin; it <= firstEnd; it++)
			{
				std::iter_swap(it, secondBegin);
				secondBegin++;
			}
		}
		firstBegin = secondEnd + 1;
		firstEnd = firstBegin + nbrElem - 1;
		secondBegin = firstEnd + 1;
		secondEnd = secondBegin + nbrElem - 1;
		i = i + (nbrElem * 2);
	}

}

/* template <typename T> void PmergeMe::_jacobsthalInsertion(T& main, T& pend, T& odd, size_t nbrElem)
{
	typedef typename T::iterator iterator;
	
	
} */

template <typename T> void PmergeMe::_insertion(T& container, size_t nbrElem)
{
	typedef typename T::iterator iterator;

	T main;
	T pend;
	T odd;
	
	iterator firstBegin = container.begin();
	iterator firstEnd = container.begin() + nbrElem;

	iterator secondBegin = firstEnd;
	iterator secondEnd = secondBegin + nbrElem;

	main.insert(main.end(), firstBegin, firstEnd);
	main.insert(main.end(), secondBegin, secondEnd);

	size_t remainingElements = container.size() - (nbrElem * 2);
	
	while (remainingElements >= nbrElem * 2)
	{
		firstBegin = secondEnd;
		firstEnd = firstBegin + nbrElem;
		
		secondBegin = firstEnd;
		secondEnd = secondBegin + nbrElem;
		
		pend.insert(pend.end(), firstBegin, firstEnd);
		main.insert(main.end(), secondBegin, secondEnd);
		
		remainingElements -= nbrElem * 2;
	}

	if (secondEnd != container.end())
		odd.insert(odd.end(), secondEnd, container.end());
	
	iterator pendBegin = pend.begin();
	iterator pendEnd = pendBegin + nbrElem;

	
	for (size_t i = 0; i < _jacobsthalNumbers.size(); i++)
	{
		if (pend[(_jacobsthalNumbers[i] - 1) * nbrElem])
	}	

	
	std::cout << *secondEnd << std::endl;

	
	for (size_t i = 0; i < main.size(); i++)
		std::cout << "main-> " << main[i] << std::endl;

	std::cout << std::endl;

	for (size_t i = 0; i < pend.size(); i++)
		std::cout << "pend-> " << pend[i] << std::endl;

	std::cout << std::endl;

	for (size_t i = 0; i < odd.size(); i++)
		std::cout << "odd-> " << odd[i] << std::endl;

	
}


template <typename T> void PmergeMe::_fordJohnsonAlgorithm(T& container, size_t nbrElem)
{
	//typedef typename T::iterator Iterator;
	
	// if (container.size() / nbrElem < 2)
		// return ;
	// 
	// _swapPairs(container, nbrElem);
	// _fordJohnsonAlgorithm(container, nbrElem * 2);
	
	_insertion(container, nbrElem);
	// for (size_t i = 0; i < container.size(); i++)
	// 	std::cout << "-> " << container[i] << std::endl;
	// std::cout << nbrElem << std::endl;
}


#endif // PMERGEME_HPP