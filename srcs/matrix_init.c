#include "fdf.h"

t_matrix	*matrix_new(size_t size_row, size_t size_col)
{
	t_matrix	*matrix;

	matrix = (t_matrix *)ft_malloc(sizeof(t_matrix));
	ft_memset(matrix, 0, sizeof(t_matrix));
	matrix->row = size_row;
	matrix->col = size_col;
	matrix->data = (double *)ft_malloc(sizeof(double) * (size_row * size_col));
	ft_memset(matrix->data, 0, sizeof(double) * (size_row * size_col));
	return (matrix);
}

t_matrix	*matrix_new_unit_matrix(size_t size_row, size_t size_col)
{	size_t		row_index;
	size_t		col_index;
	t_matrix	*matrix;

	matrix = matrix_new(size_row, size_col);
	row_index = 0; col_index = 0;
	while (row_index < size_row)
	{
		matrix->data[matrix_get_index(matrix, row_index, col_index)] = 1;
		col_index++;
		row_index++;
	}
	return (matrix);
}

size_t	matrix_get_index(t_matrix *matrix, size_t cur_row, size_t cur_col)
{
	if (matrix->row <= cur_row || matrix->col <= cur_col)
		ft_fatal("matrix index out of range");
	return (matrix->col * cur_row + cur_col);
}

void	matrix_deallocate(t_matrix *matrix)
{
	free(matrix->data);
	free(matrix);
}

void	matrix_print(t_matrix *matrix)
{
	size_t	row_index;
	size_t	col_index;

	row_index = 0;
	while (row_index < matrix->row)
	{
		col_index = 0;
		while (col_index < matrix->col)
		{
			printf("%f ", matrix->data[matrix_get_index(matrix, row_index, col_index)]);
			col_index++;
		}
		puts("");
		row_index++;
	}
}
