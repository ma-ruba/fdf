#include "fdf.h"

static void change_projection(t_mlx *mlx)
{
    if (mlx->proj == ISO)
        mlx->proj = PARALL;
    else if (mlx->proj == PARALL)
        mlx->proj = ISO;
    mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
    visualization(mlx);
}

static void finish(t_mlx *mlx)
{
    free(mlx->p_arr);
    mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    exit(0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 0X35)
        finish(mlx);
	else if (keycode == 0X31)
        change_projection(mlx);
	else if (keycode == 0X7E && mlx->proj == ISO && mlx->height_coef <= 2)
	{
		mlx->height_coef += 1;
		mlx->delta_height = 1;
		change_height(mlx);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		visualization(mlx);
	}
	else if (mlx->height_coef > 1 && keycode == 0X7D && mlx->proj == ISO)
	{
		mlx->height_coef -= 1;
		mlx->delta_height = -1;
		change_height(mlx);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		visualization(mlx);
	}
	return (0);
}
