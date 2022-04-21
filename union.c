#include <unistd.h>
int main(int ac, char **av)
{
    char hash[256] = {0}, *s1 = av[1], *s2 = av[2];
    if (ac != 3)
        return 0;
    while (*s1)
    {
        if (hash[(int)*s1] == 0)
        {
            write(1, &*s1, 1);
            hash[(int)*s1]++;
        }
        s1++;
    }
    while (*s2)
    {
        if (hash[(int)*s2] == 0)
        {
            write(1, &*s2, 1);
            hash[(int)*s2]++;
        }
        s2++;
    }
}