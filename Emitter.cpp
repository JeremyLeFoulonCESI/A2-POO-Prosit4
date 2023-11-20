#include "Emitter.hpp"


Emitter::Emitter() : 
	buffer()
{}

void Emitter::emit(const char* msg) {
	this->buffer.add(msg);
}

const char* Emitter::read(size_t index, size_t* out_size) {
	return this->buffer.get(index, out_size);
}

bool Emitter::available(size_t index) {
	return index < this->buffer.size();
}

