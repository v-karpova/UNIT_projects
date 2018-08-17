
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char 	*line;

// int fd1 = open(argv[1], O_RDONLY);

// while ((get_next_line(fd1, &line) > 0))
// {
// 	printf("%s\n", line);
// 	free(line);
// }
// close(fd1);

	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);

while (1)
{
		if ((get_next_line(fd1, &line) > 0))
	{
		printf("1: %s\n", line);
		free(line);
	}
	
	// // system("leaks --fullStacks --fullContent --hex a.out");
	if ((get_next_line(fd2, &line) > 0))
	{
		printf("2: %s\n", line);
		free(line);
	}
}
	close(fd1);
	close(fd2);
	return (0);
}
