#include "../includes/fdf.h"

// validate command line argument
void	validate_argument(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fdf [map_name].fdf", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) == NULL)
	{
		ft_putendl_fd("Unsupporeted file type (*.fdf)", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

// Opens a file by its filename for reading only.
int	open_file_by_name(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
