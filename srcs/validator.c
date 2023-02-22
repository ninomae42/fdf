/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:51:21 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 17:09:39 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	is_argc_valid(int argc)
{
	if (argc == 2)
		return (true);
	return (false);
}

static bool	is_file_extension_valid(char *file_name)
{
	char	**split;
	size_t	len;

	split = ft_split_safe(file_name, '.');
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

// validate the commandline arguments
bool	is_command_line_args_valid(int argc, char **argv)
{
	if (!is_argc_valid(argc))
	{
		ft_putendl_fd(ERR_ARGC, STDERR_FILENO);
		return (false);
	}
	if (!is_file_extension_valid(argv[1]))
	{
		ft_putendl_fd(ERR_EXTENSION, STDERR_FILENO);
		return (false);
	}
	return (true);
}
