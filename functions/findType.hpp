#include <string>

#include "findVar.hpp"

#include "../classes/variables.hpp"

#ifndef FINDTYPE_HPP
#define FINDTYPE_HPP

std::string findType(std::string wholeint, std::string decimals, std::string str, std::string var, std::vector<Variable>& varArray) {
	if (wholeint.length() && !decimals.length()) {
		return "int";
	} else if (wholeint.length() && decimals.length()) {
		return "decimal";
	} else if (str.length()) {
		return "string";
	} else if (var.length()) {
		if (varExists(varArray, var)) return "variable";//findVar(varArray, var)->varType;
		else return "undefined";
	} else {
		return "undefined";
	}
}

#endif