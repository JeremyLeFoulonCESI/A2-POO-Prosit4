#include "HertzianSpace.hpp"


HertzianSpace::HertzianSpace() :
	emitter_frequencies(), receiver_handlers()
{}

void HertzianSpace::registerEmitter(Emitter* emitter, float frequency) {
	this->emitter_frequencies[frequency] = emitter;
}

void HertzianSpace::registerReceiverHandler(Receiver* receiver, float frequency, void (Receiver::* cb)(const char*)) {
	if (!this->receiver_handlers.count(frequency)) {
		this->receiver_handlers[frequency] = std::map<Receiver*, void (Receiver::*) (const char*)>();
	}
	this->receiver_handlers[frequency][receiver] = cb;
}

void HertzianSpace::unregisterReceiverHandler(Receiver* receiver, float frequency) {
	if (!this->receiver_handlers.count(frequency))
		return;
	if (!this->receiver_handlers[frequency].count(receiver))
		return;

	this->receiver_handlers[frequency].erase(receiver);
}

const char* HertzianSpace::read(float frequency, size_t index, size_t* out_size) {
	if (!this->emitter_frequencies.count(frequency))
		return nullptr;
	return this->emitter_frequencies[frequency]->read(index, out_size);
}

void HertzianSpace::emit(float frequency, const char* msg) {
	if (!this->receiver_handlers.count(frequency))
		return;

	for (std::pair<Receiver*, void (Receiver::*) (const char*)> pair : this->receiver_handlers[frequency]) {
		(pair.first->*(pair.second))(msg);
	}
}

bool HertzianSpace::available(float frequency, size_t index) {
	if (!this->emitter_frequencies.count(frequency))
		return 0;
	return this->emitter_frequencies[frequency]->available(index);
}

