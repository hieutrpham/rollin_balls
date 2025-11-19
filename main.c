#include "algebra.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 64
#define HEIGHT 32

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
	static char *table = " _^$";
	for (int y = 0; y < HEIGHT/2; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			t_pixel top = display[2*y*WIDTH + x];
			t_pixel bot = display[(2*y+1)*WIDTH + x];
			row[x] = table[top*2 + bot];
		}
		fwrite(row, WIDTH, 1, stdout);
		fputc('\n', stdout);
	}
}

void circle(t_v2f center, float radius)
{
	float r = radius;
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
			t_v2f diff = v2f_sub(center, v2f_build(x, y));
			if (v2f_sqlen(diff) < r*r)
				display[y*WIDTH + x] = FORE;
		}
	}
}

#define RADIUS (HEIGHT/4.0f)
#define FPS 30
#define GRAVITY 100.0f
#define DT (1.0f/FPS)
#define FRIC -0.8f

void back(void)
{
	printf("\x1b[%dD", WIDTH);
	printf("\x1b[%dA", HEIGHT/2);
}

int main(void)
{
	t_v2f pos = v2f_build(RADIUS, RADIUS);
	t_v2f velocity = v2f_build(15.0f, 0.0f);
	while (pos.c[X] < WIDTH + RADIUS)
	{
		velocity = v2f_sum(velocity, v2f_build(0, GRAVITY*DT));
		pos = v2f_sum(pos, v2f_mul(velocity, v2f_build(DT, DT)));
		if (pos.c[Y] > HEIGHT - RADIUS)
		{
			pos.c[Y] = HEIGHT - RADIUS;
			velocity.c[Y] *= FRIC;
		}
		fill(BACK);
		circle(pos, RADIUS);
		show();
		back();
		usleep(1000*1000/FPS);
	}
	return 0;
}
