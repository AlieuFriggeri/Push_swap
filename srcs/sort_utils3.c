/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:51:17 by kistod            #+#    #+#             */
/*   Updated: 2023/02/23 12:01:02 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sortk2a(t_list **pa, t_list **pb)
{
	t_list	*tmp;

	tmp = *pb;
	if (bestmove(pb, findsmall(pb)) == 0)
	{
		while (tmp->index != findsmall(pb))
		{
			rotate_b(pb, 1);
			tmp = *pb;
		}				
	}		
	else
	{
		while (tmp->index != findsmall(pb))
		{
			revrotate_b(pb, 1);
			tmp = *pb;
		}	
	}
	push_a(pa, pb);
	rotate_a(pa, 1);
}

void	sortk2b(t_list **pa, t_list **pb)
{
	t_list	*tmp;

	tmp = *pb;
	if (bestmove(pb, findbig(pb)) == 0)
	{
		while (tmp->index != findbig(pb))
		{
			rotate_b(pb, 1);
			tmp = *pb;
		}	
	}
	else
	{
		while (tmp->index != findbig(pb))
		{
			revrotate_b(pb, 1);
			tmp = *pb;
		}	
	}	
	push_a(pa, pb);
}

void	sortkfinal(t_list **pa)
{
	t_list	*tmp;

	tmp = *pa;
	if (bestmove(pa, findsmall(pa)) == 0)
	{
		while (tmp->index != findsmall(pa))
		{
			rotate_a(pa, 1);
			tmp = *pa;
		}
	}
	else
	{
		while (tmp->index != findsmall(pa))
		{
			revrotate_a(pa, 1);
			tmp = *pa;
		}
	}
}

int	checkdigit(char **str, t_list **pile_a, t_list **pile_b, int index)
{
	int	i;
	int	j;

	if (index == 1)
		i = 1;
	else
		i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 1
				|| (str[i][j] == '-' && j == 0) || (str[i][j] == '+' && j == 0))
				j++;
			else
				error(pile_a, pile_b);
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_scandale(t_list **pa, char **numbers, int index)
{
	int	i;

	i = 0;
	if (index == 1)
		normalizer(pa, numbers);
	else
	{
		normalizer2(pa, numbers);
		while (numbers[i])
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
}
