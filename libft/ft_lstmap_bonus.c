/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:55:02 by afrigger          #+#    #+#             */
/*   Updated: 2022/10/19 13:33:19 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcell;

	if (!lst || !f)
		return (NULL);
	newcell = ft_lstnew(f(lst->content));
	if (!newcell)
		return (NULL);
	newlst = newcell;
	lst = lst->next;
	while (lst)
	{
		newcell = ft_lstnew(f(lst->content));
		if (!newcell)
		{
			ft_lstclear(&newlst, del);
			ft_lstclear(&lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, newcell);
	}
	return (newlst);
}
