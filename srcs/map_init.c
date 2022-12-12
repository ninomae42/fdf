#include "fdf.h"

static int	get_map_height_and_width(int fd, size_t *height, size_t *width);
static int	get_map_metrics(t_info *info, char *file_name);
static void	allocate_map_coordinates(t_info *info);

void	initialize_map(t_info *info, char *file_name)
{
	info->map = ft_malloc_exit(sizeof(t_map));
	if (get_map_metrics(info, file_name) != 0)
	{
		free(info->map);
		free(info);
		exit(EXIT_FAILURE);
	}
	allocate_map_coordinates(info);
	read_map(file_name, info);
}

static int	get_map_metrics(t_info *info, char *file_name)
{
	int		fd;
	size_t	height;
	size_t	width;

	fd = open_file(file_name);
	height = 0;
	width = 0;
	if (get_map_height_and_width(fd, &height, &width) != 0)
	{
		ft_puterr(ERR_MAP);
		close(fd);
		return (1);
	}
	info->map->height = height;
	info->map->width = width;
	close(fd);
	return (0);
}

static void	allocate_map_coordinates(t_info *info)
{
	size_t	i;

	info->map->coordinates = (t_coordinate **)ft_malloc_exit(
		sizeof(t_coordinate *) * info->map->height);
	i = 0;
	while (i < info->map->height)
	{
		info->map->coordinates[i] = (t_coordinate *)ft_malloc_exit(
			sizeof(t_coordinate) * info->map->width);
		i++;
	}
}

static int	get_map_height_and_width(int fd, size_t *height, size_t *width)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line != NULL)
	{
		split = ft_split_or_exit(line, ' ');
		free(line);
		line = NULL;
		if (*height == 0)
			*width = ft_split_len(split);
		else if (*width != ft_split_len(split))
		{
			ft_split_free(split);
			return (1);
		}
		ft_split_free(split);
		(*height)++;
		line = get_next_line(fd);
	}
	return (0);
}
