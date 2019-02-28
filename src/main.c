/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:33:09 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/28 15:29:11 by lloncham         ###   ########.fr       */
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
	ptr.dir_x = -1;
	ptr.dir_y = 0;
	ptr.plane_x = 0;
	ptr.plane_y = 1;
	ptr.y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, W, H, "Wolf3D");
	ptr.img = mlx_new_image(ptr.mlx, W, H);
	ptr.img_data = (int *)mlx_get_data_addr(ptr.img, &bpp, &size, &endian);
	load_xpm(&ptr, bpp, size, endian);
	raycast(&ptr);
	mlx_hook(ptr.win, 2, 0, deal_key, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
