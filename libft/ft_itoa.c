/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:17:06 by hmiyake           #+#    #+#             */
/*   Updated: 2018/05/05 18:33:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlenofi(int c)
{
	int	len;

	len = 0;
	if (c < 0)
		len = len + 1;
	if (c == 0)
		len = 1;
	while (c != 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		neg;

	len = getlenofi(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	neg = 1;
	if (n < 0)
		neg = -1;
	if (num)
	{
		num[len] = '\0';
		if (n < 0)
			num[0] = '-';
		if (n == 0)
			num[0] = '0';
		while (n != 0)
		{
			num[len - 1] = ((n % 10) * neg + '0');
			n = n / 10;
			len--;
		}
		return (num);
	}
	return (0);
}
