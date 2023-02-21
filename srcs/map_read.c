/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:49:37 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 02:49:38 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_row(char *row, t_map *map, size_t cur_row);
static void	read_point(char *point, t_map *map, size_t cur_row, size_t cur_col);

// load map file into memory.
void	read_map(const char *file_name, t_map *map)
{
	int		fd;
	char	*row;
	size_t	row_index;

	fd = open_file_by_name(file_name);
	row = get_next_line(fd);
	row_index = 0;
	while (row != NULL)
	{
		read_row(row, map, row_index);
		free(row);
		row = get_next_line(fd);
		row_index++;
	}
	close(fd);
}

static void	read_row(char *row, t_map *map, size_t cur_row)
{
	char	**row_split;
	size_t	col_index;

	row_split = ft_split_safe(row, ' ');
	col_index = 0;
	while (row_split[col_index])
	{
		read_point(row_split[col_index], map, cur_row, col_index);
		col_index++;
	}
	ft_split_free(row_split);
}

static void	read_point(char *point, t_map *map, size_t cur_row, size_t cur_col)
{
	size_t	index;
	char	**point_split;

	index = get_map_index(map, cur_row, cur_col);
	point_split = ft_split_safe(point, ',');
	if (ft_split_len(point_split) == 2)
		map->points[index].color = hex_to_int(point_split[1]);
	else
		map->points[index].color = -1;
	map->points[index].x = (double)cur_col;
	map->points[index].y = (double)cur_row;
	map->points[index].z = (double)ft_atoi(point_split[0]);
	ft_split_free(point_split);
}
