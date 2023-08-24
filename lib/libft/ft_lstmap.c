/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:13:06 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/07/07 04:28:18 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_lst;

	if (!(lst))
		return (NULL);
	ptr = ft_lstnew((*f)(lst->content));
	new_lst = ptr;
	while (lst->next)
	{
		lst = lst->next;
		ptr->next = ft_lstnew((*f)(lst->content));
		if (!ptr->next)
		{
			ft_lstdelone(ptr->next, del);
			continue ;
		}
		ptr = ptr->next;
	}
	return (new_lst);
}
