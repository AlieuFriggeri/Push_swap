/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:26 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/01 15:25:18 by afrigger         ###   ########.fr       */
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

	pile_a.content = num;
	num++;			
	pile_a.next = ft_lstnew(0);
	pile_a.next->content = num;
	ft_printf("values are %d and %d\n", pile_a.content, pile_a.next->content);
	swap_a(&pile_a);
	ft_printf("values are %d and %d\n", pile_a.content, pile_a.next->content);
	return 0;
}