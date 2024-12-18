/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:39:04 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/12/18 19:16:24 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(int ac, char** av)
{
	if (ac != 2)
		throw std::runtime_error("BTC has to take a parameters with the input file.");
	readDataBaseFile("data.csv");
	openInputFile(av[1]);
	readAndCalculate();
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
}

void BitcoinExchange::openInputFile(std::string file)
{
	_inFile.open(file.c_str(), std::ios::out);
	if (!_inFile.good())
		throw std::runtime_error("Can't open Input file.");
}



void BitcoinExchange::readAndCalculate()
{
	std::string line;
	while (getline(_inFile, line))
	{
		if (line.empty() || line.find_first_not_of(' ') == std::string::npos ||\
			line.find_first_not_of('	') == std::string::npos)
			continue ;
		if (!line.compare("date | value"))
			continue ;
		size_t pos = validateSyntax(line);
		if (!pos)
		{
			std::cout << "Error: bad input => " + line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		if (!validateDate(date))
		{
			std::cout << "Error: bad input => " + line << std::endl;
			continue ;	
		}
		std::string nbr = line.substr(pos + 3, line.size() - 1);
		double nbrFloat = atof(nbr.c_str());
		calculate(date, nbrFloat);
	}
}

size_t BitcoinExchange::validateSyntax(std::string& line)
{
	size_t pos = line.find(" ");
	if (pos == std::string::npos)
		return (std::string::npos);
	if (line[pos + 1] != '|' || line[pos + 2] != ' ')
		return (std::string::npos);
	return pos;
}

bool BitcoinExchange::validateDate(std::string date)
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	int year = atoi(date.substr(0, 4).c_str());

	if (year < 0 || year > 2024)
		return (false);

	int month = atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return (false);

	int day = atoi(date.substr(8, 2).c_str());
	bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    int daysInMonth[] = {31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day < 1 || day > daysInMonth[month - 1])
        return (false);

	return (true);
}

void BitcoinExchange::calculate(std::string date, double nbr)
{
	if (nbr < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	if (nbr > 2147483647)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	float res = 0;
	std::map<std::string, float>::const_iterator it = _dataBase.find(date);
	if(it != _dataBase.end())
		res = it->second * nbr;	
	else
	{
		it = _dataBase.lower_bound(date);
		it--;
		res = it->second * nbr;	
	}
	std::cout << date << " => " << nbr << " => " << res << std::endl;
}
