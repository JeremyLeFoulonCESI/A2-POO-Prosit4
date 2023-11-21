#pragma once
#include <map>
#include <vector>
#include "Emitter.hpp"
#include "Receiver.hpp"

class HertzianSpace
{
	std::map<float, Emitter*> emitter_frequencies;
	std::map<float, std::map<Receiver*, void (Receiver::*) (const char*)>> receiver_handlers;

public:
	HertzianSpace();
	void registerEmitter(Emitter*, float frequency);
	void registerReceiverHandler(Receiver*, float frequency, void (Receiver::* cb)(const char*));
	void unregisterReceiverHandler(Receiver*, float frequency);
	const char* read(float frequency, size_t index, size_t* out_size);
	void emit(float frequency, const char* msg);
	bool available(float frequency, size_t index);
};

