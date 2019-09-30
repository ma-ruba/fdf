#include "fdf.h"

void		process_map(int fd, t_mlx *mlx)
{
	char	*line;
	int		index;

	mlx->global.g_y_coord = 0;
	line = NULL;
	index = 0;
	mlx->global.g_index = 0;
	mlx->global.g_i = 0;
	if (!(mlx->p_arr = (t_pixel*)ft_memalloc(ARR_SIZE * sizeof(t_pixel))))
		exit(1);
	while (get_next_line(fd, &line))
	{
		if (!index)
		{
			index = 1;
			mlx->global.width = (int)ft_count_smth(line, ' ');
		}
		if ((int)ft_count_smth(line, ' ') != mlx->global.width)
			map_error(mlx);
		get_coord(line, mlx->p_arr, mlx);
		(mlx->global.g_y_coord)++;
		free(line);
	}
	if (!index)
		empty_map(mlx);
}

static void	fill_pixel(t_pixel *pixel, char *line, t_mlx *mlx)
{
	pixel->x = mlx->global.g_x_coord;
	pixel->y = mlx->global.g_y_coord;
	pixel->z = ft_atoi(line);
	if (!(mlx->global.g_index))
	{
		mlx->global.g_index = 1;
		mlx->global.g_max_z = pixel->z;
	}
	else if (pixel->z > mlx->global.g_max_z)
		mlx->global.g_max_z = pixel->z;
	(mlx->global.g_i)++;
	(mlx->global.g_x_coord)++;
}

void		get_coord(char *line, t_pixel *p_arr, t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx->global.g_x_coord = 0;
	while (line[i])
	{
		while (line[i] && line[i] != ' ')
		{
			if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
				i++;
			else
				map_error(mlx);
		}
		line[i] = '\0';
		fill_pixel(&p_arr[mlx->global.g_i], &line[j], mlx);
		if (mlx->global.g_x_coord != mlx->global.width)
			line[i] = ' ';
		while (line[i] && line[i] == ' ')
			i++;
		j = i;
	}
}

void	change_height(t_mlx *mlx)
{
	int		i;

	i = -1;
	if (mlx->delta_height == 1)
	{
		while (++i < mlx->global.g_i)
			mlx->p_arr[i].z *= 5;
		mlx->global.g_max_z *= 5;
	}
	else if (mlx->delta_height == -1)
	{
		while (++i < mlx->global.g_i)
			mlx->p_arr[i].z /= 5;
		mlx->global.g_max_z /=  5;
	}
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			open_error();
		mlx.height_coef = 1;
		mlx.delta_height = 0;
		process_map(fd, &mlx);
		close(fd);
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
		mlx.proj = ISO;
		mlx_hook(mlx.win_ptr, 2, 3, key_hook, &mlx);
		visualization(&mlx);
		mlx_loop(mlx.mlx_ptr);
		mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
		mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
		free(mlx.p_arr);
	}
	else
		no_arg();
	return (0);
}
