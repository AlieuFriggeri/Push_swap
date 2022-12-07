/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:27:52 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/07 13:23:38 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_a(t_list *pile_a, int mode)
{
	void	*tmp;

	tmp = pile_a->content;
	pile_a->content = pile_a->next->content;
	pile_a->next->content = tmp;
	if (mode == 1)
		ft_printf("sa\n");
}

void	swap_b(t_list *pile_b, int mode)
{
	void	*tmp;

	tmp = pile_b->content;
	pile_b->content = pile_b->next->content;
	pile_b->next->content = tmp;
	if (mode == 1)
		ft_printf("sb\n");
}

void	swap_ab(t_list *pile_a, t_list *pile_b)
{
	swap_a(pile_a, 0);
	swap_b(pile_b, 0);
	ft_printf("ss\n");
}
