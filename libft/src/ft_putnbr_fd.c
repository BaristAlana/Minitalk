/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:07:37 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:13:48 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char		c;

	if (nb == -2147483647)
		ft_putstr_fd("-2147483647", fd);
	else if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar_fd('-', fd);
		}
		if (nb > 9)
			ft_putnbr_fd(nb / 10, fd);
		c = '0' + nb % 10;
		ft_putchar_fd(c, fd);
	}
}
