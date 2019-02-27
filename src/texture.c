/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:56:10 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/27 11:59:06 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	print_xpm(t_wolf *ptr, char *xpm, int x, int y)
{
	ptr->img = mlx_xpm_file_to_image(ptr->mlx, xpm, W, H);
}
