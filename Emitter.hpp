#pragma once


class HertzianSpace;
class Emitter
{
	HertzianSpace* space;
	float frequency;

public:
	Emitter(HertzianSpace* space, float frequency);

	void emit(const char* msg);
	void emit(const char* msg, size_t sz);
	float getFrequency();
};

