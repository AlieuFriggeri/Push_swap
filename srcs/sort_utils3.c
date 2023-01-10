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

int	checkdigit(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 1 || (str[i][j] == '-' && j == 0))
				j++;
			else
			{
				ft_putstr_fd("Error\n", 2);
				exit (1);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_scandale(t_list **pa, char **numbers, int index)
{
	if (index == 1)
		normalizer(pa, numbers);
	else
		normalizer2(pa, numbers);
}
