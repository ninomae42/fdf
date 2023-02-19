#include "fdf.h"

static bool	is_argc_valid(int argc)
{
	if (argc == 2)
		return (true);
	return (false);
}

// validate the commandline arguments
bool	is_command_line_args_valid(int argc)
{
	if (!is_argc_valid(argc))
	{
		ft_putendl_fd("[Error]: invalid argc", STDERR_FILENO);
		return (false);
	}
	return (true);
}
