#include "fdf.h"

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
