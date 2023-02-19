#include "fdf.h"

int	set_map_width_height(const char *file_name, t_map *map)
{
	int		fd;
	char	*row;
	char	**points;

	fd = open_file_by_name(file_name);
	row = get_next_line(fd);
	while (row != NULL)
	{
		points = ft_split_safe(row, ' ');
		free(row);
		if (map->cols == 0)
			map->cols = ft_split_len(points);
		else if (map->cols != ft_split_len(points))
		{
			ft_split_free(points);
			return (1);
		}
		ft_split_free(points);
		row = get_next_line(fd);
		map->rows++;
	}
	close(fd);
	return (0);
}

size_t	get_map_index(t_map *map, size_t row_index, size_t col_index)
{
	return (row_index * map->cols + col_index);
}
