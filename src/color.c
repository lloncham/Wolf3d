#include "../include/wolf3d.h"

void	choose_color(int color, int texture, t_wolf *c, int nb)
{
	if (c->textures == 1)
		c->color = texture;
	else
		c->color = color;
}
