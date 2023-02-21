/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:22:33 by afrigger          #+#    #+#             */
/*   Updated: 2023/02/21 11:25:39 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	error(t_list **pile_a, t_list **pile_b)
{
	ft_putstr_fd("Error\n", 2);
	delete(*pile_a);
	*pile_a = NULL;
	free(*pile_a);
	free(*pile_b);
	exit(1);
}
