/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:05:54 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/05 18:52:31 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	revrotate_a(t_list **pile_a)
{
	t_list *first;
	t_list *last;
	t_list *tmp;

	if (!pile_a)
		return;
	last = *pile_a;
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			tmp = last;
		last = last->next;
	}
	first = *pile_a;
	ft_printf("first is %d\n last is %d\n", first->content, last->content);
	last->next = first;
	*pile_a = last;
}
