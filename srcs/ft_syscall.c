#include "fdf.h"

int	open_file_by_name(const char *file_name)
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

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
	{
		perror("fdf");
		ft_putendl_fd("[Error]: Unable to allocate memory", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (ret);
}
