/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:17 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/21 12:30:59 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <iomanip>
#include <climits>
#include <cerrno>


#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#define BOLD_BLACK       "\033[1m\033[30m"
#define BOLD_RED         "\033[1m\033[31m"
#define BOLD_GREEN       "\033[1m\033[32m"
#define BOLD_YELLOW      "\033[1m\033[33m"
#define BOLD_BLUE        "\033[1m\033[34m"
#define BOLD_MAGENTA     "\033[1m\033[35m"
#define BOLD_CYAN        "\033[1m\033[36m"
#define BOLD_WHITE       "\033[1m\033[37m"

class PmergeMe {
private:
	std::vector<int> _jacobsthalNumbers;
	size_t _rangeSize;

	template <typename T> void _printContainer(const T& container, const std::string& color, const std::string& str);
	template <typename T> void _populateContainer(T& container, char **argv);
	template <typename T> void _fordJohnsonAlgorithm(T& container, size_t nbrElem);
	template <typename T> void _swapPairs(T& container, size_t nbrElem);
	template <typename T> void _insertion(T& container, size_t nbrElem);
	template <typename T> int _pendInsertion(T& main, T& pend, int jn, size_t nbrElem, int inserted);
	template <typename T> void _oddInsertion(T& main, T& odd, size_t nbrElem);
	template <typename T> int _binarySearch(T&mainToSearch, int nbr, int jacobsthalNbr);
	template <typename T> static bool is_sorted(const T& container);

	void _jacobsthalSequence(size_t size);
	int findJacobsthalNbr(int elementCount, int jn);
	
public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();
	size_t getRangeSize();
	
	void sortVector(char **argv);
	void sortDeque(char **argv);
};

template <typename T> void PmergeMe::_printContainer(const T& container, const std::string& color, const std::string& str)
{
    std::cout << color << str + " " << RESET;
    for (size_t i = 0; i < container.size(); i++)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T> void PmergeMe::_populateContainer(T& container, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        container.push_back(atoi(argv[i]));
        i++;
    }
}

template <typename T> T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T> bool PmergeMe::is_sorted(const T& container)
{
    if (container.size() == 0 || container.size() == 1)
        return true;
    typename T::const_iterator end = container.end();
    std::advance(end, -1);
    for (typename T::const_iterator it = container.begin(); it != end; it++)
    {
        typename T::const_iterator next = it;
        std::advance(next, 1);
        if (*it > *next)
            return false;
    }
    return true;
}

template <typename T> void PmergeMe::_swapPairs(T& container, size_t nbrElem)
{
	typedef typename T::iterator iterator;
	
    iterator firstBegin = container.begin();
    iterator firstEnd = next(firstBegin, nbrElem - 1);

    iterator secondBegin = next(firstEnd, 1);
    iterator secondEnd = next(secondBegin, nbrElem - 1);

	/* exclude odd elements */
    size_t limit = container.size() % (nbrElem * 2);
    limit = container.size() - limit;

    size_t i = 0;
	
    while (i < limit)
    {
        if (*firstEnd > *secondEnd)
        {
            iterator it1 = firstBegin;
            iterator it2 = secondBegin;
            while (it1 != next(firstEnd, 1))
            {
                std::iter_swap(it1, it2);
                ++it1;
                ++it2;
            }
        }

        firstBegin = next(secondEnd, 1);
        firstEnd = next(firstBegin, nbrElem - 1);

		if (firstEnd > container.end())
        	firstEnd = container.end();
		
        secondBegin = next(firstEnd, 1);
		
		if (secondBegin > container.end())
        	break ;
        secondEnd = next(secondBegin, nbrElem - 1);

        i += (nbrElem * 2);
    }
}

template <typename T> int PmergeMe::_binarySearch(T& mainToSearch, int nbr, int jacobsthalNbr)
{
	typedef typename T::iterator iterator;

	int left = 0;
	int right = jacobsthalNbr - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2; 

		if (mainToSearch[mid] == nbr)
		{
			left = mid;
			break ;
		}
		mainToSearch[mid] < nbr ? left = mid + 1 : right = mid - 1;  
	}
		
	iterator toInsert = next(mainToSearch.begin(), left);
	mainToSearch.insert(toInsert, nbr);

	return (left);
}

template <typename T> int PmergeMe::_pendInsertion(T& main, T& pend, int jn, size_t nbrElem, int inserted)
{
	typedef typename T::iterator iterator;
	static int lastJacobsthal = 1;
	
	/* get jacobsthal nbr */

	int jacobsthalNbr;	
	jn == 0 ? jacobsthalNbr = 0 : jn == -1 ? jacobsthalNbr = lastJacobsthal - 1 : jacobsthalNbr = _jacobsthalNumbers[jn];
	if (jn != 0 && jn != -1)
		lastJacobsthal = _jacobsthalNumbers[jn - 1];
	
	/* make the mainToSearch with only with the targets */

	T mainToSearch;
	for (iterator it = next(main.begin(), nbrElem - 1); it != main.end(); ) 
	{
    	mainToSearch.insert(mainToSearch.end(), *it);
	
    	iterator nextIt = next(it, nbrElem);
    	if (nextIt <= main.end())
    	    it = nextIt;
    	else
    	    break;
	}
	
	/* insert pendElement into main... */
	int inThisTime = 0;

	/* ...when there aren't enough elements to use the Jacobsthal sequence */
	if (jn == 0 || jn == -1)
	{
	    int pendSize = static_cast<int>(pend.size());
	    while (jacobsthalNbr < pendSize / static_cast<int>(nbrElem))
	    {
	        iterator pendElemBegin = next(pend.begin(), jacobsthalNbr * nbrElem);
	        iterator pendElemEnd = next(pendElemBegin, nbrElem - 1);
	
	        int i = _binarySearch(mainToSearch, *pendElemEnd, mainToSearch.size());
	
			/* insertion */
	        iterator toInsert = next(main.begin(), i * nbrElem);
	        main.insert(toInsert, pendElemBegin, next(pendElemEnd, 1));
	
	        jacobsthalNbr++;
	        inserted++;
	        inThisTime++;
	    }
	    return (inserted);
	}

	/* ...using Jacobsthal sequence */
	while (jacobsthalNbr > lastJacobsthal)
	{
	    int index = jacobsthalNbr - 2;
	    iterator pendElemBegin = next(pend.begin(), index * nbrElem);
	    iterator pendElemEnd = next(pendElemBegin, nbrElem);
	
	    if (pendElemEnd > pend.end())
		{
	        pendElemEnd = pend.end();
		}
	
		iterator lastElem = pendElemEnd;
    	--lastElem;
	
	    int i = _binarySearch(mainToSearch, *lastElem, jacobsthalNbr + inserted);
	
	    /* insertion */
	    iterator toInsert = next(main.begin(), i * nbrElem);
	    main.insert(toInsert, pendElemBegin, pendElemEnd);
	
	    jacobsthalNbr--;
	    inserted++;
	    inThisTime++;
	}


	lastJacobsthal = _jacobsthalNumbers[jn];
	return (inserted);
}

template <typename T> void PmergeMe::_oddInsertion(T& main, T& odd, size_t nbrElem)
{
	typedef typename T::iterator iterator;

	if (odd.size() == 0)
		return ;
		
	T mainToSearch;
	for (iterator it = next(main.begin(), nbrElem - 1); it != main.end(); it = next(it, nbrElem))
	{
    	if (it != main.end())
    	    mainToSearch.insert(mainToSearch.end(), *it);
    
    	if (next(it, nbrElem) > main.end())
    	    break;
	}

	for (iterator it = odd.begin(); it != odd.end(); )
	{
		iterator oddBegin = it;
		iterator oddEnd = next(it, nbrElem - 1);
	
		/* when there are enough numbers to consider an element */
		if (oddEnd < odd.end())
		{			
			int index = _binarySearch(mainToSearch, *oddEnd, mainToSearch.size());
			
			iterator toInsert = next(main.begin(), index * nbrElem);
			main.insert(toInsert, oddBegin, next(oddEnd, 1));
			
			it = next(oddEnd, 1);
		}
		else /* if there aren't, only insert at end */
		{
			it = odd.end();
			main.insert(main.end(), oddBegin, it);
		}
	}
	
}


template <typename T> void PmergeMe::_insertion(T& container, size_t nbrElem)
{
	typedef typename T::iterator iterator;

	/* division in main, pend and odd */
		
	T main;
	T pend;
	T odd;
	
	iterator firstBegin = container.begin();
	iterator firstEnd = next(container.begin(), nbrElem);
	
	iterator secondBegin = firstEnd;
	iterator secondEnd = next(secondBegin, nbrElem);

	main.insert(main.end(), firstBegin, firstEnd);
	main.insert(main.end(), secondBegin, secondEnd);

	size_t remainingElements = container.size() - (nbrElem * 2);
	
	while (remainingElements >= nbrElem * 2)
	{
		firstBegin = secondEnd;
		firstEnd = next(firstBegin, nbrElem);
		
		secondBegin = firstEnd;
		secondEnd = next(secondBegin, nbrElem);
		
		pend.insert(pend.end(), firstBegin, firstEnd);
		main.insert(main.end(), secondBegin, secondEnd);
		
		remainingElements -= nbrElem * 2;
	}

	if (secondEnd != container.end())
		odd.insert(odd.end(), secondEnd, container.end());
	
	/* pend insertion */
	
	int elementCount = (pend.size() / nbrElem);
	int jn = 0;
	int inserted = 0;
	while (inserted < elementCount)
	{
		jn = findJacobsthalNbr(elementCount + 1, jn); /* plus one because b1 is already in main */
		inserted = _pendInsertion(main, pend, jn, nbrElem, inserted);
	}

	/* odd insertion */
	
	_oddInsertion(main, odd, nbrElem);

	/* main become container */
	container.clear();
	container = main;
}

template <typename T> void PmergeMe::_fordJohnsonAlgorithm(T& container, size_t nbrElem)
{
	if (container.size() / nbrElem < 2)
		return ;
	
	_swapPairs(container, nbrElem);
	_fordJohnsonAlgorithm(container, nbrElem * 2); /* recursion */
	_insertion(container, nbrElem);
}

#endif // PMERGEME_HPP