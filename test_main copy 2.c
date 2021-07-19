#include <unistd.h>
#include <stdlib.h>
struct solve_state
{
    int board[10][4][4];
    int views[4][9];
    int N;
};
void    ft_putchar(char c);
void    print_board(struct solve_state current);
int     get_cell_value(struct solve_state current, int x, int y);
struct solve_state    populate_array(struct solve_state current);


int main(void)
{
    struct solve_state current;
    current.N = 4;
    current = populate_array(current);

   /* current.board[0][0][0] = 1;
    current.board[0][1][3] = 1;
    current.board[0][2][2] = 1;
    current.board[0][3][1] = 1;
    current.board[1][0][1] = 2;
    current.board[1][1][0] = 2;
    current.board[1][2][3] = 2;
    current.board[1][3][2] = 2;
    current.board[2][0][2] = 3;
    current.board[2][1][1] = 3;
    current.board[2][2][0] = 3;
    current.board[2][3][3] = 3;
    current.board[3][0][3] = 4;
    current.board[3][1][2] = 4;
    current.board[3][2][1] = 4;
    current.board[3][3][0] = 4;
    current.board[9][0][0] = 1;
    current.board[9][0][1] = 1;
    current.board[9][0][2] = 1;
    current.board[9][0][3] = 1;
    current.board[9][1][0] = 1;
    current.board[9][1][1] = 1;
    current.board[9][1][2] = 1;
    current.board[9][1][3] = 1;
    current.board[9][2][0] = 1;
    current.board[9][2][1] = 1;
    current.board[9][2][2] = 1;
    current.board[9][2][3] = 1;
    current.board[9][3][0] = 1;
    current.board[9][3][1] = 1;
    current.board[9][3][2] = 1;
    current.board[9][3][3] = 1;*/

    /*    {{{1, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 0}}, 
                            {{0, 2, 0, 0}, {2, 0, 0, 0}, {0, 0, 0, 2}, {0, 0, 2, 0}},
                            {{0, 0, 3, 0}, {0, 3, 0, 0}, {3, 0, 0, 0}, {0, 0, 0, 3}},
                            {{0, 0, 0, 4}, {0, 0, 4, 0}, {0, 4, 0, 0}, {4, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                            {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}};*/
                              
 
    print_board(current);
    return (0);
}

struct solve_state    populate_array(struct solve_state current)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < 10) {
        j = 0;
        while (j < current.N){
            i = 0;
            while (i < current.N){
                current.board[k][j][i] = 0;
                i++;
            }
            j++;
        }
        k++;
    }
    return (current);
}

void    print_board(struct solve_state current)
{
    int x;
    int y;

    y = 0;
    while (y < current.N) // goes through every row
    {
        x = 0;
        ft_putchar(get_cell_value(current, x, y) + '0'); //Prints the first digit of the row
        x++;
        while (x < current.N)
        {
            ft_putchar(' ');  
            ft_putchar(get_cell_value(current, x, y) + '0');
            x++;
        }
        ft_putchar('\n');
        y++;
    }
}

int get_cell_value(struct solve_state current, int x, int y)
{
    int i;

    i = 0;
    if (current.board[9][y][x] == 1) {
        if (current.board[0][y][x] != 0)
            return (1);
        while (current.board[i][y][x] == 0)
            i++;
        return (current.board[i][y][x]);
    }
    return (0);
}

void    ft_putchar(char c)
{
    write(1, &c, sizeof(c));
}
