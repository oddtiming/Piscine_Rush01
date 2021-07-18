int view_count_top(int **board, int N, int x);
int view_count_bottom(int **board, int N, int x);
int view_count_left(int **board, int N, int y);
int view_count_right(int **board, int N, int y);
int respects_clues(int **board, int **target_view, int x, int y, int N);

int is_valid_value(int **board, int **target_view, int value, int x, int y, int N)
{
    int i;
    int j;

    i = 0;
    j = y;
    while (i < N) //Checks if the value is already present in the row
    {
        if (value == board[j][i] && i != x)
            return (0);
        i++;
    }
    j = 0;
    while (j < N) //Checks if the value is already present in the column
    {
        if (value == board[j][i] && j != y)
            return (0);
        j++;
    }
    if (respects_clues(board, target_view, x, y, N) == 0)
        return (0);
    return (1);
}
 // Check that the current value doesn't conflict with the clues, i.e. that the 
int respects_clues(int **board, int **target_view, int x, int y, int N)
{
    if (view_count_top(board, N, x) > target_view[0][x])
        return (0);
    if (view_count_bottom(board, N, x) > target_view[1][x])
        return (0);
    if (view_count_left(board, N, x) > target_view[2][y])
        return (0);
    if (view_count_right(board, N, x) > target_view[3][y])
        return (0);
    return (1);
}