#include "algebra.h"
#include <stdio.h>
#include <string.h>

#define WIDTH 32
#define HEIGHT 32

static char display[WIDTH*HEIGHT];

void fill(char c)
{
	memset(display, c, WIDTH*HEIGHT);
}

void show(void)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		fwrite(&display[y*WIDTH], WIDTH, 1, stdout);
		printf("\n");
	}
}

void circle(t_v2i center, int radius)
{
	t_v2i begin = v2i_sub(center, v2i_build(radius, radius));
	t_v2i end = v2i_sum(center, v2i_build(radius, radius));

	for (int y = begin.c[Y]; y <= end.c[Y]; y++)
	{
		for (int x = begin.c[X]; x <= end.c[X]; x++)
		{
			int dx = center.c[X] - x;
			int dy = center.c[Y] - y;
			if (dx*dx + dy*dy <= radius*radius && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
				display[y*WIDTH + x] = '.';
		}
	}
}

int main(void)
{
	fill(' ');
	circle(v2i_build(WIDTH/2, HEIGHT/2), 5);
	show();
	return 0;
}
