#include "fdf.h"

static t_state	*state_new(void);

t_state	*state_init(void)
{
	t_state	*state;

	state = state_new();
	return (state);
}

void	state_deallocate(t_state *state)
{
	free(state);
}

void	state_set_initial(t_info *info)
{
	t_state	*state;
	double	scale;

	state = info->state;
	state->theta_x = atan(sqrt(2.0));
	state->theta_y = 0;
	state->theta_z = M_PI_4;
	scale = calculate_scale(info);
	state->scale_x = scale;
	state->scale_y = scale;
	state->scale_z = scale;
	state->trans_x = info->mlx->width / 2.0;
	state->trans_y = info->mlx->height / 4.0;
	state->trans_z = 0;
}

static t_state	*state_new(void)
{
	t_state	*state;

	state = (t_state *)ft_malloc(sizeof(t_state));
	ft_memset(state, 0, sizeof(t_state));
	return (state);
}
