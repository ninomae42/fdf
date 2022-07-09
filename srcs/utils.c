#include "../includes/fdf.h"

// Wrapper function of ft_split.
// If ft_split failes allocation, then exit program with EXIT_FAILURE
char	**ft_split_or_exit(const char *s, char c)
{
	char	**ret;

	ret = ft_split(s, c);
	if (ret == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

// Deallocates the memory allocation created by ft_split.
// If ptr is a NULL pointer, no operation is performed.
void	free_split(char **ptr)
{
	size_t	i;

	if (ptr == NULL)
		return ;
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

// Find the number of sub-string count allocated by ft_split.
size_t	split_len(char **split)
{
	size_t	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}

// Wrapper function of malloc. If allocation is fail,
// then exit with status EXIT_FAILURE
void	*ft_malloc_or_exit(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

// Wrapper function of ft_calloc. If allocation is fail,
// then exit with status EXIT_FAILURE
void	*ft_calloc_or_exit(size_t count, size_t size)
{
	void	*ret;

	ret = ft_calloc(count, size);
	if (ret == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
