/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:43:05 by louali            #+#    #+#             */
/*   Updated: 2019/03/12 14:50:13 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_menu(t_wolf *ptr, int bpp, int endian)
{
	int	lon;
	int lar;

	ptr->text[4] = mlx_xpm_file_to_image(ptr->mlx, "xpm/e.xpm",
			&lar, &lon);
	ptr->t_data[4] = (int *)mlx_get_data_addr(ptr->text[4], &bpp,
			&ptr->t_size[4], &endian);
	ptr->text[3] = mlx_xpm_file_to_image(ptr->mlx, "xpm/fond.XPM",
			&lar, &lon);
	ptr->t_data[3] = (int *)mlx_get_data_addr(ptr->text[3], &bpp,
			&ptr->t_size[3], &endian);
	ptr->text[5] = mlx_xpm_file_to_image(ptr->mlx, "xpm/bois.XPM",
			&lar, &lon);
	ptr->t_data[5] = (int *)mlx_get_data_addr(ptr->text[3], &bpp,
			&ptr->t_size[5], &endian);
}

void	load_feu(t_wolf *ptr, int bpp, int endian)
{
	int lon;
	int lar;
	
	ptr->text[12] = mlx_xpm_file_to_image(ptr->mlx, "xpm/feu.xpm",
			&lar, &lon);
	ptr->t_data[12] = (int *)mlx_get_data_addr(ptr->text[12], &bpp,
		&ptr->t_size[12], &endian);
	ptr->text[13] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol8.xpm",
			&lar, &lon);
	ptr->t_data[13] = (int *)mlx_get_data_addr(ptr->text[13], &bpp,
			&ptr->t_size[13], &endian);
	ptr->text[14] = mlx_xpm_file_to_image(ptr->mlx, "xpm/feu1.xpm",
			&lar, &lon);
	ptr->t_data[14] = (int *)mlx_get_data_addr(ptr->text[14], &bpp,
			&ptr->t_size[14], &endian);
}

void	load_glace(t_wolf *ptr, int bpp, int endian)
{
	int lon;
	int lar;
	
	ptr->text[9] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur9.xpm",
			&lar, &lon);
	ptr->t_data[9] = (int *)mlx_get_data_addr(ptr->text[9],
		&bpp, &ptr->t_size[9], &endian);
	ptr->text[10] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol7.xpm",
			&lar, &lon);
	ptr->t_data[10] = (int *)mlx_get_data_addr(ptr->text[10],
			&bpp, &ptr->t_size[10], &endian);
	ptr->text[11] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol4.xpm",
			&lar, &lon);
	ptr->t_data[11] = (int *)mlx_get_data_addr(ptr->text[11],
			&bpp, &ptr->t_size[11], &endian);
}

void	load_xpm2(t_wolf *ptr, int bpp, int endian)
{
	int lon;
	int lar;

	ptr->text[7] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur2.xpm",
			&lar, &lon);
	ptr->t_data[7] = (int *)mlx_get_data_addr(ptr->text[7], &bpp, &ptr->t_size[7],
			&endian);
	ptr->text[8] = mlx_xpm_file_to_image(ptr->mlx, "xpm/plafond.xpm",
			&lar, &lon);
	ptr->t_data[8] = (int *)mlx_get_data_addr(ptr->text[8], &bpp, &ptr->t_size[8],
			&endian);

	ptr->text[15] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur7.xpm", &lar,
			&lon);
	ptr->t_data[15] = (int *)mlx_get_data_addr(ptr->text[15], &bpp,
			&ptr->t_size[15], &endian);
	ptr->text[16] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol1.xpm", &lar,
			&lon);
	ptr->t_data[16] = (int *)mlx_get_data_addr(ptr->text[16], &bpp,
			&ptr->t_size[16], &endian);
}

void	load_xpm(t_wolf *ptr, int bpp, int endian)
{
	int	lon;
	int	lar;

	ptr->text[6] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur4.xpm",
			&lar, &lon);
	ptr->t_data[6] = (int *)mlx_get_data_addr(ptr->text[6], &bpp, &ptr->t_size[6],
			&endian);
	ptr->text[2] = mlx_xpm_file_to_image(ptr->mlx, "xpm/sol2.xpm",
			&lar, &lon);
	ptr->t_data[2] = (int *)mlx_get_data_addr(ptr->text[2], &bpp, &ptr->t_size[2],
			&endian);
	ptr->text[1] = mlx_xpm_file_to_image(ptr->mlx, "xpm/plafond6.xpm", &lar,
			&lon);
	ptr->t_data[1] = (int *)mlx_get_data_addr(ptr->text[1], &bpp, &ptr->t_size[1],
			&endian);
	ptr->text[0] = mlx_xpm_file_to_image(ptr->mlx, "xpm/mur3.xpm", &lar,
			&lon);
	ptr->t_data[0] = (int *)mlx_get_data_addr(ptr->text[0], &bpp, &ptr->t_size[0],
			&endian);
	load_xpm2(ptr, bpp, endian);
	load_menu(ptr, bpp, endian);
	load_glace(ptr, bpp, endian);
	load_feu(ptr, bpp, endian);
}
