#include "fdf.h"

static int	ft_abs(int n);
static void	img_pixel_put(t_img *img, int x, int y, int color);

void	draw_line(t_img *img, int x0, int y0, int x1, int y1)
{
	t_plot	plot;
	int		i;
	double	x;
	double	y;

	plot.dx = x1 - x0;
	plot.dy = y1 - y0;
	if (ft_abs(plot.dx) > ft_abs(plot.dy))
		plot.steps = ft_abs(plot.dx);
	else
		plot.steps = ft_abs(plot.dy);
	plot.x_inc = plot.dx / (double)plot.steps;
	plot.y_inc = plot.dy / (double)plot.steps;
	i = 0;
	x = x0;
	y = y0;
	while (i < plot.steps)
	{
		img_pixel_put(img, x, y, 0xFFFFFF);
		x += plot.x_inc;
		y += plot.y_inc;
		i++;
	}
}

static int	ft_abs(int n)
{
	if (0 < n)
		return (n);
	return (-1 * n);
}

static void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || img->win_width < x || y < 0 || img->win_height < y)
		return ;
	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)dest = color;
}
