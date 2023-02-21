#include "fdf.h"

static int	ft_abs(int n);
static void	img_pixel_put(t_mlx_img *img, int x, int y, int color);
static void	plot_dot(t_mlx_img *img, t_plot *plot, double x, double y);

void	draw_line(t_mlx_img *img, t_point p1, t_point p2)
{
	t_plot	plot;

	plot.dx = p2.x - p1.x;
	plot.dy = p2.y - p1.y;
	if (ft_abs(plot.dx) > ft_abs(plot.dy))
		plot.steps = ft_abs(plot.dx);
	else
		plot.steps = ft_abs(plot.dy);
	plot.x_inc = plot.dx / (double)plot.steps;
	plot.y_inc = plot.dy / (double)plot.steps;
	plot.start_color = p1.color;
	plot.end_color = p2.color;
	plot_dot(img, &plot, p1.x, p1.y);
}

void	clear_window(t_info *info)
{
	size_t		x;
	size_t		y;
	t_mlx_img	*img;

	img = info->mlx->img;
	y = 0;
	while (y < (size_t)info->mlx->height)
	{
		x = 0;
		while (x < (size_t)info->mlx->width)
		{
			img_pixel_put(img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

static void	plot_dot(t_mlx_img *img, t_plot *plot, double x, double y)
{
	int	i;

	i = 0;
	while (i < plot->steps)
	{
		img_pixel_put(img, x, y, get_gradation_color(plot->start_color,
				plot->end_color, plot->steps, i));
		x += plot->x_inc;
		y += plot->y_inc;
		i++;
	}
}

static int	ft_abs(int n)
{
	if (0 < n)
		return (n);
	return (-n);
}

static void	img_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || img->width < x || y < 0 || img->height < y)
		return ;
	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)dest = color;
}
