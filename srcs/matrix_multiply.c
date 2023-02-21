/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:50:42 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 02:50:43 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	sum_elements(t_matrix *mat_a, t_matrix *mat_b,
					size_t row_i, size_t col_i);

t_matrix	*matrix_multiply(t_matrix *mat_a, t_matrix *mat_b)
{
	t_matrix	*result;
	size_t		row_i;
	size_t		col_i;

	result = matrix_new(mat_a->row, mat_b->col);
	row_i = 0;
	while (row_i < mat_a->row)
	{
		col_i = 0;
		while (col_i < mat_b->col)
		{
			result->data[matrix_get_index(result, row_i, col_i)]
				= sum_elements(mat_a, mat_b, row_i, col_i);
			col_i++;
		}
		row_i++;
	}
	return (result);
}

static double	sum_elements(
		t_matrix *mat_a, t_matrix *mat_b, size_t row_i, size_t col_i)
{
	double	sum;
	size_t	tmp_i;

	tmp_i = 0;
	sum = 0;
	while (tmp_i < mat_a->col)
	{
		sum += mat_a->data[matrix_get_index(mat_a, row_i, tmp_i)]
			* mat_b->data[matrix_get_index(mat_b, tmp_i, col_i)];
		tmp_i++;
	}
	return (sum);
}
