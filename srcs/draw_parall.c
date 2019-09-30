#include "fdf.h"

static void	x_parallel(t_mlx *mlx, t_pixel *pix1, t_pixel *pix2)
{
	t_coord	coord;

	coord.x = pix2->x;
	coord.y = pix2->y;
	coord.color = pix2->color;
	pixel_put(&coord, mlx, pix2->color);
	while (++(coord.x) <= pix1->x)
	{
		if (pix1->color != pix2->color)
			gradient(percentage(pix2->x, pix1->x, coord.x), &coord, pix2->color, pix1->color);
		else
			coord.color = pix1->color;
		pixel_put(&coord, mlx, -1);
	}
	pixel_put(&coord, mlx, pix1->color);
}

static void	y_parallel(t_mlx *mlx, t_pixel *pix1, t_pixel *pix2)
{
	t_coord	coord;

	coord.x = pix2->x;
	coord.y = pix2->y;
	coord.color = pix2->color;
	pixel_put(&coord, mlx, pix2->color);
	while (++(coord.y) <= pix1->y)
	{
		if (pix1->color != pix2->color)
			gradient(percentage(pix2->y, pix1->y, coord.y), &coord, pix2->color, pix1->color);
		else
			coord.color = pix1->color;
		pixel_put(&coord, mlx, -1);
	}
	pixel_put(&coord, mlx, pix1->color);
}

void		draw_parallel(t_mlx *mlx, t_pixel *pix1, t_pixel *pix2)
{
	if (pix1->x != pix2->x)
		x_parallel(mlx, pix1, pix2);
	else
		y_parallel(mlx, pix1, pix2);
}
