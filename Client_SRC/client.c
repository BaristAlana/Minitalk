/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:25 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/15 12:08:12 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	send_char_to_server(unsigned char c, __pid_t server_pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return (0);
		}
		bit >>= 1;
		usleep(100); // replace by sig_aknowledgement from server
	}
	return (1);
}

int	str_to_c(__pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (send_char_to_server(str[i], pid) == 0)
			return (0);
		++i;
	}
	//send_char_to_server('\a', pid);
	return (1);
}

int	is_pid(char *spid)
{
	int	i;

	i = 0;
	while (spid[i])
	{
		if (!ft_isdigit(spid[i]))
			return (0);
		++i;
	}
	return (1);
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		write(1, "Character has been sucessfully receieved!\n", 42);
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		return ;
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		return ;
}

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3 || !is_pid(argv[1]) || !argv[2])
		return (0);
	pid = (__pid_t)ft_atoi(argv[1]);
	config_signals();
	ft_printf ("Configured!\n\n\n\n");
	if (!str_to_c(pid, argv[2]))
		return (0);
	return (ft_printf("message sent!\n"));
}
