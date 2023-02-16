/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:26 by afrigger          #+#    #+#             */
/*   Updated: 2023/02/16 16:52:01 by afrigger         ###   ########.fr       */
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
	{//ft_printf("salut\n");
		//ft_printf("%d\n", tmp->next->index);
		
	tmp = tmp->next;
	while(tmp)
	{
		free(tmp2->bot);
		tmp2->bot = NULL;
		free(tmp2->content);
		tmp2->content = NULL;
		//tmp2->index = NULL;
		free(tmp2->top);
		tmp2->top = NULL;
		free(tmp2);
		if (tmp->next == NULL)
			break;
		tmp2 = tmp;
			//ft_printf("salut\n");
		tmp = tmp->next;
			//ft_printf("salut2\n");
	}
	}
	//ft_printf("salut3\n");
	free(tmp->bot);
	tmp->bot = NULL;
	free(tmp->content);
	tmp2->content = NULL;
	//tmp->index = NULL;
	free(tmp->top);
	tmp2->top = NULL;
	free(tmp);
	tmp = NULL;
	//free(tmp2);
	tmp2 = NULL;
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

void	setlist(t_list **pile_a, char **numbers, int index)
{
	t_list	*tmp;
	int		nb;
	int		i;

	tmp = *pile_a;
	i = index;
	while (numbers[i])
	{
		nb = ft_atoi(numbers[i]);
		if (checkdouble(numbers) == 1
			|| ft_strncmp(ft_itoa(nb), numbers[i], ft_strlen(ft_itoa(nb))) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			delete(*pile_a);
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
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (numbers[i])
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
	char	**numbers;
	int		index;

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
	ft_scandale(pile_a, numbers, index);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = malloc(sizeof(t_list));
	pile_b = NULL;
	parse_arg(&pile_a, argv, argc);
	if (ft_lstsize(pile_a) == 3)
		sort3(&pile_a, 3);
	else if (ft_lstsize(pile_a) == 5)
		sort5(&pile_a, &pile_b);
	else if (ft_lstsize(pile_a) > 5)
		sortk(&pile_a, &pile_b);

	delete(pile_a);
	pile_a = NULL;
	//ft_printf("%d\n", pile_a->index);
	free(pile_a);
	free(pile_b);
	return (0);
}
