int view_count_top(int **board, int N, int x);
int view_count_bottom(int **board, int N, int x);
int view_count_right(int **board, int N, int y);
int view_count_left(int **board, int N, int y);

void    view_count(int **board, int **current_view, N)
{ 
    int i; //the column of the current_view matrix, meaning which column OR row you're checking
    int j; //the row of the current_view matrix, so 0 is colup, 1 is coldown, 2 is rowleft, and 3 is rowright
    
    j = 0;
    while (j < 4)
    {
        i = 0;
        while (i < N) //
        {
            if (j == 0)
                current_view[j][i] = view_count_top(board, N, i);
            if (j == 1)
                current_view[j][i] = view_count_bottom(board, N, i);
            if (j == 2)
                current_view[j][i] = view_count_left(board, N, i);
            if (j == 3)
                current_view[j][i] = view_count_right(board, N, i);
            i++;
        }
        j++;
    }
    return
}

//calculates the view count from the top downwards for a given value of x, so for a given column
int view_count_top(int **board, int N, int x)
{
    int count;
    int highest;
    int y;

    y = 0;
    count = 0;
    highest = 0;
    while (y < N)
    {
        if (highest == N)   //to make sure that we stop as soon as we've reached the highest height
            return (count);
        if (board[y][x] > highest)  //if we've encountered a higher block
        {
            count++;                //we now view one more
            highest = board[y][x];  //set the current position as the new highest block
        }
        y++;
    }
    return (count);
}


int view_count_bottom(int **board, int N, int x)
{
    int count;
    int highest;
    int y;

    y = N - 1; //to start at the end of the column
    count = 0;
    highest = 0;
    while (y  >= 0)
    {
        if (highest == N)
            return (count);
        if (board[y][x] > highest)
        {
            count++;
            highest = board[y][x];
        }
        y--; //because we're going bottom to top
    }
    return (count);
}

int view_count_left(int **board, int N, int y)
{
    int count;
    int highest;
    int x;

    x = 0;
    count = 0;
    highest = 0;
    while (x < N)
    {
        if (highest == N)
            return (count);
        if (board[y][x] > highest)
        {
            count++;
            highest = board[y][x];
        }
        x++;
    }
    return (count);
}

int view_count_right(int **board, int N, int y)
{
    int count;
    int highest;
    int x;

    x = N - 1;
    count = 0;
    highest = 0;
    while (x >= 0)
    {
        if (highest == N)
            return (count);
        if (board[y][x] > highest)
        {
            count++;
            highest = board[y][x];
        }
        x--;
    }
    return (count);
}