#include "fdf.h"

static bool	is_argument_count_valid(int argc);
static bool	is_file_extension_valid(char **argv);

bool	is_cmdline_argument_valid(int argc, char **argv)
{
	if (!is_argument_count_valid(argc))
	{
		ft_puterr(ERR_ARGC);
		ft_puterr(USAGE);
		return (false);
	}
	if (!is_file_extension_valid(argv))
	{
		ft_puterr(ERR_EXTENSION);
		ft_puterr(USAGE);
		return (false);
	}
	return (true);
}

static bool	is_argument_count_valid(int argc)
{
	if (argc != 2)
		return (false);
	return (true);
}

static bool	is_file_extension_valid(char **argv)
{
	char	**split;
	size_t	len;

	split = ft_split(argv[1], '.');
	if (split == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	len = ft_split_len(split);
	if (len < 2)
	{
		ft_split_free(split);
		return (false);
	}
	if (ft_split_str_count(split, "fdf") != 1)
	{
		ft_split_free(split);
		return (false);
	}
	ft_split_free(split);
	return (true);
}
