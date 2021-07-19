void    solver(struct solve_state current) {
    int x;
    int y;
    int z;

    if (next_cell(current) == 100)
        print_board(board);
    if (next_cell(current) == 0)
        return;
    y = next_cell(current) / 10;
    x = next_cell(current) % 10;
    z = next_value(current, x, y, z);
    while (z) {
        solver(update_possible_values(current, x, y, z)); //will pass a new board where the value of z is set for the current cell
        z = next_value(current, x, y, z); //will check the next possible value for the current cell
    }
    return;
}