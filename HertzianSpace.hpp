#pragma once
#include <map>
#include "Emitter.hpp"
#include "Receiver.hpp"

class HertzianSpace
{
	std::map<float, std::map<Receiver*, void (Receiver::*) (const char*, size_t)>> receiver_handlers;

public:
	HertzianSpace();
	void registerReceiverHandler(Receiver*, float frequency, void (Receiver::* cb)(const char*, size_t));
	void unregisterReceiverHandler(Receiver*, float frequency);
	void transmit(float frequency, const char* msg, size_t size);
};

