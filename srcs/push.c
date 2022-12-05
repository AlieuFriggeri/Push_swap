/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:32:40 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/05 18:05:38 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (*pile_b == NULL)
		return;
	tmp = *pile_b;
	*pile_b = tmp->next;
	ft_lstadd_front(pile_a, tmp);
}
void	push_b(t_list **pile_b, t_list **pile_a)
{
	t_list	*tmp;

	if (*pile_a == NULL)
		return;
	tmp = *pile_a;
	*pile_a = tmp->next;
	ft_lstadd_front(pile_b, tmp);
}