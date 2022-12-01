/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:53:15 by afrigger          #+#    #+#             */
/*   Updated: 2022/10/24 10:20:31 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t	i;

	i = 0;
	if (n == 0 || (ft_strlen(s1) == 0 && ft_strlen(s2) == 0))
		return (0);
	if (ft_strlen(s1) == 0)
		return (-1);
	if (ft_strlen(s2) == 0)
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*	size_t i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	if (s1[0] == '\0')
		return (-1);
	if (s2[0] == '\0')
		return (1);
	while(s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (ft_strlen(s2) > ft_strlen(s1))
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}	*/
/*
int main()
{
	char s1[] = "Je test,car ca!";
	char s2[] = "Je test";
	int res;
	res = ft_strncmp(s1, s2, 4);
	printf("mine :%d\n", res);
	printf("original :%d\n", strncmp(s1, s2, 4));
	return 0;
}*/
