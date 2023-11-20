#include "EmitterBuffer.hpp"
#include <iostream>


EmitterBuffer::EmitterBuffer() :
	first_msg(nullptr), last_msg(nullptr), msg_count(0)
{}

void EmitterBuffer::add(const char* msg) {
	BufferElement* element = new BufferElement(msg, std::strlen(msg));

	if (this->last_msg && this->first_msg) {
		this->last_msg->setNext(element);
	}
	else {
		this->first_msg = element;
	}
	this->last_msg = element;
	this->msg_count++;
}

const char* EmitterBuffer::get(size_t index, size_t* out_size) {
	if (index >= this->msg_count)
		return nullptr;
	BufferElement* current = this->first_msg;

	for (size_t i = 0; i < index; i++) {
		if (!current->getNext())
			break;
		current = current->getNext();
	}
	if (out_size)
		*out_size = current->getSize();
	return current->getMsg();
}

size_t EmitterBuffer::size() {
	return this->msg_count;
}

void EmitterBuffer::printBuffer() {
	if (!this->msg_count) {
		std::cout << "Buffer { null }\n";
		return;
	}

	std::cout << "Buffer {\n";
	BufferElement* current = this->first_msg;
	for (;;) {
		std::cout << '"' << current->getMsg() << "\",\n";
		if (!current->getNext())
			break;
		current = current->getNext();
	}
	std::cout << "}\n";
}

EmitterBuffer::~EmitterBuffer() {
	if (!this->msg_count)
		return;
	
	delete this->first_msg;  // this deletes all the elements of the chain through the destructors
	this->first_msg = nullptr;
	this->last_msg = nullptr;
	this->msg_count = 0;
}

