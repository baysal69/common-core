#include "mlx.h"
#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define XMAX 1000
#define YMAX 1000
#define SCALE 250
#define MAX_ITER 50

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
}   t_mlx;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void complex_to_pixel(double real, double imag, int *px, int *py)
{
    *px = (int)(real * SCALE + XMAX / 2);
    *py = (int)(-imag * SCALE + YMAX / 2); // Invert y-axis for correct orientation
}

int mandelbrot(double c_re, double c_im) {
    double z_re = c_re;
    double z_im = c_im;
    int n;

    for (n = 0; n < MAX_ITER; ++n) {
        double z_re2 = z_re * z_re;
        double z_im2 = z_im * z_im;
        if (z_re2 + z_im2 > 4.0)
            break;
        z_im = 2.0 * z_re * z_im + c_im;
        z_re = z_re2 - z_im2 + c_re;
    }
    return n;
}

void draw_mandelbrot(t_mlx *mlx) {
    int x, y;
    for (x = 0; x < XMAX; ++x) {
        for (y = 0; y < YMAX; ++y) {
            double c_re = (x - XMAX / 2.0) * 4.0 / XMAX;
            double c_im = (y - YMAX / 2.0) * 4.0 / YMAX;
	    int iter = mandelbrot(c_re, c_im);
            int color;
            if (iter == MAX_ITER)
                color = 0x000000; // Black
            else {
                double t = (double)iter / MAX_ITER;
                int r = (int)(9 * (1 - t) * t * t * t * 255);
                int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
                int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
                color = (r << 16) | (g << 8) | b;
            }
            my_mlx_pixel_put(&mlx->img, x, y, color);
        }
    }
}

int draw_graph(t_data *img)
{
	int xcenter = XMAX/2 , ycenter = YMAX/2 , x = 0 , y = 0;
	while(x < XMAX)
	{
		//if(x == )
		my_mlx_pixel_put(img,x, ycenter, 0xFFFFFF);
		x++;
	}
	while(y < YMAX)
	{
		my_mlx_pixel_put(img,xcenter, y, 0xFFFFFF);
		y++;
	}
	return 0;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
	if (av[1][0] == '-')
	{
		if (av[1][1] == 'm')
		{
		         t_mlx mlx;
		         mlx.mlx_ptr = mlx_init();
   		 	 mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, XMAX, YMAX, "Mandelbrot Set");
			 mlx.img.img = mlx_new_image(mlx.mlx_ptr, XMAX, YMAX);
    		         mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);

        		draw_mandelbrot(&mlx);
       			mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img, 0, 0);
       			mlx_loop(mlx.mlx_ptr);
		}
		else
			printf("zbi machi haka ki5dm had l9lawi\n");
    	}
    }
	else if (ac == 3)
	{
		if (av[1][0] == '-')
		{
			if (av[1][1] == 'j')
			{
				                         t_mlx mlx;
                         mlx.mlx_ptr = mlx_init();
                         mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, XMAX, YMAX, "Mandelbrot Set");
                         mlx.img.img = mlx_new_image(mlx.mlx_ptr, XMAX, YMAX);
                         mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);

                        draw_mandelbrot(&mlx);
                        mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img, 0, 0);
                        mlx_loop(mlx.mlx_ptr);
			}
		}
	}	

    else
        printf("Invalid arguments\nPlease retry using 2 arguments\n");

    return 0;
}
