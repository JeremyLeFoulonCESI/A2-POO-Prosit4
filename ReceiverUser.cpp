#include "ReceiverUser.hpp"
#include <iostream>


ReceiverUser::ReceiverUser() :
	current_radio(0), favorite_radios()
{}

void ReceiverUser::putFavoriteRadio(const char* name, float frequency) {
	this->favorite_radios[name] = frequency;
}

float ReceiverUser::getFavoriteRadio(const char* name) {
	if (!this->favorite_radios.count(name))
		return 0;
	return this->favorite_radios[name];
}

bool ReceiverUser::switchRadio(const char* favorite_name) {
	if (!this->favorite_radios.count(favorite_name))
		return 0;
	this->current_radio = this->getFavoriteRadio(favorite_name);
	return 1;
}

bool ReceiverUser::switchRadio(float frequency) {
	this->current_radio = frequency;
	//std::cout << "switch radio: " << this->current_radio << '\n';
	return 1;
}

float ReceiverUser::getCurrentRadio() {
	return this->current_radio;
}

