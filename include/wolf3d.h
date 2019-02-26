/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:43:48 by lloncham          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/26 14:48:04 by louali           ###   ########.fr       */
=======
/*   Updated: 2019/02/26 13:28:58 by lloncham         ###   ########.fr       */
>>>>>>> lloncham
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include <math.h> 

#define W 480
#define H 240

typedef struct		s_wolf
{
//fenetre
	void			*mlx;
	void			*img;
	void			*win;
	int				*img_data;

//tableau
	int				**tab;
	int				nbc;
	int				nbl;
	int				j;
//	int				y_max;
	double			start_x;
	double			start_y;

//raycasting
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raypos_x;
	double			raypos_y;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			step_x;
	double			step_y;
	int				hit;
	int				side;
	double			perpwalldist;
	int				hline;
	int				draw_start;
	int				draw_end;
	int				y;
	int				color;

	double			time;
	double			old_time;
}					t_wolf;

<<<<<<< HEAD
int					**read_file(char **av);
void				error(char *s);
int					valid_char(char *s, t_wolf *r, int y);
=======
int		valid_char(char *str, t_wolf *r, int y);
void	error(char *str);
t_wolf	read_file(char **av);
void	ft_put_pixel(int x, int y, int color, t_wolf *p);

>>>>>>> lloncham
#endif
