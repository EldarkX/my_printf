/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantropo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:32:54 by aantropo          #+#    #+#             */
/*   Updated: 2018/11/22 12:49:31 by aantropo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct		s_format
{
	char 			*string;
	char            *flags;
	int				width;
	int				precision;
	char 			type;
	enum			e_mod
	{
		l,  //0
		ll, //1
		h,  //2
		hh, //3
		j,  //4
		z,  //5
		y,  //6
		L   //7
	}				mod;
}					t_format;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);

size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *sub_str);
char				*ft_strnstr(const char *str,
						const char *sub_str, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				ft_swap(int *a, int *b);
int					ft_str_is_alpha(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_uppercase(char *str);
char				*ft_str_to_upper(char *str);
char				*ft_str_to_lower(char *str);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src,
						int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelelem(void *lst_elem, size_t elem_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_printf(const char *format, ...);
char                ft_set_type(char *str, int *i, int *end_i);
char                *ft_set_flags(char *str, int format_start, int format_end);
int     			ft_set_width(char *str, int format_start, int format_end,
						va_list args);
int     			ft_set_precision(char *str, int format_start, int format_end,
						va_list args);
int					ft_digit_cnt_base(intmax_t nbr, int base);
int    				ft_set_mod(char *str, int format_start, int format_end);
char 				*ft_itoa_base(intmax_t nbr, int base);
intmax_t			ft_pow(intmax_t nbr, int pow);
void				ft_take_arg(va_list args, t_format *format);

#endif
