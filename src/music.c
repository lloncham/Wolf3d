#include "wolf3d.h"

void	music(t_wolf *ptr)
{
	static int i;

	if (ptr->press[5] == 1)
		{
			ptr->colori += 655621;
			ptr->vit = 0.15;
			ptr->ang = 0.05;
			if (i == 0)
			{
				system("afplay song/run.mp3&");
				i = 1;
			}
		}
		else
		{
			if (i == 1)
			{
				system("killall afplay");
				i = 0;
			}
			ptr->ang = 0.02;
			ptr->vit = 0.05;
		}
}
