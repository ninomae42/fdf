#include "fdf.h"

void	translate_map(t_info *info, int trans_x, int trans_y);
void	render(t_info *info);
void	render_map(t_info *info);
void	clear_window(t_info *info);
void	scale_map(t_info *info, double scale);
void	convert_to_iso(t_info *info);

void	handle_close(t_info *info)
{
	mlx_loop_end(info->mlx_ptr);
	deallocate_mlx(info);
	deallocate_map(info->map);
	free(info);
	exit(EXIT_SUCCESS);
}

int	hook_button(int keysym, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (keysym == XK_Escape)
		handle_close(info);
	clear_window(info);
	if (keysym == XK_w)
		translate_map(info, 0, -10);
	if (keysym == XK_a)
		translate_map(info, -10, 0);
	if (keysym == XK_s)
		translate_map(info, 0, 10);
	if (keysym == XK_d)
		translate_map(info, 10, 0);
	return (0);
}

int	hook_mouse(int button, int x, int y, void *param)
{
	t_info	*info;

	(void)x;
	(void)y;
	info = (t_info *)param;
	clear_window(info);
	if (button == Button4)
		scale_map(info, (double)1.1);
	if (button == Button5)
		scale_map(info, 1 / (double)1.1);
	return (0);
}

int	hook_close_button(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	handle_close(info);
	return (0);
}

void	render_map(t_info *info)
{
	size_t	x;
	size_t	y;
	t_point	**points;

	points = info->map->points;
	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if (x != info->map->width - 1)
				draw_line(info->img, points[y][x], points[y][x + 1]);
			if (y != info->map->height - 1)
				draw_line(info->img, points[y][x], points[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	scale_map(t_info *info, double scale)
{
	size_t	x;
	size_t	y;
	t_point	**points;

	points = info->map->points;
	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			points[y][x].x *= scale;
			points[y][x].y *= scale;
			points[y][x].z *= scale;
			x++;
		}
		y++;
	}
}

void	translate_map(t_info *info, int trans_x, int trans_y)
{
	size_t	x;
	size_t	y;
	t_point	**points;

	points = info->map->points;
	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			points[y][x].x += trans_x;
			points[y][x].y += trans_y;
			x++;
		}
		y++;
	}
}

void	convert_matrix_to_iso(t_point *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (prev_x - prev_y) * cos(M_PI / 6);
	point->y = (prev_x + prev_y) * sin(M_PI / 6) - point->z;
}

void	convert_to_iso(t_info *info)
{
	size_t	x;
	size_t	y;
	t_point	**points;

	points = info->map->points;
	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			convert_matrix_to_iso(&points[y][x]);
			x++;
		}
		y++;
	}
}

void	render(t_info *info)
{
	render_map(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img->mlx_img, 0, 0);
}

int	hook_render(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (info->win_ptr == NULL)
		return (1);
	render(info);
	return (0);
}