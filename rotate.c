/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:29:45 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:32:07 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *fdf)
{
	int	temp;
	int	i;

	i = 0;
	while (fdf->coor[i])
	{
		temp = fdf->coor[i]->y;
		fdf->coor[i]->y = (cos(fdf->angle[0] * M_PI / 180) * fdf->coor[i]->y)
		- (sin(fdf->angle[0] * M_PI / 180) * fdf->coor[i]->z);
		fdf->coor[i]->z = (cos(fdf->angle[0] * M_PI / 180) * fdf->coor[i]->z)
		+ (sin(fdf->angle[0] * M_PI / 180) * temp);
		if (i == 0)
		{
			fdf->y[0] = fdf->coor[i]->y;
			fdf->y[1] = fdf->coor[i]->y;
		}
		if (fdf->coor[i]->y < fdf->y[0])
			fdf->y[0] = fdf->coor[i]->y;
		else if (fdf->coor[i]->y > fdf->y[1])
			fdf->y[1] = fdf->coor[i]->y;
		i++;
	}
}

void	find_min_n_max_xz(t_fdf *fdf, int i)
{
	if (i == 0)
	{
		fdf->x[0] = fdf->coor[i]->x;
		fdf->x[1] = fdf->coor[i]->x;
		fdf->z[0] = fdf->coor[i]->z;
		fdf->z[1] = fdf->coor[i]->z;
	}
	if (fdf->coor[i]->x < fdf->x[0])
		fdf->x[0] = fdf->coor[i]->x;
	else if (fdf->coor[i]->x > fdf->x[1])
		fdf->x[1] = fdf->coor[i]->x;
	if (fdf->coor[i]->z < fdf->z[0])
		fdf->z[0] = fdf->coor[i]->z;
	else if (fdf->coor[i]->z > fdf->z[1])
		fdf->z[1] = fdf->coor[i]->z;
}

void	rotate_2(t_fdf *fdf)
{
	int	temp;
	int	i;

	i = 0;
	while (fdf->coor[i])
	{
		temp = fdf->coor[i]->x;
		fdf->coor[i]->x = (cos(fdf->angle[1] * M_PI / 180) * fdf->coor[i]->x)
		- (sin(fdf->angle[1] * M_PI / 180) * fdf->coor[i]->z);
		fdf->coor[i]->z = (cos(fdf->angle[1] * M_PI / 180) * fdf->coor[i]->z)
		+ (sin(fdf->angle[1] * M_PI / 180) * temp);
		find_min_n_max_xz(fdf, i);
		i++;
	}
}
