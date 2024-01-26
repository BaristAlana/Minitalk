/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_phex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:35:53 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/26 16:04:44 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_hex(unsigned long long hx, int input, int count)
{
	char		*hx_b;
	int			i;
	static int	ret;

	if (count == 0)
		ret = 0;
	if (input == 0)
		hx_b = "0123456789abcdef";
	else
		hx_b = "0123456789ABCDEF";
	if (hx >= 16)
	{
		count++;
		ft_itoa_hex(hx / 16, input, 1);
	}
	i = hx % 16;
	ret += (int) write(1, &hx_b[i], 1);
	return (ret);
}

int	ft_print_p(unsigned long arg)
{
	if (!arg)
		return (ft_print_s("(nil)"));
	ft_putstr_fd("0x", 1);
	return (ft_itoa_hex(arg, 0, 0) + 2);
}
