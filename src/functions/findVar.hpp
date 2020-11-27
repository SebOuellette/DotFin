#include <vector>
#include <string>

#ifndef FINDVAR_HPP
#define FINDVAR_HPP

template <typename T>
bool varExists(std::vector<T>& varArray, std::string name) {
	for(T var : varArray) {
		if (var.name == name) return true;
	}
	return false;
}

template <typename T>
T* findVar(std::vector<T>& varArray, std::string name) {
	for(T& var : varArray) {
		if (var.name == name) return &var;
	}

	return &varArray[0];
}

#endif