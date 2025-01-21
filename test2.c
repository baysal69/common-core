#include "mlx.h"
#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define SCALE 250
typedef struct  s_data {
        void    *img;
        char    *addr;
        int             bits_per_pixel;
        int             line_length;
        int             endian;
}                               t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
        char    *dst;

        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

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

int draw_graph(int XMAX,int YMAX, void *mlx, void *mlx_win)
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
	return 0;
}

void complex_to_pixel(double real, double imag, int *px, int *py, int XMAX, int YMAX)
{
    *px = (int)(real * SCALE + XMAX / 2);
    *py = (int)(-imag * SCALE + YMAX / 2); // Invert y-axis for correct orientation
}

void visualize(t_data img, double c_real, double c_imag, int XMAX , int YMAX)
{
	double z_real = 0.0 , z_imag = 0.0;
	int i = 0,px,py, max_iterations = 500;
	while (i < max_iterations)
	{
		//usleep(200 * 100);
		double new_real = (z_real * z_real) - (z_imag * z_imag) + c_real;
		double new_imag = 2 * z_real * z_imag + c_imag;
		z_real = new_real;
		z_imag = new_imag;

		
		
		if ((z_real * z_real + z_imag * z_imag) > 4)
       		    break;

		i++;	

    		int color, brightness;
    		if (i == max_iterations)
        		color = 0x000000;                                            
    		else
    		{
/*			brightness = (int)(255 * ((double)i / max_iterations));
			color = (brightness << 16) | (brightness << 8) | brightness;
*/
   			 double smooth_value = (double)i / max_iterations;
  			  int r = (int)(9 * (1 - smooth_value) * pow(smooth_value, 3) * 255); // Red component
  			  int g = (int)(15 * pow((1 - smooth_value), 2) * pow(smooth_value, 2) * 255); // Green component
   			 int b = (int)(8.5 * pow((1 - smooth_value), 3) * pow(smooth_value, 1) * 255); // Blue component

    // Combine the components into a single integer (RGB)
    color = (r << 16) | (g << 8) | b;
		}
//		^^^ to study how it was colored and optimal coloring ^^^	
		
		complex_to_pixel(z_real, z_imag, &px, &py, XMAX, YMAX);
		
		if(px>=0 && px < XMAX && py >= 0 && py < YMAX)
			my_mlx_pixel_put(&img,px,py,color);
			//draw_circle(mlx,mlx_win,px,py,2,XMAX,YMAX);
		i++;
	}
}

int main(int ac, char **av)
{
	double cr = -2.0, ci = -1.5;
	if (ac == 3)
	{
		int XMAX = atoi(av[1]);
	       	int YMAX = atoi(av[2]);
		t_data img;
		void *mlx = mlx_init();
		void *mlx_win = mlx_new_window(mlx,XMAX,YMAX,"test");
		img.img = mlx_new_image(mlx,XMAX,YMAX);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
		
		//mlx_hook(mlx_win,2,1L<<19,draw_circle(mlx,mlx_win,250,250,10,XMAX,YMAX),mlx_win);		
		draw_graph(XMAX,YMAX,mlx,mlx_win);
		while(cr <= 1)
		{
			while(ci <= 1.5) 
			{
				visualize(img, cr, ci, XMAX, YMAX);
				//if (cr != 1.0)
				ci += 0.01;
			}
			ci = -1.5;
			cr += 0.01;
		}
		//draw_circle(mlx,mlx_win,250,250,2,XMAX,YMAX);
		mlx_put_image_to_window(mlx,mlx_win,img.img,0,0);
		mlx_loop(mlx);
	}
	else
		printf("Invalid arguments\nPlease retry using 2 arguments\n");
}
