/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:25 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/28 19:51:01 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

//static int	ft_send(__pid_t srv_pid, char *str)
//{

//}

int	main(int argc, char **argv)
{
	//__pid_t	srv_pid;
	kill(ft_atoi(argv[argc - 1]), SIGUSR1);
//	PID =  argv[1]
//	str_to_send = argv[2]
//	if (argc != 3)
//		return (-1);
//	srv_pid = ft_atoi(argv[1]);
}
