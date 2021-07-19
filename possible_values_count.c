struct solve_state
{
    int board[10][9][9];
    int views[9][4];
    int N;
    int x;
    int y;
    int z;
};

struct solve_state possible_values_count(struct solve_state current) {
    int x;
    int y;
    int z;

    x = 0;
    while(x < current.N) {
        y = 0;
        while (y < current.N) {
            z = 0;
            while (z < current.N) {
                if (current.board[z][y][x] != 0)
                    current.board[9][y][x]++;
                z++;
            }
        y++;
        }
    x++;
    }
    return (current);
}


