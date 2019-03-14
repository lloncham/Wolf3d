/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:33:09 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/14 16:59:46 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	reset(int key, t_wolf *r)
{
	if (key == DEL && r->start == 1)
	{
		bzero(r->img_data, WEI * H * 4);
		r->dir_x = -1;
		r->dir_y = 0;
		r->plane_x = 0;
		r->plane_y = 1;
		r->y = 0;
		raycast(r);
	}
}

int		press_key(int key, t_wolf *r)
{
	if (key == 53)
	{
		system("killall afplay 2&>/dev/null >/dev/null");
		exit(0);
	}
	key == ENTER || key == 36 ? r->start = 1 : 0;
	key == GAUCHE ? r->press[0] = 1 : 0;
	key == DROITE ? r->press[1] = 1 : 0;
	key == BAS || key == S ? r->press[2] = 1 : 0;
	key == HAUT || key == W ? r->press[3] = 1 : 0;
	key == SHIFT ? r->press[5] = 1 : 0;
	key == 4 ? r->press[4] = 1 : 0;
	key == 17 ? r->textures = 1 : 0;
	if (key == TEXTURE)
	{
		r->press[6]++;
		basic_music(r);
	}
	key == A ? r->press[7] = 1 : 0;
	key == D ? r->press[8] = 1 : 0;
	reset(key, r);
	return (0);
}

int		release_key(int key, t_wolf *r)
{
	key == 4 ? r->press[4] = 0 : 0;
	key == GAUCHE ? r->press[0] = 0 : 0;
	key == SHIFT ? r->press[5] = 0 : 0;
	key == DROITE ? r->press[1] = 0 : 0;
	key == BAS || key == S ? r->press[2] = 0 : 0;
	key == HAUT || key == W ? r->press[3] = 0 : 0;
	key == A ? r->press[7] = 0 : 0;
	key == D ? r->press[8] = 0 : 0;
	return (0);
}

int		ft_close(t_wolf *param)
{
	(void)param;
	exit(0);
	return (1);
}

int		main(int ac, char **av)
{
	t_wolf	ptr;
	int		bpp;
	int		size;
	int		endian;

	signal(SIGINT, ft_kill);
	if (ac != 2)
		error("usage : [./wolf3d] [map]");
	ptr = read_file(av);
	var_init(&ptr);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WEI, H, "Wolf3D");
	ptr.img = mlx_new_image(ptr.mlx, WEI, H);
	ptr.img_data = (int *)mlx_get_data_addr(ptr.img, &bpp, &size, &endian);
	load_textures(&ptr, bpp, endian);
	start_screen(ptr);
	mlx_hook(ptr.win, 17, 0, ft_close, &ptr);
	mlx_hook(ptr.win, 2, 0, press_key, &ptr);
	system("afplay song/song4.mp3&");
	mlx_hook(ptr.win, 3, 0, release_key, &ptr);
	mlx_loop_hook(ptr.mlx, deal_key, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
