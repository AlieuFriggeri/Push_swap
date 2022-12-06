/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:05:54 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/06 11:41:23 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate_a(t_list **pile_a)
{
	t_list *tmp;
	t_list *last;

	tmp = *pile_a;
	*pile_a = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(*pile_a);
	last->next = tmp;
}

void	rotate_b(t_list **pile_b)
{
	t_list *tmp;
	t_list *last;

	tmp = *pile_b;
	*pile_b = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(*pile_b);
	last->next = tmp;
}

void	revrotate_a(t_list **pile_a)
{
	t_list *tmp;
	t_list *last;

	tmp = *pile_a;
	last = ft_lstlast(*pile_a);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *pile_a;
	*pile_a = last;
}

void	revrotate_b(t_list **pile_b)
{
	t_list *tmp;
	t_list *last;

	tmp = *pile_b;
	last = ft_lstlast(*pile_b);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *pile_b;
	*pile_b = last;
}

void	rotate_ab(t_list **pile_a, t_list **pile_b)
{
	rotate_a(pile_a);
	rotate_b(pile_b);
}

void	revrotate_ab(t_list **pile_a, t_list **pile_b)
{
	revrotate_a(pile_a);
	revrotate_b(pile_b);
}
