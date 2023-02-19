#include "fdf.h"

int	open_file(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("[Error]: Unable to open file", STDERR_FILENO);
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
