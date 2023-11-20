#pragma once
#include "BufferElement.hpp"


class EmitterBuffer
{
	BufferElement* first_msg;
	BufferElement* last_msg;
	size_t msg_count;

public:
	EmitterBuffer();
	EmitterBuffer(const EmitterBuffer&) = delete;
	void add(const char* msg);
	const char* get(size_t index, size_t* out_size);
	size_t size();
	void printBuffer();

	~EmitterBuffer();
};

