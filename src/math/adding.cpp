#include "adding.hpp"

std::string addString(std::string contents) {
	std::regex rgx("\"?([^\"]*)\"? *\\+ *\"?([^\"]*)\"?");
	std::smatch match;
	std::string ret = contents;

	if (std::regex_search(contents, match, rgx)) {
		ret = "\""+(std::string)match[1] + (std::string)match[2]+"\"";
	}
	return ret;
}

std::string addInt(std::string contents) {
	std::regex rgx("(\\-?\\d+) *\\+ *(\\-?\\d+)");
	std::smatch match;
	std::string ret = contents;

	if (std::regex_search(contents, match, rgx)) {
		int num1 = std::stoi((std::string)match[1]);
		int num2 = std::stoi((std::string)match[2]);
		ret = std::to_string(num1+num2);
	}
	return ret;
}

std::string addDecimal(std::string contents) {
	std::regex rgx("(\\-?\\d+)(?:\\.(\\d+))? *\\+ *(\\-?\\d+)(?:\\.(\\d+))?");
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
		int decSum = (dec1 + dec2) % (int)std::pow(10, decimal1.length());
		int carry = std::floor((dec1 + dec2) / std::pow(10, decimal1.length()));

		int num1 = std::stod(int1);
		int num2 = std::stod(int2);
		ret = std::to_string(num1+num2+carry)+'.'+std::to_string(decSum);
	}
	return ret;
}