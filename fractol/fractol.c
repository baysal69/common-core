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
	n = 0;
	while (n < MAX_ITER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		n++;
	}
	return (n);
}

int	coloring(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		color;

	if (iter == MAX_ITER)
		color = 0x000000;
	else
	{
		t = (double)iter / MAX_ITER;
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		color = (r << 16) | (g << 8) | b;
	}
	return (color);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	double	c_re;
	double	c_im;
	int		iter;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < XMAX)
	{
		while (y < YMAX)
		{
			c_re = (x - XMAX / 2.0) * 4.0 / (XMAX * mlx->zoom) + mlx->offset_x;
			c_im = (y - YMAX / 2.0) * 4.0 / (YMAX * mlx->zoom) + mlx->offset_y;
			iter = mandelbrot(c_re, c_im);
			my_mlx_pixel_put(&mlx->img, x, y, coloring(iter));
			y++;
		}
		y = 0;
		x++;
	}
}

int	julia(double z_re, double z_im, double c_re, double c_im)
{
	int		n;
	double	z_re2;
	double	z_im2;

	n = 0;
	while (n < MAX_ITER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		n++;
	}
	return (n);
}

void	draw_julia(t_mlx *mlx, double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	int		iter;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < XMAX)
	{
		while (y < YMAX)
		{
			z_re = (x - XMAX / 2.0) * 4.0 / (XMAX * mlx->zoom) + mlx->offset_x;
			z_im = (y - YMAX / 2.0) * 4.0 / (YMAX * mlx->zoom) + mlx->offset_y;
			iter = julia(z_re, z_im, c_re, c_im);
			my_mlx_pixel_put(&mlx->img, x, y, coloring(iter));
			y++;
		}
		y = 0;
		x++;
	}
}

int	sd(void *code)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)code;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}

int	zbi(int keycode, t_mlx *mlx)
{
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

int	mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		mlx->zoom *= 1.1;
		mlx->offset_x += (x - XMAX / 2) / (XMAX * mlx->zoom);
		mlx->offset_y += (y - YMAX / 2) / (YMAX * mlx->zoom);
	}
	else if (button == 5)
	{
		mlx->zoom /= 1.1;
		mlx->offset_x -= (x - XMAX / 2) / (XMAX * mlx->zoom);
		mlx->offset_y -= (y - YMAX / 2) / (YMAX * mlx->zoom);
	}
	if (mlx->fractal == MANDELBROT)
		draw_mandelbrot(mlx);
	else if (mlx->fractal == JULIA)
		draw_julia(mlx, mlx->julia_c_im, mlx->julia_c_re);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	return (0);
}

void	handle_h(void)
{
	ft_printf("Usage: ./fractol [OPTION] [C...]\n\n");
	ft_printf("These are fractol commads used in various situations:\n\n");
	ft_printf("-h		help instructions\n");
	ft_printf("-m		generate the Mandelbrot set\n");
	ft_printf("-j		generate the Julia set\n");
}

void	handle_m(char **av)
{
	t_mlx	mlx;

	if (av[1][0] == '-' && av[1][1] == 'm')
	{
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, XMAX, YMAX, "Mandelbrot Set");
		mlx.img.img = mlx_new_image(mlx.mlx_ptr, XMAX, YMAX);
		mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
				&mlx.img.line_length, &mlx.img.endian);
		mlx.zoom = 1.0;
		mlx.offset_x = 0;
		mlx.offset_y = 0;
		mlx.fractal = MANDELBROT;
		draw_mandelbrot(&mlx);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img, 0, 0);
		mlx_hook(mlx.win_ptr, 2, 1L << 0, zbi, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, sd, &mlx);
		mlx_mouse_hook(mlx.win_ptr, mouse_zoom, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		handle_h();
}

void	handle_j(char **av)
{
	const double	ci = ft_atof(av[2]), cr = ft_atof(av[3]);
	t_mlx			mlx;

	if (av[1][0] == '-' && av[1][1] == 'j')
	{
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, XMAX, YMAX, "Julia Set");
		mlx.img.img = mlx_new_image(mlx.mlx_ptr, XMAX, YMAX);
		mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
				&mlx.img.line_length, &mlx.img.endian);
		mlx.zoom = 1.0;
		mlx.offset_x = 0;
		mlx.offset_y = 0;
		mlx.julia_c_re = cr;
		mlx.julia_c_im = ci;
		mlx.fractal = JULIA;
		draw_julia(&mlx, ci, cr);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img, 0, 0);
		mlx_hook(mlx.win_ptr, 2, 1L << 0, zbi, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, sd, &mlx);
		mlx_mouse_hook(mlx.win_ptr, mouse_zoom, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		handle_m(av);
	}
	else if (ac == 4)
	{
		handle_j(av);
	}
	else
		handle_h();
	return (0);
}
