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

	ptr->text[2]= mlx_xpm_file_to_image(ptr->mlx, "../xpm/ciel.xpm", &lar, &lon);
	ptr->text_data[2] = (int *)mlx_get_data_addr(ptr->text[2], &bpp, &size, &endian);
	printf("size1 = %d\n", size);
	ptr->text[1]= mlx_xpm_file_to_image(ptr->mlx, "../xpm/gravier.xpm", &lar, &lon);
	ptr->text_data[1] = (int *)mlx_get_data_addr(ptr->text[1], &bpp, &size, &endian);
	printf("size2 = %d\n", size);
	ptr->text[0] = mlx_xpm_file_to_image(ptr->mlx, "../xpm/text.XPM", &lar, &lon);
	ptr->text_data[0] = (int *)mlx_get_data_addr(ptr->text[0], &bpp, &size, &endian);
	printf("size = %d", size);
}
