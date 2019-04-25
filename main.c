/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 23:52:16 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:24:57 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_coor(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->coor[i])
	{
		free(fdf->coor[i]);
		i++;
	}
	free(fdf->coor);
}

void	main_rest(char **arr, t_fdf *fdf)
{
	fdf->arr_ele = split_line(arr, fdf->map);
	error_check(fdf);
	find_coor(fdf->map, fdf);
	rotate(fdf);
	rotate_2(fdf);
	set_mag(fdf);
	free_coor(fdf);
	find_coor(fdf->map, fdf);
	rotate(fdf);
	rotate_2(fdf);
	set_window(fdf);
	center(fdf);
	finalize(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr =
	mlx_new_window(fdf->mlx_ptr, fdf->window[0], fdf->window[1], "mlx 42");
	draw(fdf, fdf->map);
	mlx_key_hook(fdf->win_ptr, key, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int		main(int argc, char **argv)
{
	char	**line;
	char	**arr;
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->tmp = 0;
	fdf->tmp2 = 0;
	fdf->tmp3 = 0;
	fdf->angle[0] = 15;
	fdf->angle[1] = 15;
	fdf->window[0] = 1000;
	fdf->window[1] = 800;
	fdf->mag = 5;
	arr = NULL;
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (0);
	}
	line = malloc(sizeof(char *));
	arr = malloc_arr(line, argv, arr, fdf->map);
	save_line(line, argv, arr);
	main_rest(arr, fdf);
}
