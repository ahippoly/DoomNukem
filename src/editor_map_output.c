#include "global_header.h"
#include "editor.h"

void map_output(t_env *env)
{
    int fd;
    int i;
    char *str;

    i = 0;
    printf("map output fct\n");
    while ((fd = open(str = ft_strjoinfree("maps/editor_map_", ft_itoa(i), 1), O_WRONLY | O_CREAT | O_EXCL)) == -1)
    {
        free(str);
        i++;
    }
    printf("map output name = %s\n",str);
    free(str);
}