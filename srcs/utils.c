#include "fdf.h"

// TODO: check the pointer is null or not
void	ft_puterr(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
}

void	*ft_malloc_exit(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

int	open_file(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("fdf");
		ft_puterr(USAGE);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
