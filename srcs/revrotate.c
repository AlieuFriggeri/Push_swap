/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:53 by kistod            #+#    #+#             */
/*   Updated: 2023/01/10 15:55:25 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate_ab(t_list **pile_a, t_list **pile_b)
{
	rotate_a(pile_a, 0);
	rotate_b(pile_b, 0);
	ft_printf("rr\n");
}

void	revrotate_ab(t_list **pile_a, t_list **pile_b)
{
	revrotate_a(pile_a, 0);
	revrotate_b(pile_b, 0);
	ft_printf("rrr\n");
}
