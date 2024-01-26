/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:26:39 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:14:16 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (size < i)
		j += size;
	else
		j += i;
	while (*src && (i < (size - 1)) && size != 0)
	{
		dest[i] = *src;
		++i;
		++src;
	}
	dest[i] = 0;
	return (j);
}
