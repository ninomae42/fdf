#include "fdf.h"

double	calculate_scale(t_info *info)
{
	double	distance_x;
	double	distance_y;

	distance_x = (info->mlx->width - 100) / (double)info->map->cols;
	distance_y = (info->mlx->height - 100) / (double)info->map->rows;
	if (distance_x == 0 || distance_y == 0)
		return (2.0);
	if (distance_x < distance_y)
		return (distance_x / 2.0);
	else
		return (distance_y / 2.0);
}
