/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:04:34 by afrigger          #+#    #+#             */
/*   Updated: 2022/10/20 11:16:22 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	//size_t	i;

	if (!s)
		return (NULL);
	//i = 0;
	if (start >= ft_strlen(s))
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
/*
	size_t i;
	char *res;
	char *s2;
	size_t len2;

	i = 0;
	s2 = (char *)s;
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (start >= len2)
	{
		res[i] = '\0';
		return (res);
	}
	while (s2[start] && i < len && i < len2)
	{
		res[i] = s2[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);*/

/*
int main()
{
 	char *str = "i just want this part #############";
 	size_t size = 10;
	char *res;
	res = ft_substr(str, 5 ,size);
	printf("%s\n" ,res);
	return 0;
}*/
