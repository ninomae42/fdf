#include "fdf.h"

void	state_set_translate(t_info *info, double tx, double ty)
{
	info->state->trans_x += tx;
	info->state->trans_y += ty;
}

void	state_set_scale(t_info *info, double scale)
{
	info->state->scale_x += scale;
	info->state->scale_y += scale;
	info->state->scale_z += scale;
}

void	state_set_scale_axis(t_info *info, t_rot_axis axis, double scale)
{
	if (axis == X)
		info->state->scale_x += scale;
	else if (axis == Y)
		info->state->scale_y += scale;
	else if (axis == Z)
		info->state->scale_z += scale;
}

void	state_set_rotate(t_info *info, t_rot_axis axis, double radian)
{
	if (axis == X)
		info->state->theta_x += radian;
	else if (axis == Y)
		info->state->theta_y += radian;
	else if (axis == Z)
		info->state->theta_z += radian;
}

void	state_set_initial(t_info *info)
{
	t_state	*state;

	state = info->state;
	state->theta_x = atan(sqrt(2.0));
	state->theta_y = 0;
	state->theta_z = M_PI_4;
	state->scale_x = 2;
	state->scale_y = 2;
	state->scale_z = 2;
	state->trans_x = 100;
	state->trans_y = 100;
	state->trans_z = 100;
}
