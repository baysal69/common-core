/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:29:45 by waissi            #+#    #+#             */
/*   Updated: 2025/04/08 14:53:39 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./ft_printf/ft_printf.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include "stdlib.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define XMAX 600
# define YMAX 600
# define SCALE 250
# define MAX_ITER 200
# define MANDELBROT 1
# define JULIA 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		fractal;
	double	julia_c_re;
	double	julia_c_im;
}			t_mlx;

int			ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
double		ft_atof(const char *str);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		complex_to_pixel(double real, double imag, int *px, int *py);
int			mandelbrot(double c_re, double c_im);
int			coloring(int iter);
void		draw_mandelbrot(t_mlx *mlx);
int			julia(double z_re, double z_im, double c_re, double c_im);
void		draw_julia(t_mlx *mlx, double c_re, double c_im);
int			sd(void *code);
int			zbi(int keycode, t_mlx *mlx);
int			mouse_zoom(int button, int x, int y, t_mlx *mlx);
void		handle_h(void);
void		handle_m(char **av);
void		handle_j(char **av);

#endif
