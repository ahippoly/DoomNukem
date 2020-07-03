#include "libft.h"
#include <stdlib.h>

void    *p_malloc(unsigned int size)
{
    void    *data;
    if (!(data = malloc(size)))
    {
        ft_putstr("Failed to malloc");
        // exit(1);
		return (NULL);
    }
    return (data);
}