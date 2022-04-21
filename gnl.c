#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
char *ft_strdup(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    char *new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (0);
    int i = -1;
    while (++i < len)
        new_str[i] = str[i];
    new_str[i] = 0;
    return (new_str);
}

char *get_next_line(int fd)
{

    char heap[7000000] = {0};
    char *line = NULL;
    char buff;
    int nbyte = 0;
    int i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    while ((nbyte = read(fd, &buff, 1)) && nbyte > 0)
    {
        heap[i++] = buff;
        if (buff == '\n')
            break;
    }
    heap[i] = '\0';
    if (nbyte <= 0 && i == 0)
        return (0);
    return ft_strdup(heap);
}

int main()
{
    int fd = open("t.txt", O_RDONLY);
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
}