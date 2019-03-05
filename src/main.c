/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:33:09 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/03 13:50:47 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		main(int ac, char **av)
{
	t_wolf	ptr;
	int		bpp;
	int		size;
	int		endian;

	if (ac != 2)
		error("usage : [./wolf3d] [map]");
	ptr = read_file(av);
	ptr.textures = 0;
	ptr.dir_x = -1;
	ptr.press[0] = 0;
	ptr.press[1] = 0;
	ptr.press[2] = 0;
	ptr.press[3] = 0;
	ptr.dir_y = 0;
	ptr.plane_x = 0;
	ptr.plane_y = 1;
	ptr.y = 0;
	ptr.start = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, W, H, "Wolf3D");
	ptr.img = mlx_new_image(ptr.mlx, W, H);
	ptr.img_data = (int *)mlx_get_data_addr(ptr.img, &bpp, &size, &endian);
	load_xpm(&ptr, bpp, size, endian);
	start_screen(ptr);
//	raycast(&ptr);
	mlx_hook(ptr.win, 17, 0, ft_close, &ptr);
	mlx_hook(ptr.win, 2, 0, press_key, &ptr);
	mlx_hook(ptr.win, 3, 0, release_key, &ptr);
	mlx_loop_hook(ptr.mlx, deal_key, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
