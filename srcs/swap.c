/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:27:52 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/02 10:31:23 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_a(t_list *pile_a)
{
	void	*tmp;

	tmp = pile_a->content;
	pile_a->content = pile_a->next->content;
	pile_a->next->content = tmp;
}

void	swap_b(t_list *pile_b)
{
	void	*tmp;

	tmp = pile_b->content;
	pile_b->content = pile_b->next->content;
	pile_b->next->content = tmp;
}

void	swap_ab(t_list *pile_a, t_list *pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
}
