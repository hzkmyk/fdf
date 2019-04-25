/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:50:39 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:25:34 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_fdf *fdf)
{
	fdf->start[0] = (fdf->window[0]
	- (fdf->x[1] - fdf->x[0])) / 2;
	fdf->start[1] = (fdf->window[1]
	- (fdf->y[1] - fdf->y[0])) / 2;
}

void	finalize(t_fdf *fdf)
{
	int i;
	int	temp_x;
	int temp_y;

	i = 0;
	temp_x = (fdf->start[0] - fdf->x[0]);
	temp_y = (fdf->start[1] - fdf->y[0]);
	while (fdf->coor[i])
	{
		fdf->coor[i]->x = fdf->coor[i]->x + temp_x + fdf->tmp;
		fdf->coor[i]->y = fdf->coor[i]->y + temp_y + fdf->tmp2;
		i++;
	}
}

void	set_window(t_fdf *fdf)
{
	fdf->window[0] = (fdf->x[1] - fdf->x[0]) * 1.5;
	fdf->window[1] = (fdf->y[1] - fdf->y[0]) * 1.5;
}

void	set_mag(t_fdf *fdf)
{
	if ((fdf->x[1] - fdf->x[0]) < 50 && (fdf->y[1] - fdf->y[0]) < 50)
		fdf->mag = 40;
	else if ((fdf->x[1] - fdf->x[0]) < 100 && (fdf->y[1] - fdf->y[0]) < 100)
		fdf->mag = 25;
	else
		fdf->mag = 7;
}
