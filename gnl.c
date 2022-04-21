#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
char *ft_dup(char *str)
{
    char *s;
    int len = 0;
    while (str[++len])
        ;
    s = malloc(len + 1);
    if (!s)
        return NULL;
    int i = -1;

    while (++i < len)
    {
        s[i] = str[i];
    }
    s[i] = '\0';
    return s;
}
char *gnl(int fd)
{
    char heap[7000000] = {0}, buff;
    int i = 0, byte = 0;
    while ((byte = read(fd, &buff, 1)) && byte > 0)
    {
        heap[i++] = buff;
        if (buff == '\n')
            break;
    }
    heap[i] = 0;
    if (byte < 1 && i == -0)
        return 0;
    return (ft_dup(heap));
}
int main()
{
    int fd = open("t.txt", O_RDONLY);
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
}