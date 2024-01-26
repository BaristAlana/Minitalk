/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:29:49 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/26 16:05:05 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv(const char identifier, va_list args)
{
	if (identifier == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (identifier == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (identifier == 'd' || identifier == 'i')
		return (ft_print_n((long) va_arg(args, int)));
	else if (identifier == 'u')
		return (ft_print_u((unsigned int) va_arg(args, unsigned int)));
	else if (identifier == 'p')
		return (ft_print_p(va_arg(args, unsigned long)));
	else if (identifier == 'x')
		return (ft_itoa_hex(va_arg(args, unsigned int), 0, 0));
	else if (identifier == 'X')
		return (ft_itoa_hex(va_arg(args, unsigned int), 1, 0));
	else if (identifier == '%')
		return (ft_print_c('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		check_conv;
	int		i;

	i = 0;
	ret = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			ret += ft_print_c(format[i]);
		else
		{
			check_conv = ft_conv(format[++i], args);
			if (check_conv == -1)
				return (-1);
			ret += check_conv;
		}
		++i;
	}
	va_end(args);
	return (ret);
}

/*int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		check_conv;
	int		i;

	i = 0;
	ret = 0;
	check_conv = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_conv = ft_conv(format[++i], args);
			if (check_conv == -1)
				return (-1);
			ret += check_conv;
		}
		else
			ret += ft_print_c(format[i]);
		++i;
	}
	va_end(args);
	return (ret);
}
*/
