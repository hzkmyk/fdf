/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:15:06 by hmiyake           #+#    #+#             */
/*   Updated: 2018/05/05 18:34:20 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnumofw(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*mallocandcopy(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (str)
	{
		while (s[i] != '\0' && s[i] != c)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		now;

	i = 0;
	if (!s)
		return (0);
	now = getnumofw(s, c);
	array = (char **)malloc(sizeof(char *) * (now + 1));
	if (array)
	{
		while (i < now)
		{
			while (*s == c)
				s++;
			if (*s != '\0')
				array[i] = mallocandcopy(s, c);
			while (*s != c && *s != '\0')
				s++;
			i++;
		}
		array[i] = 0;
	}
	return (array);
}
