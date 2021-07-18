void    ft_putchar(char c);

void    print_board(int **board, int N)
{
    int x;
    int y;

    y = 0;
    while(y < N) // goes through every row
    {
        x = 0;
        ft_putchar(board[y][x]] + '0'); //Prints the first digit of the row
        while (x < N)
        {
            ft_putchar(' ');  
            ft_putchar(board[y][x] + '0');
            i++;
        }
        ft_putchar("\n");
        y++;
    }
}