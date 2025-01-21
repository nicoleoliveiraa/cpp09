/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:42:19 by nsouza-o          #+#    #+#             */
/*   Updated: 2025/01/21 12:31:15 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void validate_arg(std::string arg)
{
    if (arg[0] == '-')
		throw std::runtime_error("Negative numbers are not allowed");
    long nbr = strtol(arg.c_str(), NULL, 10);
    if (nbr == 0 && arg != "0")
		throw std::runtime_error("Non-number arguments not allowed");
    if (nbr > INT_MAX || errno == ERANGE)
		throw std::runtime_error("Too big arguments are not allowed");
}

static void validate(int argc, char** argv)
{
    if (argc == 1)
		throw std::runtime_error("No arguments were provided");
    for (int i = 1; i < argc; i++)
        validate_arg(argv[i]);
}

int main(int argc, char** argv)
{
	try
	{
		validate(argc, argv);
		PmergeMe pmergeme;

		pmergeme.sortVector(argv);
		pmergeme.sortDeque(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "[ERROR]: " << RESET << e.what() << std::endl;
	}
	
	return (0);
}