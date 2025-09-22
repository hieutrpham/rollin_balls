#include "algebra.h"

float lerpf(float a, float b, float t)
{
	return a + (b - a) * t;
}

int lerpi(int a, int b, int t)
{
	return a + (b - a) * t;
}

// 2D vectors
t_v2f v2f_build_scalar(float x)
{
	t_v2f vector;

	vector.c[X] = x;
	vector.c[Y] = x;
	return vector;
}
t_v2f v2f_build(float x, float y)
{
	t_v2f vector;

	vector.c[X] = x;
	vector.c[Y] = y;
	return vector;
}

t_v2f v2f_sum(t_v2f a, t_v2f b)
{
	for (int i = 0; i < 2; i++)
		a.c[i] += b.c[i];
	return a;
}

t_v2f v2f_sub(t_v2f a, t_v2f b)
{
	for (int i = 0; i < 2; i++)
		a.c[i] -= b.c[i];
	return a;
}

t_v2f v2f_mul(t_v2f a, t_v2f b)
{
	for (int i = 0; i < 2; i++)
		a.c[i] *= b.c[i];
	return a;
}

t_v2f v2f_div(t_v2f a, t_v2f b)
{
		for (int i = 0; i < 2; i++)
	   		a.c[i] /= b.c[i];
	return a;
}

float v2f_sqlen(t_v2f a)
{
	return a.c[X] * a.c[X] + a.c[Y] * a.c[Y];
}

t_v2f v2f_min(t_v2f a, t_v2f b)
{
	for (int i = 0; i < 2; i ++)
	{
		if (a.c[i] > b.c[i])
			a.c[i] = b.c[i];
	}
	return a;
}

t_v2f v2f_max(t_v2f a, t_v2f b)
{
	for (int i = 0; i < 2; i ++)
	   	{
	   		if (a.c[i] < b.c[i])
	   			a.c[i] = b.c[i];
	}
	return a;
}

t_v2f v2f_lerpf(t_v2f a, t_v2f b, t_v2f t)
{
	for (int i = 0; i < 2; i ++)
		a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
	return a;
}

t_v2f v2f_sqrt(t_v2f a)
{
	for (int i = 0; i < 2; i ++)
		a.c[i] = sqrtf(a.c[i]);
	return a;
}

t_v2f v2f_pow(t_v2f a, t_v2f b)
{
	for (int i = 0; i < 2; i ++)
		a.c[i] = powf(a.c[i], b.c[i]);
	return a;
}

// 3D vectors
t_v3f v3f_build_scalar(float x)
{
	t_v3f vector;

	vector.c[X] = x;
	vector.c[Y] = x;
	vector.c[Z] = x;
	return vector;
}

t_v3f v3f_build(float x, float y, float z)
{
	t_v3f vector;

	vector.c[X] = x;
	vector.c[Y] = y;
	vector.c[Z] = z;
	return vector;
}

t_v3f v3f_sum(t_v3f a, t_v3f b)
{
	for (int i = 0; i < 3; i++)
		a.c[i] = a.c[i] + b.c[i];
	return a;
}

t_v3f v3f_sub(t_v3f a, t_v3f b)
{
	for (int i = 0; i < 3; i++)
		a.c[i] -= b.c[i];
	return a;
}

t_v3f v3f_mul(t_v3f a, t_v3f b)
{
	for (int i = 0; i < 3; i++)
		a.c[i] *= b.c[i];
	return a;
}

t_v3f v3f_div(t_v3f a, t_v3f b)
{
		for (int i = 0; i < 3; i++)
	   		a.c[i] /= b.c[i];
	return a;
}

float v3f_sqlen(t_v3f a)
{
	return a.c[X] * a.c[X] + a.c[Y] * a.c[Y];
}

t_v3f v3f_min(t_v3f a, t_v3f b)
{
	for (int i = 0; i < 3; i ++)
	{
		if (a.c[i] > b.c[i])
			a.c[i] = b.c[i];
	}
	return a;
}

t_v3f v3f_max(t_v3f a, t_v3f b)
{
	for (int i = 0; i < 3; i ++)
	{
		if (a.c[i] < b.c[i])
			a.c[i] = b.c[i];
	}
	return a;
}

t_v3f v3f_lerpf(t_v3f a, t_v3f b, t_v3f t)
{
	for (int i = 0; i < 3; i ++)
		a.c[i] = lerpf(a.c[i], b.c[i], t.c[i]);
	return a;
}

t_v3f v3f_sqrt(t_v3f a)
{
	for (int i = 0; i < 3; i ++)
		a.c[i] = sqrtf(a.c[i]);
	return a;
}

t_v3f v3f_pow(t_v3f a, t_v3f b)
{
	for (int i = 0; i < 3; i ++)
		a.c[i] = powf(a.c[i], b.c[i]);
	return a;
}

////////////////////////////////////////////////
///interger vectors

// 2D vectors
t_v2i v2i_build_scalar(int x)
{
	t_v2i vector;

	vector.c[X] = x;
	vector.c[Y] = x;
	return vector;
}
t_v2i v2i_build(int x, int y)
{
	t_v2i vector;

	vector.c[X] = x;
	vector.c[Y] = y;
	return vector;
}

t_v2i v2i_sum(t_v2i a, t_v2i b)
{
	for (int i = 0; i < 2; i++)
		a.c[i] += b.c[i];
	return a;
}

t_v2i v2i_sub(t_v2i a, t_v2i b)
{
	for (int i = 0; i < 2; i++)
		a.c[i] -= b.c[i];
	return a;
}

t_v2i v2i_mul(t_v2i a, t_v2i b)
{
	for (int i = 0; i < 2; i++)
		a.c[i] *= b.c[i];
	return a;
}

t_v2i v2i_div(t_v2i a, t_v2i b)
{
		for (int i = 0; i < 2; i++)
	   		a.c[i] /= b.c[i];
	return a;
}

int v2i_sqlen(t_v2i a)
{
	return a.c[X] * a.c[X] + a.c[Y] * a.c[Y];
}

t_v2i v2i_min(t_v2i a, t_v2i b)
{
	for (int i = 0; i < 2; i ++)
	{
		if (a.c[i] > b.c[i])
			a.c[i] = b.c[i];
	}
	return a;
}

t_v2i v2i_max(t_v2i a, t_v2i b)
{
	for (int i = 0; i < 2; i ++)
	   	{
	   		if (a.c[i] < b.c[i])
	   			a.c[i] = b.c[i];
	}
	return a;
}

t_v2i v2i_lerpi(t_v2i a, t_v2i b, t_v2i t)
{
	for (int i = 0; i < 2; i ++)
		a.c[i] = lerpi(a.c[i], b.c[i], t.c[i]);
	return a;
}

t_v2i v2i_sqrt(t_v2i a)
{
	for (int i = 0; i < 2; i ++)
		a.c[i] = sqrtf(a.c[i]);
	return a;
}

t_v2i v2i_pow(t_v2i a, t_v2i b)
{
	for (int i = 0; i < 2; i ++)
		a.c[i] = powf(a.c[i], b.c[i]);
	return a;
}

// 3D vectors
t_v3i v3i_build_scalar(int x)
{
	t_v3i vector;

	vector.c[X] = x;
	vector.c[Y] = x;
	vector.c[Z] = x;
	return vector;
}

t_v3i v3i_build(int x, int y, int z)
{
	t_v3i vector;

	vector.c[X] = x;
	vector.c[Y] = y;
	vector.c[Z] = z;
	return vector;
}

t_v3i v3i_sum(t_v3i a, t_v3i b)
{
	for (int i = 0; i < 3; i++)
		a.c[i] = a.c[i] + b.c[i];
	return a;
}

t_v3i v3i_sub(t_v3i a, t_v3i b)
{
	for (int i = 0; i < 3; i++)
		a.c[i] -= b.c[i];
	return a;
}

t_v3i v3i_mul(t_v3i a, t_v3i b)
{
	for (int i = 0; i < 3; i++)
		a.c[i] *= b.c[i];
	return a;
}

t_v3i v3i_div(t_v3i a, t_v3i b)
{
		for (int i = 0; i < 3; i++)
	   		a.c[i] /= b.c[i];
	return a;
}

int v3i_sqlen(t_v3i a)
{
	return a.c[X] * a.c[X] + a.c[Y] * a.c[Y];
}

t_v3i v3i_min(t_v3i a, t_v3i b)
{
	for (int i = 0; i < 3; i ++)
	{
		if (a.c[i] > b.c[i])
			a.c[i] = b.c[i];
	}
	return a;
}

t_v3i v3i_max(t_v3i a, t_v3i b)
{
	for (int i = 0; i < 3; i ++)
	{
		if (a.c[i] < b.c[i])
			a.c[i] = b.c[i];
	}
	return a;
}

t_v3i v3i_lerpi(t_v3i a, t_v3i b, t_v3i t)
{
	for (int i = 0; i < 3; i ++)
		a.c[i] = lerpi(a.c[i], b.c[i], t.c[i]);
	return a;
}

t_v3i v3i_sqrt(t_v3i a)
{
	for (int i = 0; i < 3; i ++)
		a.c[i] = sqrtf(a.c[i]);
	return a;
}

t_v3i v3i_pow(t_v3i a, t_v3i b)
{
	for (int i = 0; i < 3; i ++)
		a.c[i] = powf(a.c[i], b.c[i]);
	return a;
}

