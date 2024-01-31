/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:47 by aherbin           #+#    #+#             */
/*   Updated: 2024/01/31 12:03:59 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <signal.h>

# ifndef MAX_CHARS
#  define MAX_CHARS 25
# endif

typedef struct s_data
{
	char			buffer[MAX_CHARS];
	unsigned char	c;
	int				index;
	int				client_pid;
}				t_data;

#endif
