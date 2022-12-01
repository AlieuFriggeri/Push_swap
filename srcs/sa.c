/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:27:52 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/01 15:23:22 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_a(t_list *pile_a)
{
	int	tmp;

	tmp = pile_a->content;
	pile_a->content = pile_a->next->content;
	pile_a->next->content = tmp;
}
