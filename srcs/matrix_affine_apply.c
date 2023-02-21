#include "fdf.h"

void	apply_affine_to_matrices(t_matrix *affine, t_matrices *matrices)
{
	size_t		i;
	size_t		matrices_size;
	t_matrix	*tmp;

	i = 0;
	matrices_size = matrices->col * matrices->row;
	while (i < matrices_size)
	{
		tmp = matrices->data[i];
		matrices->data[i] = matrix_multiply(affine, matrices->data[i]);
		matrix_deallocate(tmp);
		i++;
	}
	matrix_deallocate(affine);
}

t_matrix	*combine_affine_matrix(t_matrix *affine_prev, t_matrix *affine_next)
{
	t_matrix	*res;

	res = matrix_multiply(affine_next, affine_prev);
	matrix_deallocate(affine_next);
	matrix_deallocate(affine_prev);
	return (res);
}
