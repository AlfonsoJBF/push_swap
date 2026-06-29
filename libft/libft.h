/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 02:21:13 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 18:46:03 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//Types
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

// String.h
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *ptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *litle, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *S, unsigned int start, size_t len);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// FILE DESCRIPTORS
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// General utilites
int		ft_count_words(char *str);
char	**ft_split(const char *s, char c);

// LINKED LISTS
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// PRINTF 
int		ft_printf(char const *format, ...);
int		ft_printf_error(char const *format, ...);
int		ft_putstring(char *string);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_base_un(unsigned int nbr, char *base);
int		ft_putnbr_base_ptr(unsigned long nbr, char *base);
int		ft_putpointer(void *ptr);
int		ft_putstring_err(char *string);
int		ft_putnbr_base_err(int nbr, char *base);
int		ft_putnbr_base_un_err(unsigned int nbr, char *base);
int		ft_putnbr_base_ptr_err(unsigned long nbr, char *base);
int		ft_putpointer_err(void *ptr);

// GNL

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strdup(const char *s);

#endif
