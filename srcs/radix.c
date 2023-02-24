/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:02:30 by afrigger          #+#    #+#             */
/*   Updated: 2023/02/24 11:24:52 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	indexToBinary(t_list **pa, int bitmax)
{
	t_list	*tmp;

	tmp = *pa;
	while (tmp)
	{
		while (tmp->index > 0)
		{
			if (tmp->binaryindex)
				tmp->binaryindex = ft_strjoin(ft_itoa(tmp->index % 2), tmp->binaryindex);
			else
				tmp->binaryindex = ft_strjoin(ft_itoa(tmp->index % 2), "");
			tmp->index = tmp->index / 2;
		}
		while((int)ft_strlen(tmp->binaryindex) < bitmax)
			tmp->binaryindex = ft_strjoin("0", tmp->binaryindex);
		ft_printf("binary index is %s\n", tmp->binaryindex);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}

int	bitmax(int maxnb)
{
	int i;

	i = 0;
	while (maxnb > 0)
	{
		maxnb /= 2;
		i++;
	}
	return (i);
}