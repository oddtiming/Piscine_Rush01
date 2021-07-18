//This function will read the input from argv and set the inital matrix states

//This section is for headers and function prototypes (in that order)




//Function to fill board with 0s
void    put_zero_board(int **array, int N)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < N)
    {
        while (j < N)
        {
            board[i][j] = 0;
            j++;
        }
    i++;
    }
}
//Function to fill current_view with 0s
void    put_zero_view(int **array, int N)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < N)
        {
            current_view[i][j] = 0;
            j++;
        }
    i++;
    }
}

//Does this need to return a pointer??
int *put_matrix(char *argv, int N)
{
    //Here we are declaring our 3 matrices (board, target_view, and current_view)
    int board[9][9];
    int target_view[4][9];
    int current_view[4][9];
    int i;
    int j;
    
    i = 0;
    j = 0;
    //Initialize board and current_view with all 0s
    put_zero_board(board, N);
    put_zero_view(current_view, N);

    //Set the values of the target_view matrix using the input
    while (j < 4)
    {
        while (i < N)
        {
            target_view[j][i] = argv[j + i] - '0';
            i++;
        }
        j++;
    }
}
