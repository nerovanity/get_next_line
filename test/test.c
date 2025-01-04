#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#include <stdio.h>


int main()
{
	int fd = open("test",O_RDWR , 0777);
	char *str = get_next_line(fd);
	// while (str != NULL)
	// {
	// 	printf("%s", str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// }
	printf("%s", str);
	free(str); 
	str = get_next_line(400);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	// read(fd, buff, 1024);
	// printf("%s", buff);
	// read(fd, buff, BUFFER_SIZE);
}