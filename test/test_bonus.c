#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd1,fd2;
	char	buff[BUFFER_SIZE];

	fd1 = open("test",O_RDWR , 0777);
	fd2 = open("test2",O_RDWR , 0777);
	char *str1 = get_next_line(fd1);
	char *str2 = get_next_line(fd2);
	printf("str1 : %s", str1);
	printf("str2 : %s", str2);
	str1 = get_next_line(fd1);
	str2 = get_next_line(fd2);
	printf("str1 : %s", str1);
	printf("str2 : %s", str2);
	str1 = get_next_line(fd1);
	str2 = get_next_line(fd2);
	printf("str1 : %s", str1);
	printf("str2 : %s", str2);
	// read(fd, buff, BUFFER_SIZE);
}