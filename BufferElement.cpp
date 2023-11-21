#include "BufferElement.hpp"
#include <iostream>


BufferElement::BufferElement(const char* msg, size_t sz) :
	sz(sz), next(nullptr)
{
	if (!sz) {
		this->msg = nullptr;
		return;
	}
	this->msg = msg;
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
	this->msg = nullptr;
	this->sz = 0;
}

