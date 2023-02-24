/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:26 by afrigger          #+#    #+#             */
/*   Updated: 2023/02/24 11:21:32 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	delete(t_list *root)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = root;
	tmp2 = root;
	if (tmp->next != NULL)
	{
		tmp = tmp->next;
		while (tmp)
		{
			free(tmp2->bot);
			tmp2->bot = NULL;
			free(tmp2->content);
			tmp2->content = NULL;
			free(tmp2->top);
			tmp2->top = NULL;
			free(tmp2);
			if (tmp->next == NULL)
				break ;
			tmp2 = tmp;
			tmp = tmp->next;
		}
	}
	deletepart2(tmp, tmp2);
}

/* void	printlist(t_list **pile_a, t_list **pile_b)
{
	t_list *tmp;
	int i;
	
	i = 1;
	if (*pile_a)
	{
		tmp = *pile_a;
		ft_printf("pile a = \n");
		while(tmp != NULL)
		{
			if (tmp->content)
				ft_printf("%d: {%d} [%d]\n", i, *(int *)tmp->content, tmp->index);
			else
				ft_printf("%d: {%d}\n", i, tmp->content);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break;
			i++;
		}
	}
	i = 1;
	if(*pile_b)
	{
		tmp = *pile_b;
		ft_printf("pile b = \n");
		while(tmp != NULL)
		{
			if(tmp->content)
				ft_printf("%d: {%d} [%d]\n", i, *(int *)tmp->content, tmp->index);
			else
				ft_printf("%d: {%d}\n", i, tmp->content);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break ;
			i++;
		}
	}
	ft_printf("[END OF LIST]\n");
} */

void	setlist(t_list **pile_a, t_list **pile_b, char **numbers, int index)
{
	t_list	*tmp;
	int		nb;
	int		i;
	char	*itoa;

	tmp = *pile_a;
	i = index;
	while (numbers[i])
	{
		nb = ft_atoi(numbers[i]);
		itoa = ft_itoa(nb);
		if (checkval(numbers, i) == 1)
			error(pile_a, pile_b);
		tmp->content = malloc(sizeof(int));
		*((int *)tmp->content) = nb;
		if (numbers[i + 1])
			tmp->next = ft_lstnew(0);
		tmp = tmp->next;
		i++;
		free(itoa);
	}
	tmp = NULL;
}

int	checkdouble(char **numbers)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (numbers[i])
	{
		while (numbers[j])
		{
			if ((j != i && ft_atoi(numbers[j]) == ft_atoi(numbers[i])
					&& ft_strncmp(numbers[j], "./push_swap", 12) != 0))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	parse_arg(t_list **pile_a, t_list **pile_b, char **argv, int argc)
{
	char	**numbers;
	int		index;

	if (argc <= 1)
	{
		error(pile_a, pile_b);
		index = 0;
		numbers = NULL;
	}
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		index = 0;
	}
	else
	{
		numbers = argv;
		index = 1;
	}
	checkdigit(numbers, pile_a, pile_b, index);
	setlist(pile_a, pile_b, numbers, index);
	ft_scandale(pile_a, numbers, index);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (!argv[1])
		exit(1);
	pile_a = malloc(sizeof(t_list));
	pile_b = NULL;
	parse_arg(&pile_a, &pile_b, argv, argc);
	// if (ft_lstsize(pile_a) == 3)
	// 	sort3(&pile_a, 3);
	// else if (ft_lstsize(pile_a) == 5)
	// 	sort5(&pile_a, &pile_b);
	// else if (ft_lstsize(pile_a) > 5 || ft_lstsize(pile_a) == 4)
	// 	sortk(&pile_a, &pile_b);
	indexToBinary(&pile_a, bitmax(500));
	delete(pile_a);
	pile_a = NULL;
	free(pile_a);
	free(pile_b);
	pile_b = NULL;
	return (0);
}
