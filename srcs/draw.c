#include "fdf.h"

void	draw_line(t_img *img, t_point *p1, t_point *p2)
{
	double	dx;
	double	dy;
	double	theta;
	unsigned int	d;
	unsigned int	l;
	double	x;
	double	y;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	d = sqrt(dx * dx + dy * dy);
	theta = atan2(dy, dx);
	l = 0;
	printf("dx: %e, dy: %e, d: %d, theta: %e\n", dx, dy, d, theta);
	printf("sin: %e, cos: %e\n", sin(theta), cos(theta));
	while (l < d)
	{
		x = (double)p1->x + l * cos(theta);
		y = (double)p1->y + l * sin(theta);
		my_mlx_pixel_put(img, (int)x, (int)y, 0x0000FF00);
		l++;
	}
	printf("x: %e, y: %e\n\n", p1->x + l * cos(theta), p1->y + l * sin(theta));
}

void	draw_horizontal_line(t_img *img, int x1, int y1, int x2, int y2)
{
	printf("x1: %d, y1: %d, x2: %d, y2: %d\n", x1, y1, x2, y2);
	while (x1 < x2 - 1)
	{
		my_mlx_pixel_put(img, x1, y1, 0x00FFFFFF);
		x1++;
	}
	printf("x1: %d, y1: %d, x2: %d, y2: %d\n", x1, y1, x2, y2);
}

void	draw_vertical_line(t_img *img, int x1, int y1, int x2, int y2)
{
	printf("x1: %d, y1: %d, x2: %d, y2: %d\n", x1, y1, x2, y2);
	while (y1 < y2 - 1)
	{
		my_mlx_pixel_put(img, x1, y1, 0x00FFFFFF);
		y1++;
	}
	printf("x1: %d, y1: %d, x2: %d, y2: %d\n", x1, y1, x2, y2);
}
