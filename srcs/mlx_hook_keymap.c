#include "fdf.h"

void	set_keymap_translate(int keysym, t_info *info)
{
	if (keysym == XK_w)
		state_set_translate(info, 0, -10);
	else if (keysym == XK_s)
		state_set_translate(info, 0, 10);
	else if (keysym == XK_a)
		state_set_translate(info, -10, 0);
	else if (keysym == XK_d)
		state_set_translate(info, 10, 0);
}

void	set_keymap_rotate(int keysym, t_info *info)
{
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
}

void	set_keymap_scale(int keysym, t_info *info)
{
	if (keysym == XK_u)
		state_set_scale_axis(info, Z, 1.5);
	if (keysym == XK_y)
		state_set_scale_axis(info, Z, -1.5);
	if (keysym == XK_j)
		state_set_scale_axis(info, Y, 1.05);
	if (keysym == XK_h)
		state_set_scale_axis(info, Y, -1.05);
	if (keysym == XK_m)
		state_set_scale_axis(info, X, 1.05);
	if (keysym == XK_n)
		state_set_scale_axis(info, X, -1.05);
}

void	set_keymap_zoom(int keysym, t_info *info)
{
	if (keysym == XK_x)
		state_set_scale(info, 1.05);
	if (keysym == XK_z)
		state_set_scale(info, -1.05);
}
