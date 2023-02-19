#include "fdf.h"

static void	handle_close(t_info *info);

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

static void	handle_close(t_info *info)
{
	mlx_loop_end(info->mlx->mlx_ptr);
	deallocate_mlx(info->mlx);
	deallocate_map(info->map);
	exit(EXIT_SUCCESS);
}

