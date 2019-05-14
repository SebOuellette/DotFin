#include <string>

#include "functions/findType.h"

#ifndef OPERATION_H
#define OPERATION_H

// (?:(\d+)((?:\.)\d+)?|(".*")|(\w+)) *(\+|\/|\-|\*) *(?:(\d+)((?:\.)\d+)?|(".*")|(\w+))

/*
This function should return the string of the completed operation for replacement

|
\/ change to std::string when able to */
void completeOperation(std::string file, std::vector<Variable>& varArray) {
	std::string operationRegex = "(?:(\\d+)((?:\\.)\\d+)?|(\".*\")|(\\w+)) *(\\+|\\/|\\-|\\*) *(?:(\\d+)((?:\\.)\\d+)?|(\".*\")|(\\w+))";
	std::regex printCheck(operationRegex);
	if (std::regex_search(file, printCheck)) {
		// Print statement found
		std::regex rgx(operationRegex);
		std::smatch match;

		if (std::regex_search(file, match, rgx)) {
			// Variables of the found things
			std::string wholeint1 = match[1];
			std::string decimals1 = match[2];
			std::string strcontents1 = match[3];
			std::string varfound1 = match[4];
			std::string type1 = findType(wholeint1, decimals1, strcontents1, varfound1);

			std::string oper = match[5];

			std::string wholeint2 = match[6];
			std::string decimals2 = match[7];
			std::string strcontents2 = match[8];
			std::string varfound2 = match[9];
			std::string type2 = findType(wholeint2, decimals2, strcontents2, varfound2);

			if (oper == "+") {
				// adding
			} else if (oper == "-") {
				// subtracting
			} else if (oper == "*") {
				// multiplying
			} else if (oper == "/") {
				// dividing
			}

		}
	}
}

#endif