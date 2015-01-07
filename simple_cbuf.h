#ifndef _SIMPLE_CBUF_
#define _SIMPLE_CBUF_
#include <cstdint>
#include <cstddef>
#include <vector>

template <typename T>
class simple_cbuf 
{
public:
	enum {
	   	default_size = 100,
		max_size = 100000
	};

	explicit simple_cbuf(size_t size = default_size);

	simple_cbuf(const simple_cbuf &cbuf);

	~simple_cbuf();

	size_t size() const;

	bool   empty() const;

	const T& top() const; 

	void   pop();

	void   push(const T& new_value);

	simple_cbuf& operator = (const simple_cbuf &cbuf);

	const T& operator[](size_t index);

//private:
	T		*data;
	//std::vector<T>	data;
	size_t	buf_length;
	size_t	front;	//first data
	size_t	back;	//next write position
};

#include "simple_cbuf.impl.cpp"

#endif //_SIMPLE_CBUF_
