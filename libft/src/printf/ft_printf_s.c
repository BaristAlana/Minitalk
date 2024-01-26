/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:34:59 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/26 16:04:51 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_s(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (arg[i])
		ft_print_c(arg[i++]);
	return (i);
}
