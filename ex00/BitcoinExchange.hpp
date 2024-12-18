/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:29:01 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/18 18:48:16 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <exception>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
	std::ifstream _inFile;
	std::map<std::string, float> _dataBase;
	//std::map<std::string, float> _result;
	BitcoinExchange();
public:
	BitcoinExchange(int ac, char** av);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);
	~BitcoinExchange();

	//void inputParser(std::string input);
	void readDataBaseFile(std::string file);
	void openInputFile(std::string file);
	void readAndCalculate();
	size_t validateSyntax(std::string& line);
	bool validateDate(std::string date);
	void calculate(std::string date, double nbr);
};

#endif // BITCOINEXCHANGE_HPP