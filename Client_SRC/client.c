/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:25 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/26 18:03:06 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	ft_send(__pid_t srv_pid, char *str)
{

}

int	main(int argc, char **argv)
{
	__pid_t	srv_pid;
//	PID =  argv[1]
//	str_to_send = argv[2]
	if (argc != 3)
		return (-1);
	srv_pid = ft_atoi(argv[1]);
	return (ft_send(srv_pid, argv[2]));
}
