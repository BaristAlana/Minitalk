/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:43:51 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/26 17:01:35 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* ************************************************************************** */
/*                                general ft                                  */
/* ************************************************************************** */

int		ft_isprint(int c);

int		ft_isdigit(int c);

int		ft_isascii(int c);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

size_t	ft_strlen(const char *str);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dest, char *src, size_t size);

size_t	ft_strlcat(char *dest, char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memrchr(const void *s, int c, size_t n);

int		ft_atoi(char *str);

char	*ft_strdup(const char *s);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *str, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	**ft_split(char const *s, char c);

/* ************************************************************************** */
/*                               linked list ft                               */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new_node);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new_node);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************** */
/*                                 ft_printf                                  */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);

int		ft_conv(const char identifier, va_list args);

int		ft_print_c(char arg);

int		ft_print_s(char *arg);

int		ft_print_n(long int arg);

int		ft_itoa_hex(unsigned long long hx, int input, int count);

int		ft_print_u(unsigned int arg);

int		ft_print_p(unsigned long arg);

/* ************************************************************************** */
/*                               Get_Next_Line                                */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef MAX_FD
#  define MAX_FD 64
# endif

char	*get_next_line(int fd);

#endif
