/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:55:08 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:43:04 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_coor(t_fdf *fdf, int i, int j, int k)
{
	fdf->coor[i] = (t_map *)malloc(sizeof(t_map));
	fdf->coor[i]->x = k;
	fdf->coor[i]->x = fdf->coor[i]->x * fdf->mag;
	fdf->coor[i]->x = fdf->coor[i]->x + fdf->tmp;
	fdf->coor[i]->y = j;
	fdf->coor[i]->y = fdf->coor[i]->y * fdf->mag;
	fdf->coor[i]->y = fdf->coor[i]->y + fdf->tmp2;
	fdf->coor[i]->z = ft_atoi(fdf->arr_ele[j][k]);
	fdf->coor[i]->z = fdf->coor[i]->z * fdf->mag;
}

void	find_coor(t_map *map, t_fdf *fdf)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	fdf->coor = (t_map **)malloc(sizeof(t_map *) * ((map->x * map->y) + 1));
	while (fdf->arr_ele[j])
	{
		k = 0;
		while (fdf->arr_ele[j][k])
		{
			update_coor(fdf, i, j, k);
			i++;
			k++;
		}
		j++;
	}
	fdf->coor[i] = NULL;
}

char	***split_line(char **arr, t_map *map)
{
	int		i;
	char	***arr_ele;

	i = 0;
	arr_ele = (char ***)malloc(sizeof(char **) * ((map->y) + 1));
	while (i < map->y)
	{
		arr_ele[i] = ft_strsplit(arr[i], ' ');
		i++;
	}
	arr_ele[i] = NULL;
	i = 1;
	while (arr_ele[0][i])
		i++;
	map->x = i;
	return (arr_ele);
}

void	save_line(char **line, char **argv, char **arr)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, line))
	{
		arr[i] = ft_strdup(*line);
		free(*line);
		i++;
	}
	arr[i] = NULL;
	close(fd);
}

char	**malloc_arr(char **line, char **argv, char **arr, t_map *map)
{
	int	fd;
	int	i;

	map->y = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_and_exit();
	i = get_next_line(fd, line);
	checkline(line);
	if (0 >= i)
		error_and_exit();
	while (i)
	{
		map->y++;
		i = get_next_line(fd, line);
		checkline(line);
	}
	arr = (char **)malloc(sizeof(char *) * (map->y + 1));
	close(fd);
	return (arr);
}
