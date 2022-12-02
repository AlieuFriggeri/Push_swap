/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:32:40 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/02 13:02:45 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_a(t_list *pile_a, t_list *pile_b)
{
	t_list	*tmp;
	
	tmp = pile_b;
	pile_b = pile_b->next;
	pile_b->top = pile_b;
	
}