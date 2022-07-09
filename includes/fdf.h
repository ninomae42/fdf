#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

// init.c
void	validate_argument(int argc, char *argv[]);
int		open_file_by_name(const char *file_name);

// utils.c
char	**ft_split_or_exit(const char *s, char c);
void	free_split(char **ptr);
size_t	split_len(char **split);

// hex_to_int.c
int		hex_to_int(const char *hex);

#endif
