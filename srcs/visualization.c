#include "fdf.h"

void	set_color(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i < mlx->global.g_i)
	{
		if (mlx->p_arr[i].z < mlx->global.g_max_z / 3)
			mlx->p_arr[i].color = 0x87ceeb;
		else if (mlx->p_arr[i].z < mlx->global.g_max_z * 2 / 3)
			mlx->p_arr[i].color = 0x6400;
		else
			mlx->p_arr[i].color = 0xffa500;
	}
}

void		draw_line(t_pixel *pix1, t_pixel *pix2, t_mlx *mlx)
{
	int		x_proj;
	int		y_proj;

	x_proj = abs(pix1->x - pix2->x);
	y_proj = abs(pix1->y - pix2->y);
	if (mlx->proj == ISO)
	{
		if (x_proj > y_proj)
			x_line(pix1, pix2, mlx, 0);
		else
			y_line(pix1, pix2, mlx, 0);
	}
	else if (mlx->proj == PARALL)
		draw_parallel(mlx, pix1, pix2);
}

void		pixel_put(t_coord *coord, t_mlx *mlx, int color)
{
	int		pos;
	
	pos = (coord->x + coord->y * WIN_WIDTH);
	if (pos < WIN_WIDTH * WIN_HEIGHT)
	{
		if  (color != -1)
			mlx->img_data.data[pos] = color;
		else
			mlx->img_data.data[pos] = coord->color;
	}
}

void	draw_black(t_mlx *mlx)
{
	int		i;
	int		size;

	i = -1;
	size = WIN_WIDTH * WIN_HEIGHT;
	while (++i < size)
		mlx->img_data.data[i] = 0x000000;
}

int    		visualization(t_mlx *mlx)
{
	int		i;

	i = -1;
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img_data.data = (int*)mlx_get_data_addr(mlx->img_ptr, \
		&mlx->img_data.pbb, &mlx->img_data.size, &mlx->img_data.endian);
	scale(mlx);
	draw_black(mlx);
	set_color(mlx);
	while (++i < mlx->global.g_i)
	{
		if ((i + mlx->global.g_x_coord) < mlx->global.g_i)
			draw_line(&(mlx->p_arr[i + mlx->global.g_x_coord]), &(mlx->p_arr[i]), mlx);
		if (i + 1 < mlx->global.g_i && (i + 1) % mlx->global.width != 0)
			draw_line(&(mlx->p_arr[i + 1]), &(mlx->p_arr[i]), mlx);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (0);
}
