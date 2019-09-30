#include "fdf.h"

static void	set_yvalues2(t_coord *max, t_pixel *pix2)
{
	max->y = pix2->y;
	max->z = pix2->z;
	max->color = pix2->color;
}

static void	set_yvalues(t_coord *min, t_coord *max, t_pixel *pix1, t_pixel *pix2)
{
	min->x = fmin(pix1->x, pix2->x);
	if (min->x == pix1->x)
	{
		min->y = pix1->y;
		min->z = pix1->z;
		min->color = pix1->color;
	}
	else
	{
		min->y = pix2->y;
		min->z = pix2->z;
		min->color = pix2->color;
	}
	max->x = fmax(pix1->x, pix2->x);
	if (max->x == pix1->x)
	{
		max->y = pix1->y;
		max->z = pix1->z;
		max->color = pix1->color;
	}
	else
		set_yvalues2(max, pix2);
}

static int	define_ydirection(t_pixel *pix1, t_pixel *pix2)
{
    int     max_y;

    max_y = fmax(pix1->y, pix2->y);
    if (max_y == pix1->y && pix1->x > pix2->x)
        return (1);
    else if (max_y == pix1->y && pix1->x < pix2->x)
        return (0);
    else if (max_y == pix2->y && pix2->x > pix1->x)
        return (1);
    else
        return (0);
}

static void	bresenhem(float *error, int flag, float coef, t_coord *coord)
{
	*error += coef;
	if (*error >= 0.5)
	{
		(coord->x)++;
		(*error)--;
	}
	if (flag)
		(coord->y)++;
	else
		(coord->y)--;
}

void		y_line(t_pixel *pix1, t_pixel *pix2, t_mlx *mlx, float error)
{
	float	coef;
	t_coord	coord;
	t_coord	max;
    t_coord min;
    int     flag;

	set_yvalues(&min, &max, pix1, pix2);
    flag = define_ydirection(pix1, pix2);
	if (pix1->y - pix2->y != 0)
		coef = fabsf((float)(pix1->x - pix2->x) / (pix1->y - pix2->y));
	coord = min;
    pixel_put(&min, mlx, min.color);
	while (coord.y != max.y)
	{
		bresenhem(&error, flag, coef, &coord);
        if (pix1->color != pix2->color)
			gradient(percentage(min.y, max.y, coord.y), &coord, min.color, max.color);
		else
			coord.color = pix1->color;
		pixel_put(&coord, mlx, -1);
	}
    pixel_put(&max, mlx, max.color);
}
