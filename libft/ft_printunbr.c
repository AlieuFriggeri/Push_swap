/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:45:22 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/24 10:27:48 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = nb;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_printunbr(unsigned int n)
{
	if (n == 0)
		return (ft_printchar('0'));
	if (n >= 10)
	{
		ft_printnbr(n / 10);
		ft_printchar(n % 10 + 48);
	}
	if (n <= 9)
		ft_printchar(n + 48);
	return (ft_len(n));
}
