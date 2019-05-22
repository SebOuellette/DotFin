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
        std::regex conditionBracketCheck("^ *\\(");
        std::regex variableCheck("^ *var");

        // List of if statements to lex the next segment into a token
        if (std::regex_search(toParse, match, functionCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], functionCheck, "function"));
        } else if (std::regex_search(toParse, match, conditionBracketCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], conditionBracketCheck, "conditionBracketOpen"));
        } else if (std::regex_search(toParse, match, variableCheck)) {
            tokenList.push_back(handleLex(&toParse, match[1], variableCheck, "newVariable"));
        } else {
            found = false;
        }
    } while(found);

    return tokenList;
}

#endif