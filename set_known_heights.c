void	col_up(int	x, int	view_count, const int	N, int	**board)
{
	int	height;
	int y;

	height = 0;
	y = 0;
	if (view_count == 1)
		board[0][x] = 1;
	if (view_count == N)
	{
		while (y < N)
		{
			board[y][x] = ++height;
			y++;
		}
	}
}

void	col_down(int	x, int	view_count, const int	N, int	**board)
{
	int	height;
	int y;

	height = 0;
	y = N;
	if (view_count == 1)
		board[N - 1][x] = 1;
	if (view_count == N)
	{
		while (y > 0)
		{
			board[y][x] = ++height;
			y--;
		}
	}
}

void	row_left(int	y, int	view_count, const int	N, int	**board)
{
	int	height;
	int x;

	height = 0;
	x = 0;
	if (view_count == 1)
		board[y][0] = 1;
	if (view_count == N)
	{
		while (x < N)
		{
			board[y][x] = ++height;
			x--;
		}
	}
}

void	row_right(int	y, int	view_count, const int	N, int	**board)
{
	int	height;
	int	x;

	height = 0;
	x = N;
	if (view_count == 1)
		board[y][N - 1] = 1;
	if (view_count == N)
	{
		while (x > 0)
		{
			board[y][x] = ++height;
			x--;
		}
	}
}

int	*set_known_heights(int	**target_view, const int	N)
{
	int	board[4][4] = {0};
	int	i;
	int	j;

	j = 0;
	while (j < N)
	{
		i = 0;
		col_up(j, target_view[i][j], N, board);
		i = 1;
		col_down(j, target_view[i][j], N, board);
		i = 2;
		row_left(j, target_view[i][j], N, board);
		i = 3;
		row_right(j, target_view[i][j], N, board);
		j++;
	}
}

void    print_board(int **board, const int N)
{
    int x;
    int y;

    y = 0;
    while(y < N) // goes through every row
    {
        x = 0;
        ft_putchar(board[y][x]) + '0'); //Prints the first digit of the row
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

int	main(void)
{
	const	int N;

	N = 4;
	//const int	N = sqrrt(argc - 1)
	int	target_view[4][4] = {4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2};
	set_known_heights(target_view, N);
	print_board(board, N);
	return (0);
}