#include "HertzianSpace.hpp"
#include <iostream>


HertzianSpace::HertzianSpace() :
	receiver_handlers()
{}

void HertzianSpace::registerReceiverHandler(Receiver* receiver, float frequency, void (Receiver::* cb)(const char*, size_t)) {
	if (!this->receiver_handlers.count(frequency)) {
		this->receiver_handlers[frequency] = std::map<Receiver*, void (Receiver::*) (const char*, size_t)>();
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

void HertzianSpace::transmit(float frequency, const char* msg, size_t sz) {
	if (!this->receiver_handlers.count(frequency))
		return;
	for (std::pair<Receiver*, void (Receiver::*) (const char*, size_t)> pair : this->receiver_handlers[frequency]) {
		(pair.first->*(pair.second))(msg, sz);
	}
}

