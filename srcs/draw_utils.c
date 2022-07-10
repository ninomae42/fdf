#include "../includes/fdf.h"

// Calculate current color for gradation.
int	calc_color(double l, double d, int color1, int color2)
{
	double	ret;

	ret = (color2 - color1) * l / d;
	return (ret);
}

// Calculate scale based on widow size and
// points per axis(x / y)
double	calculate_scale(t_map *map_info)
{
	double	scale_x;
	double	scale_y;

	scale_x = 1000.0 / map_info->width;
	scale_y = 600.0 / map_info->height;
	if (scale_x < scale_y)
		return (scale_x);
	else
		return (scale_y);
}
