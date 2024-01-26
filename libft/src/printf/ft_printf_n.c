/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:35:20 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/26 16:04:31 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_n(long arg)
{
	char	*str_n;
	int		i;

	str_n = ft_itoa(arg);
	i = ft_strlen(str_n);
	ft_putstr_fd(str_n, 1);
	free(str_n);
	return (i);
}
