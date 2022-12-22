/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:00 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/08 15:45:23 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	checksort(t_list *pile)
{
	int i;
	int j;
	t_list *tmp;

	tmp = pile;
	j = 0;
	while (tmp != NULL)
	{
		i = *(int *)tmp->content;
		if (i < j)
			return 1;
		j = i;
		tmp = tmp->next;
	}
	return 0;
}

void	normalizer(t_list **pile, char **numbers)
{
	t_list	*tmp;
	int min;
	int i;

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
		{
			tmp = tmp->next;
		}
		tmp->index = i;
		tmp = *pile;
		i++;
	}
}

void	normalizer2(t_list **pile, char **numbers)
{
	t_list	*tmp;
	int min;
	int i;

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

void	sort_sale(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	int		max;

	if (ft_lstsize(*pile_a) <= 2)
		return;
	if (checksort(*pile_a) == 0)
		return;
	while (*pile_a)
		push_b(pile_b, pile_a);
	// SI TMP->CONTENT NON MALLOC CA SEGFAULT LORS DE COMPARAISON AVEC INT	
	tmp = *pile_b;
	while (*pile_b)
	{
		tmp = *pile_b;
		if (!tmp->content)
			break;
		max = -2147483648;
		while (tmp->content)
		{	
			if (*((int *)tmp->content) >= max) // segfault a cette ligne
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
			//ft_printf("tmp loop is %d\n", *(int *)tmp->content);
			revrotate_b(pile_b, 1);
		}
		push_a(pile_a, pile_b);
		//ft_printf("b is %d\n", *(int *)tmp->content);
		//printlist(pile_a, pile_b);
	}
	//printlist(pile_a, pile_b);
	//ft_printf("max is %d\n", max);
}

void	sorttest(t_list **pa, t_list **pb)
{
	t_list *tmp;
	int i;


	while (*pa)
		push_b(pb ,pa);	
	i = ft_lstsize(*pb) - 1;
	while (*pb)
	{	
 		if (ft_lstsize(*pb) == 1)
			break;
		tmp = *pb;
		while (tmp->index != i)
			tmp = tmp->next;
/* 		ft_printf("tmp value %d\n", *(int *)tmp->content);
		ft_printf("tmp is %d\n", tmp->index); */
		if (findpos(pb, tmp->index) >= ft_lstsize(*pb) / 2)
		{
			tmp = *pb;
			while (tmp->index != i)
			{
				revrotate_b(pb, 1);
				tmp = *pb;
			}
		}
		else
		{
			tmp = *pb;
			while (tmp->index != i)
			{
				rotate_b(pb, 1);
				tmp = *pb;
			}
		}
/* 		ft_printf("tmp value %d\n", *(int *)tmp->content);
		ft_printf("tmp is %d\n", tmp->index); */
		push_a(pa, pb);
		i--;
	}
	push_a(pa, pb);
	rotate_a(pa, 1);
}

void	sortk(t_list **pa, t_list **pb)
{
	t_list *tmp;
	int mid;
	
	tmp = *pa;
	while (ft_lstsize(*pa) > 1)
	{
		tmp = *pa;
		mid = (findbig(pa) + findsmall(pa)) / 2;
		//ft_printf("mid is %d big is %d small is %d\n", mid, findbig(pa), findsmall(pa));
		if (tmp->index <= mid)
			push_b(pb, pa);
		else
			rotate_a(pa, 1);
	}
	while (*pb)
	{
		tmp = *pb;
		if (movecalc(pb, findsmall(pb)) < movecalc(pb, findbig(pb)))
		{
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
		else
		{	
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
	}
	tmp = *pa;
	if (bestmove(pa, findsmall(pa)) == 0)
	{
		while(tmp->index != findsmall(pa))
		{
			rotate_a(pa ,1);
			tmp = *pa;
		}
	}
	else
	{
		while(tmp->index != findsmall(pa))
		{
			revrotate_a(pa ,1);
			tmp = *pa;
		}
	}
} 

int	midvalue(t_list *p)
{
	int		res;

	res = findbig(&p) + findsmall(&p);
	return (res / 2);
}

int	findpos(t_list **pile, int	tofind)
{
	t_list	*tmp;
	int i;

	i = 1;
	tmp = *pile;
	while (tmp->index != tofind)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	bestmove(t_list **p, int tofind)
{
	t_list *tmp;

	tmp = *p;
	while (tmp)
	{
		if (tmp->index == tofind)
			break ;
		tmp = tmp->next;
	}
	if (findpos(p, tmp->index) >= ft_lstsize(*p) / 2)
		return (1);
	else
		return (0);	
} 

int movecalc(t_list **p, int tofind)
{
	t_list *tmp;

	tmp = *p;
	while (tmp)
	{
		if (tmp->index == tofind)
			break ;
		tmp = tmp->next;
	}
	if (findpos(p, tmp->index) > ft_lstsize(*p) / 2)
		return (ft_lstsize(*p) - findpos(p, tmp->index) + 1);
	else if (findpos(p, tmp->index) <= ft_lstsize(*p) / 2)
		return (findpos(p, tmp->index) - 1);
	return 0;
}

int findbig(t_list **p)
{
	int max;
	t_list *tmp;

	tmp = *p;
	max = 0;
	while (tmp)
	{	
		if (tmp->index >= max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return max;
}

int findsmall(t_list **p)
{
	int min;
	t_list *tmp;

	tmp = *p;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index <= min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return min;
}


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