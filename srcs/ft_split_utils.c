#include "fdf.h"

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

size_t	ft_split_len(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

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
