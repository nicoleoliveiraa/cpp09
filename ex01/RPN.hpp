/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:12:37 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/19 13:50:08 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <math.h>
#include <stack>

class RPN {
private:
	std::stack<int> _stack;
	std::string _exp;
	RPN();

public:
	RPN(std::string expression);
	RPN(const RPN& src);
	RPN& operator=(const RPN& src);
	~RPN();

	bool parsingExpression();
	void calculate();
};

#endif // RPN_HPP