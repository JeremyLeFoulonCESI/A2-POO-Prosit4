#include "BufferElement.hpp"
#include <iostream>


BufferElement::BufferElement(const char* msg, size_t sz) :
	sz(sz), next(nullptr) 
{
	if (!sz) {
		this->msg = nullptr;
		return;
	}
	this->msg = new char[sz + 1];
	std::memcpy(this->msg, msg, sz);
	this->msg[sz] = 0;
}

BufferElement* BufferElement::getNext() {
	return this->next;
}

void BufferElement::setNext(BufferElement* next) {
	this->next = next;
}

const char* BufferElement::getMsg() {
	if (!this->sz)
		return "";
	return this->msg;
}

size_t BufferElement::getSize() {
	return this->sz;
}

BufferElement::~BufferElement() {
	if (this->next) {
		delete this->next;
		this->next = nullptr;
	}
	if (this->msg) {
		delete this->msg;
		this->msg = nullptr;
	}
	this->sz = 0;
}

