#ifndef FRACTOL_H
#define FRACTOL_H

#include "../../minilibx-linux/mlx.h"
#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define XMAX 600
#define YMAX 600
#define SCALE 250
#define MAX_ITER 100
#define MANDELBROT 1
#define JULIA 2

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

typedef struct s_mlx {
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  img;
    double  zoom;
    double  offset_x;
    double  offset_y;
    int		fractal;
    double julia_c_re;
    double julia_c_im;
}   t_mlx;

int	ft_strlen(const char *s);
int	ft_atoi(const char *nptr);
double	ft_atof(const char *str);

#endif
