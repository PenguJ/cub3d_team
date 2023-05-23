/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:17:21 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/23 18:14:25 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE (1)

typedef enum e_state
{
	failure = 0,
	success = 1,
}	t_state;

typedef struct s_list
{
	void			*dat;
	struct s_list	*next;
}					t_list;

typedef struct s_doubly_list
{
	void					*dat;
	struct s_doubly_list	*next;
	struct s_doubly_list	*prev;
}				t_dlist;

typedef struct s_stack
{
	t_list	*top;
}				t_stk;

typedef struct s_queue
{
	t_list	*head;
	t_list	*tail;
}				t_que;

typedef struct s_deque
{
	t_dlist	*head;
	t_dlist	*tail;
}				t_dque;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t num);
void	ft_bzero(void *str, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t num);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t num);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t num);
int		ft_memcmp(const void *s1, const void *s2, size_t num);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_stkinit(t_stk *s);
int		ft_stkisempty(t_stk *s);
t_stk	*ft_stkpush(t_stk *s, void *dat);
void	*ft_stkpop(t_stk *s);
void	ft_queinit(t_que *q);
int		ft_queisempty(t_que *q);
t_que	*ft_quepush(t_que *q, void *dat);
void	*ft_quepop(t_que *q);
void	ft_dqueinit(t_dque *dq);
int		ft_dqueisempty(t_dque *dq);
t_dque	*ft_dquepush_front(t_dque *dq, void *dat);
t_dque	*ft_dquepush_back(t_dque *dq, void *dat);
void	*ft_dquepop_front(t_dque *dq);
void	*ft_dquepop_back(t_dque *dq);
char	get_next_line(int fd, char **ret);
void	*ft_delsplit(char **strings);
void	*ft_allocerr(void);
char	**ft_rectangle_split(char const *s, char c);

#endif
