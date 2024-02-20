/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:33:56 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/20 16:25:27 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char_to_server(unsigned char c, __pid_t server_pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit (0);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit (0);
		}
		pause();
		bit >>= 1;
	}
}

static void	sig_handler(int signum)
{
	if (signum == 12)
		write(1, "confirmation received!\n", 23);
}

static int	str_to_c(__pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char_to_server(str[i], pid);
		++i;
	}
	send_char_to_server(0, pid);
	return (1);
}

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3 || !is_pid(argv[1]) || !argv[2])
		return (0);
	pid = (__pid_t)ft_atoi(argv[1]);
	signal(10, &sig_handler);
	signal(12, &sig_handler);
	if (!str_to_c(pid, argv[2]))
		return (0);
}
