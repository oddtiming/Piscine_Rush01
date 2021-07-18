#include <unistd.h>
void    ft_putchar(char c);

int main(void)
{
    int **board;
    int N;

    N = 4;
    board = &malloc(N * N * sizeof(int))
}

void    ft_putchar(char c)
{
    write(1, &c, sizeof(c));
}