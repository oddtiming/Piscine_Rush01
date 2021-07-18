void    ft_putchar(char c);
int     get_cell_value(struct solve_state current, int x, int y);

void    print_board(struct solve_state current)
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
            i++;
        }
        ft_putchar("\n");
        y++;
    }
}

int get_cell_value(struct solve_state current, int x, int y)
{
    int i;

    i = 0;
    if (current.board[9][y][x] == 1) {
        if (current.board[0][y][x] == 1)
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