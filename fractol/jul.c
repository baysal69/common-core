/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:10 by waissi            #+#    #+#             */
/*   Updated: 2025/04/08 14:33:11 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
