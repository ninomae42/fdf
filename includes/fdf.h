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
t_mlx	*init_mlx(t_map *map);
void	deallocate_mlx(t_mlx *mlx);

// ft_split_utils.c
char	**ft_split_safe(char *s, char c);
size_t	ft_split_len(char **split);
void	ft_split_free(char **split);

#endif
