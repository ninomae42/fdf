/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:47:40 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 15:44:18 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"

# define ERR_ARGC "[Error] Invalid argc. argc must be 2"
# define ERR_MAP "[Error] Empty map or column number not same"
# define ERR_RANGE "[Error] Some map argument overflow"
# define ERR_MEM "[Error] Unable to allocate memory"
# define ERR_OPEN "[Error] Unable to open file"
# define ERR_MLX_INIT "[Error] Unable to initialize minilibx"
# define ERR_MLX_WINDOW "[Error] Unable to create minilibx window"

# define DEFAULT_WIN_WIDTH 960
# define DEFAULT_WIN_HEIGHT 540

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_map
{
	size_t	rows;
	size_t	cols;
	t_point	*points;
}	t_map;

typedef struct s_plot
{
	int		dx;
	int		dy;
	int		steps;
	double	x_inc;
	double	y_inc;
	int		start_color;
	int		end_color;
}	t_plot;

typedef struct s_matrix
{
	size_t	row;
	size_t	col;
	double	*data;
}	t_matrix;

typedef struct s_matrices
{
	size_t		row;
	size_t		col;
	t_matrix	**data;
}	t_matrices;

typedef enum e_rotate_axis
{
	X = 0,
	Y = 1,
	Z = 2,
}	t_rot_axis;

typedef struct s_state
{
	double	trans_x;
	double	trans_y;
	double	trans_z;
	double	scale_x;
	double	scale_y;
	double	scale_z;
	double	theta_x;
	double	theta_y;
	double	theta_z;
}	t_state;

typedef struct s_minilibx_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_mlx_img;

typedef struct s_minilibx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_mlx_img	*img;
}	t_mlx;

typedef struct s_global_info
{
	t_map	*map;
	t_map	*draw_map;
	t_state	*state;
	t_mlx	*mlx;
}	t_info;

// validator.c
bool		is_command_line_args_valid(int argc);

// ft_syscall.c
int			open_file_by_name(const char *file_name);
void		*ft_malloc(size_t size);

// ft_fatal.c
void		ft_fatal(char *err_msg);
void		ft_perror(char *err_msg);

// hex_to_int.c
int			hex_to_int(const char *hex);

// map_init.c
t_map		*init_map(char *file_name);
t_map		*copy_map(t_map *map);
void		deallocate_map(t_map *map);

// map_read.c
void		read_map(const char *file_name, t_map *map);

// map_utils.c
int			set_map_width_height(const char *file_name, t_map *map);
size_t		get_map_index(t_map *map, size_t row_index, size_t col_index);
void		print_map(t_map *map);

// state_init.c
t_state		*state_init(void);
void		state_deallocate(t_state *state);

// state_mutate.c
void		state_set_initial(t_info *info);
void		state_set_translate(t_info *info, double tx, double ty);
void		state_set_scale(t_info *info, double scale);
void		state_set_scale_axis(t_info *info, t_rot_axis axis, double scale);
void		state_set_rotate(t_info *info, t_rot_axis axis, double radian);

// mlx_init.c
void		init_mlx(t_info *info);
void		deallocate_mlx(t_mlx *mlx);

// mlx_hook_events.c
int			hook_button(int keysym, void *param);
int			hook_close_button(void *param);

// mlx_hook_keymap.c
void		set_keymap_translate(int keysym, t_info *info);
void		set_keymap_rotate(int keysym, t_info *info);
void		set_keymap_scale(int keysym, t_info *info);
void		set_keymap_zoom(int keysym, t_info *info);

// mlx_hook_render.c
int			hook_render(void *param);

// draw_line.c
void		draw_line(t_mlx_img *img, t_point p1, t_point p2);
void		clear_window(t_info *info);

// draw_color.c
int			get_gradation_color(
				int start, int end, double steps, double current);

// draw_scale.c
double		calculate_scale(t_info *info);

// ft_split_utils.c
char		**ft_split_safe(char *s, char c);
size_t		ft_split_len(char **split);
void		ft_split_free(char **split);

// matrix_init.c
size_t		matrix_get_index(t_matrix *matrix, size_t cur_row, size_t cur_col);
t_matrix	*matrix_new(size_t size_row, size_t size_col);
t_matrix	*matrix_new_unit_matrix(size_t size_row, size_t size_col);
void		matrix_deallocate(t_matrix *matrix);
void		matrix_print(t_matrix *matrix);
size_t		matrices_get_index(
				t_matrices *matrices, size_t cur_row, size_t cur_col);

// matrix_affine_scale_trans.c
t_matrix	*affine_new_scale_matrix(double sx, double sy, double sz);
t_matrix	*affine_new_translate_matrix(double tx, double ty, double tz);

// matrix_affine_rotate.c
t_matrix	*affine_new_rotate_matrix(t_rot_axis axis, double radian);

// matrix_multiply.c
t_matrix	*matrix_multiply(t_matrix *matrix_a, t_matrix *matrix_b);

// matrix_interface.c
t_matrices	*map_to_matrices(t_map *map);
void		matrices_to_map(t_matrices *matrices, t_map *map);

// matrix_multiply.c
t_matrix	*matrix_multiply(t_matrix *mat_a, t_matrix *mat_b);

// matrix_affine_apply.c
void		apply_affine_to_matrices(t_matrix *affine, t_matrices *matrices);
t_matrix	*combine_affine_matrix(
				t_matrix *affine_prev, t_matrix *affine_next);

// isometric.c
void		isometric_projection(t_info *info);

#endif
