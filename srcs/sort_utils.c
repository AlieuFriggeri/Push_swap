#include "../headers/push_swap.h"

int	findpos(t_list **pile, int tofind)
{
	t_list	*tmp;
	int		i;

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
	t_list	*tmp;

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

int	movecalc(t_list **p, int tofind)
{
	t_list	*tmp;

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
	return (0);
}

int	findbig(t_list **p)
{
	int		max;
	t_list	*tmp;

	tmp = *p;
	max = 0;
	while (tmp)
	{	
		if (tmp->index >= max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	findsmall(t_list **p)
{
	int		min;
	t_list	*tmp;

	tmp = *p;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index <= min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}
