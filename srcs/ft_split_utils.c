#include "fdf.h"

// Wrapper function of ft_split.
// When allocation fails then print error message and exit with status 1.
char	**ft_split_safe(char *s, char c)
{
	char	**ret;

	ret = ft_split(s, c);
	if (ret == NULL)
	{
		ft_fatal(ERR_MEM);
	}
	return (ret);
}

// find the length of array allocated by ft_split.
size_t	ft_split_len(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

// free resources allocated by ft_split.
void	ft_split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
