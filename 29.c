#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILENAME "source.txt"

void main()
{
    int id = fork();
    if (id == -1)
    {
        printf("Error while creating a fork.\n");
        return;
    }

    if (id == 0) // child process
    {
        int fd = open(FILENAME, O_RDONLY);
        if (fd == -1)
        {
            printf("The source file does not exist.\n");
            return;
        }

        char buffer;
        printf("The contents of the file are: ");
        while (read(fd, &buffer, 1) != 0)
        {
            printf("%c", buffer);
        }
        printf("\n");
    }
    else // parent process
    {
        printf("getpid: %d\ngetppid: %d\n", getpid(), getppid());
    }
}