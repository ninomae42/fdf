#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define USAGE "[Usage] ./fdf [map_filename].fdf"
# define ERR_ARGC "[Error] Invalid argument count"
# define ERR_EXTENSION "[Error] Invalid file extension"
# define ERR_MAP "[Error] Invalid map input"
# define ERR_LOAD_MAP "[Error] Error occured while loading map"

# define ERR_MEM "[Error] Unable to allocate memory"

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coordinate;

typedef struct s_map
{
	size_t			width;
	size_t			height;
	t_coordinate	**coordinates;
}	t_map;

typedef struct s_info
{
	t_map	*map;
}	t_info;

// cmdline_arguments.c
bool	is_cmdline_argument_valid(int argc, char **argv);

// map_init.c
void	initialize_map(t_info *info, char *file_name);
void	deallocate_map(t_map *map);

// map_reader.c
void	read_map(char *file_name, t_info *info);

// hex_to_int.c
int		hex_to_int(const char *hex);

// utils.c
void	ft_puterr(char *err_msg);
void	*ft_malloc_exit(size_t size);
int		open_file(const char *file_name);

// split_utils.c
char	**ft_split_or_exit(const char *s, char c);
void	ft_split_free(char **split);
size_t	ft_split_len(char **split);
size_t	ft_split_str_count(char **split, char *target);

#endif