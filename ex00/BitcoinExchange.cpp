/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:39:04 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/17 16:33:51 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(int ac, char** av)
{
	if (ac != 2)
		throw std::runtime_error("BTC has to take a parameters with the input file.");
	readDataBaseFile("data.csv");
	(void)av;
	//openInputFile(av[1]);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		_dataBase = src._dataBase;
		// _input = src._input;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::readDataBaseFile(std::string file)
{
	std::ifstream inFile;
	inFile.open(file.c_str(), std::ios::out);
	if (!inFile.good())
		throw std::runtime_error("Can't open Database file.");
	
	std::string line;
	getline(inFile, line);
	while (getline(inFile, line))
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			if (line[i] == ',')
				_dataBase[line.substr(0, i)] = atof(line.substr(i + 1, line.size()).c_str());
		}
	}
	// std::cout << std::fixed << std::setprecision(2);
	// std::cout << _dataBase["2021-01-20"] << std::endl;
}

void BitcoinExchange::openInputFile(std::string file)
{
	std::ifstream inFile;
	inFile.open(file.c_str(), std::ios::out);
	if (!inFile.good())
		throw std::runtime_error("Can't open Input file.");
	
	std::string line;
	while (getline(inFile, line))
	{
		if (!line.compare("date | value"))
			continue;
		
	}
}
