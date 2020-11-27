#include <regex>
#include <string>

#include "token.hpp"

#ifndef HANDLELEX_HPP
#define HANDLELEX_HPP

Token handleLex(std::string* toParse, std::string value, std::regex regex, std::string type);

#endif