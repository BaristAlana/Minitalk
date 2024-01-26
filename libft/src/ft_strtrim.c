/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:08:02 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:14:43 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ispartofset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;
	int		i;
	char	*retstr;

	beg = 0;
	end = ft_strlen(s1) - 1;
	while (ispartofset(s1[beg], set) == 1)
		++beg;
	while (ispartofset(s1[end], set) == 1)
		--end;
	if (end <= 0 || end <= beg)
		return (ft_strdup(""));
	retstr = (char *)malloc(sizeof(char) * (end - beg + 2));
	if (!retstr)
		return (NULL);
	i = 0;
	while (beg <= end)
		retstr[i++] = s1[beg++];
	retstr[i] = 0;
	return (retstr);
}
