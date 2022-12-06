/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:26 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/06 16:32:05 by afrigger         ###   ########.fr       */
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

void	setlist(t_list **pile_a, char **numbers)
{
	t_list	*tmp;
	int		nb;
	int		i;

	tmp = *pile_a;
	i = 1;
	while(numbers[i])
	{
		nb = ft_atoi(numbers[i]);
		if (checkdouble(pile_a, nb) == 1 ||
			ft_strncmp(ft_itoa(nb), numbers[i], ft_strlen(ft_itoa(nb))) != 0)
			{
				ft_putstr_fd("Error\n", 2);
				//ft_lstclear(pile_a, &delete);
				return;
			}
			ft_printf("content is %d\n", tmp->content);
		tmp->content = &nb; // probleme d-assignation a regler
		tmp->next = ft_lstnew(0);
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
}

int	checkdouble(t_list **pile_a, int nb)
{
	t_list	*tmp;

	tmp = *pile_a;
	if (tmp->content)
	{
		while (tmp != NULL)
		{ //c ici le illegal ou le segfault
			if (&nb == tmp->content)
				return (1);
			if (tmp->next == NULL)
				return(0);
			tmp = tmp->next;
		}
	}
	return (0);
}

void	parse_arg(t_list **pile_a, char **argv, int argc)
{
	char **numbers;

	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		return;
	}
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		setlist(pile_a, numbers);
	}
	else
	{
		numbers = argv;
		setlist(pile_a, numbers);
	}
}

int main(int argc, char **argv)
{
	t_list *pile_a;
	t_list *pile_b;
	int nb = 12;
	//int * num = &nb;

	pile_a = ft_lstnew((int *)1);
	pile_b = ft_lstnew((int *)2);
	(void)argc;
	(void)argv;
	parse_arg(&pile_a, argv, argc);
	ft_printf("content is %d\n", pile_a->content);
	pile_a->content = &nb;
	ft_printf("content is %d\n", *(int *)pile_a->content);
	// pile_a->content = (int *)1;
	// pile_b->content = (int *)10;
	// ft_lstadd_back(&pile_a, ft_lstnew((int *)2));
	// ft_lstadd_back(&pile_a, ft_lstnew((int *)3));
	// ft_lstadd_back(&pile_a, ft_lstnew((int *)4));
	// ft_lstadd_back(&pile_b, ft_lstnew((int *)11));
	// ft_lstadd_back(&pile_b, ft_lstnew((int *)12));
	// ft_lstadd_back(&pile_b, ft_lstnew((int *)13));
	printlist(&pile_a, &pile_b);
	return 0;
}