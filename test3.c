#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 10000

typedef struct {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int bpp;
    int size_line;
    int endian;
} t_mlx;

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
    for (x = 0; x < WIDTH; ++x) {
        for (y = 0; y < HEIGHT; ++y) {
            double c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double c_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int iter = mandelbrot(c_re, c_im);
            int color = iter < MAX_ITER ? 0x00FF00 * iter / MAX_ITER : 0x000000;
            int index = (x * mlx->bpp / 8) + (y * mlx->size_line);
            mlx->img_data[index] = color;
            mlx->img_data[index + 1] = color >> 8;
            mlx->img_data[index + 2] = color >> 16;
        }
    }
}

int main() {
    t_mlx mlx;

    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
    mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
    mlx.img_data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_line, &mlx.endian);

    draw_mandelbrot(&mlx);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
    mlx_loop(mlx.mlx_ptr);

    return 0;
}
