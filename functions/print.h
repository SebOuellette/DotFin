#include <string>
#include <vector>
#include <regex>
#include <iostream>

#include "functions/findVar.h"

#include "classes/variables.h"

#ifndef PRINT_H
#define PRINT_H

void findPrint(std::string file, std::vector<Variable>& varArray) {
	std::regex printCheck("print(ln)?(?=\\([^\\)]*\\))");
	if (std::regex_search(file, printCheck)) {
		// Print statement found
		std::regex rgx("print(ln)?\\((([^\\)])*)\\);");
		std::smatch match;

		if (std::regex_search(file, match, rgx)) {
			// Found inside of print()
			std::string contents = match[2];
			if (match[1] == "ln") std::cout << std::endl;

			if (varExists(varArray, contents)) {
				std::cout << findVar(varArray, contents)->value;
				
			} else {
				std::cout << addStr(contents);
			}
		}
	}
}

#endif