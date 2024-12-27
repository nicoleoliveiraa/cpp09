/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:17 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/27 15:43:09 by nsouza-o         ###   ########.fr       */
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
	template <typename T> void _fordJohnsonAlgorithm(T& container, size_t nbrElem);
	template <typename T> void _swapPairs(T& container, size_t nbrElem);

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
		i++;
	}
	// std::cout << *firstBegin << std::endl;
	// std::cout << *firstEnd << std::endl;
	// std::cout << *secondBegin << std::endl;
	// std::cout << *secondEnd << std::endl;

}


template <typename T> void PmergeMe::_fordJohnsonAlgorithm(T& container, size_t nbrElem)
{
	//typedef typename T::iterator Iterator;
	
	if (container.size() / nbrElem < 2)
		return ;
	
	_swapPairs(container, nbrElem);
	//_fordJohnsonAlgorithm(container, nbrElem);	
	
}


#endif // PMERGEME_HPP