#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;

	fd = open("test",O_RDWR , 0777);
	char *str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	// read(fd, buff, 1024);
	// printf("%s", buff);
	// read(fd, buff, BUFFER_SIZE);
}