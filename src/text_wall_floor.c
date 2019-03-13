#include "wolf3d.h"

void	text_wall_option(t_wolf *r)
{
	if (r->press[6] % 5 == 2)
	{
		if (r->side == 1 && r->raydir_y > 0)
			r->color = r->t_data[0][r->t_size[0] / 4 * (int)r->tex_y + (int)r->tex_x];
		else if (r->side == 1 && r->raydir_y < 0)
			r->color = r->t_data[8][r->t_size[8] / 4 * (int)r->tex_y + (int)r->tex_x];
		else if (r->side == 0 && r->raydir_x < 0)
			r->color = r->t_data[7][r->t_size[7] / 4 * (int)r->tex_y + (int)r->tex_x];
		else
			r->color = r->t_data[6][r->t_size[6] / 4 * (int)r->tex_y + (int)r->tex_x];
	}
	if (r->press[6] % 5 == 1)
		r->color = 0xf2f2f2;
	else if (r->press[6] % 5 == 3)
		r->color = r->t_data[11][r->t_size[11] / 4 * (int)r->tex_y + (int)r->tex_x];
	else if (r->press[6] % 5 == 0)
		r->color = r->t_data[15][r->t_size[15] / 4 * (int)r->tex_y + (int)r->tex_x];
	else if (r->press[6] % 5 == 4)
		r->color = r->t_data[14][r->t_size[14] / 4 * (int)r->tex_y + (int)r->tex_x];
}

void	text_wall(t_wolf *r, double x, double y)
{
	r->wall_x -= floor((r->wall_x));
	r->tex_x = r->wall_x * r->texwidth;
	if (r->side == 0 && r->raydir_x > 0)
		r->tex_x = r->texwidth - r->tex_x - 1;
	if (r->side == 1 && r->raydir_y < 0)
		r->tex_x = r->texwidth - r->tex_x - 1;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		r->tex_y = (y * 2 - H + r->hline) * (r->texheight / 2) / r->hline;
		text_wall_option(r);
		if (r->side == 1)
			r->color = (r->color >> 1) & 8355711;
		ft_put_pixel((int)x, (int)y, r->color, r);
		y++;
	}
}

void	t_floor_option1(t_wolf *r, double x, double y)
{
	if (r->press[6] % 5 == 2)
	{
		ft_put_pixel(x, y, r->t_data[1][r->t_size[1] / 4 * r->ftex_y + r->ftex_x], r);
		ft_put_pixel(x, H - y - 1, r->t_data[2][r->t_size[2] / 4
			* r->ftex_y + r->ftex_x], r);
	}
	if (r->press[6] % 5 == 1)
	{
		r->press[5] == 0 ? r->colori = 16724530 : 0;
		ft_put_pixel(x, y, r->colori, r);
		r->press[5] == 0 ? r->colori = 84561 : 0;
		ft_put_pixel(x, H - y - 1, r->colori, r);
	}
}

void	t_floor_option2(t_wolf *r, double x, double y)
{
	if (r->press[6] % 5 == 3)
	{
		ft_put_pixel(x, y, r->t_data[2][r->t_size[2] / 4 * r->ftex_y + r->ftex_x], r);
		ft_put_pixel(x, H - y - 1, r->t_data[11][r->t_size[11] / 4
			* r->ftex_y + r->ftex_x], r);
	}
	if (r->press[6] % 5 == 0)
	{
		ft_put_pixel(x, y, r->t_data[16][r->t_size[16] / 4
			* r->ftex_y + r->ftex_x], r);
		ft_put_pixel(x, H - y - 1, r->t_data[2][r->t_size[2] / 4
			* r->ftex_y + r->ftex_x], r);
	}
	if (r->press[6] % 5 == 4)
	{
		ft_put_pixel(x, y, r->t_data[2][r->t_size[2] / 4 * r->ftex_y + r->ftex_x], r);
		ft_put_pixel(x, H - y - 1, r->t_data[14][r->t_size[14] / 4
			* r->ftex_y + r->ftex_x], r);
	}
}

void	text_floor(t_wolf *r, double x, double y)
{
	y = r->draw_end;
	while (y < H)
	{
		r->currentdist = H / (2 * y - H);
		r->weight = (r->currentdist - r->distplayer) / (r->distwall - r->distplayer);
		r->currentfloor_x = r->weight * r->floor_x_wall
				+ (1.0 - r->weight) * r->pos_x;
		r->currentfloor_y = r->weight * r->floor_y_wall
				+ (1.0 - r->weight) * r->pos_y;
		r->ftex_x = (int)(r->currentfloor_x * r->texwidth) % r->texwidth;
		r->ftex_y = (int)(r->currentfloor_y * r->texheight) % r->texheight;
		t_floor_option1(r, x, y);
		t_floor_option2(r, x, y);
		y++;
	}
}
