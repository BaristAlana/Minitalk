/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:47 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:14:11 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret_str;

	i = 0;
	j = 0;
	ret_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!ret_str)
		return (NULL);
	while (s1[i])
		ret_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret_str[j++] = s2[i++];
	ret_str[j] = 0;
	return (ret_str);
}
