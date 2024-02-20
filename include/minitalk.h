/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:33:49 by aherbin           #+#    #+#             */
/*   Updated: 2024/02/16 16:08:54 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(char *str);

int		ft_isdigit(int c);

void	ft_putnbr_fd(int nb, int fd);

int		ft_strlen(char *str);

int		is_pid(char *spid);

#endif
