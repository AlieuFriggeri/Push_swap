/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:32:40 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/08 11:53:06 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (*pile_b == NULL)
		return;
	tmp = *pile_b;
	if (!tmp->content)
	{
		tmp = NULL;
		*pile_b = tmp;
		return;
	}
	*pile_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(pile_a, tmp);
	ft_printf("pa\n");
}
void	push_b(t_list **pile_b, t_list **pile_a)
{
	t_list	*tmp;

	if (*pile_a == NULL)
		return;
	tmp = *pile_a;
	if (!tmp->content)
	{
		tmp = NULL;
		*pile_a = tmp;
		return;
	}
	*pile_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(pile_b, tmp);
	ft_printf("pb\n");
}