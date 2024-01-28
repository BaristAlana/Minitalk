/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:36:14 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/28 20:25:08 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

/*static void	listen(void)
{
}
*/

void	*signal_handler(int signum)
{
	ft_printf("received signum %i\n", signum);
}

int	main(void)
{
	ft_print_header((int) getpid());
	pause();
	sigaction(SIGUSR1, &signal_handler, NULL);
	//ft_printf("Process Id = %i\n", pid);
	//while (1)
	//	listen();
	return (0);
}
