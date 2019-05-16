#include <string>
#include <vector>

#ifndef SPLITLINES_H
#define SPLITLINES_H

std::vector<std::string> splitLines(std::string str) {
	std::vector<std::string> vec;
	int prev = 0;
	for(int i=0;i<str.length();i++) {
		if (str[i] == ';' && str[i-1] != '\\') {
			vec.push_back(str.substr(prev, i+1));
			prev = i;
		}
	}

	return vec;
}

#endif