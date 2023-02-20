#ifndef FDF_H
# define FDF_H
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"

# define ERR_ARGC "[Error] Invalid argc. argc must be 2"
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
	t_mlx	*mlx;
}	t_info;

// validator.c
bool	is_command_line_args_valid(int argc);

// ft_syscall.c
int		open_file_by_name(const char *file_name);
void	*ft_malloc(size_t size);

// ft_fatal.c
void	ft_fatal(char *err_msg);

// hex_to_int.c
int		hex_to_int(const char *hex);

// map_init.c
t_map	*init_map(char *file_name);
void	deallocate_map(t_map *map);

// map_read.c
void	read_map(const char *file_name, t_map *map);

// map_utils.c
int		set_map_width_height(const char *file_name, t_map *map);
size_t	get_map_index(t_map *map, size_t row_index, size_t col_index);
void	print_map(t_map *map);

// mlx_init.c
void	init_mlx(t_info *info);
void	deallocate_mlx(t_mlx *mlx);

// mlx_hook_events.c
int		hook_button(int keysym, void *param);
int		hook_close_button(void *param);

// mlx_hook_render.c
int		hook_render(void *param);

// draw_line.c
void	draw_line(t_mlx_img *img, t_point p1, t_point p2);
void	clear_window(t_info *info);

// rotate.c
void	rotate_x(t_map *map, double radian);
void	rotate_y(t_map *map, double radian);
void	rotate_z(t_map *map, double radian);

// rotate_point.c
void	rotate_point_xaxis(t_point *point, double radian);
void	rotate_point_yaxis(t_point *point, double radian);
void	rotate_point_zaxis(t_point *point, double radian);

// translate_scale.c
void	translate(t_map *map, double dx, double dy);
void	scale(t_map *map, double scale);

// ft_split_utils.c
char	**ft_split_safe(char *s, char c);
size_t	ft_split_len(char **split);
void	ft_split_free(char **split);

// matrix_init.c
size_t		matrix_get_index(t_matrix *matrix, size_t cur_row, size_t cur_col);
t_matrix	*matrix_new(size_t size_row, size_t size_col);
t_matrix	*matrix_new_unit_matrix(size_t size_row, size_t size_col);
void		matrix_deallocate(t_matrix *matrix);
void		matrix_print(t_matrix *matrix);


// matrix_multiply.c
t_matrix	*matrix_multiply(t_matrix *matrix_a, t_matrix *matrix_b);

// matrix_interface.c
size_t		matrices_get_index(t_matrices *matrices, size_t cur_row, size_t cur_col);
t_matrices	*map_to_matrices(t_map *map);
void		matrices_to_map(t_matrices *matrices, t_map *map);

// matrix_multiply.c
t_matrix	*matrix_multiply(t_matrix *mat_a, t_matrix *mat_b);

#endif
