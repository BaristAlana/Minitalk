/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:33:52 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/21 15:55:15 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(char *str);

int		ft_isdigit(int c);

void	ft_putnbr_fd(int nb, int fd);

void	exit_on_error(char *error_code);

int		is_pid(char *spid);

#endif
