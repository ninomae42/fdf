#include "fdf.h"

void	ft_fatal(char *err_msg)
{
	perror("fdf");
	ft_putstr_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
