#ifndef _SIMPLE_CBUF_
#define _SIMPLE_CBUF_
//#include <stdint.h>
#include <cstdint>
#include <cstddef>

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

	int    top() const; /* see below */

	void   pop();

	void   push(int new_value);

	simple_cbuf& operator = (const simple_cbuf &cbuf);

	int& operator[](size_t index);

private:
	/* whatever you want */
	int		*data;
	size_t	buf_length;
	size_t	front;	//first data
	size_t	back;	//next write position
};

#endif //_SIMPLE_CBUF_
