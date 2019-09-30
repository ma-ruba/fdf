#include "fdf.h"

void	no_arg()
{
	ft_printf("An argument is required.\n");
	ft_printf("Usage:\n");
	ft_printf(" KEY_ESC -> exit the window\n KEY_SPACE ->\
 change projection\n KEY_UPARROW -> increase z_coord in 5 times\n\
 KEY_DOWNARROW decrease z_coord in 5 times\n");
}

void    map_error(t_mlx *mlx)
{
	write(1, "MAP_ERROR\n", 10);
	free(mlx->p_arr);
	exit(1);
}

void    open_error()
{
	write(1, "OPEN  FAILED\n", 13);
	exit(1);
}

void	empty_map(t_mlx *mlx)
{
	ft_printf("Empty map! ERROR\n");
	free(mlx->p_arr);
	exit (1);
}

void	debug_help(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->global.g_i)
	{
		
		ft_printf("%i:", mlx->p_arr[i].x);
		ft_printf("%i, ", mlx->p_arr[i].y);
		if (i % mlx->global.width == 0)
			ft_printf("\n");
	}
}
