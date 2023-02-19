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

// validator.c
bool	is_command_line_args_valid(int argc);

// ft_syscall.c
int		open_file_by_name(const char *file_name);
void	*ft_malloc(size_t size);

// hex_to_int.c
int		hex_to_int(const char *hex);

// map_read.c
void	read_map(const char *file_name, t_map *map);

// map_utils.c
int		set_map_width_height(const char *file_name, t_map *map);
size_t	get_map_index(t_map *map, size_t row_index, size_t col_index);
void	print_map(t_map *map);

// ft_split_utils.c
char	**ft_split_safe(char *s, char c);
size_t	ft_split_len(char **split);
void	ft_split_free(char **split);

#endif
