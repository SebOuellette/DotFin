#include "strContents.hpp"

std::string removeQuotes(std::string contents) {
	std::string ret = contents;
	std::regex rgx("\"?([^\"]*)\"?");
	std::smatch match;

	if (std::regex_search(contents, match, rgx)) {
		ret = match[1];
	}
	return ret;
}