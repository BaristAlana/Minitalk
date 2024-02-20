/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:33:59 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/20 16:21:58 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_print(int signum, siginfo_t *info, void *ucontent);

static void	print_header(int pid)
{
	write(1, "\033[38;5;42m\n\
                                                              \n \
███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗ \n \
████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝ \n \
██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝  \n \
██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗  \n \
██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗ \n \
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ \n\
\033[0m", 1018);
	write(1, "\n\n\t\t\t\033[38;5;42;4;3;1mPID: ", 27);
	ft_putnbr_fd(pid, 1);
	write(1, " \033[0m", 6);
	write(1, "\n\n\033[38;5;125m \
════════════════════════════════════════════════════════════ \
\n\n\n\033[0m", 203);
}

static void	print_char(char c, int i, int pid)
{
	write(1, &c, 1);
	if (i == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit (1);
	}
	if (i == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit (1);
	}
	sig_print(0, NULL, NULL);
}

static void	sig_print(int signum, siginfo_t *info, void *ucontent)
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
	usleep(100);
	if (i == 8)
	{
		if (bit == 0)
			return (print_char('\n', 0, info->si_pid));
		return (print_char(bit, 1, info->si_pid));
	}
	kill(info->si_pid, SIGUSR1);
}

static void	sig_init(void)
{
	struct sigaction	server_sig;

	sigemptyset(&server_sig.sa_mask);
	sigaddset(&server_sig.sa_mask, SIGUSR1);
	sigaddset(&server_sig.sa_mask, SIGUSR2);
	server_sig.sa_sigaction = &sig_print;
	server_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &server_sig, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &server_sig, NULL) == -1)
		exit(2);
}

int	main(void)
{
	sig_init();
	print_header((int) getpid());
	sig_print(0, NULL, NULL);
	while (1)
		pause();
	return (0);
}
