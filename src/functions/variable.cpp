#include "variable.hpp"

void findVariable(std::string file, std::vector<Variable>& varArray) {
	std::regex varDefine("(?:(const) +)?var +(\\w+) *= *(?:([^\"|\\d| |;]+)|\"([^\"]*)\"|(\\d+)(?:\\.(\\d+))?);");
	std::regex varSet("(\\w+) *= *(?:([^\"|\\d| |;]+)|\"([^\"]*)\"|(\\d+)(?:\\.(\\d+))?);");
	if (std::regex_search(file, varDefine)) {
		// Variable declaration found
		std::regex rgx("(?:(const) +)?var +(\\w+) *= *(?:([^\"|\\d| |;]+)|\"([^\"]*)\"|(\\d+)(?:\\.(\\d+))?);");
		std::smatch match;

		if (std::regex_search(file, match, rgx)) {
			bool isConst = match[1] == "const";
			std::string name = match[2];
			std::string var = match[3];
			std::string str = match[4];
			std::string wholeint = match[5];
			std::string decimals = match[6];

			if (var.length()) { // Variable
			}
			else if (str.length()) { // String
				varArray.push_back(
					Variable("\""+str+"\"", "string", name, varArray, isConst)
				);
			}
			else if (wholeint.length() && !decimals.length()) { // Int
				varArray.push_back(
					Variable(wholeint, "int", name, varArray, isConst)
				);
			}
			else if (wholeint.length() && decimals.length()) { // Decimals
				varArray.push_back(
					Variable(wholeint+"."+decimals, "decimal", name, varArray, isConst)
				);
			}
		}
	} else if (std::regex_search(file, varSet)) {
		std::regex rgx("(\\w+) *= *(?:([^\"|\\d| |;]+)|\"([^\"]*)\"|(\\d+)(?:\\.(\\d+))?);");
		std::smatch match;

		if (std::regex_search(file, match, rgx)) {
			std::string name = match[1];
			std::string var = match[2];
			std::string str = match[3];
			std::string wholeint = match[4];
			std::string decimals = match[5];

			if (!varExists(varArray, name)) {
				std::cerr << "ERROR: Assignment to unexisting variable" << std::endl;
			} else {
				Variable* selected = findVar(varArray, name);

				if (str.length()) { // String
					selected->set(str, "string");
				}
				else if (wholeint.length() && !decimals.length()) { // Int
					selected->set(wholeint, "int");
				}
				else if (wholeint.length() && decimals.length()) { // Decimals
					selected->set(wholeint+"."+decimals, "decimal");
				}
			}
		}
	}
}
