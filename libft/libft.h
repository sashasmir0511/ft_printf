/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:33:08 by lhaired           #+#    #+#             */
/*   Updated: 2019/10/09 13:50:35 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
void			ft_bzero(void *b, size_t n);
int				ft_atoi(const char *str);
void			*ft_dup(void const *content, size_t content_size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_isspace(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *str);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s);
unsigned int	ft_strnumfirstchar(char *str, const char *charset);
unsigned int	ft_strnumlastchar(char *str, const char *charset);
void			ft_putchar(char c);
void			ft_putstr(char *c);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
char			*ft_strdup(const char *s);
void			*ft_dup(void const *content, size_t content_size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *c, int fd);
void			ft_putendl_fd(char const *c, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *str, char c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_strncpy(char *dest, const char *src, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_numaddone(int n);
int				ft_numsubone(int n);
unsigned int	ft_strnumfirstchar(char *str, const char *charset);
unsigned int	ft_strnumlastchar(char *str, const char *charset);
char			*ft_itoa_long(long nbr);
char			*ft_itoa_longlong(long long nbr);
char			*ft_itoa_unsigned(size_t nbr);
char			*ft_itoa_base_unsigned(size_t nbr, int base);
char			*ft_itoa_base(unsigned int nbr, int base);
char			*ft_strjoin_free(char *s1, char *s2, int indx);
char			*ft_ftoa(double nbr, unsigned int precision);
char			*ft_ftoa_long(long double nbr, unsigned int precision);
void			ft_swap(char *c1, char *c2);
int				ft_iszero(char *str);

#endif
