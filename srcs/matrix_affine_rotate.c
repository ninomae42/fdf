#include "fdf.h"

static void	affine_rotate_xaxis(t_matrix *matrix, double radian);
static void	affine_rotate_yaxis(t_matrix *matrix, double radian);
static void	affine_rotate_zaxis(t_matrix *matrix, double radian);

t_matrix	*affine_new_rotate_matrix(t_rot_axis axis, double radian)
{
	t_matrix	*matrix;

	matrix = matrix_new_unit_matrix(4, 4);
	if (axis == X)
		affine_rotate_xaxis(matrix, radian);
	else if (axis == Y)
		affine_rotate_yaxis(matrix, radian);
	else if (axis == Z)
		affine_rotate_zaxis(matrix, radian);
	else
	{
	 	matrix_deallocate(matrix);
		return (NULL);
	}
	return (matrix);
}

static void	affine_rotate_xaxis(t_matrix *matrix, double radian)
{
	matrix->data[matrix_get_index(matrix, 1, 1)] = cos(radian);
	matrix->data[matrix_get_index(matrix, 1, 2)] = -sin(radian);
	matrix->data[matrix_get_index(matrix, 2, 1)] = sin(radian);
	matrix->data[matrix_get_index(matrix, 2, 2)] = cos(radian);
}

static void	affine_rotate_yaxis(t_matrix *matrix, double radian)
{
	matrix->data[matrix_get_index(matrix, 0, 0)] = cos(radian);
	matrix->data[matrix_get_index(matrix, 0, 2)] = sin(radian);
	matrix->data[matrix_get_index(matrix, 2, 0)] = -sin(radian);
	matrix->data[matrix_get_index(matrix, 2, 2)] = cos(radian);
}

static void	affine_rotate_zaxis(t_matrix *matrix, double radian)
{
	matrix->data[matrix_get_index(matrix, 0, 0)] = cos(radian);
	matrix->data[matrix_get_index(matrix, 0, 1)] = -sin(radian);
	matrix->data[matrix_get_index(matrix, 1, 0)] = sin(radian);
	matrix->data[matrix_get_index(matrix, 1, 1)] = cos(radian);
}
