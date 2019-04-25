/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 21:15:05 by hmiyake           #+#    #+#             */
/*   Updated: 2018/09/24 14:29:45 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
	int			mag;
}				t_map;

typedef struct	s_fdf
{
	t_map		**coor;
	void		*mlx_ptr;
	void		*win_ptr;
	char		***arr_ele;
	t_map		*map;
	int			x[2];
	int			y[2];
	int			z[2];
	int			window[2];
	int			start[2];
	int			mag;
	int			tmp;
	int			tmp2;
	int			tmp3;
	int			angle[2];
}				t_fdf;

void			dot_to_dot(t_map *cooor, t_map *cooor2, t_fdf *fdf);
void			draw(t_fdf *fdf, t_map *map);
void			same_x(int *tmp, t_map *coor2, t_fdf *fdf);
void			within_one(int *tmp, double *a, t_map *coor2, t_fdf *fdf);
void			rest(int *tmp, double *a, t_map *coor2, t_fdf *fdf);
int				key(int keycode, t_fdf *fdf);
void			rotate(t_fdf *fdf);
void			rotate_2(t_fdf *fdf);
void			center(t_fdf *fdf);
void			finalize(t_fdf *fdf);
void			find_biggest_z(t_fdf *fdf);
void			find_coor(t_map *map, t_fdf *fdf);
char			***split_line(char **arr, t_map *map);
void			save_line(char **line, char **argv, char **arr);
char			**malloc_arr(char **line, char **argv, char **arr, t_map *map);
int				error_message(char *s);
void			set_window(t_fdf *fdf);
void			free_coor(t_fdf *fdf);
void			free_arr(char **arr);
void			free_arr_ele(char ***arr_ele);
void			set_mag(t_fdf *fdf);
void			error_and_exit(void);
int				error_check(t_fdf *fdf);
void			checkline(char **line);

#endif
