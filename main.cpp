
#include <iostream>
#include "simple_cbuf.h"

struct foo
{
	int		i;
	double	d;
	char	c;
	bool	b;
};

int
main(int argc, char *argv[])
{
	simple_cbuf<foo>	buf(47);
	srand(time(NULL));
	for(int i = 0; i < 1024; i++){
		foo	f;
		f.d = rand();
		buf.push(f);
	}
	size_t	j = 0;
	simple_cbuf<foo>	cuf = buf;
	simple_cbuf<foo>	duf = buf;
	while(buf.size() > 0){
		std::cout<<buf.top().d<<std::endl;
		buf.pop();
	}
	std::cout<<"---------------"<<std::endl;
	while(cuf.size()){
		std::cout<<cuf.top().d<<std::endl;
		cuf.pop();
	}
	std::cout<<"---------------"<<std::endl;
	for(j = 0; j < duf.size(); j++)
		std::cout<<duf[j].d<<std::endl;

	return 0;
}
