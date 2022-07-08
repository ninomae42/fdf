#include "../includes/fdf.h"
#include <stdio.h>
#include <errno.h>
#include <limits.h>

#define HEX_BASE "0123456789abcdef"
#define BASE_LEN 16

// Convert upper-cased hex value to lower-cased hex value
char	*convert_to_lower_hex(const char *hex)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup(hex);
	if (ret == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (ret[i] != '\0')
	{
		ret[i] = ft_tolower(ret[i]);
		i++;
	}
	return (ret);
}

// find the index of 'c' in string 's'
size_t	index_at(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

// Overflow detection.
int	is_overflow(int current, char next_char)
{
	int	next_digit;

	next_digit = index_at(HEX_BASE, next_char);
	if (INT_MAX / BASE_LEN < next_digit)
		return (1);
	current = current * BASE_LEN;
	if ((INT_MAX - current) < next_digit)
		return (1);
	return (0);
}

// Convert hex string to signed int value.
int	hex_to_int(const char *hex)
{
	int		ret;
	size_t	i;
	char	*hex_lower;

	ret = 0;
	i = 0;
	hex_lower = convert_to_lower_hex(hex);
	i += 2;
	while (hex_lower[i] != '\0' && ft_strchr(HEX_BASE, hex_lower[i]))
	{
		if (is_overflow(ret, hex_lower[i]))
		{
			errno = ERANGE;
			return (0);
		}
		ret = ret * BASE_LEN + index_at(HEX_BASE, hex_lower[i]);
		i++;
	}
	if (i != ft_strlen(hex))
	{
		errno = EINVAL;
		return (0);
	}
	return (ret);
}
