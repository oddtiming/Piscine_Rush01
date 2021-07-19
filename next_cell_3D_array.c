//Will return an int where the first digit is the y position and the second digit is the x position.
//If one of the cell is impossible, will return 0
//If the board is fully populated, next_cell = 100

int next_cell(int ***board, int N) {
    int most_certain;   //will store the smallest amount of possible values
    int next_cell;      //will store the position of the most certain cell
    int i;
    int j;

    most_certain = 9;   //the maximum value for any size board
    j = 0;
    next_cell = 100;
    while (j < N) {
        i = 0;
        while (i < N) {
            if (board[9][j][i] == 0)
                return (0);
            //if that cell has less possible values than the one currently held
            else if (board[9][j][i] < most_certain && board[9][j][i] != 1) { 
                next_cell = (10 * j + i);
                most_certain = board[9][j][i];
            }
            i++;
        }
        j++;
    }
    return (next_cell);
}