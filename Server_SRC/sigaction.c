/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:36:14 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/14 15:52:03 by aherbin          ###   ########.fr       */
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

void	sig_printf(int signum)
{
	static int	i;
	static char	bit;

	if (signum == 0)
	{
		i = 0;
		bit = 0;
	}
	if (signum == 12)
	{
		//write(STDOUT_FILENO, "0", 2);
		++i;
	}
	if (signum == 10)
	{
		bit += 1 << (7 - i);
		//write(STDOUT_FILENO, "1", 2);
		++i;
	}
	if (i == 8)
	{
		ft_printf("%c", bit);
		i = 0;
		bit = 0;
	}
}

void	loop_handler(void)
{
	sig_printf(0);
	signal(SIGUSR1, &sig_printf);
	signal(SIGUSR2, &sig_printf);
	while (1)
		pause();
}

int	main(void)
{
	ft_print_header((int) getpid());
	loop_handler();
	return (0);
}

 ██████╗███████╗ ██████╗██╗    ███████╗███████╗████████╗    ██╗   ██╗███╗   ██╗    ████████╗███████╗███████╗████████╗
██╔════╝██╔════╝██╔════╝██║    ██╔════╝██╔════╝╚══██╔══╝    ██║   ██║████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
██║     █████╗  ██║     ██║    █████╗  ███████╗   ██║       ██║   ██║██╔██╗ ██║       ██║   █████╗  ███████╗   ██║
██║     ██╔══╝  ██║     ██║    ██╔══╝  ╚════██║   ██║       ██║   ██║██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║
╚██████╗███████╗╚██████╗██║    ███████╗███████║   ██║       ╚██████╔╝██║ ╚████║       ██║   ███████╗███████║   ██║
 ╚═════╝╚══════╝ ╚═════╝╚═╝    ╚══════╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
 ██████╗███████╗ ██████╗██╗    ███████╗███████╗████████╗    ██╗   ██╗███╗   ██╗    ████████╗███████╗███████╗████████╗
██╔════╝██╔════╝██╔════╝██║    ██╔════╝██╔════╝╚══██╔══╝    ██║   ██║████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
██║     █████╗  ██║     ██║    █████╗  ███████╗   ██║       ██║   ██║██╔██╗ ██║       ██║   █████╗  ███████╗   ██║
██║     ██╔══╝  ██║     ██║    ██╔══╝  ╚════██║   ██║       ██║   ██║██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║
╚██████╗███████╗╚██████╗██║    ███████╗███████║   ██║       ╚██████╔╝██║ ╚████║       ██║   ███████╗███████║   ██║
 ╚═════╝╚══════╝ ╚═════╝╚═╝    ╚══════╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
  ██████╗███████╗ ██████╗██╗    ███████╗███████╗████████╗    ██╗   ██╗███╗   ██╗    ████████╗███████╗███████╗████████╗
██╔════╝██╔════╝██╔════╝██║    ██╔════╝██╔════╝╚══██╔══╝    ██║   ██║████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
██║     █████╗  ██║     ██║    █████╗  ███████╗   ██║       ██║   ██║██╔██╗ ██║       ██║   █████╗  ███████╗   ██║
██║     ██╔══╝  ██║     ██║    ██╔══╝  ╚════██║   ██║       ██║   ██║██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║
╚██████╗███████╗╚██████╗██║    ███████╗███████║   ██║       ╚██████╔╝██║ ╚████║       ██║   ███████╗███████║   ██║
 ╚═════╝╚══════╝ ╚═════╝╚═╝    ╚══════╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
  ██████╗███████╗ ██████╗██╗    ███████╗███████╗████████╗    ██╗   ██╗███╗   ██╗    ████████╗███████╗███████╗████████╗
██╔════╝██╔════╝██╔════╝██║    ██╔════╝██╔════╝╚══██╔══╝    ██║   ██║████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
██║     █████╗  ██║     ██║    █████╗  ███████╗   ██║       ██║   ██║██╔██╗ ██║       ██║   █████╗  ███████╗   ██║
██║     ██╔══╝  ██║     ██║    ██╔══╝  ╚════██║   ██║       ██║   ██║██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║
╚██████╗███████╗╚██████╗██║    ███████╗███████║   ██║       ╚██████╔╝██║ ╚████║       ██║   ███████╗███████║   ██║
 ╚═════╝╚══════╝ ╚═════╝╚═╝    ╚══════╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
  ██████╗███████╗ ██████╗██╗    ███████╗███████╗████████╗    ██╗   ██╗███╗   ██╗    ████████╗███████╗███████╗████████╗
██╔════╝██╔════╝██╔════╝██║    ██╔════╝██╔════╝╚══██╔══╝    ██║   ██║████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
██║     █████╗  ██║     ██║    █████╗  ███████╗   ██║       ██║   ██║██╔██╗ ██║       ██║   █████╗  ███████╗   ██║
██║     ██╔══╝  ██║     ██║    ██╔══╝  ╚════██║   ██║       ██║   ██║██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║
╚██████╗███████╗╚██████╗██║    ███████╗███████║   ██║       ╚██████╔╝██║ ╚████║       ██║   ███████╗███████║   ██║
 ╚═════╝╚══════╝ ╚═════╝╚═╝    ╚══════╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
  ██████╗███████╗ ██████╗██╗    ███████╗███████╗████████╗    ██╗   ██╗███╗   ██╗    ████████╗███████╗███████╗████████╗
██╔════╝██╔════╝██╔════╝██║    ██╔════╝██╔════╝╚══██╔══╝    ██║   ██║████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
██║     █████╗  ██║     ██║    █████╗  ███████╗   ██║       ██║   ██║██╔██╗ ██║       ██║   █████╗  ███████╗   ██║
██║     ██╔══╝  ██║     ██║    ██╔══╝  ╚════██║   ██║       ██║   ██║██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║
╚██████╗███████╗╚██████╗██║    ███████╗███████║   ██║       ╚██████╔╝██║ ╚████║       ██║   ███████╗███████║   ██║
 ╚═════╝╚══════╝ ╚═════╝╚═╝    ╚══════╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝