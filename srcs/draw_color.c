#include "fdf.h"

static uint8_t	get_r(int color)
{
	return (color >> 16);
}

static uint8_t	get_g(int color)
{
	return (color >> 8 & 0xff);
}

static uint8_t	get_b(int color)
{
	return (color & 0xff);
}

static int	encode_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16 | g << 8 | b);
}

int	get_gradation_color(int start, int end, double steps, double current)
{
	uint8_t	rgb[3];

	rgb[0] = get_r(start) + (get_r(end) - get_r(start)) / steps * current;
	rgb[1] = get_g(start) + (get_g(end) - get_g(start)) / steps * current;
	rgb[2] = get_b(start) + (get_b(end) - get_b(start)) / steps * current;
	return (encode_rgb(rgb[0], rgb[1], rgb[2]));
}
