/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:11:59 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/19 14:09:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	RPN myRPN(av[1]);
	myRPN.calculate();
}