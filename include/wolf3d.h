/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:43:48 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/25 16:00:01 by louali           ###   ########.fr       */
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

#endif
