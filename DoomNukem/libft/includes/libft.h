/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:53:59 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 18:18:30 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 8

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memalloc(size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memdel(void **ap);
void			*ft_memset(void *s, int i, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **as);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t nb);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t nb);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *s));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s1, char (*f)(char));
char			*ft_strmapi(const char *s1, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s1, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char*s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(int nb);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **link, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t			ft_lstsize(t_list *lst);
void			ft_lstmerge(t_list **alst1, t_list *alst2);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_putnbr_base(int nb, char *base);
int				ft_atoi_base(char *str, char *base);
void			ft_putnbr_base_fd(int nb, char *base, int fd);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
t_list			*ft_create_elem(void *content);
void			ft_list_push_back(t_list **begin_list, void *content);
int				get_next_line(int const fd, char **line);
char			*ft_strfjoin(const char *s1, const char *s2, int choose);
int				ft_tablen(char **tab);
int				ft_isbetween(double a, double low, double hight);
double			ft_abs(double n);
void			ft_tabfree(char **tab);
double			ft_max(double a, double b);
double			ft_min(double a, double b);

#endif
