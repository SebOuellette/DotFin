#include <iostream>
#include <typeinfo>

#include "functions/findVar.h"

// Gonna have to reconstruct this probably
// Don't use template, just store int id for type

#ifndef VARIABLES_H
#define VARIABLES_H

class Variable {
public:
	Variable(std::string contents, std::string type, std::string name, std::vector<Variable>& varArray, bool isConst);
	bool set(std::string contents, std::string type);

	const bool isConst;
	const std::string name;
	bool exists = true; 
	// ^^^ Just to help when checking if variable with name exists
	std::string varType;
	std::string value;
};

#endif