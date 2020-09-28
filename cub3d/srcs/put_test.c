# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define BLOCK_SIZE 32
# define mapWidth 6
# define mapHeight 8

# define FOV M_PI / 3

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

typedef struct  s_win 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    void        *mlx;
    void        *win;
}               t_win;

typedef struct  s_player
{
    int         x_player;
    int         y_player;
    double      direction;
}               t_player;

typedef struct  s_all
{
    t_win		win;
    t_player	player;
}               t_all;



void            my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void 		ft_cub_draw(t_win win)
{
	int	x = -1;
	int	y = -1;

	int width = 5;
	int i = -1;

	int j = 1;
	int jy = 1;
	while(++y < 100)	
	{	
		while (++i <= width)
		{
				while (++x < (j * BLOCK_SIZE))
				{
					if ((x + 1) == j * BLOCK_SIZE)
					{
						my_mlx_pixel_put(&win, x, y, 0xff0000);
						my_mlx_pixel_put(&win, x + 1, y, 0xff0000);
						printf("x = %i\n", x);
						printf("x = %i\n", x+1);
					}
					else
					{
						my_mlx_pixel_put(&win, x, y, 0x878794);
						// printf("x = %i\n", x);
					}
				}
				x = j * BLOCK_SIZE;
				j++;
		}
		i = -1;
		x = -1;
		j = 1;
		// jy++;
	}
	x = -1;
	y = -1;
	while(++y < 100)	
	{	
		if ((y + 1) == jy * BLOCK_SIZE)
		{
			while (++x <= (width + 1)  * BLOCK_SIZE)
			{
				my_mlx_pixel_put(&win, x, y, 0xff0000);
				my_mlx_pixel_put(&win, x, y + 1, 0xff0000);
				printf("y = %i\n", y);
				printf("y = %i\n", y +1);
			}
			x = -1;
			jy++;	
		}
	}

}
	


int             main(void)
{ 
    t_all   s;

	char    *relative_path = "./textures/WALL_NORD.xpm";
    int     img_width;
    int     img_height;
	void	*img;
    s.win.mlx = mlx_init();
    s.win.win = mlx_new_window(s.win.mlx, 1920, 1080, "cub3D");
    s.win.img = mlx_new_image(s.win.mlx, 1920, 1080);
    s.win.addr = mlx_get_data_addr(s.win.img, &s.win.bits_per_pixel, &s.win.line_length,
                                 &s.win.endian);
    // ft_cub_draw(s.win);
	img = mlx_xpm_file_to_image(s.win.mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(s.win.mlx, s.win.win, s.win.img, 0, 0);
    mlx_loop(s.win.mlx);
    return (0);
}


