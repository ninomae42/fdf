#include "fdf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	exit (EXIT_SUCCESS);
}

__attribute__((destructor)) static void destructor()
{
    system("leaks -q fdf");
}
