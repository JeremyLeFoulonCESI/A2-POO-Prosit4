#include "Receiver.hpp"
#include "HertzianSpace.hpp"
#include <iostream>


float Receiver::getFrequency() {
	if (!this->current_user)
		return 0;
	return this->current_user->getCurrentRadio();
}


Receiver::Receiver(HertzianSpace* space) :
	space(space), users(), pool(), current_user(nullptr)
{}

void Receiver::addUser(const char* name) {
	if (this->users.count(name))
		return;
	this->users[name] = ReceiverUser();
}

bool Receiver::switchUser(const char* name) {
	if (!this->users.count(name))
		return 0;
	if (this->getFrequency())
		this->space->unregisterReceiverHandler(this, this->getFrequency());
	this->current_user = &this->users[name];
	this->space->registerReceiverHandler(this, this->getFrequency(), &Receiver::onReceive);
	return 1;
}

void Receiver::subToFrequency(float frequency, const char* name) {
	this->current_user->putFavoriteRadio(name, frequency);
}

bool Receiver::switchRadio(const char* favorite_name) {
	if (this->getFrequency())
		this->space->unregisterReceiverHandler(this, this->getFrequency());
	if (!this->current_user->switchRadio(favorite_name))
		return 0;
	if (this->getFrequency())
		this->space->registerReceiverHandler(this, this->getFrequency(), &Receiver::onReceive);
	return 1;
}

bool Receiver::switchRadio(float frequency) {
	if (this->getFrequency())
		this->space->unregisterReceiverHandler(this, this->getFrequency());
	if (!this->current_user->switchRadio(frequency))
		return 0;
	if (this->getFrequency())
		this->space->registerReceiverHandler(this, this->getFrequency(), &Receiver::onReceive);
	return 1;
}

void Receiver::onReceive(const char* msg, size_t sz) {
	this->pool.add(msg, sz);
}

const char* Receiver::peek(size_t* out_size) {
	return this->pool.peek(out_size);
}

const char* Receiver::read(size_t* out_size) {
	return this->pool.get(out_size);
}

bool Receiver::available() {
	return this->pool.available();
}

