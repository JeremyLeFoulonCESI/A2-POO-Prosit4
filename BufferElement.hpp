#pragma once

class BufferElement;

class BufferElement
{
	const char* msg;
	size_t sz;
	BufferElement* next;

public:
	BufferElement(const char*, size_t);
	BufferElement(const BufferElement&) = delete;
	BufferElement* getNext();
	void setNext(BufferElement*);
	const char* getMsg();
	size_t getSize();
	~BufferElement();
};

