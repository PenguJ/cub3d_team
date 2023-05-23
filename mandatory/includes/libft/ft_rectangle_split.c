/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:04:23 by jeojeon           #+#    #+#             */
/*   Updated: 2023/05/23 18:23:28 by jeojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_sizes(char *str, char sep, size_t *out_max_len)
{
	size_t	cnt;
	size_t	tmp_len;

	cnt = 0;
	while (*str)
	{
		while (*str && (*str == sep))
			++str;
		if (*str)
			++cnt;
		tmp_len = 0;
		while (*str && (*str != sep))
		{
			++str;
			++tmp_len;
		}
		if (tmp_len > *out_max_len)
			*out_max_len = tmp_len;
	}
	return (cnt);
}

static char	*ft_word_dup(char *str, char sep, size_t max_len)
{
	char	*tmp;
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && (str[word_len] != sep))
		word_len++;
	tmp = (char *)ft_calloc(max_len + 1, sizeof(char));
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

static char	**alloc_arr(char *s, char c, size_t *max_len)
{
	char	**ret;

	ret = NULL;
	if (!s)
		ret = (char **)ft_calloc(1, sizeof(char *));
	else
		ret = (char **)ft_calloc(get_sizes((char *)s, c, max_len) + 1, \
								sizeof(char *));
	return (ret);
}

char	**ft_rectangle_split(char const *s, char c)
{
	char	**arr;
	size_t	max_len;
	size_t	i;

	arr = alloc_arr((char *)s, c, &max_len);
	if (!arr)
		return (NULL);
	i = 0;
	while (s && *s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			arr[i] = ft_word_dup((char *)s, c, max_len);
			if (!arr[i])
				return (ft_null_guard(arr, i));
			i++;
		}
		while (*s && (*s != c))
			s++;
	}
	return (arr);
}
