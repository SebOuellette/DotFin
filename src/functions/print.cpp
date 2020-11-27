#include "print.hpp"

void findPrint(std::string file, std::vector<Variable>& varArray) {
	std::regex printCheck("print(ln)?(?=\\([^\\)]*\\))");
	if (std::regex_search(file, printCheck)) {
		// Print statement found
		std::regex rgx("print(ln)?\\((.*)\\);");
		std::smatch match;

		if (std::regex_search(file, match, rgx)) {
			// Found inside of print()
			std::string contents = match[2];

			if (varExists(varArray, contents)) {
				std::cout << removeQuotes(findVar(varArray, contents)->value);
				
			} else {
				std::cout << removeQuotes(contents);
			}

			if (match[1] == "ln") std::cout << std::endl;
		}
	}
}