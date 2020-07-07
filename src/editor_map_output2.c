#include "proto_global.h"

//OKK
char *join_int_value(int val1, char *separator, int val2)
{
    char *str;

    str = ft_itoa(val1);
    str = ft_strjoinfree(str, separator, 0);
    str = ft_strjoinfree(str, ft_itoa(val2), 0);
    return (str);
}

char *join_float_value(float val1, char *separator, float val2)
{
    char *str;

    str = ft_ftoa(val1, p_malloc(3), 3);
    str = ft_strjoinfree(str, separator, 0);
    str = ft_strjoinfree(str, ft_ftoa(val2, p_malloc(3), 3), 0);
    return (str);
}

void	write_key(int fd, char *key)
{
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(key, fd);
	ft_putchar_fd(' ', fd);
}

void write_param(int fd, char *key, char *value)
{
    char *str;

    str = ft_strjoin(key, " : ");
    str = ft_strjoinfree(str, value, 0);
    str = ft_strjoinfree(str, " ; ", 0);
	ft_putstr_fd(str, fd);
    free(value);
    free(str);
}

void write_head_param(int fd, char *key, char *value)
{
    ft_putstr_fd(key, fd);
    ft_putchar_fd(' ',fd);
    ft_putstr_fd(value, fd);
    ft_putchar_fd('\n',fd);
}