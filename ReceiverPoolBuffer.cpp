#include "ReceiverPoolBuffer.hpp"
#include <iostream>


ReceiverPoolBuffer::ReceiverPoolBuffer() :
	first_msg(nullptr), last_msg(nullptr), msg_count(0)
{}

BufferElement* ReceiverPoolBuffer::pop_front() {
	BufferElement* result = this->first_msg;
	this->first_msg = this->first_msg->getNext();
	result->setNext(nullptr);
	return result;
}

void ReceiverPoolBuffer::add(const char* msg, size_t sz) {
	BufferElement* element = new BufferElement(msg, sz);

	if (this->last_msg && this->first_msg) {
		this->last_msg->setNext(element);
	}
	else {
		this->first_msg = element;
	}
	this->last_msg = element;
	this->msg_count++;
}

const char* ReceiverPoolBuffer::get(size_t* out_size) {
	BufferElement* first = this->pop_front();
	const char* result = first->getMsg();
	if (result && out_size)
		*out_size = first->getSize();
	delete first;
	return result;
}

const char* ReceiverPoolBuffer::peek(size_t* out_size) {
	BufferElement* first = this->first_msg;
	const char* result = first->getMsg();
	if (result && out_size)
		*out_size = first->getSize();
	return result;
}

bool ReceiverPoolBuffer::available() {
	return (this->first_msg != 0) && (this->last_msg != 0);
}

void ReceiverPoolBuffer::printBuffer() {
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

ReceiverPoolBuffer::~ReceiverPoolBuffer() {
	if (!this->msg_count)
		return;
	
	delete this->first_msg;  // this deletes all the elements of the chain through the destructors
	this->first_msg = nullptr;
	this->last_msg = nullptr;
	this->msg_count = 0;
}

