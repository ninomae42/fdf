/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:49:37 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 17:38:36 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	read_row(char *row, t_map *map, size_t cur_row);
static int	read_point(char *point, t_map *map, size_t cur_row, size_t cur_col);
static int	set_color(char **point_split, t_map *map, size_t index);

// load map file into memory.
// If no map error detected then returns 0, otherwise returns 1
int	read_map(const char *file_name, t_map *map)
{
	int		fd;
	char	*row;
	size_t	row_index;
	bool	is_err;

	fd = open_file_by_name(file_name);
	row = get_next_line(fd);
	row_index = 0;
	is_err = false;
	while (row != NULL)
	{
		if (read_row(row, map, row_index) != 0)
			is_err = true;
		free(row);
		row = get_next_line(fd);
		row_index++;
	}
	close(fd);
	if (is_err)
		return (1);
	return (0);
}

static int	read_row(char *row, t_map *map, size_t cur_row)
{
	char	**row_split;
	size_t	col_index;

	row_split = ft_split_safe(row, ' ');
	col_index = 0;
	while (row_split[col_index])
	{
		if (read_point(row_split[col_index], map, cur_row, col_index) != 0)
		{
			ft_split_free(row_split);
			return (1);
		}
		col_index++;
	}
	ft_split_free(row_split);
	return (0);
}

static int	read_point(char *point, t_map *map, size_t cur_row, size_t cur_col)
{
	size_t	index;
	char	**point_split;

	index = get_map_index(map, cur_row, cur_col);
	point_split = ft_split_safe(point, ',');
	if (set_color(point_split, map, index) != 0)
	{
		ft_split_free(point_split);
		return (1);
	}
	map->points[index].x = (double)cur_col;
	map->points[index].y = (double)cur_row;
	errno = 0;
	map->points[index].z = (double)ft_atoi(point_split[0]);
	if (errno != 0)
	{
		ft_perror(ERR_RANGE);
		ft_split_free(point_split);
		return (1);
	}
	ft_split_free(point_split);
	return (0);
}

static int	set_color(char **point_split, t_map *map, size_t index)
{
	if (ft_split_len(point_split) == 2)
	{
		errno = 0;
		map->points[index].color = hex_to_int(point_split[1]);
		if (errno != 0)
		{
			ft_perror(ERR_RANGE);
			return (1);
		}
	}
	else
		map->points[index].color = -1;
	return (0);
}
