#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// validator.c
bool	is_command_line_args_valid(int argc);

// file.c
int		open_file(const char *file_name);

// ft_split_utils.c
size_t	ft_split_len(char **split);
void	ft_split_free(char **split);

#endif
