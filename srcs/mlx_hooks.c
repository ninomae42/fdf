#include "fdf.h"

void	handle_close(t_info *info)
{
	mlx_loop_end(info->mlx_ptr);
	deallocate_mlx(info);
	// deallocate_map(info->map);
	free(info);
	exit(EXIT_SUCCESS);
}

int	hook_button(int keysym, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (keysym == XK_Escape)
		handle_close(info);
	return (0);
}

int	hook_close_button(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	handle_close(info);
	return (0);
}

void	render(t_info *info)
{
	// draw_line(info->img, 0, 0, info->win_width - 100, info->win_width - 100);
	// draw_line(info->img, 0, 0, info->win_width + 100, info->win_height + 30);
	draw_line(info->img, -1, -1, 100, 100);
	draw_line(info->img, -1200, -1200, 300, 100);
	draw_line(info->img, 0, 0, info->win_width + 100, info->win_height + 100);

	(void)info;
}

int	hook_render(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (info->win_ptr == NULL)
		return (1);
	render(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img->mlx_img, 0, 0);
	return (0);
}