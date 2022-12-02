/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:26 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/02 10:28:55 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	lol(char *str)
{
	ft_printf("string is %s\n", str);
}

int main()
{
	t_list pile_a;
	int num = 2;
	int *np = &num;

	pile_a.content = malloc(sizeof(int *));
	*(int *)pile_a.content = (int)num;
	num++;
	pile_a.next = ft_lstnew(np);
	//*(int *)pile_a.next->content = (int)num;
	ft_printf("values are %d and %d\n", *(int *)pile_a.content, *(int *)pile_a.next->content);
	swap_a(&pile_a);
	ft_printf("values are %d and %d\n", *(int *)pile_a.content, *(int *)pile_a.next->content);
	return 0;
}