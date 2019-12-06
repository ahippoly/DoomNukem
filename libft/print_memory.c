/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:40:29 by exam              #+#    #+#             */
/*   Updated: 2019/03/21 12:16:15 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void putc(unsigned char c)
{
	write(1,&c,1);
}

static void print_hexa(unsigned char c)
{
	if (c > 9)
		putc(c + 87);
	else
		putc(c + 48);
}

void print_memory(const void *addr, size_t size)
{
	size_t i = 0;
	size_t bloc = 0;
	size_t step = 16;
	unsigned char *mem;
	mem = (unsigned char *)addr;
	while (i < size)
	{
		step = 16;
		while (step)
		{
			step--;
			if (i < size)
			{
				print_hexa(mem[bloc] / 16);
				print_hexa(mem[bloc] % 16);
			}
			else
				write(1,"  ",2);
			i++;
			bloc++;
			if (bloc && bloc % 2 == 0)
				write(1," ",1);
			
		}
		step = 16;
		i -= 16;
		while (step)
		{
			step--;
			if (i < size)
			{
				if (mem[i] > 31 && mem[i] < 127)
					putc(mem[i]);
				else
					putc('.');
			}
			i++;
		}
		write(1,"\n",1);	
	}
}
