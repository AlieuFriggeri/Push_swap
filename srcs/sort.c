/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:00 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/08 12:51:05 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sale(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	int		max;

	printlist(pile_a, pile_b);
	while (*pile_a)
		push_b(pile_b, pile_a);
	// SI TMP->CONTENT NON MALLOC CA SEGFAULT LORS DE COMPARAISON AVEC INT	
	while (*pile_b)
	{
		tmp = *pile_b;
		max = -2147483648;
		while (tmp->content)
		{
			if (*((int *)tmp->content) > max) // segfault a cette ligne
				max = *(int *)tmp->content;
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		//printlist(pile_a, pile_b);
		tmp = *pile_b;
		ft_printf("max is %d\n", max);
		while (*((int *)tmp->content) != max)
		{
			tmp = *pile_b;
			if (*((int *)tmp->content) == max)
				break ;
			//ft_printf("tmp loop is %d\n", *(int *)tmp->content);
			rotate_b(pile_b, 1);	
		}
		push_a(pile_a, pile_b);
		printlist(pile_a, pile_b);
	}
	printlist(pile_a, pile_b);
	//ft_printf("max is %d\n", max);
}
