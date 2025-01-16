#include "mlx.h"
#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>

#define SCALE 200

void draw_circle(void *mlx, void *win, int x_c, int y_c, int radius,int XMAX, int YMAX)
{
    int x, y;

    for (x = x_c - radius; x <= x_c + radius; x++)
    {
        for (y = y_c - radius; y <= y_c + radius; y++)
        {
            // Check if the point (x, y) is within the circle's radius
            if ((x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) <= radius * radius)
            {
                // Draw the pixel
                if (x >= 0 && x < XMAX && y >= 0 && y < YMAX) // Ensure the point is within the window bounds
                    mlx_pixel_put(mlx, win, x, y, 0xFF0000);
            }
        }
    }
}

void draw_graph(int XMAX,int YMAX, void *mlx, void *mlx_win)
{
	int xcenter = XMAX/2 , ycenter = YMAX/2 , x = 0 , y = 0;
	while(x < XMAX)
	{
		//if(x == )
		mlx_pixel_put(mlx, mlx_win,x, ycenter, 0xFFFFFF);
		x++;
	}
	while(y < YMAX)
	{
		mlx_pixel_put(mlx, mlx_win,xcenter, y, 0xFFFFFF);
		y++;
	}
}

void complex_to_pixel(double real, double imag, int *px, int *py, int XMAX, int YMAX)
{
    *px = (int)(real * SCALE + XMAX / 2);
    *py = (int)(-imag * SCALE + YMAX / 2); // Invert y-axis for correct orientation
}

void visualize(void *mlx, void *mlx_win, double c_real, double c_imag, int XMAX , int YMAX)
{
	double z_real = 0.0 , z_imag = 0.0;
	int i,px,py;
	while (i < 1000)
	{
		usleep(500 * 100);
		double new_real = (z_real * z_real) - (z_imag * z_imag) + c_real;
		double new_imag = 2 * z_real * z_imag + c_imag;
		z_real = new_real;
		z_imag = new_imag;

		complex_to_pixel(z_real, z_imag, &px, &py, XMAX, YMAX);

		if(px>=0 && px < XMAX && py >= 0 && py < YMAX)
			draw_circle(mlx,mlx_win,px,py,2,XMAX,YMAX);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 5)
	{
		int XMAX = atoi(av[1]);
	       	int YMAX = atoi(av[2]);
		void *mlx = mlx_init();
		void *mlx_win = mlx_new_window(mlx,XMAX,YMAX,"test");
		
		draw_graph(XMAX,YMAX,mlx,mlx_win);

		visualize(mlx,mlx_win,atof(av[3]),atof(av[4]),XMAX,YMAX);
		//draw_circle(mlx,mlx_win,250,250,2,XMAX,YMAX);

		mlx_loop(mlx);
	}
	else
		printf("Invalid arguments\nPlease retry using 2 arguments\n");
}
