/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:36:14 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/01 22:59:06 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>
#include <aio.h>

static void	ft_print_header(int pid)
{
	ft_printf("\033[38;5;42m\n\
                                                              \n \
███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗ \n \
████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝ \n \
██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝  \n \
██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗  \n \
██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗ \n \
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ \n\033[0m");
	ft_printf("\n\n  \033[38;5;42;4;3;1m\t\tPID: %i\t\
by: aherbin\n\n\033[0m", pid);
	ft_printf("\033[38;5;125m \
════════════════════════════════════════════════════════════\n\n\n\033[0m");
}

unsigned char	bit;
int				i;

void	sig_printf(int signum)
{
	unsigned char	c;

	c = 0b10000000;
	if (signum == 12)
	{
		write(STDOUT_FILENO, "0", 2);
		++i;
	}
	if (signum == 10)
	{
		bit |= c >> i;
		write(STDOUT_FILENO, "1", 2);
		++i;
	}
}

void	loop_handler(void)
{

	bit = 0;
	i = 0;

	signal(SIGUSR1, &sig_printf);
	signal(SIGUSR2, &sig_printf);
	while (1)
	{
		pause();
		if (i == 8)
		{
			if (bit == 0)
			{
				write(1, "\n", 1);
				//exit(0);
			}
			ft_printf(" : %c\n", bit);
			i = 0;
			bit = 0;
		}
	}
}

int	main(void)
{
	ft_print_header((int) getpid());
	loop_handler();
	return (0);
}
