#include "fdf.h"

static void	render(t_info *info);
static void	render_map(t_info *info);

int	hook_render(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (info->mlx->win_ptr == NULL)
		return (1);
	render(info);
	return (0);
}

static void	render(t_info *info)
{
	render_map(info);
	mlx_put_image_to_window(info->mlx->mlx_ptr, info->mlx->win_ptr,
		info->mlx->img->mlx_img, 0, 0);
}

static void	render_map(t_info *info)
{
	size_t	x;
	size_t	y;
	t_point	*points;

	points = info->draw_map->points;
	y = 0;
	while (y < info->draw_map->rows)
	{
		x = 0;
		while (x < info->draw_map->cols)
		{
			if (x != info->draw_map->cols - 1)
				draw_line(info->mlx->img,
					points[get_map_index(info->draw_map, y, x)],
					points[get_map_index(info->draw_map, y, x + 1)]);
			if (y != info->draw_map->rows - 1)
				draw_line(info->mlx->img,
					points[get_map_index(info->draw_map, y, x)],
					points[get_map_index(info->draw_map, y + 1, x)]);
			x++;
		}
		y++;
	}
}
