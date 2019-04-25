/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:45:25 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:23:51 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	same_x(int *tmp, t_map *coor2, t_fdf *fdf)
{
	if (tmp[1] >= coor2->y)
	{
		while (tmp[1] >= coor2->y)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tmp[0], tmp[1], 0xFFFFFF);
			tmp[1] = tmp[1] - 1;
		}
	}
	else if (tmp[1] < coor2->y)
	{
		while (tmp[1] < coor2->y)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tmp[0], tmp[1], 0xFFFFFF);
			tmp[1] = tmp[1] + 1;
		}
	}
}

void	ceil_or_floor(int *tmp, double *a)
{
	if ((ceil(a[2]) - a[2]) < (a[2] - floor(a[2])))
		tmp[1] = ceil(a[2]);
	else
		tmp[1] = floor(a[2]);
}

void	within_one(int *tmp, double *a, t_map *coor2, t_fdf *fdf)
{
	if (tmp[0] > coor2->x)
	{
		while (tmp[0] > coor2->x)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tmp[0], tmp[1], 0xFFFFFF);
			tmp[0] = tmp[0] - 1;
			a[2] = (a[0] * tmp[0]) + a[1];
			ceil_or_floor(tmp, a);
		}
	}
	else
	{
		while (tmp[0] < coor2->x)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tmp[0], tmp[1], 0xFFFFFF);
			tmp[0] = tmp[0] + 1;
			a[2] = (a[0] * tmp[0]) + a[1];
			ceil_or_floor(tmp, a);
		}
	}
}

void	ceil_or_floor2(int *tmp, double *a)
{
	if ((ceil(a[2]) - a[2]) < (a[2] - floor(a[2])))
		tmp[0] = ceil(a[2]);
	else
		tmp[0] = floor(a[2]);
}

void	rest(int *tmp, double *a, t_map *coor2, t_fdf *fdf)
{
	if (tmp[1] > coor2->y)
	{
		while (tmp[1] > coor2->y)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tmp[0], tmp[1], 0xFFFFFF);
			tmp[1] = tmp[1] - 1;
			a[2] = (tmp[1] - a[1]) / a[0];
			ceil_or_floor2(tmp, a);
		}
	}
	else
	{
		while (tmp[1] < coor2->y)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tmp[0], tmp[1], 0xFFFFFF);
			tmp[1] = tmp[1] + 1;
			a[2] = (tmp[1] - a[1]) / a[0];
			ceil_or_floor2(tmp, a);
		}
	}
}
