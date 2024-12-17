/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:26:07 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/17 17:46:10 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	try
	{
		BitcoinExchange mybtc(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[1m\033[33m[ERROR]: \033[0m" << e.what() << std::endl;
	}
}