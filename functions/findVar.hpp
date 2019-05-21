#include <vector>

#ifndef FINDVAR_HPP
#define FINDVAR_HPP

template <class T>
bool varExists(std::vector<T>& varArray, std::string name) {
	for(T var : varArray) {
		if (var.name == name) return true;
	}
	return false;
}

template <class T>
T* findVar(std::vector<T>& varArray, std::string name) {
	for(T& var : varArray) {
		if (var.name == name) return &var;
	}

	return &varArray[0];
}

#endif