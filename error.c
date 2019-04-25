/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:32:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:31:25 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_and_exit(void)
{
	perror("ERROR");
	exit(0);
}

void	wrong_line_length(int l, int j)
{
	if (l != j && l != 0)
	{
		ft_printf("Found wrong line length. Exiting.\n");
		exit(0);
	}
}

int		invalid_file(t_fdf *fdf, int i, int j, int k)
{
	if ((fdf->arr_ele[i][j][k] >= '0' && fdf->arr_ele[i][j][k] <= '9')
	|| (fdf->arr_ele[i][j][k] == '-' && (fdf->arr_ele[i][j][k + 1] >= '0'
	&& fdf->arr_ele[i][j][k + 1] <= '9')))
		k++;
	else
	{
		ft_printf("invalid file\n");
		exit(0);
	}
	return (k);
}

int		error_check(t_fdf *fdf)
{
	int		i;
	size_t	j;
	int		k;
	size_t	l;

	i = 0;
	j = 0;
	l = j;
	while (i < fdf->map->y)
	{
		wrong_line_length(l, j);
		l = j;
		j = 0;
		while (fdf->arr_ele[i][j] != NULL)
		{
			k = 0;
			while (fdf->arr_ele[i][j][k] != '\0')
				k = invalid_file(fdf, i, j, k);
			j++;
		}
		i++;
	}
	return (0);
}

void	checkline(char **line)
{
	int i;
	int valid;

	i = 0;
	valid = 0;
	if (*line)
	{
		while ((*line)[i])
		{
			if ((*line)[i] >= '0' && (*line)[i] <= '9')
				valid = 1;
			i++;
		}
		free(*line);
		if (!valid)
		{
			ft_printf("invalid file\n");
			exit(0);
		}
	}
}
