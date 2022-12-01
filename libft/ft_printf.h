/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:45:49 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/24 10:32:43 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printstr(char *str);
int		ft_printchar(char c);
char	*ft_printitoa(int n);
int		ft_printnbr(int n);
int		ft_printhex(unsigned int n, const char form);
int		ft_printperc(char c);
int		ft_printptr(void *n, const char form);
int		ft_printunbr(unsigned int n);

#endif
