#include "fdf.h"

int	main(int argc, char **argv)
{
	if (!is_cmdline_argument_valid(argc, argv))
		exit(EXIT_FAILURE);
	printf("usage and file extension is valid\n");
	exit (EXIT_SUCCESS);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fdf");
// }
