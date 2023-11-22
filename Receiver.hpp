#pragma once
#include <map>
#include "ReceiverUser.hpp"
#include "ReceiverPoolBuffer.hpp"

class HertzianSpace;
class Receiver
{
	HertzianSpace* space;
	std::map<const char*, ReceiverUser> users;
	ReceiverUser* current_user;
	ReceiverPoolBuffer pool;

public:
	
	Receiver(HertzianSpace* space);
	void addUser(const char* name);
	bool switchUser(const char* name);
	bool switchRadio(const char* favorite_name);
	bool switchRadio(float frequency);
	void subToFrequency(float frequency, const char* name);
	void onReceive(const char* msg, size_t size);
	const char* read(size_t* out_size);
	const char* peek(size_t* out_size);
	bool available();
	float getFrequency();
};

