/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printitoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:07:11 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/24 10:31:05 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int x)
{
	int	i;

	if (x == -2147483648)
		return (11);
	i = 1;
	if (x < 0)
		x *= -1;
	while (x / 10 > 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

static char	*ft_array(char *res, int len, int sign, int n)
{
	if (sign == 1)
	{
		while (len > 0)
		{
			res[len] = n % 10 + 48;
			n /= 10;
			len--;
		}
		res[len] = '-';
		return (res);
	}
	else
	{
		while (len >= 0)
		{
			res[len] = n % 10 + 48;
			n /= 10;
			len--;
		}
		return (res);
	}
}

static char	*ft_intmin(int n, char *res)
{
	int	i;

	res = malloc(sizeof(char) * ft_len(n) + 1);
	if (!res)
		return (NULL);
	i = ft_len(n);
	res[0] = '-';
	res[i] = '\0';
	res[i - 1] = '8';
	i = i - 2;
	n /= -10;
	while (i > 0)
	{
		res[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (res);
}

char	*ft_printitoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	res = NULL;
	if (n == -2147483648)
		return (ft_intmin(n, res));
	len = ft_len(n);
	sign = 0;
	if (n < 0)
	{
		len++;
		sign = 1;
		n *= -1;
	}
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	res = ft_array(res, len, sign, n);
	return (res);
}
/*
int main()
{
	int n;
	char *str;

	n = -2147483648;
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	printf("%s\n", str);
	return 0;
}*/
