struct solve_state
{
    int board[10][9][9];
    int views[9][4];
    int N;
    int x;
    int y;
    int z;
};
int next_value(struct solve_state current, int x, int y, int z);
int next_cell(struct solve_state current);
struct solve_state	update_possible_values(struct solve_state current, int x, int y, int z);
void    print_board(struct solve_state current);

void    solver(struct solve_state current) {
    int x;
    int y;
    int z;

    z = 0;
    if (next_cell(current) == 100)
        print_board(current);
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