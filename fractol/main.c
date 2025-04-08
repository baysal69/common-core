/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:38 by waissi            #+#    #+#             */
/*   Updated: 2025/04/08 17:35:21 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_h(void)
{
	ft_printf("Usage: ./fractol [OPTION] [C...]\n\n");
	ft_printf("These are fractol commads used in various situations:\n\n");
	ft_printf("-h		help instructions\n");
	ft_printf("-m		generate the Mandelbrot set\n");
	ft_printf("-j		generate the Julia set\n");
}

void	check_fail(t_mlx *mlx)
{
	if (mlx->mlx_ptr == NULL)
		exit(1);
	if (mlx->win_ptr == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(1);
	}
	if (mlx->img.img == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(1);
	}
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
		check_fail(&mlx);
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
		check_fail(&mlx);
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
