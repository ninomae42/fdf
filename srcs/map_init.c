#include "fdf.h"

// initialize map struct. load map file given by filename
t_map	*init_map(char *file_name)
{
	t_map	*map;

	map = ft_malloc(sizeof(t_map));
	ft_bzero(map, sizeof(t_map));
	set_map_width_height(file_name, map);
	map->points = (t_point *)ft_malloc(sizeof(t_point) * (map->rows * map->cols));
	ft_bzero(map->points, (sizeof(t_point) * (map->rows * map->cols)));
	read_map(file_name, map);
	return (map);
}

// copy map struct.
t_map	*copy_map(t_map *map)
{
	t_map	*map_new;

	map_new = ft_malloc(sizeof(t_map));
	ft_bzero(map_new, sizeof(t_map));
	map_new->rows = map->rows;
	map_new->cols = map->cols;
	map_new->points = (t_point *)ft_malloc(sizeof(t_point) * (map_new->cols * map_new->rows));
	ft_memcpy(map_new->points, map->points,
			(sizeof(t_point) * (map->cols * map->rows)));
	return (map_new);
}

// deallocate map struct.
void	deallocate_map(t_map *map)
{
	free(map->points);
	free(map);
}
