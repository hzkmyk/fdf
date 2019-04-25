/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 10:51:18 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/23 21:37:25 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_to_dot(t_map *coor, t_map *coor2, t_fdf *fdf)
{
	double	a[3];
	int		tmp[2];

	tmp[0] = coor->x;
	tmp[1] = coor->y;
	if (tmp[0] == coor2->x)
		same_x(tmp, coor2, fdf);
	else
	{
		a[0] = (double)(tmp[1] - coor2->y) / (tmp[0] - coor2->x);
		a[1] = (-1 * tmp[0] * a[0]) + tmp[1];
		if (a[0] >= -1 && a[0] <= 1)
			within_one(tmp, a, coor2, fdf);
		else
			rest(tmp, a, coor2, fdf);
	}
}

void	draw(t_fdf *fdf, t_map *map)
{
	int i;
	int	j;

	i = 0;
	j = 1;
	while (fdf->coor[i])
	{
		while (((i + 1) < (map->x * j)))
		{
			dot_to_dot(fdf->coor[i], fdf->coor[i + 1], fdf);
			i++;
		}
		i++;
		j++;
	}
	i = 0;
	while (fdf->coor[i])
	{
		while ((i + map->x) < (map->x * map->y))
		{
			dot_to_dot(fdf->coor[i], fdf->coor[i + map->x], fdf);
			i++;
		}
		i++;
	}
}
