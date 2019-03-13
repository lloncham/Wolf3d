#include "wolf3d.h"

void	basic_music(t_wolf *ptr)
{
	system("killall afplay");
	if (ptr->press[6] % 5 == 1)
		system("afplay song/song4.mp3&");
	else if (ptr->press[6] % 5 == 2)
		system("afplay song/song2.mp3&");
	else if (ptr->press[6] % 5 == 3)
		system("afplay song/song3.mp3&");
	else if (ptr->press[6] % 5 == 4)
		system("afplay song/song1.mp3&");
	else if (ptr->press[6] % 5 == 0)
		system("afplay song/song0.mp3&");
}

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
			system("killall afplay");
			system("afplay song/run.mp3&");
			i = 1;
		}
	}
	else
	{
		if (i == 1)
		{
			system("killall afplay");
			basic_music(ptr);
			i = 0;
		}
		ptr->ang = 0.02;
		ptr->vit = 0.05;
	}
}
