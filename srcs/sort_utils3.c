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
	t_list *tmp;
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
	t_list *tmp;
	
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