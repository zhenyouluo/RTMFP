
#include "simple_cbuf.h"

simple_cbuf::simple_cbuf(size_t size)
{
	if(size > max_size){
		size = default_size;
	}
	buf_length = size + 1;
	data = new int[buf_length];
	front = back = 0;
}

simple_cbuf::simple_cbuf(const simple_cbuf &cbuf) : 
	buf_length(cbuf.buf_length),
	front(cbuf.front),
	back(cbuf.back)
{
	data = new int[buf_length];
}

simple_cbuf::~simple_cbuf()
{
	delete data;
}

size_t
simple_cbuf::size() const
{
	if(back >= front){
		return back - front;
	}else{
		return buf_length - front + back;
	}
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
	//overlap
	if(back == front){
		front++;
		front %= buf_length;
	}
}

simple_cbuf&
simple_cbuf::operator=(const simple_cbuf &cbuf)
{
	buf_length = cbuf.buf_length;
	front = cbuf.front;
	back = cbuf.back;
	data = new int[buf_length];
	return *this;
}

int&
simple_cbuf::operator[](size_t index)
{
	if(index >= size)
		return data[back];
	if(index >= buf_length - front)
		return data[index - (buf_length - front)];
	return data[front + index];
}
