#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <cstdlib>

#include "findVar.hpp"

#include "../classes/variables.hpp"

#include "../math/operation.hpp"

#ifndef VARIABLE_HPP
#define VARIABLE_HPP

void findVariable(std::string file, std::vector<Variable>& varArray);

#endif