#include "algebra.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 64
#define HEIGHT 64

typedef enum {
	BACK = 0,
	FORE,
	PIXEL_N,
} t_pixel;

static t_pixel display[WIDTH*HEIGHT];

void fill(t_pixel c)
{
	t_pixel *ptr = display;
	size_t n = WIDTH*HEIGHT;
	while (n-- > 0)
		*ptr++ = c;
}

/* @brief: compressed the ascii characters by combining 2 rows into 1 row
 */
void show(void)
{
	static char row[WIDTH];
	static char table[PIXEL_N][PIXEL_N] = {
		{' ', '_'},
		{'^', '$'},
	};
	for (int y = 0; y < HEIGHT/2; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			t_pixel top = display[2*y*WIDTH + x];
			t_pixel bot = display[(2*y+1)*WIDTH + x];
			row[x] = table[top][bot];
		}
		fwrite(row, WIDTH, 1, stdout);
		fputc('\n', stdout);
	}
}

void circle(t_v2i center, int radius)
{
	int r = radius;
	// NOTE: with bounding box
	//
	// t_v2i begin = v2i_sub(center, v2i_build(r, r));
	// t_v2i end = v2i_sum(center, v2i_build(r, r));
	// for (int y = begin.c[Y]; y <= end.c[Y]; y++)
	// {
	// 	for (int x = begin.c[X]; x <= end.c[X]; x++)
	// 	{
	// 		t_v2i diff = v2i_sub(center, v2i_build(x, y));
	// 		if (v2i_sqlen(diff) < r*r && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	// 			display[y*WIDTH + x] = '*';
	// 	}
	// }
	// NOTE: without bounding box
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			t_v2i diff = v2i_sub(center, v2i_build(x, y));
			if (v2i_sqlen(diff) < r*r)
				display[y*WIDTH + x] = FORE;
		}
	}
}

#define FPS 2
void back(void)
{
	printf("\x1b[%dD", WIDTH);
	printf("\x1b[%dA", HEIGHT/2);
}

int main(void)
{
	t_v2i pos = v2i_build(WIDTH/2, HEIGHT/2);
	t_v2i velocity = v2i_build(0, 5);
	
	while (1)
	{
		pos = v2i_sum(pos, velocity);
		fill(BACK);
		circle(pos, 13);
		show();
		back();
		usleep(1000*1000/FPS);
	}
	return 0;
}
