#include <regex>
#include <iostream>
#include <cmath>

#ifndef SUBTRACTING_HPP
#define SUBTRACTING_HPP

std::string subInt(std::string contents) {
	std::regex rgx("(\\-?\\d+) *\\- *(\\-?\\d+)");
	std::smatch match;
	std::string ret = contents;

	if (std::regex_search(contents, match, rgx)) {
		int num1 = std::stoi((std::string)match[1]);
		int num2 = std::stoi((std::string)match[2]);
		ret = std::to_string(num1-num2);
	}
	return ret;
}


std::string subDecimal(std::string contents) {
	std::regex rgx("(\\-?\\d+)(?:\\.(\\d+))? *\\- *(\\-?\\d+)(?:\\.(\\d+))?");
	std::smatch match;
	std::string ret = contents;

	if (std::regex_search(contents, match, rgx)) {
		std::string int1 = match[1];
		std::string decimal1 = match[2];
		std::string int2 = match[3];
		std::string decimal2 = match[4];

		int dec1Length = decimal1.length();
		int dec2Length = decimal2.length();
		if (dec1Length > dec2Length) {
			decimal2 += std::string(dec1Length - dec2Length, '0');
		} else {
			decimal1 += std::string(dec2Length - dec1Length, '0');
		}
		int dec1 = std::stoi((std::string)decimal1);
		int dec2 = std::stoi((std::string)decimal2);

		int powResult = std::pow(10, decimal1.length());

		int decDiff = (dec1 - dec2) + powResult % powResult;
		int carry = std::floor((dec1 - dec2) / powResult);

		int num1 = std::stoi(int1);
		int num2 = std::stoi(int2);
		int intResult = num1 - num2 - carry;
		
		std::string neg = "";
		if (decDiff < 0) {
			decDiff = -decDiff;
			if (intResult > 0) neg = "-";
		}
		ret = neg+std::to_string(intResult)+'.'+std::to_string(decDiff);
	}
	return ret;
}

#endif