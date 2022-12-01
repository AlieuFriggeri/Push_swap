/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:39:25 by afrigger          #+#    #+#             */
/*   Updated: 2022/10/20 11:16:44 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
	{
		ft_memset(s, 0, n);
	}
}
/*
int main()
{
	char str[] = "abcdefghik";
	printf("%s\n", str);
	ft_bzero(str, 1);
	if (str[0] == 0)
		str[0] = '7';
	printf("%s\n", str);
	return 0;
}*/
