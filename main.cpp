#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>

#include "functions/splitLines.hpp"
#include "functions/print.hpp"
#include "functions/variable.hpp"
#include "functions/comment.hpp"
#include "functions/escapeInQuotes.hpp"
#include "functions/unEscape.hpp"

#include "math/operation.hpp"

#include "classes/variables.hpp"

int main(int argc, char** argv) {
	// The args are here for if I want to use them in the future
	// So that you can run command './main file.fin' to run the program
	std::string fileNamePassed(*argv);
	std::ifstream text;
	text.open("lang.fin");

	if (!text.is_open()) {
		std::cout << "Failed to open" << std::endl;
	}

	// Open an input file stream
	std::ifstream finFile("lang.fin");

	// Create the array of variables
	std::vector<Variable> varArray;
	varArray.push_back(Variable("", "undefined", "default", varArray, true));
	
	// The depth will hold how far into {} the code is. The variables will also have to be modified to hold the scope that they are defined in. The class for functions could be passed as the scope to the created variable. Function classes should also hold their parent so we can get the variables from that scope as well. Then obviously the global variables are global.
	int depth = 0;
	std::string tokens = ";/+-*(){}&^%.";

	// Loop through each line
	for(std::string fileStr; getline( finFile, fileStr );) {
		std::string file = removeComments(fileStr);
		file = escapeInQuotes(file, tokens);

		// Loop through each statement on a line
		for(std::string fileStr : splitLines(file)) {
			// Check and complete operations
			fileStr = completeOperation(fileStr, varArray);

			// Unescape ; that's in quotes
			fileStr = unEscape(fileStr, tokens);

			// check for variable
			findVariable(fileStr, varArray);

			// check for print statement
			findPrint(fileStr, varArray);
		}
	}
	return 1;
}