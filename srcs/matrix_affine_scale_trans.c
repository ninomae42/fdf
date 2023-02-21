/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_affine_scale_trans.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:50:26 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 02:50:26 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	affine_scale(t_matrix *matrix, double sx, double sy, double sz);
static void	affine_translate(t_matrix *matrix, double tx, double ty, double tz);

t_matrix	*affine_new_scale_matrix(double sx, double sy, double sz)
{
	t_matrix	*matrix;

	matrix = matrix_new_unit_matrix(4, 4);
	affine_scale(matrix, sx, sy, sz);
	return (matrix);
}

t_matrix	*affine_new_translate_matrix(double tx, double ty, double tz)
{
	t_matrix	*matrix;

	matrix = matrix_new_unit_matrix(4, 4);
	affine_translate(matrix, tx, ty, tz);
	return (matrix);
}

static void	affine_scale(t_matrix *matrix, double sx, double sy, double sz)
{
	size_t		row_index;
	size_t		col_index;

	row_index = 0;
	col_index = 0;
	while (row_index < matrix->row)
	{
		if (col_index == 0)
			matrix->data[matrix_get_index(matrix, row_index, col_index)] = sx;
		else if (col_index == 1)
			matrix->data[matrix_get_index(matrix, row_index, col_index)] = sy;
		else if (col_index == 2)
			matrix->data[matrix_get_index(matrix, row_index, col_index)] = sz;
		col_index++;
		row_index++;
	}
}

static void	affine_translate(t_matrix *matrix, double tx, double ty, double tz)
{
	size_t		row_index;
	size_t		col_index;

	row_index = 0;
	col_index = matrix->col - 1;
	while (row_index < matrix->row)
	{
		if (row_index == 0)
			matrix->data[matrix_get_index(matrix, row_index, col_index)] = tx;
		else if (row_index == 1)
			matrix->data[matrix_get_index(matrix, row_index, col_index)] = ty;
		else if (row_index == 2)
			matrix->data[matrix_get_index(matrix, row_index, col_index)] = tz;
		row_index++;
	}
}
