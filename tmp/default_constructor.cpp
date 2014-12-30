
#include <iostream>

struct foo
{
	/*
	foo() {};
	foo(const foo&) = default;
	*/
	int	mem;
};

/*
foo::foo()
{
	mem = 5;
}*/

int
main(int argc, char *argv[])
{
	foo	f;
	f.mem = 5;
	foo g(f);
	foo h = g;
	std::cout<<h.mem<<std::endl;
	return 0;
}
