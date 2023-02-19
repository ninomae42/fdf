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

// ft_syscall.c
int		open_file_by_name(const char *file_name);
void	*ft_malloc(size_t size);

// ft_split_utils.c
char	**ft_split_safe(char *s, char c);
size_t	ft_split_len(char **split);
void	ft_split_free(char **split);

#endif
