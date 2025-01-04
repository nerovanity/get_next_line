#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#include <stdio.h>


int main()
{
	int fd;

	FILE *file = fopen("output.txt", "wb");  // Open file in binary write mode
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char null_char = '\0';  // Null character
    fwrite(&null_char, sizeof(char), 1, file);  // Write it to the file

    fclose(file);
    return 0;
	fd = open("output.txt",O_RDWR , 0777);
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