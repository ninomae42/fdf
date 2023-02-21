#include "fdf.h"

static void	handle_close(t_info *info);

int	hook_button(int keysym, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (keysym == XK_Escape)
		handle_close(info);
	if (keysym == XK_i)
		state_set_initial(info);
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
		set_keymap_translate(keysym, info);
	if (keysym == XK_t || keysym == XK_r || keysym == XK_g || keysym == XK_f
			|| keysym == XK_b || keysym == XK_v)
		set_keymap_rotate(keysym, info);
	if (keysym == XK_u || keysym == XK_y || keysym == XK_j || keysym == XK_h
			|| keysym == XK_m || keysym == XK_n)
		set_keymap_scale(keysym, info);
	if (keysym == XK_x || keysym == XK_z)
		set_keymap_zoom(keysym, info);
	clear_window(info);
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

