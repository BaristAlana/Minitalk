/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:36:14 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/01 02:59:20 by aherbin          ###   ########.fr       */
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
	if (signum == 12)
	{
		bit >>= 1;
		write(STDOUT_FILENO, "0", 2);
		++i;
	}
	if (signum == 10)
	{
		bit |= 1;
		bit >>= 1;
		write(STDOUT_FILENO, "1", 2);
		++i;
	}
}

void	loop_handler(void)
{

	bit = 0b10000000;

	signal(SIGUSR1, &sig_printf);
	signal(SIGUSR2, &sig_printf);
	while (1)
	{
		pause();
		if (i == 8)
		{
			i = 0;
			ft_printf("\n%c\n", bit);
			bit = 0b10000000;
		}
		if (bit == 126)
			exit(0);
	}
}

int	main(void)
{
	i = 0;
	ft_print_header((int) getpid());
	loop_handler();
	return (0);
}


// TODO: look for a "start of text" (STX, 02 in ascii) char before printing the string
// if last char received
