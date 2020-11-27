#include <string>
#include <regex>
#include <vector>

#include "token.hpp"
#include "handleLex.hpp"

#ifndef LEXER_HPP
#define LEXER_HPP

std::vector<Token> lex(std::string file);

#endif