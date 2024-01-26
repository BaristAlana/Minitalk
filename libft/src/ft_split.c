/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:10:20 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:13:55 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	control;
	size_t	wc;

	i = 0;
	control = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c && control == 0)
		{
			++wc;
			control = 1;
		}
		else if (s[i] == c)
			control = 0;
		++i;
	}
	return (wc);
}

static void	*freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
	return (NULL);
}

static char	*ft_putword(int start, int end, const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (str[start] != c && start <= end)
	{
		word[i] = str[start];
		++start;
		++i;
	}
	word[i] = 0;
	return (word);
}

static char	**ft_fill_arr(const char *s, char c, char **arr)
{
	size_t	i;
	int		j;
	int		start_word;

	i = 0;
	j = 0;
	start_word = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			arr[j] = ft_putword(start_word, i, s, c);
			if (!arr[j])
				return (freeall(arr));
			++j;
			start_word = -1;
		}
		++i;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_fill_arr(s, c, arr));
}
