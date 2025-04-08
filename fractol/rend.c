/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:23 by waissi            #+#    #+#             */
/*   Updated: 2025/04/08 14:33:24 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
