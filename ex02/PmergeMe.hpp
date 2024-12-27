/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:17 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/27 11:59:12 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
private:
	template <typename T> void _fordJohnsonAlgorithm(T& container, size_t nbrElem);
	template <typename T> void _swapPairs(T& container, size_t nbrElem);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();

};

template <typename T> void PmergeMe::_swapPairs(T& container, size_t nbrElem)
{
	typedef typename T::iterator Iterator;
	
	int nbrOfElem = container.size() / nbrElem;
	
}


template <typename T> void PmergeMe::_fordJohnsonAlgorithm(T& container, size_t nbrElem)
{
	typedef typename T::iterator Iterator;
	
	if (container.size() / nbrElem < 2)
		return ;
	
	_swapPairs(container, nbrElem);
	_fordJohnsonAlgorithm(container, nbrElem);	
	
}


#endif // PMERGEME_HPP