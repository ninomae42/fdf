#include "fdf.h"

static void	handle_close(t_info *info);

int	hook_button(int keysym, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (keysym == XK_Escape)
		handle_close(info);
	clear_window(info);
	if (keysym == XK_w)
		state_set_translate(info, 0, -10);
	if (keysym == XK_s)
		state_set_translate(info, 0, 10);
	if (keysym == XK_a)
		state_set_translate(info, -10, 0);
	if (keysym == XK_d)
		state_set_translate(info, 10, 0);

	if (keysym == XK_t)
		state_set_rotate(info, Z, M_PI_2 / 10.0f);
	if (keysym == XK_r)
		state_set_rotate(info, Z, -(M_PI_2 / 10.0f));
	if (keysym == XK_g)
		state_set_rotate(info, Y, M_PI_2 / 10.0f);
	if (keysym == XK_f)
		state_set_rotate(info, Y, -(M_PI_2 / 10.0f));
	if (keysym == XK_b)
		state_set_rotate(info, X, M_PI_2 / 10.0f);
	if (keysym == XK_v)
		state_set_rotate(info, X, -(M_PI_2 / 10.0f));
	if (keysym == XK_x)
		state_set_scale(info, 1.1);
	if (keysym == XK_z)
		state_set_scale(info, -1.1);
	isometric_projection(info);
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
	deallocate_map(info->draw_map);
	state_deallocate(info->state);
	exit(EXIT_SUCCESS);
}

