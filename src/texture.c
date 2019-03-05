/*                                                    */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:56:10 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/28 12:55:01 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	load_xpm(t_wolf *ptr, int bpp, int size, int endian)
{
	int	lon;
	int	lar;

	ptr->text[4]= mlx_xpm_file_to_image(ptr->mlx, "../xpm/e.xpm", &lar, &lon);
	ptr->text_data[4] = (int *)mlx_get_data_addr(ptr->text[4], &bpp, &size, &endian);
	ptr->t_size[4] = size;
	ptr->text[3]= mlx_xpm_file_to_image(ptr->mlx, "../xpm/fond.xpm", &lar, &lon);
	ptr->text_data[3] = (int *)mlx_get_data_addr(ptr->text[3], &bpp, &size, &endian);
	ptr->t_size[3] = size;
	ptr->text[2]= mlx_xpm_file_to_image(ptr->mlx, "../xpm/ciel01.xpm", &lar, &lon);
	ptr->text_data[2] = (int *)mlx_get_data_addr(ptr->text[2], &bpp, &size, &endian);
	ptr->t_size[2] = size;
	ptr->text[1]= mlx_xpm_file_to_image(ptr->mlx, "../xpm/terre.xpm", &lar, &lon);
	ptr->text_data[1] = (int *)mlx_get_data_addr(ptr->text[1], &bpp, &size, &endian);
	ptr->t_size[1] = size;
	ptr->text[0] = mlx_xpm_file_to_image(ptr->mlx, "../xpm/haie.XPM", &lar, &lon);
	printf("lar %d,lon %d\n", lar, lon);
	ptr->text_data[0] = (int *)mlx_get_data_addr(ptr->text[0], &bpp, &size, &endian);
	ptr->t_size[0] = size;
}
