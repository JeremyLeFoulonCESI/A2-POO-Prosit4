#include "Emitter.hpp"
#include "HertzianSpace.hpp"


Emitter::Emitter(HertzianSpace* space, float frequency) : 
	buffer(), space(space), frequency(frequency)
{
	space->registerEmitter(this, frequency);
}

void Emitter::emit(const char* msg) {
	this->buffer.add(msg);
	this->space->emit(this->frequency, msg);
}

const char* Emitter::read(size_t index, size_t* out_size) {
	return this->buffer.get(index, out_size);
}

bool Emitter::available(size_t index) {
	return index < this->buffer.size();
}

float Emitter::getFrequency() {
	return this->frequency;
}

