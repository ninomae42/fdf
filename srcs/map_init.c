#include "fdf.h"

// initialize map struct. load map file given by filename
t_map	*init_map(char *file_name)
{
	t_map	*map;

	map = ft_malloc(sizeof(t_map));
	ft_bzero(map, sizeof(t_map));
	set_map_width_height(file_name, map);
	printf("row: %zu, col: %zu\n", map->rows, map->cols);
	map->points = (t_point *)ft_malloc(sizeof(t_point) * (map->rows * map->cols));
	ft_bzero(map->points, (sizeof(t_point) * (map->rows * map->cols)));
	read_map(file_name, map);
	print_map(map);
	return (map);
}

// deallocate map struct.
void	deallocate_map(t_map *map)
{
	free(map->points);
	free(map);
}
