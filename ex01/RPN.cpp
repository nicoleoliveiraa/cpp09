/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:15:55 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/19 15:13:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string expression) : _exp(expression) {}

RPN::RPN(const RPN& src)
{
	this->_exp = src._exp;
	this->_stack = src._stack;
}

RPN& RPN::operator=(const RPN& src)
{
	if (this != &src)
	{
		this->_exp = src._exp;
		this->_stack = src._stack;
	}
	return (*this);
}

RPN::~RPN(){}

bool RPN::parsingExpression()
{
	for (size_t i = 0; i < _exp.size(); i++)
	{
		bool ok = (_exp[i] >= '0' && _exp[i] <= '9') || (_exp[i] == '+' || \
		_exp[i] == '-' || _exp[i] == '*' || _exp[i] == '/' || _exp[i] == ' ') ? true : false;
		if (!ok)
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}
	return (true);
}

void RPN::calculate()
{
	int res = 0;
	
	if (!this->parsingExpression())
		return ;
	
	for (size_t i = 0; i < _exp.size(); i++)
	{
		if (_exp[i] >= '0' && _exp[i] <= '9')
			_stack.push(_exp[i] - '0');
		
		if (_exp[i] == '+' || _exp[i] == '-' || _exp[i] == '*' || _exp[i] == '/')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			int second = _stack.top();
			_stack.pop();
			int first = _stack.top();
			_stack.pop();
			res = (_exp[i] == '+') ? first + second : 
				(_exp[i] == '-') ? first - second :
				(_exp[i] == '*') ? first * second :
				first / second;
			_stack.push(res);
		}
	}
	
	if(_stack.size() == 1)
		std::cout << res << std::endl;
	else
		std::cerr << "Error" << std::endl;
}

