/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:05:54 by afrigger          #+#    #+#             */
/*   Updated: 2023/01/10 15:58:26 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate_a(t_list **pile_a, int mode)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *pile_a;
	*pile_a = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(*pile_a);
	if (last->content == NULL)
	{
		last->content = tmp->content;
		last->next = NULL;
	}
	else
		last->next = tmp;
	if (mode == 1)
		ft_printf("ra\n");
}

void	rotate_b(t_list **pile_b, int mode)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *pile_b;
	*pile_b = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(*pile_b);
	if (last->content == NULL)
	{
		last->content = tmp->content;
		last->next = NULL;
	}
	else
		last->next = tmp;
	if (mode == 1)
		ft_printf("rb\n");
}

void	revrotate_a(t_list **pile_a, int mode)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *pile_a;
	last = ft_lstlast(*pile_a);
	while (tmp->next->content != last->content)
		tmp = tmp->next;
	if (!last->content)
	{
		last->content = tmp->content;
		tmp->next = NULL;
		last->next = *pile_a;
		*pile_a = last;
	}
	else
	{
		tmp->next = NULL;
		ft_lstadd_front(pile_a, last);
	}
	if (mode == 1)
		ft_printf("rra\n");
}

void	revrotate_b(t_list **pile_b, int mode)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *pile_b;
	last = ft_lstlast(*pile_b);
	while (tmp->next->content != last->content)
		tmp = tmp->next;
	if (!last->content)
	{
		last->content = tmp->content;
		tmp->next = NULL;
		tmp->content = NULL;
		last->next = *pile_b;
		*pile_b = last;
	}
	else
	{
		tmp->next = NULL;
		ft_lstadd_front(pile_b, last);
	}
	if (mode == 1)
		ft_printf("rrb\n");
}
