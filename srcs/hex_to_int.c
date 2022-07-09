#include "../includes/fdf.h"

#define HEX_BASE "0123456789abcdef"
#define BASE_LEN 16

// Convert upper-cased hex value to lower-cased hex value
static char	*convert_to_lower_hex(const char *hex)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup(hex);
	if (ret == NULL)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (ret[i] != '\0')
	{
		ret[i] = ft_tolower(ret[i]);
		i++;
	}
	return (ret);
}

// find the index of 'c' in string 's'
static size_t	index_at(const char *s, char c)
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
static int	is_overflow(int current, char next_char)
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

static int	do_conversion(char *hex_lower, size_t *index, int *is_err)
{
	size_t	i;
	int		ret;

	ret = 0;
	i = *index;
	while (hex_lower[i] != '\0' && ft_strchr(HEX_BASE, hex_lower[i]))
	{
		if (is_overflow(ret, hex_lower[i]))
		{
			*is_err = 1;
			errno = ERANGE;
			return (0);
		}
		ret = ret * BASE_LEN + index_at(HEX_BASE, hex_lower[i]);
		i++;
	}
	*index = i;
	return (ret);
}

// Convert hex string to signed int value.
int	hex_to_int(const char *hex)
{
	int		ret;
	size_t	i;
	char	*hex_lower;
	int		is_err;

	hex_lower = convert_to_lower_hex(hex);
	i = 2;
	is_err = 0;
	ret = do_conversion(hex_lower, &i, &is_err);
	if (is_err == 1 || i != ft_strlen(hex))
	{
		if (errno != ERANGE)
			errno = EINVAL;
		perror("fdf");
		free(hex_lower);
		exit(EXIT_FAILURE);
	}
	free(hex_lower);
	return (ret);
}
