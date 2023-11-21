#pragma once
#include "BufferElement.hpp"


class ReceiverPoolBuffer
{
	BufferElement* first_msg;
	BufferElement* last_msg;
	size_t msg_count;

	BufferElement* pop_front();

public:
	ReceiverPoolBuffer();
	ReceiverPoolBuffer(const ReceiverPoolBuffer&) = delete;
	void add(const char* msg, size_t);
	const char* get(size_t* out_size);
	const char* peek(size_t* out_size);
	bool available();
	void printBuffer();

	~ReceiverPoolBuffer();
};

