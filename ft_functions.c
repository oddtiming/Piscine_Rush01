//This file will contain all of the basic ft_functions that we need to use

//This section is for headers and function prototypes (in that order)
#include <unistd.h>

//ft_functions start here
void    ft_putchar(char c)
{
    write(1, &c, sizeof(c));
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;

    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}