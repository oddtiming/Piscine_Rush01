#include <unistd.h>
#include <stdlib.h>
void    ft_putchar(char c);
void    print_board(int *board, int N);
int     get_cell_value(int *possible_values, int x, int y, int N);

int main(void)
{
    /*int board[10][4][4] = {{{1, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 0}}, 
                            {{0, 2, 0, 0}, {2, 0, 0, 0}, {0, 0, 0, 2}, {0, 0, 2, 0}},
                            {{0, 0, 3, 0}, {0, 3, 0, 0}, {3, 0, 0, 0}, {0, 0, 0, 3}},
                            {{0, 0, 0, 4}, {0, 0, 4, 0}, {0, 4, 0, 0}, {4, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}};
                              */
    int N;

    N = 4;
    //int *board = (int *)malloc(N*N*10*(sizeof(int)));
    int board[]  =         {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 
                            0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0,
                            0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3,
                            0, 0, 0, 4, 0, 0, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    print_board(board, N);
    return (0);
}

void    print_board(int *board, int N)
{
    int x;
    int y;

    y = 0;
    while(y < N) // goes through every row
    {
        x = 0;
        ft_putchar(get_cell_value(board, x, y, N) + '0'); //Prints the first digit of the row
        x++;
        while (x < N)
        {
            ft_putchar(' ');  
            ft_putchar(get_cell_value(board, x, y, N) + '0');
            x++;
        }
        ft_putchar('\n');
        y++;
    }
}

int get_cell_value(int *possible_values, int x, int y, int N)
{
    int i;

    i = 0;
    if (possible_values[N * y + x]!= 0) //because at the 0th layer z == 0
        return (1);
    if (possible_values[N * N * (9) + N * y + x] == 1) {
        while (possible_values[N * N * i + N * y + x] == 0)
            i++;
        return (possible_values[N * N * (i) + N * y + x]);
    }
    return (0);
}

void    ft_putchar(char c)
{
    write(1, &c, sizeof(c));
}
