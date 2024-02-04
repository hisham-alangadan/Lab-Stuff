#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define SOURCE_FILE "source.txt"
#define DESTINATION_FILE "destination.txt"

int main()
{
    FILE *source = fopen(SOURCE_FILE, "r");
    if (source == NULL)
    {
        printf("Error while opening the source file.\n");
        return 1;
    }

    FILE *desination = fopen(DESTINATION_FILE, "w");

    char buffer;
    while ((buffer = fgetc(source)) != EOF)
    {
        fputc(buffer, desination);
    }
    fflush(desination);

    printf("New file created.");
    while (getchar() != '\n')
        ;
    unlink(DESTINATION_FILE);

    return 0;
}