/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:51:02 by kistod            #+#    #+#             */
/*   Updated: 2023/01/10 15:51:22 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	checksort(t_list *pile)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = pile;
	j = 0;
	while (tmp != NULL)
	{
		i = *(int *)tmp->content;
		if (i < j)
			return (1);
		j = i;
		tmp = tmp->next;
	}
	return (0);
}

void	normalizer(t_list **pile, char **numbers)
{
	t_list	*tmp;
	int		min;
	int		i;

	tmp = *pile;
	i = 0;
	while (numbers[i])
	{
		min = 2147483647;
		while (tmp)
		{
			if (*(int *)tmp->content <= min && tmp->index == 0)
				min = *(int *)tmp->content;
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp = *pile;
		while (*(int *)tmp->content != min && tmp)
			tmp = tmp->next;
		tmp->index = i;
		tmp = *pile;
		i++;
	}
}

void	normalizer2(t_list **pile, char **numbers)
{
	t_list	*tmp;
	int		min;
	int		i;

	tmp = *pile;
	i = 0;
	while (numbers[i++])
	{
		min = 2147483647;
		while (tmp)
		{
			if (*(int *)tmp->content <= min && tmp->index == 0)
				min = *(int *)tmp->content;
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp = *pile;
		while (*(int *)tmp->content != min && tmp)
		{
			tmp = tmp->next;
		}
		tmp->index = i;
		tmp = *pile;
	}
}

int	midvalue(t_list *p)
{
	int		res;

	res = findbig(&p) + findsmall(&p);
	return (res / 2);
}
