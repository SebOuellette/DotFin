#include <string>

#include "../functions/findType.hpp"
#include "../functions/findVar.hpp"
#include "../functions/escapeInQuotes.hpp"
#include "../functions/unEscape.hpp"

#include "adding.hpp"
#include "subtracting.hpp"

#include "../classes/variables.hpp"

#ifndef OPERATION_HPP
#define OPERATION_HPP

//(?:(\d+)(?:(?:\.)(\d+))?|("[^"]*")|(\w+)) *(\+|\/|\-|\*) *(?:(\d+)(?:(?:\.)(\d+))?|("[^"]*")|(\w+))

//(?:\d+(?:\.\d+)?|"[^"]*"|\w+) *(?:\+|\/|\-|\*) *(?:\d+(?:\.\d+)?|"[^"]*"|\w+)

std::string completeOperation(std::string file, std::vector<Variable>& varArray);

#endif