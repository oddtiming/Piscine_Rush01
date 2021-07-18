#include <unistd.h>
#include <stdlib.h>
void    ft_putchar(char c);
void    print_board(int board[10][4][4], int N);
int     get_cell_value(int possible_values[10][4][4], int x, int y);

int main(void)
{
    /int board[10][4][4] =   {{{1, 0, 0., 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 0}}, 
                            {{0, 2, 0, 0}, {2, 0, 0, 0}, {0, 0, 0, 2}, {0, 0, 2, 0}},
                            {{0, 0, 3, 0}, {0, 3, 0, 0}, {3, 0, 0, 0}, {0, 0, 0, 3}},
                            {{0, 0, 0, 4}, {0, 0, 4, 0}, {0, 4, 0, 0}, {4, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}};
                              
    int N;

    N = 4;


 
    print_board(board, N);
    return (0);
}

void    print_board(int board[10][4][4], int N)
{
    int x;
    int y;

    y = 0;
    while(y < N) // goes through every row
    {
        x = 0;
        ft_putchar(get_cell_value(board, x, y) + '0'); //Prints the first digit of the row
        x++;
        while (x < N)
        {
            ft_putchar(' ');  
            ft_putchar(get_cell_value(board, x, y) + '0');
            x++;
        }
        ft_putchar('\n');
        y++;
    }
}

int get_cell_value(int possible_values[10][4][4], int x, int y)
{
    int i;

    i = 0;
    if (possible_values[0][y][x] != 0)
        return (1);
    if (possible_values[9][y][x] == 1) {
        while (possible_values[i][y][x] == 0)
            i++;
        return (i);
    }
    return (0);
}

void    ft_putchar(char c)
{
    write(1, &c, sizeof(c));
}
