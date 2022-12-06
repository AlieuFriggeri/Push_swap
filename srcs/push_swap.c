/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:26 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/06 11:52:29 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	delete(t_list **root)
{
	t_list *tmp;
	t_list *tmp2;

	if (root == NULL)
		return;
	tmp = *root;
	tmp2 = *root;
	*root = tmp->next;
	free(tmp2);
	// tmp = *root;
	// 	while (tmp->content != value)
	// 	{
	// 		if (tmp->next->content == value)
	// 			prev = tmp;
	// 		tmp = tmp->next;
	// 	}
	// 	prev->next = tmp->next;
	// 	tmp->content = NULL;
	// 	tmp->next = NULL;
}

void	printlist(t_list **pile_a, t_list **pile_b)
{
	t_list *tmp;
	int i;
	
	i = 0;
	if (*pile_a)
	{
		tmp = *pile_a;
		ft_printf("pile a = \n");
		while(tmp != NULL)
		{
			ft_printf("%d: {%d}\n", i, tmp->content);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break;
			i++;
		}
	}
	i = 0;
	if(*pile_b)
	{
		tmp = *pile_b;
		ft_printf("pile b = \n");
		while(tmp != NULL)
		{
			ft_printf("%d: {%d}\n", i, tmp->content);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break ;
			i++;
		}
	}
	ft_printf("[END OF LIST]\n");
}

void	parse_arg(t_list **pile_a, char **argv, int argc)
{

}

int main()
{
	t_list *pile_a;
	t_list *pile_b;

	pile_a = malloc(sizeof(t_list));
	pile_b = malloc(sizeof(t_list));
	pile_a->content = (int *)1;
	pile_b->content = (int *)10;
	ft_lstadd_back(&pile_a, ft_lstnew((int *)2));
	ft_lstadd_back(&pile_a, ft_lstnew((int *)3));
	ft_lstadd_back(&pile_a, ft_lstnew((int *)4));
	ft_lstadd_back(&pile_b, ft_lstnew((int *)11));
	ft_lstadd_back(&pile_b, ft_lstnew((int *)12));
	ft_lstadd_back(&pile_b, ft_lstnew((int *)13));
	printlist(&pile_a, &pile_b);
	return 0;
}