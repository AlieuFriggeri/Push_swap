/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:27:52 by afrigger          #+#    #+#             */
/*   Updated: 2023/01/10 15:52:28 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_a(t_list **pile_a, int mode)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *pile_a;
	tmp = tmp->next;
	tmp2 = *pile_a;
	tmp2->next = tmp->next;
	tmp->next = tmp2;
	*pile_a = tmp;
	if (mode == 1)
		ft_printf("sa\n");
}

void	swap_b(t_list **pile_b, int mode)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *pile_b;
	tmp = tmp->next;
	tmp2 = *pile_b;
	tmp2->next = tmp->next;
	tmp->next = tmp2;
	*pile_b = tmp;
	if (mode == 1)
		ft_printf("sb\n");
}

void	swap_ab(t_list *pile_a, t_list *pile_b)
{
	swap_a(&pile_a, 0);
	swap_b(&pile_b, 0);
	ft_printf("ss\n");
}
