/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:15:17 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:13:31 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	get_len(long n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static void	*memalloc(int sign, int len, char *str)
{
	if (sign == -1)
	{
		str = (char *)malloc(sizeof(char) * len + 2);
		if (!str)
			return (NULL);
		str[0] = '-';
		str[len + 1] = 0;
	}
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	long	nbr;
	char	*str;

	nbr = n;
	str = NULL;
	sign = get_sign(nbr);
	if (sign < 0)
		nbr *= -1;
	len = get_len(nbr);
	str = memalloc(sign, len, str);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		if (sign < 0)
			str[len] = (nbr % 10) + 48;
		else
			str[len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		--len;
	}
	return (str);
}
