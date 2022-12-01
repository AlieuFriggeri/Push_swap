/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:02:07 by afrigger          #+#    #+#             */
/*   Updated: 2022/10/21 11:07:35 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	checkfirst(char *str, char c)
{

}

int	count_words(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (str[0] != c)
		word++;
	while (str[i])
	{
		if (str[i] == c && i > 0 && str[i + 1] != c && str[i + 1])
			word++;
		i++;
	}
	return (word);
}

int	word_len(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c)
		len++;
	return (len);
}
*/
static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	int		i;
	char	*res;

	i = 0;
		res = (char *)malloc(sizeof(char) * (finish - start) + 1);
	if (!res)
		return (NULL);
	while (start < finish)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
/*
!!!!! CE SPLIT NE FONCTIONNEPAS COMME IL FAUT !!!!!!
char	**ft_split(char const *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	
	res = malloc(sizeof(char *) * (count_words((char *)str, c) + 1));
	if(!res)
		return (NULL);
	while (str[i] == c)
	{
		i++;
		j++;
	}
	while (str[i])
	{
		if ((str[i] == c && str[i + 1] != c) || str[i + 1] == '\0' )
		{
			if (str[i + 1] == '\0')
				i++;
			res[k] = word_dup((char *)str, j, i);
			j = i + 1;
			k++;
			i++;
		}
		i++;
	}
	res[count_words((char *)str, c)] = (NULL);
	return (res);
}
*/

char	**ft_split(char const *str, char const c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**res;

	i = 0;
	j = 0;
	res = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!str || !res)
		return (0);
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str)) && index >= 0)
		{
			res[j++] = word_dup(str, index, i);
			index = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
/*
int main()
{
	char	*str;
	char	sep;
	sep = '1';
	str = "1abc11111def11111111111ghi111111111klm11111";
	char **res;
	res = ft_split(str, sep);
	printf("%s\n", res[0]);
	printf("%s\n", res[1]);
	printf("%s\n", res[2]);
	printf("%s\n", res[3]);
	printf("%s\n", res[4]);
	printf("%s\n", res[5]);
	printf("%s\n", res[18]);


	return (0);
}*/