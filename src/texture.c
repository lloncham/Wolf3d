/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:43:05 by louali            #+#    #+#             */
/*   Updated: 2019/03/25 15:50:17 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_menu(t_wolf *ptr, int bpp, int endian)
{
	int	lon;
	int lar;

	if (!(ptr->text[4] = mlx_xpm_file_to_image(ptr->mlx, "textures/con.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[4] = (int *)mlx_get_data_addr(ptr->text[4], &bpp,
		&ptr->t_size[4], &endian);
	if (!(ptr->text[5] = mlx_xpm_file_to_image(ptr->mlx, "textures/fond.XPM",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[5] = (int *)mlx_get_data_addr(ptr->text[5], &bpp,
		&ptr->t_size[5], &endian);
	if (!(ptr->text[3] = mlx_xpm_file_to_image(ptr->mlx, "textures/acc.XPM",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[3] = (int *)mlx_get_data_addr(ptr->text[3], &bpp,
		&ptr->t_size[3], &endian);
}

void	load_glace_fire(t_wolf *ptr, int bpp, int endian)
{
	int lon;
	int lar;

	if (!(ptr->text[11] = mlx_xpm_file_to_image(ptr->mlx, "textures/glace.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[11] = (int *)mlx_get_data_addr(ptr->text[11],
		&bpp, &ptr->t_size[11], &endian);
	if (!(ptr->text[14] = mlx_xpm_file_to_image(ptr->mlx, "textures/feu.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[14] = (int *)mlx_get_data_addr(ptr->text[14], &bpp,
		&ptr->t_size[14], &endian);
}

void	load_text4(t_wolf *ptr, int bpp, int endian)
{
	int lon;
	int lar;

	if (!(ptr->text[7] = mlx_xpm_file_to_image(ptr->mlx, "textures/mur2.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[7] = (int *)mlx_get_data_addr(ptr->text[7], &bpp,
		&ptr->t_size[7], &endian);
	if (!(ptr->text[8] = mlx_xpm_file_to_image(ptr->mlx, "textures/plafond.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[8] = (int *)mlx_get_data_addr(ptr->text[8], &bpp,
		&ptr->t_size[8], &endian);
	if (!(ptr->text[15] = mlx_xpm_file_to_image(ptr->mlx, "textures/mur7.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[15] = (int *)mlx_get_data_addr(ptr->text[15], &bpp,
		&ptr->t_size[15], &endian);
	if (!(ptr->text[16] = mlx_xpm_file_to_image(ptr->mlx, "textures/sol1.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[16] = (int *)mlx_get_data_addr(ptr->text[16], &bpp,
		&ptr->t_size[16], &endian);
	load_glace_fire(ptr, bpp, endian);
}

void	load_textures(t_wolf *ptr, int bpp, int endian)
{
	int	lon;
	int	lar;

	if (!(ptr->text[6] = mlx_xpm_file_to_image(ptr->mlx, "textures/mur4.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[6] = (int *)mlx_get_data_addr(ptr->text[6], &bpp,
		&ptr->t_size[6], &endian);
	if (!(ptr->text[2] = mlx_xpm_file_to_image(ptr->mlx, "textures/sol2.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[2] = (int *)mlx_get_data_addr(ptr->text[2], &bpp,
		&ptr->t_size[2], &endian);
	if (!(ptr->text[1] = mlx_xpm_file_to_image(ptr->mlx,
		"textures/plafond6.xpm", &lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[1] = (int *)mlx_get_data_addr(ptr->text[1], &bpp,
		&ptr->t_size[1], &endian);
	if (!(ptr->text[0] = mlx_xpm_file_to_image(ptr->mlx, "textures/mur3.xpm",
		&lar, &lon)))
		error("Oops...you should check textures files", ptr);
	ptr->t_data[0] = (int *)mlx_get_data_addr(ptr->text[0], &bpp,
		&ptr->t_size[0], &endian);
	load_text4(ptr, bpp, endian);
	load_menu(ptr, bpp, endian);
}
