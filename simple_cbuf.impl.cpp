
#include <algorithm>
#include "simple_cbuf.h"

template <typename T>
simple_cbuf<T>::simple_cbuf(size_t size)
{
	if(size > max_size){
		size = default_size;
	}
	buf_length = size + 1;
	data = new T[buf_length];
	front = back = 0;
}

template <typename T>
simple_cbuf<T>::simple_cbuf(const simple_cbuf &cbuf) : 
	buf_length(cbuf.buf_length),
	front(cbuf.front),
	back(cbuf.back)
{
	data = new T[buf_length];
	std::copy(cbuf.data, cbuf.data + cbuf.buf_length, data);
}

template <typename T>
simple_cbuf<T>::~simple_cbuf()
{
	delete data;
}

template <typename T>
size_t
simple_cbuf<T>::size() const
{
	if(back >= front){
		return back - front;
	}else{
		return buf_length - front + back;
	}
}

template <typename T>
bool
simple_cbuf<T>::empty() const
{
	return front == back;
}

template <typename T>
void
simple_cbuf<T>::pop()
{
	if(empty()){
		return;
	}
	front++;
	front %= buf_length;
}

template <typename T>
const T&
simple_cbuf<T>::top() const
{
	return data[front];
}

template <typename T>
void
simple_cbuf<T>::push(const T& new_value)
{
	data[back++] = new_value;
	back %= buf_length;
	//overlap
	if(back == front){
		front++;
		front %= buf_length;
	}
}

template <typename T>
simple_cbuf<T>&
simple_cbuf<T>::operator=(const simple_cbuf<T> &cbuf)
{
	buf_length = cbuf.buf_length;
	front = cbuf.front;
	back = cbuf.back;
	delete data;
	data = new int[buf_length];
	std::copy(cbuf.data, cbuf.data + cbuf.buf_length, data);
	return *this;
}

template <typename T>
const T&
simple_cbuf<T>::operator[](size_t index)
{
	if(index >= size())
		return data[back];
	if(index >= buf_length - front)
		return data[index - (buf_length - front)];
	return data[front + index];
}
