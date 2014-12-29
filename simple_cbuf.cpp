
#include "simple_cbuf.h"

simple_cbuf::simple_cbuf(size_t size) : length(size)
{
	data = new int[length];
	front = back = 0;
}

simple_cbuf::~simple_cbuf()
{
	delete data;
}

size_t
simple_cbuf::size() const
{
	return length;
}

bool
simple_cbuf::empty() const
{
	return front == back;
}

void
simple_cbuf::pop()
{
	front++;
	front %= length;
}

int
simple_cbuf::top() const
{
	return data[front];
}

void
simple_cbuf::push(int new_value)
{
	data[back++] = new_value;
	back %= length;
}
