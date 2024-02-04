#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILENAME "file.dat"

void main()
{
    int fd = open(FILENAME, O_RDWR);

    if (fd == -1)
    {
        creat(FILENAME, 0777);
        fd = open(FILENAME, O_RDWR);
    }

    char buffer[20] = "Alpha Bravo";
    char buffer2[20];
    if (write(fd, buffer, 12) == -1)
    {
        printf("Error while writing to file.\n");
        return;
    }
    printf("%s written to file.\n", buffer);

    lseek(fd, 0, SEEK_SET);

    if (read(fd, buffer2, 12) == -1)
    {
        printf("Error while reading from the file.\n");
        return;
    }
    printf("%s read from the file.\n", buffer2);

    printf("Press enter to continue...");
    while (getchar() != '\n')
        ;

    if (link(FILENAME, "./newfile.dat") == -1)
    {
        printf("An error occured while trying to create a link.\n");
        return;
    }

    printf("A new file named newfile has been created. Press enter to continue...");
    while (getchar() != '\n')
        ;

    if (unlink("./newfile.dat") == -1)
    {
        printf("An error occured while trying to delete a file.\n");
        return;
    }

    printf("The new file has been deleted.\n");

    if (close(fd) == -1)
    {
        printf("Error while closing the file.\n");
        return;
    }
}