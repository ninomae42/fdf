#include "fdf.h"

// TODO: check the pointer is null or not
char	**ft_split_or_exit(const char *s, char c)
{
	char	**ret;

	ret = ft_split(s, c);
	if (ret == NULL)
	{
		ft_puterr(ERR_MEM);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

void	ft_split_free(char **split)
{
	size_t	len;

	len = 0;
	while (split[len] != NULL)
	{
		free(split[len]);
		len++;
	}
	free(split);
}

size_t	ft_split_len(char **split)
{
	size_t	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}

size_t	ft_split_str_count(char **split, char *target)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (split[i] != NULL)
	{
		if (ft_strncmp(split[i], target, ft_strlen(split[i])) == 0)
			cnt++;
		i++;
	}
	return (cnt);
}