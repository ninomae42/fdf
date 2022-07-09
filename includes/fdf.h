#ifndef FDF_H
# define FDF_H
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

// constants for minilibx
# define KEY_PRESS 2
# define ESC_KEY 65307
# define DESTROY_NOTIFY 17

// type for point
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

// type for map
typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_point	**map;
}	t_map;

// type for mlx info struct
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

// init.c
void	validate_argument(int argc, char *argv[]);
int		open_file_by_name(const char *file_name);
t_map	*init(int argc, char *argv[]);

// map_utils.c
t_map	*init_map_info(char *file_name);

// map_loader.c
void	load_map(char *file_name, t_map *map_info);
void	print_points(t_map *map_info);

// utils.c
char	**ft_split_or_exit(const char *s, char c);
void	free_split(char **ptr);
size_t	split_len(char **split);

// window_utils.c
int		close_window_with_esc(int keycode, t_mlx *mlx);
int		close_window_with_button(t_mlx *mlx);

// hex_to_int.c
int		hex_to_int(const char *hex);

#endif
