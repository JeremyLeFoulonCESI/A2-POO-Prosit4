#pragma once
#include "EmitterBuffer.hpp"

class Emitter
{
	EmitterBuffer buffer;

public:
	Emitter();

	void emit(const char* msg);
	const char* read(size_t index, size_t* out_size);
	bool available(size_t index);
};

