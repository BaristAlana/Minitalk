/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:36:14 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/20 12:28:49 by aherbin          ###   ########.fr       */
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

void	sig_printf(int signum, siginfo_t *info, void *ucontent)
{
	static int	i;
	static char	bit;

	(void)ucontent;
	if (signum == 0)
	{
		i = 0;
		bit = 0;
		return ;
	}
	if (signum == 12)
		++i;
	if (signum == 10)
	{
		bit += 1 << (7 - i);
		++i;
	}
	if (i == 8)
	{
		if (bit == 0)
			write(1, "\n", 1);
		else
			write(1, &bit, 1);
		i ^= i;
		bit ^= bit;
		kill(info->si_pid, SIGUSR2); //BYTE received, keep sending
	}
	kill(info->si_pid, SIGUSR1); //bit received, keep sending
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &sig_printf;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		return ;
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		return ;
}


/*void	loop_handler(void)
{
	sig_printf(0, NULL, NULL);
	signal(SIGUSR1, &sig_printf);
	signal(SIGUSR2, &sig_printf);
	while (1)
		pause();
}*/

int	main(void)
{
	ft_print_header((int) getpid());
	sig_printf(0, NULL, NULL);
	//loop_handler();
	while (1)
		config_signals();
	return (0);
}


/*
void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Failed to send SIGUSR1");
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n\n", pid);
	while (1)
		config_signals();
	return (EXIT_SUCCESS);
}*/
