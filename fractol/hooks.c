/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baysal <baysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:04 by waissi            #+#    #+#             */
/*   Updated: 2025/04/12 17:48:35 by baysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	free_win(int keycode, t_mlx *mlx)
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

int	ft_close(void *code)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)code;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}
