#include <string>

#ifndef FINDTYPE_H
#define FINDTYPE_H

std::string findType(std::string wholeint, std::string decimals, std::string str, std::string var) {
	if (wholeint.length() && !decimals.length()) {
		return "int";
	} else if (wholeint.length() && decimals.length()) {
		return "decimal";
	} else if (str.length()) {
		return "string";
	} else if (var.length()) {
		return "variable";
	} else {
		return "undefined";
	}
}

#endif