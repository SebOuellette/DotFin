#include <string>
#include <vector>
#include <regex>

#ifndef BASICFUNCS_H
#define BASICFUNCS_H

// Adding strings
std::string addStr(std::string contents) {
	std::vector<std::string> strs;
	std::string ret = "";
	int pos = 0;
	for(int i=0;i<contents.length();i++) {
		if(contents[i] == '+') {
			strs.push_back(contents.substr(pos, i));
			pos = i+1;
		} else if (i == contents.length()-1) {
			strs.push_back(contents.substr(pos, i+1));
		}
	}

	for(std::string piece : strs) {
		std::regex rgx("\"([^\"]*)\"");
		std::smatch match;

		if (std::regex_search(piece, match, rgx)) {
			ret+=match[1];
		}
	}

	return ret;
}

#endif