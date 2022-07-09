#include "../includes/fdf.h"

static char	*remove_return(const char *row)
{
	char	*ret;

	ret = ft_strtrim(row, "\n\r\f");
	if (ret == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

static void	parse_map_row(const char *row, t_point **map, size_t col_index)
{
	size_t	i;
	char	*cleaned_row;
	char	**row_split;
	char	**point_split;

	cleaned_row = remove_return(row);
	row_split = ft_split_or_exit(cleaned_row, ' ');
	free(cleaned_row);
	i = 0;
	while (row_split[i] != NULL)
	{
		point_split = ft_split_or_exit(row_split[i], ',');
		if (1 < split_len(point_split))
			map[col_index][i].color = hex_to_int(*(point_split + 1));
		map[col_index][i].z = (double)ft_atoi(*point_split);
		map[col_index][i].x = (double)i;
		map[col_index][i].y = (double)col_index;
		free_split(point_split);
		i++;
	}
	free_split(row_split);
}

void	load_map(char *file_name, t_map *map_info)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open_file_by_name(file_name);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		parse_map_row(line, map_info->map, i);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (i != map_info->height)
	{
		ft_putendl_fd("fdf: Error occured while loading map.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	print_points(t_map *map_info)
{
	t_point	**map;
	size_t	i;
	size_t	j;

	map = map_info->map;
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			printf("i: %zu, j: %zu, x: %f, y: %f, z: %f, color: %d\n",
				i, j, map[i][j].x, map[i][j].y, map[i][j].z, map[i][j].color);
			j++;
		}
		i++;
	}
}
