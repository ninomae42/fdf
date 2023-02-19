#include "fdf.h"

static void	init_mlx_image(t_mlx *mlx);

void	register_mlx_hooks(t_info *info)
{
	// TODO: register hooks (render, keypress, mouse) to display isometric map properly.
	mlx_hook(info->mlx->win_ptr, KeyPress, KeyPressMask, &hook_button, info);
	mlx_hook(info->mlx->win_ptr, DestroyNotify, StructureNotifyMask, &hook_close_button, info);
}

void	init_mlx(t_info *info)
{
	info->mlx = (t_mlx *)ft_malloc(sizeof(t_mlx));
	info->mlx->mlx_ptr = mlx_init();
	if (info->mlx->mlx_ptr == NULL)
		ft_fatal(ERR_MLX_INIT);
	info->mlx->width = DEFAULT_WIN_WIDTH;
	info->mlx->height = DEFAULT_WIN_HEIGHT;
	info->mlx->win_ptr = mlx_new_window(
			info->mlx->mlx_ptr, info->mlx->width, info->mlx->height, "fdf");
	if (info->mlx->mlx_ptr == NULL)
		ft_fatal(ERR_MLX_WINDOW);
	init_mlx_image(info->mlx);
	register_mlx_hooks(info);
	mlx_loop(info->mlx->mlx_ptr);
}

void	deallocate_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->mlx_img);
	free(mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx);
}

static void	init_mlx_image(t_mlx *mlx)
{
	t_mlx_img	*img;

	img = (t_mlx_img *)ft_malloc(sizeof(t_mlx_img));
	img->mlx_img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	img->width = mlx->width;
	img->height = mlx->height;
	mlx->img = img;
}
