/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:49:43 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 02:49:44 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// find and set the map's width and height from the file.
// on success returns 0, otherwise returns 1.
int	set_map_width_height(const char *file_name, t_map *map)
{
	int		fd;
	char	*row;
	char	**points;

	fd = open_file_by_name(file_name);
	row = get_next_line(fd);
	while (row != NULL)
	{
		points = ft_split_safe(row, ' ');
		free(row);
		if (map->cols == 0)
			map->cols = ft_split_len(points);
		else if (map->cols != ft_split_len(points))
		{
			ft_split_free(points);
			return (1);
		}
		ft_split_free(points);
		row = get_next_line(fd);
		map->rows++;
	}
	close(fd);
	return (0);
}

// find the index of map's point based on current row and col index.
size_t	get_map_index(t_map *map, size_t row_index, size_t col_index)
{
	return (row_index * map->cols + col_index);
}

// print the value stored on t_map struct. (deprecated)
// void	print_map(t_map *map)
// {
// 	size_t	row_index;
// 	size_t	col_index;
// 	size_t	map_index;
// 	t_point	point;
//
// 	row_index = 0;
// 	while (row_index < map->rows)
// 	{
// 		col_index = 0;
// 		while (col_index < map->cols)
// 		{
// 			map_index = get_map_index(map, row_index, col_index);
// 			point = map->points[map_index];
// 			printf("x: %f, y: %f, z: %f, color: %d\n",
// 				point.x, point.y, point.z, point.color);
// 			col_index++;
// 		}
// 		row_index++;
// 	}
// }
