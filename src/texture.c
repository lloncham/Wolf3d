/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:43:05 by louali            #+#    #+#             */
/*   Updated: 2019/03/11 18:05:01 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_menu(t_wolf *ptr, int bpp, int size, int endian)
{
	int	lon;
	int lar;

	ptr->text[4] = mlx_xpm_file_to_image(ptr->mlx, "xpm/e.xpm",
			&lar, &lon);
	ptr->text_data[4] = (int *)mlx_get_data_addr(ptr->text[4], &bpp,
			&size, &endian);
	ptr->t_size[4] = size;
	ptr->text[3] = mlx_xpm_file_to_image(ptr->mlx, "xpm/fond.XPM",
			&lar, &lon);
	ptr->text_data[3] = (int *)mlx_get_data_addr(ptr->text[3], &bpp,
			&size, &endian);
	ptr->t_size[3] = size;
	ptr->text[5] = mlx_xpm_file_to_image(ptr->mlx, "xpm/bois.XPM",
			&lar, &lon);
	ptr->text_data[5] = (int *)mlx_get_data_addr(ptr->text[3], &bpp,
			&size, &endian);
	ptr->t_size[5] = size;
}

void	load_feu(t_wolf *ptr, int bpp, int size, int endian)
{
	int lon;
	int lar;
	
	ptr->text[12] = mlx_xpm_file_to_image(ptr->mlx, "xpm/feu.xpm",
			&lar, &lon);
	ptr->text_data[12] = (int *)mlx_get_data_addr(ptr->text[12], &bpp, &size,
			&endian);
	ptr->t_size[12] = size;
	ptr->text[13] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol8.xpm",
			&lar, &lon);
	ptr->text_data[13] = (int *)mlx_get_data_addr(ptr->text[13], &bpp, &size,
			&endian);
	ptr->t_size[13] = size;
	ptr->text[14] = mlx_xpm_file_to_image(ptr->mlx, "xpm/feu1.xpm",
			&lar, &lon);
	ptr->text_data[14] = (int *)mlx_get_data_addr(ptr->text[14], &bpp, &size,
			&endian);
	ptr->t_size[14] = size;
}

void	load_glace(t_wolf *ptr, int bpp, int size, int endian)
{
	int lon;
	int lar;
	
	ptr->text[9] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur9.xpm",
			&lar, &lon);
	ptr->text_data[9] = (int *)mlx_get_data_addr(ptr->text[9], &bpp, &size,
			&endian);
	ptr->t_size[9] = size;
	ptr->text[10] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol7.xpm",
			&lar, &lon);
	ptr->text_data[10] = (int *)mlx_get_data_addr(ptr->text[10], &bpp, &size,
			&endian);
	ptr->t_size[10] = size;
	ptr->text[11] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol4.xpm",
			&lar, &lon);
	ptr->text_data[11] = (int *)mlx_get_data_addr(ptr->text[11], &bpp, &size,
			&endian);
	ptr->t_size[11] = size;
}

void	load_xpm(t_wolf *ptr, int bpp, int size, int endian)
{
	int	lon;
	int	lar;

	ptr->text[6] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur6.xpm",
			&lar, &lon);
	ptr->text_data[6] = (int *)mlx_get_data_addr(ptr->text[6], &bpp, &size,
			&endian);
	ptr->t_size[6] = size;
	ptr->text[7] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur2.xpm",
			&lar, &lon);
	ptr->text_data[7] = (int *)mlx_get_data_addr(ptr->text[7], &bpp, &size,
			&endian);
	ptr->t_size[7] = size;
	ptr->text[8] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur6.xpm",
			&lar, &lon);
	ptr->text_data[8] = (int *)mlx_get_data_addr(ptr->text[8], &bpp, &size,
			&endian);
	ptr->t_size[8] = size;
	ptr->text[2] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol2.xpm",
			&lar, &lon);
	ptr->text_data[2] = (int *)mlx_get_data_addr(ptr->text[2], &bpp, &size,
			&endian);
	ptr->t_size[2] = size;
	ptr->text[1] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol5.xpm", &lar,
			&lon);
	ptr->text_data[1] = (int *)mlx_get_data_addr(ptr->text[1], &bpp, &size,
			&endian);
	ptr->t_size[1] = size;
	ptr->text[0] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur3.xpm", &lar,
			&lon);
	ptr->text_data[0] = (int *)mlx_get_data_addr(ptr->text[0], &bpp, &size,
			&endian);
	ptr->t_size[0] = size;
	load_menu(ptr, bpp, size, endian);
	load_glace(ptr, bpp, size, endian);
	load_feu(ptr, bpp, size, endian);
}
