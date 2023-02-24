/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:02:30 by afrigger          #+#    #+#             */
/*   Updated: 2023/02/24 14:03:44 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	bitmax(int maxnb)
{
	int	i;

	i = 0;
	while (maxnb >> i != 0)
		i++;
	return (i);
}

void	radix_sort(t_list **pile_a, t_list **pile_b, int bitmax)
{
	t_list	*pa;
	t_list	*pb;
	int		i;
	int		j;
	int		imax;

	i = 0;
	imax = ft_lstsize(*pile_a);
	while (i < bitmax)
	{
		j = 0;
		while (j < imax)
		{
			pa = *pile_a;
			pb = *pile_b;
			if (((pa->index >> i) & 1) == 1)
				rotate_a(pile_a, 1);
			else
				push_b(pile_b, pile_a);
			j++;
		}
		i++;
		while (*pile_b)
			push_a(pile_a, pile_b);
	}
}
