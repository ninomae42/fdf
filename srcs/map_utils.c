#include "../includes/fdf.h"

// find map width.
static size_t	get_map_width(char **split)
{
	return (split_len(split));
}

// set map width and height with passed arguments.
static void	set_map_height_and_width(int fd, size_t *width, size_t *height)
{
	char	*line;
	char	**line_split;

	line = get_next_line(fd);
	*height = 0;
	while (line != NULL)
	{
		line_split = ft_split_or_exit(line, ' ');
		free(line);
		if (*height == 0)
			*width = get_map_width(line_split);
		else if (*width != get_map_width(line_split))
		{
			free_split(line_split);
			ft_putendl_fd("Map Error", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		free_split(line_split);
		*height = *height + 1;
		line = get_next_line(fd);
	}
}

static void	allocate_map(t_map *map_info)
{
	t_point	**map;
	size_t	i;

	map = (t_point **)ft_calloc(map_info->height, sizeof(t_point *));
	if (map == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map_info->height)
	{
		map[i] = (t_point *)ft_calloc(map_info->width, sizeof(t_point));
		if (map[i] == NULL)
		{
			perror("fdf");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map_info->map = map;
}

// Allocate new t_map struct and set map width and height.
t_map	*init_map_info(char *file_name)
{
	t_map	*map_info;
	int		fd;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (map_info == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	fd = open_file_by_name(file_name);
	set_map_height_and_width(fd, &(map_info->width), &(map_info->height));
	allocate_map(map_info);
	close(fd);
	return (map_info);
}
