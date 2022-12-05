/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:32:40 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/05 17:13:56 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (*pile_a == NULL || *pile_b == NULL)
		return;
	tmp = *pile_b;
	*pile_b = tmp->next;
	ft_lstadd_front(pile_a, tmp);
}
	
	