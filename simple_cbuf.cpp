
#include "simple_cbuf.h"

simple_cbuf::simple_cbuf(size_t size) : buf_length(size + 1)
{
	data = new int[buf_length];
	front = back = 0;
}

simple_cbuf::~simple_cbuf()
{
	delete data;
}

size_t
simple_cbuf::size() const
{
	return (back + buf_length - front) % buf_length;
}

bool
simple_cbuf::empty() const
{
	return front == back;
}

void
simple_cbuf::pop()
{
	if(empty()){
		return;
	}
	front++;
	front %= buf_length;
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
	back %= buf_length;
	if(back == front){
		front++;
		front %= buf_length;
	}
}
