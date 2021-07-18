int     get_cell_value(int ***possible_values, int x, int y);
void    remove_value(int *possible_values, int x, int y, int value);
void    set_value(board, x, y, z, N);

//to remove the value given to a cell (at pos (x,y) ) from the possible values of its corresponding rows and columns.
int ***update_possible_values(int ***board, int x, int y, int z, int N)
{
    int i;
    int j;

    j = 0;
    i = x;
    set_value(board, x, y, z, N);
    while (j < N) {
        if (j != y)
            remove_value(board, i, j, z);
        j++;
    }
    j = y;
    i = 0;
    while (i < N) {
        if (i != x)
            remove_value(board, i, j, z);
        i++;
    }
    return (board);
}

//Checks the 10th layer of the 3D array to make sure that there is only one possibility, and fetches it from the possible values.
int get_cell_value(int ***possible_values, int x, int y) {
    int i;

    i = 0;
    if (possible_values[0][y][x] != 0)
        return (1);
    if (possible_values[9][y][x] == 1) {
        while (possible_values[i][y][x] == 0)
            i++;
        return (i);
    }
    return (0);
}

//Takes the value to be removed, puts that index at 0, and decrements the total possible value count to 0
void    remove_value(int ***possible_values, int x, int y, int value) {
    possible_values[value - 1][y][x] = 0;
    possible_values[9][y][x] -= 1;
}

//Sets the passed value as a set one for the next iteration
void    set_value(int ***board, int x, int y, int z, int N) {
    int zndex;

    zndex = 0;
    board[9][x][1] = 1;
    while (zndex < N) {
        if (zndex != z - 1)
            board[zndex][x][y] = 0;
    }
}
