/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:00 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/07 15:10:37 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sale(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		max;

	tmp = *pile_a;
	while (tmp->next)
		push_b(pile_b, &tmp);
	tmp = *pile_b;
	while (tmp->next != NULL)
	{
		if (*((int *)tmp->content) > max)
			max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	tmp2 = *pile_b;
	while (*((int *)tmp2->content) != max)
	{
		tmp2 = *pile_b;
		if (*((int *)tmp2->content) == max)
			break ;
		ft_printf("tmp2 is %d\n", *(int *)tmp2->content);
		rotate_b(pile_b, 1);	
	}
	ft_printf("max is %d\n", max);
}