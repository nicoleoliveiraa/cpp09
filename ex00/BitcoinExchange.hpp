/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:29:01 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/16 10:17:50 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _input;
	std::map<std::string, float> _dataBase;
	BitcoinExchange();
public:
	BitcoinExchange(int ac, char** av);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);
	~BitcoinExchange();

	//void inputParser(std::string input);
	void readDataBaseFile(std::string file);
	void readInputFile(std::string file);
};

#endif // BITCOINEXCHANGE_HPP