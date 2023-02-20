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

void	state_set_rotate(t_info *info, t_rot_axis axis, double radian)
{
	if (axis == X)
		info->state->theta_x += radian;
	if (axis == Y)
		info->state->theta_y += radian;
	if (axis == Z)
		info->state->theta_z += radian;
}
