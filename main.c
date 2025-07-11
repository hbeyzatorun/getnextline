#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
  int    fd;
  char  *next_line;
  
  fd = open("example.txt", O_RDONLY);
  while ((next_line = get_next_line(fd)) != NULL)
    {
        printf("%s\n",next_line);
        free (next_line);
    }
  close(fd);
  return (0);
}