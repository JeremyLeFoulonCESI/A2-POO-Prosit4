#include "HertzianSpace.hpp"
#include <iostream>


HertzianSpace::HertzianSpace() :
	emitter_frequencies(), receiver_handlers()
{}

void HertzianSpace::registerEmitter(Emitter* emitter, float frequency) {
	this->emitter_frequencies[frequency] = emitter;
}

void HertzianSpace::registerReceiverHandler(Receiver* receiver, float frequency, void (Receiver::* cb)(const char*, size_t)) {
	//std::cout << "register: f=" << frequency << "\n";
	if (!this->receiver_handlers.count(frequency)) {
		this->receiver_handlers[frequency] = std::map<Receiver*, void (Receiver::*) (const char*, size_t)>();
	}
	this->receiver_handlers[frequency][receiver] = cb;
	//std::cout << this->receiver_handlers[frequency].count(receiver) << '\n';
}

void HertzianSpace::unregisterReceiverHandler(Receiver* receiver, float frequency) {
	//std::cout << "unregister\n";
	if (!this->receiver_handlers.count(frequency))
		return;
	if (!this->receiver_handlers[frequency].count(receiver))
		return;

	this->receiver_handlers[frequency].erase(receiver);
}

void HertzianSpace::emit(float frequency, const char* msg, size_t sz) {
	//std::cout << "emit: " << this->receiver_handlers.count(frequency) << ", f=" << frequency << '\n';
	if (!this->receiver_handlers.count(frequency))
		return;
	for (std::pair<Receiver*, void (Receiver::*) (const char*, size_t)> pair : this->receiver_handlers[frequency]) {
		(pair.first->*(pair.second))(msg, sz);
	}
}

