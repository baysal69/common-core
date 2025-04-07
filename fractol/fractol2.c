#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	complex_to_pixel(double real, double imag, int *px, int *py)
{
	*px = (int)(real * SCALE + XMAX / 2);
	*py = (int)(-imag * SCALE + YMAX / 2);
		// Invert y-axis for correct orientation
}

int	mandelbrot(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	int		n;
	double	z_re2;
	double	z_im2;

	z_re = c_re;
	z_im = c_im;
	for (n = 0; n < MAX_ITER; ++n)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
	}
	return (n);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	double	c_re;
	double	c_im;
	int		iter;
			int color;
	double	t;
	int		r;
	int		g;
	int		b;

	int x, y;
	for (x = 0; x < XMAX; ++x)
	{
		for (y = 0; y < YMAX; ++y)
		{
			c_re = (x - XMAX / 2.0) * 4.0 / (XMAX * mlx->zoom) + mlx->offset_x;
            		c_im = (y - YMAX / 2.0) * 4.0 / (YMAX * mlx->zoom) + mlx->offset_y;
			iter = mandelbrot(c_re, c_im);
			if (iter == MAX_ITER)
				color = 0x000000; // Black
			else
			{
				t = (double)iter / MAX_ITER;
				r = (int)(9 * (1 - t) * t * t * t * 255);
				g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
				b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
				color = (r << 16) | (g << 8) | b;
			}
			my_mlx_pixel_put(&mlx->img, x, y, color);
		}
	}
}

int	draw_graph(t_data *img)
{
	int	xcenter = XMAX / 2, ycenter = YMAX / 2, x = 0, y;

	xcenter = XMAX / 2, ycenter = YMAX / 2, x = 0, y = 0;
	while (x < XMAX)
	{
		// if(x == )
		my_mlx_pixel_put(img, x, ycenter, 0xFFFFFF);
		x++;
	}
	while (y < YMAX)
	{
		my_mlx_pixel_put(img, xcenter, y, 0xFFFFFF);
		y++;
	}
	return (0);
}

int	julia(double z_re, double z_im, double c_re, double c_im)
{
	int		n;
	double	z_re2;
	double	z_im2;

	for (n = 0; n < MAX_ITER; ++n)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
	}
	return (n);
}
void	draw_julia(t_mlx *mlx, double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	int		iter;
			int color;
	double	t;
	int		r;
	int		g;
	int		b;

	int x, y;
	for (x = 0; x < XMAX; ++x)
	{
		for (y = 0; y < YMAX; ++y)
		{
			z_re = (x - XMAX / 2.0) * 4.0 / (XMAX * mlx->zoom) + mlx->offset_x;
            		z_im = (y - YMAX / 2.0) * 4.0 / (YMAX * mlx->zoom) + mlx->offset_y;
			iter = julia(z_re, z_im, c_re, c_im);
			if (iter == MAX_ITER)
				color = 0x000000; // Black
			else
			{
				t = (double)iter / MAX_ITER;
				r = (int)(9 * (1 - t) * t * t * t * 255);
				g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
				b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
				color = (r << 16) | (g << 8) | b;
			}
			my_mlx_pixel_put(&mlx->img, x, y, color);
		}
	}
}
int sd(void *code)
{
		 t_mlx *mlx = (t_mlx*)code;
	         mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
                 mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
                 mlx_destroy_display(mlx->mlx_ptr);
                 free(mlx->mlx_ptr);
                 exit(0);
}

int	zbi(int keycode, t_mlx *mlx)
{
#include "../ft_printf/ft_printf.h"
	if (keycode == 65307)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(0);
	}
	return (0);
}

int mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
    if (button == 4) // Scroll up
    {
        mlx->zoom *= 1.1;
        mlx->offset_x += (x - XMAX / 2) / (XMAX * mlx->zoom);
        mlx->offset_y += (y - YMAX / 2) / (YMAX * mlx->zoom);
    }
    else if (button == 5) // Scroll down
    {
        mlx->zoom /= 1.1;
        mlx->offset_x -= (x - XMAX / 2) / (XMAX * mlx->zoom);
        mlx->offset_y -= (y - YMAX / 2) / (YMAX * mlx->zoom);
    }
    // Redraw the fractal with the new zoom and center coordinates
    if (mlx->fractal == MANDELBROT)
        draw_mandelbrot(mlx);
    else if (mlx->fractal == JULIA)
        draw_julia(mlx, mlx->julia_c_re, mlx->julia_c_im);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
    return 0;
}
int	main(int ac, char **av)
{
				t_mlx mlx;

	if (ac == 2)
	{
		if (av[1][0] == '-')
		{
			if (av[1][1] == 'm')
			{
				mlx.mlx_ptr = mlx_init();
				mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, XMAX, YMAX,
						"Mandelbrot Set");
				mlx.img.img = mlx_new_image(mlx.mlx_ptr, XMAX, YMAX);
				mlx.img.addr = mlx_get_data_addr(mlx.img.img,
						&mlx.img.bits_per_pixel, &mlx.img.line_length,
						&mlx.img.endian);
				mlx.zoom = 1.0;
            			mlx.offset_x = 0;
             			mlx.offset_y = 0;
				mlx.fractal = MANDELBROT;
				draw_mandelbrot(&mlx);
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img,
					0, 0);
				mlx_hook(mlx.win_ptr, 2, 1L << 0, zbi, &mlx);
				mlx_hook(mlx.win_ptr, 17, 0 , sd, &mlx);
				mlx_mouse_hook(mlx.win_ptr, mouse_zoom, &mlx);
				mlx_loop(mlx.mlx_ptr);
			}
			else
				printf("zbi machi haka ki5dm had l9lawi\n");
		}
	}
	else if (ac == 4)
	{
		if (av[1][0] == '-')
		{
			if (av[1][1] == 'j')
			{

				double Ci = ft_atof(av[2]), Cr = ft_atof(av[3]);
				mlx.mlx_ptr = mlx_init();
				mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, XMAX, YMAX,
						"Julia Set");
				mlx.img.img = mlx_new_image(mlx.mlx_ptr, XMAX, YMAX);
				mlx.img.addr = mlx_get_data_addr(mlx.img.img,
						&mlx.img.bits_per_pixel, &mlx.img.line_length,
						&mlx.img.endian);
				mlx.zoom = 1.0;
            		 	mlx.offset_x = 0;
                		mlx.offset_y = 0;
				mlx.julia_c_re = Cr;
				mlx.julia_c_im = Ci;
				mlx.fractal = JULIA;
				draw_julia(&mlx, Ci, Cr);
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img,
					0, 0);
				mlx_hook(mlx.win_ptr, 2, 1L << 0, zbi, &mlx);
				mlx_hook(mlx.win_ptr, 17, 0 , sd, &mlx);
				mlx_mouse_hook(mlx.win_ptr, mouse_zoom, &mlx);
				mlx_loop(mlx.mlx_ptr);
			}
		}
	}
	else
		printf("Invalid arguments\nPlease retry using 2 arguments\n");
	return (0);
}
