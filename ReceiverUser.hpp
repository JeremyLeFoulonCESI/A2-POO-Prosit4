#pragma once
#include <map>

class ReceiverUser
{
	std::map<const char*, float> favorite_radios;
	float current_radio;

public:
	ReceiverUser();
	void putFavoriteRadio(const char* name, float frequency);
	float getFavoriteRadio(const char* name);
	bool switchRadio(const char* favorite_name);
	bool switchRadio(float frequency);
	float getCurrentRadio();
};

