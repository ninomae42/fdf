#include "fdf.h"

static void	read_point(char *point,
				size_t x, size_t y, t_point **points);
static void	read_row(char *row, size_t y, t_map *map);

void	read_map(char *file_name, t_info *info)
{
	int		fd;
	char	*row;
	size_t	y;

	fd = open_file(file_name);
	row = get_next_line(fd);
	y = 0;
	while (row != NULL)
	{
		read_row(row, y, info->map);
		free(row);
		row = NULL;
		y++;
		row = get_next_line(fd);
	}
	if (info->map->height != y)
	{
		ft_puterr(ERR_LOAD_MAP);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static void	read_row(char *row, size_t y, t_map *map)
{
	char	**row_split;
	size_t	x;

	row_split = ft_split_or_exit(row, ' ');
	x = 0;
	while (row_split[x] != NULL)
	{
		read_point(row_split[x], x, y, map->points);
		x++;
	}
	ft_split_free(row_split);
	if (x != map->width)
	{
		ft_puterr(ERR_LOAD_MAP);
		exit(EXIT_FAILURE);
	}
}

static void	read_point(char *point,
	size_t x, size_t y, t_point **points)
{
	size_t	i;
	char	**point_split;

	i = 0;
	point_split = ft_split_or_exit(point, ',');
	if (ft_split_len(point_split) == 2)
		points[y][x].color = hex_to_int(point_split[1]);
	else
		points[y][x].color = -1;
	points[y][x].z = (double)ft_atoi(point_split[0]);
	points[y][x].y = (double)y;
	points[y][x].x = (double)x;
	ft_split_free(point_split);
	i++;
}
