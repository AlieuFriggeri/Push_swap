/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:42:28 by afrigger          #+#    #+#             */
/*   Updated: 2022/10/18 13:02:58 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	char	*s2;
	int		i;

	c2 = (char)c;
	s2 = (char *)s;
	i = ft_strlen(s2);
	if (c2 == '\0')
		return (&s2[i]);
	while (i >= 0)
	{
		if (s2[i] == c2)
			return (&s2[i]);
		i--;
	}
	return (NULL);
}
/*
int main()
{
	char c = '\0';
	char str[] = "123456789";
	char *res;
	printf("%s\n", str);
	res = ft_strrchr(str, c);
	printf("%s\n", res);
}*/
