/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:25 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/31 15:39:24 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

//static int	ft_send(__pid_t srv_pid, char *str)
//{

//}

int send_char_to_server(unsigned char c, __pid_t server_pid)
{
	unsigned char   bit;

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
		usleep(100);
	}
	return (1);
}

int str_to_c(__pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (send_char_to_server(str[i], pid) == 0 )
			return (0);
		++i;
	}
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

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3 || !is_pid(argv[1]))
		return (0);
	pid = (__pid_t)ft_atoi(argv[1]);
	if (!str_to_c(pid, argv[2]))
		return (0);
	return (ft_printf("message sent!\n"));


//	PID =  argv[1]
//	str_to_send = argv[2]
//	if (argc != 3)
//		return (-1);
//	srv_pid = ft_atoi(argv[1]);
}