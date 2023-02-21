#include "fdf.h"

static t_matrix	*point_to_matrix(t_point *point);
static void		matrix_to_point(t_matrix *matrix, t_point *point);
static void		matrices_deallocate(t_matrices *matrices);

t_matrices	*map_to_matrices(t_map *map)
{
	t_matrices	*matrices;
	size_t		row_i;
	size_t		col_i;

	matrices = (t_matrices *)ft_malloc(
			sizeof(t_matrices) * map->cols * map->rows);
	matrices->row = map->rows;
	matrices->col = map->cols;
	matrices->data = (t_matrix **)ft_malloc(
			sizeof(t_matrix *) * map->cols * map->rows);
	row_i = 0;
	while (row_i < map->rows)
	{
		col_i = 0;
		while (col_i < map->cols)
		{
			matrices->data[matrices_get_index(matrices, row_i, col_i)]
				= point_to_matrix(
					&map->points[get_map_index(map, row_i, col_i)]);
			col_i++;
		}
		row_i++;
	}
	return (matrices);
}

void	matrices_to_map(t_matrices *matrices, t_map *map)
{
	size_t	row_i;
	size_t	col_i;

	row_i = 0;
	while (row_i < matrices->row)
	{
		col_i = 0;
		while (col_i < matrices->col)
		{
			matrix_to_point(
				matrices->data[matrices_get_index(matrices, row_i, col_i)],
				&map->points[get_map_index(map, row_i, col_i)]);
			col_i++;
		}
		row_i++;
	}
	matrices_deallocate(matrices);
}

static t_matrix	*point_to_matrix(t_point *point)
{
	t_matrix	*matrix;

	matrix = matrix_new(4, 1);
	matrix->data[matrix_get_index(matrix, 0, 0)] = point->x;
	matrix->data[matrix_get_index(matrix, 1, 0)] = point->y;
	matrix->data[matrix_get_index(matrix, 2, 0)] = point->z;
	matrix->data[matrix_get_index(matrix, 3, 0)] = 1;
	return (matrix);
}

static void	matrix_to_point(t_matrix *matrix, t_point *point)
{
	point->x = matrix->data[matrix_get_index(matrix, 0, 0)];
	point->y = matrix->data[matrix_get_index(matrix, 1, 0)];
	point->z = matrix->data[matrix_get_index(matrix, 2, 0)];
	matrix_deallocate(matrix);
}

static void	matrices_deallocate(t_matrices *matrices)
{
	free(matrices->data);
	free(matrices);
}
