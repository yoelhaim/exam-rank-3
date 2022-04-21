#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#define HEX "0123456789abcdef"
int ft_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
int hex(int nb)
{
    if (nb < 16)
    {
        putchar(HEX[nb]);
    }
    else
    {
        hex(nb / 16);
        hex(nb % 16);
    }
    return 1;
}
int punbr(int n)
{
    long long nb;
    nb = n;
    int r = 0;
    if (nb < 0)
    {
        nb *= nb;
        write(1, "-", 1);
    }
    if (nb < 10)
    {
        putchar(nb + 48);
    }
    else
    {
        punbr(nb / 10);
        punbr(nb % 10);
    }
    return (0);
}
void check(char format, void *val, int *len)
{
    if (format == 'd')
        punbr((int)val);
    else if (format == 'x')
        hex((int)val);
}

int ft_print(char *format, ...)
{
    int i = 0;
    void *next;
    va_list list;
    va_start(list, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format != '%')
                next = va_arg(list, void *);
            check(*format, next, &i);
        }
        else
            i += ft_putchar(*format);
        format++;
    }

    va_end(list);

    return 0;
}
int main()
{
    ft_print("%x", 10);
}