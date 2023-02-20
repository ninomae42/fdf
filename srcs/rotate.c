#include "fdf.h"

void	rotate_x(t_map *map, double radian)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	while (row_index < map->rows)
	{
		col_index = 0;
		while (col_index < map->cols)
		{
			rotate_point_xaxis(&map->points[get_map_index(map, row_index, col_index)], radian);
			col_index++;
		}
		row_index++;
	}
}

void	rotate_y(t_map *map, double radian)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	while (row_index < map->rows)
	{
		col_index = 0;
		while (col_index < map->cols)
		{
			rotate_point_yaxis(&map->points[get_map_index(map, row_index, col_index)], radian);
			col_index++;
		}
		row_index++;
	}
}

void	rotate_z(t_map *map, double radian)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	while (row_index < map->rows)
	{
		col_index = 0;
		while (col_index < map->cols)
		{
			rotate_point_zaxis(&map->points[get_map_index(map, row_index, col_index)], radian);
			col_index++;
		}
		row_index++;
	}
}
