/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:45:09 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/24 10:30:18 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	ft_nb_args(char *str)
{
	int	i;
	int	nb_args;

	i = 0;
	nb_args = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p'
				|| str[i + 1] == 'd' || str[i + 1] == 'i'
				|| str[i + 1] == 'u'
				|| str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == '%')
				nb_args++;
		}
		i++;
	}
	return (nb_args);
}
*/
int	ft_printarg(va_list args, char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_printchar(va_arg(args, int));
	else if (c == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		size += ft_printptr(va_arg(args, void *), 'x');
	else if (c == 'd')
		size += ft_printnbr(va_arg(args, int));
	else if (c == 'i')
		size += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		size += ft_printunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		size += ft_printhex(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		size += ft_printhex(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		size += ft_printchar('%');
	return (size);
}

/*
int	ft_isarg(char c)
{
	int i;
	
	i = 0;
	while (i < 10)
	{
		if (c == 'c' || c == 's' ||c == 'p' || c == 'd' || c == 'i' 
			|| c == 'u' || c == 'x' ||c == 'X' || c == '%')
			return (1);
		i++;
	}
	return (0);
}
*/

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_printarg(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_printchar(str[i]);
			size++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
/*
int main()
{
	ft_printf("salut %5% bonjour");
	return 0;
}
*/