#include "fdf.h"

static void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

static void moove(t_mlx *mlx, int min_x, int min_y, int min_z)
{
	int     i;

	i = -1;
	ft_printf("\n");
	if (min_x < 0)
	{
		while (++i < mlx->global.g_i)
			mlx->p_arr[i].x += abs(min_x) + 50;
	}
	i = -1;
	if (min_y < 0)
	{
		while (++i < mlx->global.g_i)
			mlx->p_arr[i].y += abs(min_y) + 50;
	}
	i = -1;
	if (min_z < 0)
	{
		while (++i < mlx->global.g_i)
			mlx->p_arr[i].z += abs(min_z);
	}
}

static void	iso_prep(t_mlx *mlx, int index)
{
	int		i;
	int		min_x;
	int		min_y;
	int     min_z;

	i = -1;
	while (++i < mlx->global.g_i)
	{
		if (mlx->proj == ISO)
			iso(&(mlx->p_arr[i]).x, &(mlx->p_arr[i]).y, (mlx->p_arr[i]).z);
		if (index == 0)
		{
			min_x = mlx->p_arr[i].x;
			min_y = mlx->p_arr[i].y;
			min_z = mlx->p_arr[i].z;
			index = 1;
		}
		else if (mlx->p_arr[i].x < min_x)
			min_x = mlx->p_arr[i].x;
		else if (mlx->p_arr[i].y < min_y)
			min_y = mlx->p_arr[i].y;
		else if (mlx->p_arr[i].z < min_z)
			min_z = mlx->p_arr[i].z;
	}
	moove(mlx, min_x, min_y, min_z);
}

void        scale(t_mlx *mlx)
{
	int		delta_x;
	int		delta_y;
	int		i;
	int		nb;
	
	i = -1;
	nb = mlx->global.g_x_coord;
	delta_x = (WIN_WIDTH - 400) / (nb - 1);
	delta_y = (WIN_HEIGHT - 400) / (mlx->global.g_y_coord - 1);
	while (++i < mlx->global.g_i)
	{
		if (i % nb == 0)
			mlx->p_arr[i].x = 200;
		else
			mlx->p_arr[i].x = mlx->p_arr[i - 1].x + delta_x;
		if (i == 0)
			mlx->p_arr[i].y = 200;
		else if (i % nb == 0)
			mlx->p_arr[i].y = mlx->p_arr[i - nb].y + delta_y;
		else
			mlx->p_arr[i].y = mlx->p_arr[i - 1].y;
	}
	iso_prep(mlx, 0);
}

