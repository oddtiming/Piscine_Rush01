

//This function is to intialize a 3d array with the possible values for each spot on the board based on the edge view values


void    board_initialization(int *target_view, int N)
{
    int possible_values[9][9][9];
    int x;
    int y;
    int z;
    int possible_index;
    int value;

    x = 0;
    y = 0;
    z = 0;
    value = 1;
    possible_index = 0;



   //Initialize the possible values array with
    while (x < N)
    {
        while (y < N)
        {
            while (z < N)
            {
        
                possible_values[z][y][x] = z + 1;
                z++;
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
    //Starting with columndown clue
    while (x < N)
    {
        while (y < N)
        {
            possible_index = (N - target_view[y][x] + 2 + y)
            z = possible_index
            while (z < N)
            {
                possible_values[z][y][x] = 0;
                z++;
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
}

// This expression will allow us to set the possible values for any location on our board
//N is board size, c is the view and d is the distance from the clue starting at 0
N - c + 2 + d 


