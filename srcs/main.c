#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	int	fd;

	validate_argument(argc, argv);
	fd = open_file_by_name(argv[1]);
	close(fd);
}

//__attribute__((destructor)) static void destructor()
//{
//    system("leaks -q a.out");
//}
