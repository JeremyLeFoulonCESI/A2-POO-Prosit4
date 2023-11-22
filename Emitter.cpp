#include "Emitter.hpp"
#include "HertzianSpace.hpp"


Emitter::Emitter(HertzianSpace* space, float frequency) : 
	space(space), frequency(frequency)
{}

void Emitter::emit(const char* msg) {
	return this->emit(msg, std::strlen(msg));
}

void Emitter::emit(const char* msg, size_t sz) {
	this->space->transmit(this->frequency, msg, sz);
}

float Emitter::getFrequency() {
	return this->frequency;
}

