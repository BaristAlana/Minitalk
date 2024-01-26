/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:42:34 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:14:38 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(s);
	tmp = (char *) &s[len];
	while (len > 0)
	{
		if (*tmp == (char) c)
			return (tmp);
		--len;
		--tmp;
	}
	tmp = (char *) s;
	if (*tmp == (char) c)
		return (tmp);
	return (NULL);
}
