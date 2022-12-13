#include "fdf.h"

static void	init_mlx_img(t_info *info);
static void	register_hooks(t_info *info);

void	init_mlx(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (info->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	mlx_get_screen_size(info->mlx_ptr, &info->win_width, &info->win_height);
	info->win_height = info->win_height / 3;
	info->win_width = info->win_width / 4;
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			info->win_width, info->win_height, "fdf");
	if (info->win_ptr == NULL)
		exit(EXIT_FAILURE);
	init_mlx_img(info);
	register_hooks(info);
	mlx_loop(info->mlx_ptr);
}

void	deallocate_mlx(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->img->mlx_img);
	free(info->img);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	info->win_ptr = NULL;
	mlx_destroy_display(info->mlx_ptr);
	free(info->mlx_ptr);
}

static void	init_mlx_img(t_info *info)
{
	info->img = (t_img *)ft_malloc_exit(sizeof(t_img));
	info->img->mlx_img = mlx_new_image(info->mlx_ptr, info->win_width, info->win_height);
	info->img->addr = mlx_get_data_addr(info->img->mlx_img, &info->img->bpp, &info->img->line_len, &info->img->endian);
}

static void	register_hooks(t_info *info)
{
	mlx_hook(info->win_ptr, KeyPress, KeyPressMask, &hook_button, info);
	mlx_hook(info->win_ptr, DestroyNotify, StructureNotifyMask, &hook_close_button, info);
	mlx_loop_hook(info->mlx_ptr, &hook_render, info);
}
