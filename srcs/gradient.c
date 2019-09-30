#include "fdf.h"
float		percentage(int start, int end, int current)
{
	float	placement;
    float	distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

static int	get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

static int	get_color(int start, int end, float percentage)
{
	int 	red;
    int		green;
    int		blue;

    red = get_light((start >> 16) & 0xFF, (end >> 16) & 0xFF, percentage);
    green = get_light((start >> 8) & 0xFF, (end >> 8) & 0xFF, percentage);
    blue = get_light(start & 0xFF, end & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

void		gradient(float percent, t_coord *coord, int start, int end)
{
	coord->color = get_color(start, end, percent);
}
