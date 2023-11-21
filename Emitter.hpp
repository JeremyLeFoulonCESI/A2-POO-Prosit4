#pragma once
#include "EmitterBuffer.hpp"


class HertzianSpace;
class Emitter
{
	HertzianSpace* space;
	EmitterBuffer buffer;
	float frequency;

public:
	Emitter(HertzianSpace* space, float frequency);

	void emit(const char* msg);
	const char* read(size_t index, size_t* out_size);
	bool available(size_t index);
	float getFrequency();
};

