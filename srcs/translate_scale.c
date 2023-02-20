#include "fdf.h"

static void	translate_point(t_point *point, double dx, double dy);
static void	scale_point(t_point *point, double scale);

void	translate(t_map *map, double dx, double dy)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	while (row_index < map->rows)
	{
		col_index = 0;
		while (col_index < map->cols)
		{
			translate_point(&map->points[get_map_index(map, row_index, col_index)], dx, dy);
			col_index++;
		}
		row_index++;
	}
}

void	scale(t_map *map, double scale)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	while (row_index < map->rows)
	{
		col_index = 0;
		while (col_index < map->cols)
		{
			scale_point(&map->points[get_map_index(map, row_index, col_index)], scale);
			col_index++;
		}
		row_index++;
	}
}

static void	translate_point(t_point *point, double dx, double dy)
{
	point->x = point->x + dx;
	point->y = point->y + dy;
}

static void	scale_point(t_point *point, double scale)
{
	point->x = point->x * scale;
	point->y = point->y * scale;
	point->z = point->z * scale;
}
