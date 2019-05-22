#include <regex>
#include <string>

#include "token.hpp"

#ifndef HANDLELEX_HPP
#define HANDLELEX_HPP

Token handleLex(std::string* toParse, std::string value, std::regex regex, std::string type) {
    *toParse = regex_replace(*toParse, regex, "", std::regex_constants::format_first_only);

    Token newToken;
    newToken.type = "conditionBracket";
    newToken.value = type;
    return newToken;
}

#endif