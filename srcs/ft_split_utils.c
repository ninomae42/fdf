/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:49:00 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 17:07:02 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t	ft_split_str_count(char **split, char *target)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (split[i] != NULL)
	{
		if (ft_strncmp(split[i], target, ft_strlen(target)) == 0)
			cnt++;
		i++;
	}
	return (cnt);
}
