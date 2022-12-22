/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:26 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/08 15:10:31 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	delete(void *root)
{
	t_list *tmp;
	t_list *tmp2;

	if (root == NULL)
		return;
	tmp = root;
	tmp2 = root;
	root = tmp->next;
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
}

void	setlist(t_list **pile_a, char **numbers, int index)
{
	t_list	*tmp;
	int		nb;
	int		i;

	tmp = *pile_a;
	i = index;
	while(numbers[i])
	{
		nb = ft_atoi(numbers[i]);
		if (checkdouble(numbers) == 1 ||
			ft_strncmp(ft_itoa(nb), numbers[i], ft_strlen(ft_itoa(nb))) != 0)
			{
				ft_putstr_fd("Error\n", 2);
				ft_lstclear(pile_a, &delete);
				exit(1);
			}
		tmp->content = malloc(sizeof(int));
		*((int *)tmp->content) = nb;
		if (numbers[i + 1])
			tmp->next = ft_lstnew(0);
		tmp = tmp->next;
		i++;
	}
	tmp = NULL;
}

int	checkdouble(char **numbers)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(numbers[i])
	{
		while (numbers[j])
		{
			if (ft_strncmp(numbers[j], numbers[i], ft_strlen(numbers[i])) == 0
				&& j != i && ft_strlen(numbers[i]) == ft_strlen(numbers[j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	parse_arg(t_list **pile_a, char **argv, int argc)
{
	char **numbers;
	int index;

	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
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
	checkdigit(numbers);
	setlist(pile_a, numbers, index);
	if (index == 1)
	normalizer(pile_a, numbers);
	else
	normalizer2(pile_a, numbers);
}

int	checkdigit(char **str)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(str[i])
	{
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 1 || (str[i][j] == '-' && j == 0))
				j++;
			else
			{
				ft_putstr_fd("Error\n" ,2);
				exit (1);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}

/* int	checknbr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '-' && i != 0)
		{
			ft_putstr_fd("Error\n" ,2);
			exit (1);
		}
		i++;
	}
	return 0;
} */

int main(int argc, char **argv)
{
	t_list *pile_a;
	t_list *pile_b;
	//t_list	*tmp;
	pile_a = malloc(sizeof(t_list));
	pile_b = NULL;
	parse_arg(&pile_a, argv, argc);
	sortk(&pile_a, &pile_b);
 	//tmp = pile_a;
/*  	while (tmp)
	{
		ft_printf("index for %d is %d and his pos is%d\n", *(int *)tmp->content, tmp->index, findpos(&pile_a, tmp));
		tmp = tmp->next;
	} */
/* 	while (tmp)
	{
		ft_printf("index for %d is %d\n", *(int *)tmp->content, tmp->index);
		tmp = tmp->next;
	} */
	//printlist(&pile_a, &pile_b);
	//ft_printf("END OF EXECUTION\n");
	return 0;
}