#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    int fd2;
    int fd3;
    char *line;

    fd = open("test.txt",O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    fd3 = open("test3.txt", O_RDONLY);

    // if (fd == -1 || fd2 == -1 || fd3 == -1)
    // {
    //     printf("err");
    //     return (1);
    // }

    line = "";
    while (line)
    {
        line = get_next_line(fd);
        if (line)
            printf("fd = %s", line);
        free (line);
    }
    printf("\n\n");

    line = "";
    while (line)
    {
        line = get_next_line(fd2);
        if (line)
            printf("fd2 = %s", line);
        free (line);
    }
    printf("\n\n");

    line = "";
    while (line)
    {
        line = get_next_line(fd3);
        if (line)
            printf("fd3 = %s", line);
        free (line);
    }
    printf("\n\n");

    close(fd);
    close(fd2);
    close(fd3);

    return (0);

}