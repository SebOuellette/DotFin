#include <string>
#include <regex>
#include <vector>

#include "token.hpp"
#include "handleLex.hpp"

#ifndef LEXER_HPP
#define LEXER_HPP

std::vector<Token> lex(std::string file) {
    std::string toParse;
    std::vector<Token> tokenList;
    bool found = true;
    
    do {
        std::smatch match;
        
        // List of regexes in same order as if statements that handle them below
        std::regex functionCheck("^ *(\\w+)?(?=\\()");
        std::regex bracketCheck("^ *\\(|\\)|\\{|\\}|\\[|\\]");
        std::regex variableCheck("^ *var *(\\w+)");
        std::regex stringCheck("^ *\"(\w+)\"");
        std::regex varReferenceCheck("^ *(\w+)");
        std::regex intCheck("^ *(\\d+)");
        std::regex assignCheck("^ *(=)");
        std::regex compareCheck("^ *(>=|<=|==|!=|>|<)");
        std::regex operationCheck("^ *(\+|-|\/|\*)");

        // List of if statements to lex the next segment into a token
        if (std::regex_search(toParse, match, functionCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], functionCheck, "function"));
        } else if (std::regex_search(toParse, match, bracketCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], bracketCheck, "bracket"));
        } else if (std::regex_search(toParse, match, variableCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], variableCheck, "newVar"));
        } else if (std::regex_search(toParse, match, stringCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], stringCheck, "string"));
        } else if (std::regex_search(toParse, match, varReferenceCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], varReferenceCheck, "varRef"));
        } else if (std::regex_search(toParse, match, intCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], intCheck, "int"));
        } else if (std::regex_search(toParse, match, assignCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], assignCheck, "assign"));
        } else if (std::regex_search(toParse, match, compareCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], compareCheck, "compare"));
        } else if (std::regex_search(toParse, match, operationCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], operationCheck, "operation"));
        } else {
            found = false;
        }
    } while(found);

    return tokenList;
}

#endif