#include "fdf.h"

static t_state	*state_new(void);

t_state	*state_init(void)
{
	t_state	*state;

	state = state_new();
	state->theta_z = M_PI_4;
	state->theta_x = atan(sqrt(2.0));
	return (state);
}

void	state_deallocate(t_state *state)
{
	free(state);
}

static t_state	*state_new(void)
{
	t_state	*state;

	state = (t_state *)ft_malloc(sizeof(t_state));
	ft_memset(state, 0, sizeof(t_state));
	return (state);
}

