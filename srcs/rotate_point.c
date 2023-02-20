#include "fdf.h"

void	rotate_point_xaxis(t_point *point, double radian)
{
	double	y;
	double	z;

	y = point->y * cos(radian) - sin(radian) * point->z;
	z = point->y * sin(radian) + cos(radian) * point->z;
	point->y = y;
	point->z = z;
}

void	rotate_point_yaxis(t_point *point, double radian)
{
	double	x;
	double	z;

	x = point->x * cos(radian) + point->z * sin(radian);
	z = point->z * cos(radian) - point->x * sin(radian);

	point->x = x;
	point->z = z;
}

void	rotate_point_zaxis(t_point *point, double radian)
{
	double	x;
	double	y;

	x = point->x * cos(radian) - sin(radian) * point->y;
	y = point->x * sin(radian) + cos(radian) * point->y;
	point->x = x;
	point->y = y;
}
