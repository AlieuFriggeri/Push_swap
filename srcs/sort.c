/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:00 by afrigger          #+#    #+#             */
/*   Updated: 2023/02/23 12:17:16 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sortk(t_list **pa, t_list **pb)
{
	t_list	*tmp;
	int		mid;

	if (checksort(*pa) == 0)
		return ;
	while (ft_lstsize(*pa) > 1)
	{
		tmp = *pa;
		mid = (findbig(pa) + findsmall(pa)) / 2;
		if (tmp->index <= mid)
			push_b(pb, pa);
		else
			rotate_a(pa, 1);
	}
	while (*pb)
	{
		tmp = *pb;
		if (movecalc(pb, findsmall(pb)) < movecalc(pb, findbig(pb)))
			sortk2a(pa, pb);
		else
			sortk2b(pa, pb);
	}
	sortkfinal(pa);
}

void	sort3(t_list **p, int nbnb)
{
	t_list	*tmp;

	tmp = *p;
	if (tmp->index == nbnb)
		rotate_a(p, 1);
	else if (tmp->next->index == nbnb)
		revrotate_a(p, 1);
	tmp = *p;
	if (tmp->index == nbnb - 1)
		swap_a(p, 1);
}

void	sort5(t_list **pa, t_list **pb)
{
	t_list	*tmp;

	if (checksort(*pa) == 0)
		return ;
	while (ft_lstsize(*pa) != 3)
	{	
		tmp = *pa;
		if (tmp->index == 1 || tmp->index == 2)
			push_b(pb, pa);
		else
			rotate_a(pa, 1);
	}
	sort3(pa, 5);
	tmp = *pb;
	if (tmp->index == 1)
		swap_b(pb, 1);
	push_a(pa, pb);
	push_a(pa, pb);
}
/* void	sort_sale(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	int		max;

	if (ft_lstsize(*pile_a) <= 2)
		return;
	if (checksort(*pile_a) == 0)
		return;
	while (*pile_a)
		push_b(pile_b, pile_a);
	tmp = *pile_b;
	while (*pile_b)
	{
		tmp = *pile_b;
		if (!tmp->content)
			break;
		max = -2147483648;
		while (tmp->content)
		{	
			if (*((int *)tmp->content) >= max)
				max = *(int *)tmp->content;
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp = *pile_b;
		while (*((int *)tmp->content) != max)
		{
			tmp = *pile_b;
			if (*((int *)tmp->content) == max)
				break ;
			revrotate_b(pile_b, 1);
		}
		push_a(pile_a, pile_b);

	}

} */

/* NOTES ALGO K 
while ( lstsize(pa) > 1)
{
	while (i != lstsize / lstsize -1)
	{
		if nb >= midvalue 
			push b
		else
			rotate_a
	}
}
	find bigger && smaller
	bestmove(bigger / smaller)
	if (bestmove == smaller)
		push a -> rotate_a
	if (bestmove == bigger)
		push a
	while (pa->top != smaller)
		revrotate_a;
} */

int	checkval(char **numbers, int index)
{
	int		nb;
	char	*itoa;
	int		i;

	i = index;
	nb = ft_atoi(numbers[i]);
	itoa = ft_itoa(nb);
	if (checkdouble(numbers) == 1)
	{
		free(itoa);
		return (1);
	}
	else if (ft_strncmp(numbers[i], itoa, ft_strlen(numbers[i])) != 0
		|| ft_strlen(itoa) != ft_strlen(numbers[i]))
	{
		free(itoa);
		return (1);
	}
	else
	{
		free(itoa);
		return (0);
	}
}

void	deletepart2(t_list *tmp, t_list *tmp2)
{
	free(tmp->bot);
	tmp->bot = NULL;
	free(tmp->content);
	tmp->content = NULL;
	free(tmp->top);
	tmp2->top = NULL;
	free(tmp);
	tmp = NULL;
	tmp2 = NULL;
}
