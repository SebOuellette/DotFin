#include <regex>


#ifndef STRCONTENTS_H
#define STRCONTENTS_H

std::string removeQuotes(std::string contents) {
	std::string ret = contents;
	std::regex rgx("\"?([^\"]*)\"?");
	std::smatch match;

	if (std::regex_search(contents, match, rgx)) {
		ret = match[1];
	}
	return ret;
}

#endif