/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:13:09 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/14 20:07:34 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char    *read_map(char *filename)
{
    int     fd;
    int     ret;
    char    *map;
    char    buff[BUFF_SIZE + 1];

    if ((fd = open(filename, O_RDONLY)) == -1)
        errorcase();
    if (!(map = (char*)malloc(sizeof(char))))
        errorcase();
    map[0] = '\0';
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[ret] = 0;
        if (!(map = ft_strjoinfree(map, buff, 1)))
            errorcase();
    }
    if (ret == -1)
        errorcase();
    return (map);
}

int skip_space(char *map, int i)
{
	while (map[i] == ' ')
		i++;
	return (i);
}

int skip_char(char *map, int i)
{
	while (map[i] && map[i] != ' ' && map[i] != '\n')
		i++;
	return (i);
}

int count_x(char *map, int i)
{
	int x;

	x = 0;
	i = skip_space(map, i);
	while (map[i] && map[i] != '\n')
	{
		i = skip_char(map, i);
		i = skip_space(map, i);
		x++;
	}
	return (x);
}

t_vox count_size2(char *map)
{
	int i;
	t_vox size;

	i = 0;
	size.x = 0;
	size.y = 0;
	i = skip_space(map, i);
	size.z = skip_char(map, i) - i;
	printf("size z = %f\n", size.z);
	size.x = count_x(map, i);
	printf("size x = %f\n", size.x);
	while (map[i])
	{
		while (map[i] != '\n' && map[i])
			i++;
		i++;
		size.y++;
	}
	return (size);
}

char ***alloc_voxmap(t_vox size)
{
	char ***tab;
	int i;
	int j;

	i = 0;
	if (!(tab = (char***)malloc(sizeof(char**) * size.x)))
        errorcase();
	while (i < size.x)
	{
		j = 0;
		if (!(tab[i] = (char**)malloc(sizeof(char*) * size.y)))
			errorcase();
		while (j < size.y)
		{
			if (!(tab[i][j] = (char*)malloc(sizeof(char) * size.z)))
				errorcase();
			j++;
		}
		i++;
	}
	return (tab);
}

void fill_map2(char *map, t_vox size, char ***tab)
{
	int i;
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	printf("size : x = %f, y = %f, z = %f\n",size.x, size.y, size.z);
	i = skip_space(map, i);
	while (map[i])
	{
		x = 0;
			printf("z : ");
		while (map[i] != '\n' && x < size.x)
		{
			z = 0;
			while (map[i] != ' ' && map[i] != '\n' && map[i] && z < size.z)
				tab[x][y][z++] = map[i++] - 48;
//			printf("%i,%i ",tab[x][y][z - 1], map[i - 1]);
//			printf("%i ",map[i - 1]);
			printf("x%i y%i z%i  ",x,y,z);
			while (z < size.z)
				tab[x][y][z++] = 0;
			i = skip_space(map, i);
			x++;
			
		}
		while (x < size.x)
		{
			z = 0;
			while (z < size.z)
				tab[x][y][z++] = 0;
			x++;
		}
		while (map[i] && map[i] != '\n')
			i++;
		i++;
		printf("\n");
		
		y++;
	
	}
}

char ***readfile2(char *file, t_var *v)
{
	char *map;
	char ***tab;
	
	printf("BEGIN readfile\n");
	map = read_map(file);
	printf("ALL MAP BELOW :\n%s\nEND OF READ\n",map);
	v->map_size = count_size2(map);
	printf("MAP SIZE COUNTED : x = %f, y = %f , z = %f\n",v->map_size.x,v->map_size.y,v->map_size.z);
	tab = alloc_voxmap(v->map_size);
	fill_map2(map, v->map_size, tab);
	free(map);
	return (tab);
}
