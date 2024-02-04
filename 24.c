/*
    https://youtu.be/Mqb2dVRe0uo?si=3bjw1RHe18EwpTXo
*/

#include <stdio.h>
#include <unistd.h>

void main()
{
    int fd[2];
    if (pipe(fd) != 0)
    {
        printf("Error in creating the pipe.\n");
        return;
    }

    int id = fork();
    if (id < 0)
    {
        printf("Error while creating a fork.\n");
        return;
    }

    if (id != 0) // parent
    {
        close(fd[0]);
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);

        if (write(fd[1], &num, sizeof(int)) == -1)
        {
            printf("Error while writing to the pipe.\n");
            return;
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int n;
        if (read(fd[0], &n, sizeof(int)) == -1)
        {
            printf("Error while reading from the pipe.\n");
            return;
        }

        printf("Got %d from the parent process.\n", n);
        close(fd[0]);

        // primality test
        int isprime = 1;
        int nbytwo = n / 2;
        for (int i = 2; i < nbytwo; i++)
        {
            if ((n % i) == 0)
            {
                isprime = 0;
                break;
            }
        }
        if (isprime == 1)
        {
            printf("%d is a prime number.\n", n);
        }
        else
        {
            printf("%d is not a prime number.\n", n);
        }
    }
}