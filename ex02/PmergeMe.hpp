/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:17 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/11 19:35:46 by nsouza-o         ###   ########.fr       */
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
	template <typename T> int _jacobsthalInsertion(T& main, T& pend, int jn, size_t nbrElem);

	void _jacobsthalSequence(size_t size);
	int findJacobsthalNbr(int elementCount, int jn);
	
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

template <typename T> int PmergeMe::_jacobsthalInsertion(T& main, T& pend, int jn, size_t nbrElem)
{
	// typedef typename T::iterator iterator;
	
	int jacobsthalNbr;
	
	if (jn == 0 )
		jacobsthalNbr = 0;
	else if (jn == -1)
	jacobsthalNbr = _jacobsthalNumbers[jn] - 2;
	
	T mainToSort;
	for (size_t i = nbrElem - 1; i < main.size(); )
	{
		//mainToSort.pushback(main[i]);
		i = i + nbrElem;
	}
	
	for (size_t j = 0; j < mainToSort.size(); j++)
	{
		std::cout << mainToSort[j] << std::endl;
	}
	//std::pair<iterator, iterator> pendElement;
	(void)pend;
	
}

template <typename T> void PmergeMe::_insertion(T& container, size_t nbrElem)
{
	typedef typename T::iterator iterator;

	/* division in main, pend and odd */	
	
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
	
	/* insertion */
	
	int elementCount = (pend.size() / nbrElem);
	int jn = 0;
	// for (int i = elementCount; i > 0; )
	// {
	// 	jn = findJacobsthalNbr(elementCount + 1, jn);
	// 	i = _jacobsthalInsertion(main, pend, jn);
	// }
	jn = findJacobsthalNbr(elementCount + 1, jn);
	_jacobsthalInsertion(main, pend, jn, nbrElem);
	// std::cout << "aqui" << std::endl;
	// _oddInsertion(main, odd);


	
	// std::vector<T> pendVec;
	// pendVec.push_back(pend.begin());
	// pendVec.push_back(pendVec[0] + nbrElem);
	
	
	//iterator pendBegin = pend.begin();
//	iterator pendEnd = pendBegin + nbrElem;
/* 
	int i = find
	for (i; i < _jacobsthalNumbers.size(); i++)
	{
		if (pend[(_jacobsthalNumbers[i] - 1) * nbrElem])
	}	 */

	
	// for (size_t i = 0; i < main.size(); i++)
	// 	std::cout << "main-> " << main[i] << std::endl;

	// std::cout << std::endl;

	// for (size_t i = 0; i < pend.size(); i++)
	// 	std::cout << "pend-> " << pend[i] << std::endl;

	// std::cout << std::endl;

	// for (size_t i = 0; i < odd.size(); i++)
	// 	std::cout << "odd-> " << odd[i] << std::endl;

	
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