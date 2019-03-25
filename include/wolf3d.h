/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:43:48 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/18 14:41:40 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WEI 1180
# define H 720
# define W 13
# define S 1
# define A 0
# define D 2
# define GAUCHE 123
# define DROITE 124
# define HAUT 126
# define BAS 125
# define DEL 51
# define ENTER 76
# define SHIFT 257
# define TEXTURE 17

typedef struct		s_wolf
{
	void			*text[17];
	void			*mlx;
	void			*img;
	void			*win;
	int				bpp;
	int				endian;
	int				size;
	int				colori;
	int				*img_data;
	int				press[9];
	int				start;
	int				**tab;
	int				nbc;
	int				nbl;
	int				j;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				hline;
	int				draw_start;
	int				draw_end;
	int				y;
	int				col;
	int				textures;
	int				t_size[17];
	int				*t_data[17];
	int				ftex_x;
	int				ftex_y;
	int				texnum;
	int				texwidth;
	int				texheight;
	double			perpwalldist;
	double			vit;
	double			ang;
	double			px;
	double			drx;
	double			start_x;
	double			start_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raypos_x;
	double			raypos_y;
	double			raydir_x;
	double			raydir_y;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			wall_x;
	double			texx;
	double			texy;
	double			floor_x_wall;
	double			floor_y_wall;
	double			weight;
	double			currentfloor_x;
	double			currentfloor_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;

}					t_wolf;

void				start_screen(t_wolf r);
void				init_raycast(t_wolf *r, double x);
void				ray(t_wolf *r);
void				music(t_wolf *ptr);
void				text_wall(t_wolf *r, double x, double y);
void				text_floor(t_wolf *r, double x, double y);
void				basic_music(t_wolf *ptr);
void				var_init(t_wolf *ptr);
void				ft_kill(int sign);
void				free_tab(t_wolf *f);
void				choose_color(int color, int texture, t_wolf *c);
void				controls(t_wolf r);
void				error(char *str, t_wolf *w);
void				ft_put_pixel(int x, int y, int color, t_wolf *p);
void				load_textures(t_wolf *ptr, int bpp, int endian);
void				raycast(t_wolf *ptr);
void				mini_map(t_wolf r);
void				menu(t_wolf r);
int					ft_count_col(char *split);
int					valid_char(char *s, t_wolf *r, int y);
int					deal_key(t_wolf *ptr);
int					ft_close(t_wolf *param);
int					press_key(int key, t_wolf *ptr);
int					release_key(int key, t_wolf *ptr);
t_wolf				read_file(char **av);

#endif
