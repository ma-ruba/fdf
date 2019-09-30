#include "fdf.h"

static void	set_xvalues2(t_coord *max, t_pixel *pix2)
{
	max->x = pix2->x;
	max->z = pix2->z;
	max->color = pix2->color;
}

static void	set_xvalues(t_coord *min, t_coord *max, t_pixel *pix1, t_pixel *pix2)
{
	min->y = fmin(pix1->y, pix2->y);
	if (min->y == pix1->y)
	{
		min->x = pix1->x;
		min->z = pix1->z;
		min->color = pix1->color;
	}
	else
	{
		min->x = pix2->x;
		min->z = pix2->z;
		min->color = pix2->color;
	}
	max->y = fmax(pix1->y, pix2->y);
	if (max->y == pix1->y)
	{
		max->x = pix1->x;
		max->z = pix1->z;
		max->color = pix1->color;
	}
	else
		set_xvalues2(max, pix2);
}

static int	define_xdirection(t_pixel *pix1, t_pixel *pix2)
{
    int     max_x;

    max_x = fmax(pix1->x, pix2->x);
    if (max_x == pix1->x && pix1->y > pix2->y)
        return (1);
    else if (max_x == pix1->x && pix1->y < pix2->y)
        return (0);
    else if (max_x == pix2->x && pix2->y > pix1->y)
        return (1);
    else
        return (0);
}

static void bresenhem(float *error, int flag, float coef, t_coord *coord)
{
	*error += coef;
	if (*error >= 0.5)
	{
		(coord->y)++;
		(*error)--;
	}
	if (flag)
		(coord->x)++;
	else
		(coord->x)--;
}

void		x_line(t_pixel *pix1, t_pixel *pix2, t_mlx *mlx, float error)
{
	float	coef;
	t_coord	coord;
	t_coord	max;
	t_coord	min;
	int		flag;

	set_xvalues(&min, &max, pix1, pix2);
    flag = define_xdirection(pix1, pix2);
	if (pix1->x - pix2->x != 0)
		coef = fabsf((float)(pix1->y - pix2->y) / (pix1->x - pix2->x));
	coord = min;
	pixel_put(&coord, mlx, coord.color);
	while (coord.x != max.x)
	{
		bresenhem(&error, flag, coef, &coord);
		if (pix1->color != pix2->color)
			gradient(percentage(min.x, max.x, coord.x), &coord, min.color, max.color);
		else
			coord.color = pix1->color;
		pixel_put(&coord, mlx, -1);
	}
	pixel_put(&coord, mlx, coord.color);
}
