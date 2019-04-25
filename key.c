/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 01:58:00 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:33:54 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	re_do(t_fdf *fdf)
{
	find_coor(fdf->map, fdf);
	rotate(fdf);
	rotate_2(fdf);
	center(fdf);
	finalize(fdf);
	draw(fdf, fdf->map);
}

void	clear_and_free(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	free_coor(fdf);
}

void	move(int keycode, t_fdf *fdf)
{
	if (keycode == 124)
	{
		clear_and_free(fdf);
		fdf->tmp = fdf->tmp + 5;
		re_do(fdf);
	}
	if (keycode == 123)
	{
		clear_and_free(fdf);
		fdf->tmp = fdf->tmp - 5;
		re_do(fdf);
	}
	if (keycode == 126)
	{
		clear_and_free(fdf);
		fdf->tmp2 = fdf->tmp2 - 5;
		re_do(fdf);
	}
	if (keycode == 125)
	{
		clear_and_free(fdf);
		fdf->tmp2 = fdf->tmp2 + 5;
		re_do(fdf);
	}
}

void	rotation(int keycode, t_fdf *fdf)
{
	if (keycode == 7)
	{
		clear_and_free(fdf);
		fdf->angle[0] = fdf->angle[0] + 5;
		re_do(fdf);
	}
	if (keycode == 8)
	{
		clear_and_free(fdf);
		fdf->angle[0] = fdf->angle[0] - 5;
		re_do(fdf);
	}
	if (keycode == 16)
	{
		clear_and_free(fdf);
		fdf->angle[1] = fdf->angle[1] + 5;
		re_do(fdf);
	}
	if (keycode == 32)
	{
		clear_and_free(fdf);
		fdf->angle[1] = fdf->angle[1] - 5;
		re_do(fdf);
	}
}

int		key(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	if (keycode == 24)
	{
		clear_and_free(fdf);
		fdf->mag = fdf->mag + 5;
		re_do(fdf);
	}
	if (keycode == 27 && fdf->mag > 5)
	{
		clear_and_free(fdf);
		fdf->mag = fdf->mag - 5;
		re_do(fdf);
	}
	move(keycode, fdf);
	rotation(keycode, fdf);
	return (0);
}
