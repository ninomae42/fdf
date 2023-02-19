#include "fdf.h"

static void	init_mlx_image(t_mlx *mlx);

void	register_mlx_hooks(t_mlx *mlx, t_map *map)
{
	(void)mlx;
	(void)map;
	// TODO: register hooks (render, keypress, mouse) to display isometric map properly.
}

t_mlx	*init_mlx(t_map *map)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		ft_fatal(ERR_MLX_INIT);
	mlx->width = DEFAULT_WIN_WIDTH;
	mlx->height = DEFAULT_WIN_HEIGHT;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "fdf");
	if (mlx->mlx_ptr == NULL)
		ft_fatal(ERR_MLX_WINDOW);
	init_mlx_image(mlx);
	register_mlx_hooks(mlx, map);
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
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
