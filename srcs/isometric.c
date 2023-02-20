#include "fdf.h"

void	isometric_projection(t_map *map)
{
	t_matrices	*matrices;
	t_matrix	*affine_matrix;

	matrices = map_to_matrices(map);
	affine_matrix = matrix_new_unit_matrix(4, 4);
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_rotate_matrix(Z, M_PI_4));
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_rotate_matrix(X, atan(sqrt(2.0))));
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_scale_matrix(10, 10, 10));
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_translate_matrix(100, 100, 0));
	apply_affine_to_matrices(affine_matrix, matrices);
	matrices_to_map(matrices, map);
}
