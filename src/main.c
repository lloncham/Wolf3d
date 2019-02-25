/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:33:09 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/25 14:09:24 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	mlx(t_wolf *ptr)
{
	int bpp;
	int endian;
	int size_l;

	ptr->mlx = mlx_init();
//	ptr->win = mlx_new_window(ptr->mlx, ptr->size_w, ptr->size_h, "Wolf3D");
//	ptr->img = mlx_new_image(ptr->mlx, ptr->size_w, ptr->size_h);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &bpp, &size_l, &endian);
	//mlx_hook(ptr->win, 2, 0, deal_key, ptr);
	//mlx_hook(ptr->win, 6, 0, motion_hook, ptr);
	//mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	//put_info(ptr);
	mlx_loop(ptr->mlx);
}

int		main()
{
	t_wolf	ptr;

	ptr = (ptr);
	mlx(&ptr);
	return (0);
}
