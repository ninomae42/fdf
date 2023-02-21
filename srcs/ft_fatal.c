#include "fdf.h"

// Prints the error message based on perror and
// prints the user defined error message.
// Then exit with EXIT_FAILURE.
void	ft_fatal(char *err_msg)
{
	perror("fdf");
	ft_putstr_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
