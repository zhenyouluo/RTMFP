
#include <stdint.h>
#include <stdlib.h>
#include <iostream>

uint16_t
add_mod(uint16_t p1, uint16_t p2, uint16_t mod)
{
	uint16_t	tmp = (p1 + mod - p2) % mod;
	return tmp;
	//return (p1 + (mod - p2)) % mod;
}

uint16_t
mod_p2(uint16_t p1, uint16_t p2, uint16_t mod)
{
	uint16_t	tmp = (p1 + (mod - p2)) % mod;
	return tmp;
}

uint16_t
raw(uint16_t p1, uint16_t p2, uint16_t mod)
{
	uint16_t	tmp = (p1 - p2) % mod;
	return tmp;
}

int
main(int argc, char *argv[])
{
	if(argc != 4){
		std::cout<<"usage: a.out p1 p2 mod"<<std::endl;
	}
	uint16_t	p1 = atoi(argv[1]);
	uint16_t	p2 = atoi(argv[2]);
	uint16_t	mod = atoi(argv[3]);

	std::cout<<raw(p1, p2, mod)<<std::endl<<std::endl;
	std::cout<<add_mod(p1, p2, mod)<<std::endl<<std::endl;
	std::cout<<mod_p2(p1, p2, mod)<<std::endl<<std::endl;

	return 0;
}
