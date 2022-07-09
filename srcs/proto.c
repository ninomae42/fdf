#include "../includes/fdf.h"

void	inits(void)
{
	t_data	var;
	t_img	img;
	t_point	p1;
	t_point	p2;
	t_point	p3;

	var.mlx = mlx_init();
	mlx_get_screen_size(var.mlx, &(var.sizex), &(var.sizey));
	var.win = mlx_new_window(var.mlx, var.sizex / 3, 2 * var.sizey / 3, "fdf");
	printf("window size: x: %d, y: %d\n", var.sizex / 3, var.sizey * 2 / 3);
	mlx_hook(var.win, 2, 1L << 0, close, &var);
	mlx_hook(var.win, 17, 0L, quit, &var);
	img.img = mlx_new_image(var.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("bits_per_pixel: %d, line_length: %d, endian: %d\n", img.bits_per_pixel, img.line_length, img.endian);

	p1.x = 100;
	p1.y = 100;
	p2.x = 100;
	p2.y = 200;
	p3.x = 700;
	p3.y = 300;
	draw_line(&img, &p1, &p2);
	draw_line(&img, &p2, &p3);
	draw_line(&img, &p3, &p1);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
}

void	draw_grid(void)
{
	t_data	var;
	t_img	img;
	t_point	p1;
	double	w;
	double	h;

	var.mlx = mlx_init();
	mlx_get_screen_size(var.mlx, &(var.sizex), &(var.sizey));
	var.win = mlx_new_window(var.mlx, var.sizex / 3, 2 * var.sizey / 3, "fdf");
	printf("window size: x: %d, y: %d\n", var.sizex / 3, var.sizey * 2 / 3);
	mlx_hook(var.win, 2, 1L << 0, close, &var);
	mlx_hook(var.win, 17, 0L, quit, &var);
	img.img = mlx_new_image(var.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("bits_per_pixel: %d, line_length: %d, endian: %d\n", img.bits_per_pixel, img.line_length, img.endian);

	p1.x = 100;
	p1.y = 100;
	w = h = 40;
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);

}
