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
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
}					t_wolf;

#endif
