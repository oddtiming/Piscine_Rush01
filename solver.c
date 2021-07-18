void    solver(int ***board, int N) {
    int x;
    int y;
    int z;

    if (next_cell(board, N) == 100)
        print_board(board);
    if (next_cell(board, N) == 0)
        return;
    y = next_cell(board, N) / 10;
    x = next_cell(board, N) % 10;
    z = next_value(board, x, y, z, N);
    while (z) {
        solver(update_possible_values(board, x, y, z, N), N); //will pass a new board where the value of z is set for the current cell
        z = next_value(board, x, y, z, N); //will check the next possible value for the current cell
    }
    return;
}