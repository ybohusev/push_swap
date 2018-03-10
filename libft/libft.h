/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:56:02 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/06 09:27:43 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>
# include <unistd.h>
# include "get_next_line.h"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(char *str);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(char *src);
size_t				ft_strlen(char *str);
char				*ft_strncpy(char *dest, const char *src, size_t num);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putchar(char c);
int					ft_putstr(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(int n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
void				*ft_memalloc(size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_sqrt(int nb);
char				*ft_itoa_base(uintmax_t n, int base);
int					ft_putwchar(unsigned int a);
int					ft_count_octets(unsigned int a);
char				*ft_itoa_large(intmax_t n);
int					ft_putwstr(wchar_t *wstr);
size_t				ft_wstrsize(wchar_t *wstr);
size_t				ft_wstrlen(wchar_t *wstr);
wchar_t				*ft_wstrsub(wchar_t const *s, unsigned int start,
								size_t len);
wchar_t				*ft_wstrnew(size_t size);
wchar_t				*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2);
wchar_t				*ft_wstrset(wchar_t *b, int c, size_t n);

#endif
