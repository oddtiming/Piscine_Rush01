#include <unistd.h>
//Function declarations
void    ft_putchar(char c);
void    ft_putstr(char *c);

//Declare struct here
struct solve_state
{
    int board[10][9][9];
    int views[9][4];
    int N;
    int x;
    int y;
    int z;
};

//Function to print our the entire board array

void print_entire_board(struct solve_state current)
{
    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;
    while (z < current.N) // goes through every row
    {
        y = 0;
        while (y < current.N)
        {
            x = 0;
            while (x < current.N)
            {
                ft_putchar(' ');  
                ft_putchar(current.board[z][y][x] + '0');
                x++;
            }
            y++;
        }
        ft_putchar('\n');
        z++;
    }
}

/*
void    print_views(struct solve_state current)
{
    int x = 0;
    int y = 0;

    while (y < current.N) {
        x = 0;
        while (x < current.N) {
            ft_putchar(current.views[y][x] + '0');
            ft_putchar(' ');
            x++;
        }
        ft_putchar('\n');
        y++;
    }
}*/