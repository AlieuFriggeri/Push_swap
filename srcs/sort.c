/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:00 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/07 13:52:15 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sale(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*max;

	while (*pile_a)
		push_b(pile_b, pile_a);
	tmp = *pile_b;
	max = ft_lstnew(0);
	max->content = malloc(sizeof(int));
	while (tmp->next != NULL)
	{
		if (*((int *)tmp->content) > *(int *)max->content)
			*(int *)max->content = *(int *)tmp->content; // probleme de segfault
		tmp = tmp->next;
	}
	tmp = *pile_b;
	tmp2 = *pile_b;
	while (*((int *)tmp2->content) != *(int *)max)
		rotate_b(pile_b, 0);
}