#include "fdf.h"

void	isometric_projection(t_info *info)
{
	t_matrices	*matrices;
	t_matrix	*affine_matrix;

	matrices = map_to_matrices(info->map);
	affine_matrix = matrix_new_unit_matrix(4, 4);
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_scale_matrix(info->state->scale_x,
				info->state->scale_y, info->state->scale_z * 0.2));
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_rotate_matrix(Y, info->state->theta_y));
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_rotate_matrix(Z, info->state->theta_z));
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_rotate_matrix(X, info->state->theta_x));
	affine_matrix = combine_affine_matrix(affine_matrix,
			affine_new_translate_matrix(info->state->trans_x,
				info->state->trans_y, info->state->trans_z));
	apply_affine_to_matrices(affine_matrix, matrices);
	matrices_to_map(matrices, info->draw_map);
}
