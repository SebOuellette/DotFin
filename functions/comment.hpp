#include <regex>
#include <string>

#ifndef COMMENT_HPP
#define COMMENT_HPP

std::string removeComments(std::string line) {
	std::regex commentCheck("\\/{2}");
	std::regex inQuote("(?:\".*)\\/{2}(?:.*\")");
	if (std::regex_search(line, commentCheck) && !std::regex_search(line, inQuote)) {
		// Print statement found
		std::regex rgx(".*(?=\\/{2})");
		std::smatch match;

		if (std::regex_search(line, match, rgx)) {
			return match[0];
		}
	}
	return line;
}

#endif