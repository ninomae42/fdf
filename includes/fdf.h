#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define USAGE "[Usage] ./fdf [map_filename].fdf"
# define ERR_ARGC "[Error] Invalid argument count"
# define ERR_EXTENSION "[Error] Invalid file extension"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	
}	t_map;

typedef struct s_info
{
	t_map	**map;
}	t_info;

// cmdline_arguments.c
bool	is_cmdline_argument_valid(int argc, char **argv);

// utils.c
void	ft_puterr(char *err_msg);
void	*ft_malloc_exit(size_t size);
void	ft_split_free(char **split);
size_t	ft_split_len(char **split);
size_t	ft_split_str_count(char **split, char *target);

#endif