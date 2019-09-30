#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define PUT		1
# define NOT_PUT	0
# define ARR_SIZE	500000
# define ISO		1
# define PARALL		0

typedef struct		s_global
{
	int					g_x_coord;
	int					g_y_coord;
	int					g_max_z;
	int					g_index;
	int					g_i;
	int					width;
}					t_global;


typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct      s_pixel
{
	int			    x;
	int			    y;
	int			    z;
	int				color;
}                   t_pixel;

typedef struct		s_img_data
{
	int				*data;
	int				pbb;
	int				size;
	int				endian;
}					t_img_data;

typedef struct      s_mlx
{
   void             *mlx_ptr;
   void             *win_ptr;
   void				*img_ptr;
   t_img_data		img_data;
   t_pixel			*p_arr;
   t_color			color;
   int				proj;
   int				height_coef;
   int				delta_height;
   t_global			global;
}					t_mlx;

void				get_coord(char *line, t_pixel *p_arr, t_mlx *mlx);
void				process_map(int fd, t_mlx *mlx);
void				scale(t_mlx *mlx);
void				draw_black(t_mlx *mlx);
void				set_color(t_mlx *mlx);

void				draw_line(t_pixel *pix1, t_pixel *pix2, t_mlx *mlx);
int    				visualization(t_mlx *mlx);
void				x_line(t_pixel *pix1, t_pixel *pix2, t_mlx *mlx, float error);
void				y_line(t_pixel *pix1, t_pixel *pix2, t_mlx *mlx, float error);
void				pixel_put(t_coord *coord, t_mlx *mlx, int color);
int					key_hook(int keycode, t_mlx *mlx);
void				change_height(t_mlx *mlx);

void				no_arg();
void    			open_error();
void				map_error(t_mlx *mlx);
void				debug_help(t_mlx *mlx);
void				empty_map(t_mlx *mlx);

void    			gradient(float percent, t_coord *coord, int start, int end);
float				percentage(int start, int end, int current);

void				draw_parallel(t_mlx *mlx, t_pixel *pix1, t_pixel *pix2);

#endif
