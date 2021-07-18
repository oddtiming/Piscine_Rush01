int is_valid_value(int **board, int value, int x, int y, int N)
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
    
}