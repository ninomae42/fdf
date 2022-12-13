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

int	hook_render(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (info->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img->mlx_img, 0, 0);
	return (0);
}