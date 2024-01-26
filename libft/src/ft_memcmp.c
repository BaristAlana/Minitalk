/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:55:36 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:13:16 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*membloc1;
	unsigned char	*membloc2;

	membloc1 = (unsigned char *) s1;
	membloc2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (membloc1[i] != membloc2[i])
			return (membloc1[i] - membloc2[i]);
		++i;
	}
	return (0);
}
