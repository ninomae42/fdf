#include "fdf.h"

// Wrapper function of open.
// When fails to open file,
// then prints the error message and exit with status 1.
int	open_file_by_name(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_fatal(ERR_OPEN);
	}
	return (fd);
}

// Wrapper function of malloc.
// When fails to allocate memory,
// then prints the error message and exit with status 1.
void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
	{
		ft_fatal(ERR_MEM);
	}
	return (ret);
}
