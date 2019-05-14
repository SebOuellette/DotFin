#include <string>

#include "variables.h"

Variable::Variable(std::string contents, std::string type, std::string namePassed, std::vector<Variable>& varArray, bool isConst = false):
	isConst(isConst), name(namePassed) {
		this->value = contents;
		this->varType = type;
		if (varExists<Variable>(varArray, namePassed)) {
			std::cerr << "ERROR: Variable with name: \"" << name << "\" already exists" << std::endl;
		}
		if (type == "undefined") this->exists = false;
	}

bool Variable::set(std::string contents, std::string type) {
	if (!this->isConst) {
		this->value = contents;
		this->varType = type;
	} else {
		std::cerr << "ERROR: Cannot assign value to constant variable" << std::endl;
		return true;
	}
	return false;
}

