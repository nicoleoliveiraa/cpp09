/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:30:56 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/26 11:34:58 by nsouza-o         ###   ########.fr       */
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
