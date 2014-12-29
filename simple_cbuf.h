#ifndef _SIMPLE_CBUF_
#define _SIMPLE_CBUF_
//#include <stdint.h>
#include <cstdint>
#include <cstddef>

class simple_cbuf {
	public:
		enum { default_size = 100 };
		explicit simple_cbuf(size_t size =
				default_size);
		~simple_cbuf();
		size_t size() const;
		bool   empty() const;
		int    top() const; /* see below */
		void   pop();
		void   push(int new_value);
	private:
		/* whatever you want */
		int		*data;
		size_t	length;
		uint32_t	front;
		uint32_t	back;
};

#endif //_SIMPLE_CBUF_
