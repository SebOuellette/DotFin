#include <string>

#include "../functions/findType.h"
#include "../functions/findVar.h"
#include "../functions/escapeInQuotes.h"
#include "../functions/unEscape.h"

#include "adding.h"

#ifndef OPERATION_H
#define OPERATION_H

//(?:(\d+)((?:\.)\d+)?|("[^"]*")|(\w+)) *(\+|\/|\-|\*) *(?:(\d+)((?:\.)\d+)?|("[^"]*")|(\w+))

//(?:\d+(?:\.)\d+?|"[^"]*"|\w+) *(?:\+|\/|\-|\*) *(?:\d+(?:\.)\d+?|"[^"]*"|\w+)

std::string completeOperation(std::string file, std::vector<Variable>& varArray) {
	std::string ret = file;

	std::string operationRegex = "(?:(\\d+)((?:\\.)\\d+)?|(\"[^\"]*\")|(\\w+)) *(\\+|\\/|\\-|\\*) *(?:(\\d+)((?:\\.)\\d+)?|(\"[^\"]*\")|(\\w+))";
	std::string operationReplace = "(?:\\d+(?:\\.)\\d+?|\"[^\"]*\"|\\w+) *(?:\\+|\\/|\\-|\\*) *(?:\\d+(?:\\.)\\d+?|\"[^\"]*\"|\\w+)";
	std::regex opReplace(operationReplace);
	std::regex opCheck(operationRegex);
	std::smatch match;

	while (std::regex_search(ret, match, opCheck)) {
		// Variables of the found things
		std::string wholeint1 = match[1];
		std::string decimals1 = match[2];
		std::string strcontents1 = match[3];
		std::string varfound1 = match[4];
		std::string type1 = findType(wholeint1, decimals1, strcontents1, varfound1);
		std::string found1;
		if (type1 == "int") found1 = wholeint1;
		else if (type1 == "decimal") found1 = wholeint1+"."+decimals1;
		else if (type1 == "string") found1 = strcontents1;
		else if (type1 == "variable") found1 = findVar(varArray, type1)->value;
		else if (type1 == "undefined") found1 = "undefined";

		std::string oper = match[5];

		std::string wholeint2 = match[6];
		std::string decimals2 = match[7];
		std::string strcontents2 = match[8];
		std::string varfound2 = match[9];
		std::string type2 = findType(wholeint2, decimals2, strcontents2, varfound2);
		std::string found2;
		if (type2 == "int") found2 = wholeint2;
		else if (type2 == "decimal") found2 = wholeint2+"."+decimals2;
		else if (type2 == "string") found2 = strcontents2;
		else if (type2 == "variable") found2 = findVar(varArray, type2)->value;
		else if (type2 == "undefined") found2 = "undefined";

		std::string convType;
		if (type1 == "string" || type2 == "string") {
			convType = "string";
		} else if (type1 == "decimal" || type2 == "decimal") {
			convType = "decimal";
		} else if (type1 == "int" && type2 == "int") {
			convType = "int";
		} else {
			convType = "undefined";
		}

		if (oper == "+") {
			if (convType == "string") {
				ret = regex_replace(ret, opReplace, addString(found1+"+"+found2));
				//std::cout << ret << std::endl;
			} else if (convType == "int") {
				ret = regex_replace(ret, opReplace, addInt(found1+"+"+found2));
			}
		} else if (oper == "-") {
			// subtracting
			return file;
		} else if (oper == "*") {
			// multiplying
			return file;
		} else if (oper == "/") {
			// dividing
			return file;
		}

	}
	return ret;
}

#endif