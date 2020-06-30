#include "proto_global.h"

int	ft_short(unsigned char *nb)
{
	return ((nb[0] << 8) | (nb[1]));
}

int	ft_int(unsigned char *nb)
{
	return ((nb[0] << 24) | (nb[1] << 16) | (nb[2] << 8) | (nb[3]));
}