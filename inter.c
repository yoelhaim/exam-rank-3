#include <unistd.h>

int main(int ac, char **av)
{
    char *s1 = av[1], *s2 = av[2], hash[256];
    if (ac != 3)
        return 0;
    while (*s2)
    {
        hash[(int)*s2] = 1;
        s2++;
    }
    while (*s1)
    {
        if (hash[(int)*s1] == 1)
        {
            write(1, &*s1, 1);
            hash[(int)*s1] = 0;
        }
        s1++;
    }
}