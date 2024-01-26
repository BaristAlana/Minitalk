/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:29:21 by aherbin           #+#    #+#             */
/*   Updated: 2023/11/25 14:13:22 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	new_list = ft_lstnew(f(tmp->content));
	if (!new_list)
		return (NULL);
	save = new_list;
	tmp = tmp->next;
	while (tmp)
	{
		new_list->next = ft_lstnew(f(tmp->content));
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		new_list = new_list->next;
		tmp = tmp->next;
	}
	new_list->next = NULL;
	return (save);
}
