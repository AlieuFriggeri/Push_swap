/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:00 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/08 15:45:23 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	checksort(t_list *pile)
{
	int i;
	int j;
	t_list *tmp;

	tmp = pile;
	j = 0;
	while (tmp != NULL)
	{
		i = *(int *)tmp->content;
		if (i < j)
			return 1;
		j = i;
		tmp = tmp->next;
	}
	return 0;
}

void	normalizer(t_list **pile, char **numbers)
{
	t_list	*tmp;
	int min;
	int i;

	tmp = *pile;
	i = 0;
	while (numbers[i++])
	{
		min = 2147483647;
		while (tmp)
		{
			if (*(int *)tmp->content <= min && tmp->index == 0)
				min = *(int *)tmp->content;
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp = *pile;
		while (*(int *)tmp->content != min && tmp)
		{
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp->index = i;
		tmp = *pile;
	}
}

void	sort_sale(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	int		max;

	if (ft_lstsize(*pile_a) <= 2)
		return;
	if (checksort(*pile_a) == 0)
		return;
	while (*pile_a)
		push_b(pile_b, pile_a);
	// SI TMP->CONTENT NON MALLOC CA SEGFAULT LORS DE COMPARAISON AVEC INT	
	tmp = *pile_b;
	while (*pile_b)
	{
		tmp = *pile_b;
		if (!tmp->content)
			break;
		max = -2147483648;
		while (tmp->content)
		{	
			if (*((int *)tmp->content) >= max) // segfault a cette ligne
				max = *(int *)tmp->content;
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp = *pile_b;
		while (*((int *)tmp->content) != max)
		{
			tmp = *pile_b;
			if (*((int *)tmp->content) == max)
				break ;
			//ft_printf("tmp loop is %d\n", *(int *)tmp->content);
			revrotate_b(pile_b, 1);
		}
		push_a(pile_a, pile_b);
		//ft_printf("b is %d\n", *(int *)tmp->content);
		//printlist(pile_a, pile_b);
	}
	//printlist(pile_a, pile_b);
	//ft_printf("max is %d\n", max);
}
