#ifndef ALGEBRA_H
#define ALGEBRA_H
#include <math.h>

enum { X, Y, Z, W, };
enum { R, G, B, A, };
enum { U, V };

typedef struct { float c[2]; } t_v2f;
typedef struct { float c[3]; } t_v3f;
typedef struct { float c[4]; } t_v4f;
typedef struct { int c[2]; } t_v2i;
typedef struct { int c[3]; } t_v3i;

typedef t_v3f RGB;
typedef t_v2f UV;

t_v2f v2f_build_scalar(float x);
t_v2f v2f_build(float x, float y);
t_v2f v2f_sum(t_v2f a, t_v2f b);
t_v2f v2f_sub(t_v2f a, t_v2f b);
t_v2f v2f_mul(t_v2f a, t_v2f b);
t_v2f v2f_div(t_v2f a, t_v2f b);
float v2f_sqlen(t_v2f a);
t_v2f v2f_min(t_v2f a, t_v2f b);
t_v2f v2f_max(t_v2f a, t_v2f b);
t_v2f v2f_lerpf(t_v2f a, t_v2f b, t_v2f t);
t_v2f v2f_sqrt(t_v2f a);
t_v2f v2f_pow(t_v2f a, t_v2f b);

t_v3f v3f_build_scalar(float x);
t_v3f v3f_build(float x, float y, float z);
t_v3f v3f_sum(t_v3f a, t_v3f b);
t_v3f v3f_sub(t_v3f a, t_v3f b);
t_v3f v3f_mul(t_v3f a, t_v3f b);
t_v3f v3f_div(t_v3f a, t_v3f b);
float v3f_sqlen(t_v3f a);
t_v3f v3f_min(t_v3f a, t_v3f b);
t_v3f v3f_max(t_v3f a, t_v3f b);
t_v3f v3f_lerpf(t_v3f a, t_v3f b, t_v3f t);
t_v3f v3f_sqrt(t_v3f a);
t_v3f v3f_pow(t_v3f a, t_v3f b);
float lerpf(float a, float b, float t);

int lerpi(int a, int b, int t);
t_v2i v2i_build_scalar(int x);
t_v2i v2i_build(int x, int y);
t_v2i v2i_sum(t_v2i a, t_v2i b);
t_v2i v2i_sub(t_v2i a, t_v2i b);
t_v2i v2i_mul(t_v2i a, t_v2i b);
t_v2i v2i_div(t_v2i a, t_v2i b);
int v2i_sqlen(t_v2i a);
t_v2i v2i_min(t_v2i a, t_v2i b);
t_v2i v2i_max(t_v2i a, t_v2i b);
t_v2i v2i_lerpi(t_v2i a, t_v2i b, t_v2i t);
t_v2i v2i_sqrt(t_v2i a);
t_v2i v2i_pow(t_v2i a, t_v2i b);

t_v3i v3i_build_scalar(int x);
t_v3i v3i_build(int x, int y, int z);
t_v3i v3i_sum(t_v3i a, t_v3i b);
t_v3i v3i_sub(t_v3i a, t_v3i b);
t_v3i v3i_mul(t_v3i a, t_v3i b);
t_v3i v3i_div(t_v3i a, t_v3i b);
int v3i_sqlen(t_v3i a);
t_v3i v3i_min(t_v3i a, t_v3i b);
t_v3i v3i_max(t_v3i a, t_v3i b);
t_v3i v3i_lerpf(t_v3i a, t_v3i b, t_v3i t);
t_v3i v3i_sqrt(t_v3i a);
t_v3i v3i_pow(t_v3i a, t_v3i b);
int lerpi(int a, int b, int t);
#endif //ALGEBRA_H
