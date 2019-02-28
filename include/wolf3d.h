/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:43:48 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/28 15:46:33 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include <math.h> 

#define W 1180
#define H 720
#define GAUCHE 123
#define DROITE 124
#define HAUT 126
#define BAS 125
#define DEL 51

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
	double			start_x;
	double			start_y;
	double			pos_x;
	double			pos_y;

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
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perpwalldist;
	int				hline;
	int				draw_start;
	int				draw_end;
	int				y;
	int				color;

//textures
	int				t_size[3];
	void			*text[3];
	int				*text_data[3];
}					t_wolf;

int					ft_count_col(char *split);
t_wolf				read_file(char **av);
void				error(char *s);
int					valid_char(char *s, t_wolf *r, int y);
int					valid_char(char *str, t_wolf *r, int y);
void				error(char *str);
void				ft_put_pixel(int x, int y, int color, t_wolf *p);
void				load_xpm(t_wolf *ptr, int bpp, int size, int endian);
void				raycast(t_wolf *ptr);
int					deal_key(int key, t_wolf *ptr);

#endif
