#include "proto_global.h"

uint16_t	swap2(uint16_t x)
{
	return ((x >> 8) | (x << 8));
}

uint32_t	swap4(uint32_t x)
{
	uint32_t	n1;
	uint32_t	n2;

	n1 = ((x >> 24) & 0xFF) | ((x << 8) & 0xFF0000);
	n2 = ((x >> 8) & 0xFF00) | ((x << 24) & 0xFF000000);
	return (n1 | n2);
}