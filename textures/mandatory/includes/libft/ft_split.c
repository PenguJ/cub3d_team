/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:30:26 by jeojeon           #+#    #+#             */
/*   Updated: 2022/12/03 17:20:12 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_arr_size(char *str, char sep)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && (*str == sep))
			str++;
		if (*str)
			cnt++;
		while (*str && (*str != sep))
			str++;
	}
	return (cnt);
}

static char	*ft_word_dup(char *str, char sep)
{
	char	*tmp;
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && (str[word_len] != sep))
		word_len++;
	tmp = (char *)ft_calloc(word_len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str, word_len + 1);
	return (tmp);
}

static char	**ft_null_guard(char **arr, size_t i)
{
	if (i > 0)
		while (i--)
			free(arr[i]);
	free(arr);
	return (ft_allocerr());
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (!s)
		arr = (char **)ft_calloc(1, sizeof(char *));
	else
		arr = (char **)ft_calloc(ft_arr_size((char *)s, c) + 1, sizeof(char *));
	if (!arr)
		return (ft_allocerr());
	while (s && *s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			arr[i] = ft_word_dup((char *)s, c);
			if (!arr[i])
				return (ft_null_guard(arr, i));
			i++;
		}
		while (*s && (*s != c))
			s++;
	}
	return (arr);
}
