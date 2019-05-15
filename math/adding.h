#include <string>
#include <regex>

#ifndef ADDING_H
#define ADDING_H

// Add Strings
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
	std::regex rgx("(\\d+) *\\+ *(\\d+)");
	std::smatch match;
	std::string ret = contents;

	if (std::regex_search(contents, match, rgx)) {
		int num1 = std::stoi((std::string)match[1]);
		int num2 = std::stoi((std::string)match[2]);
		ret = std::to_string(num1+num2);
	}
	return ret;
}

#endif