//Declare struct here
struct solve_state
{
    int board[10][9][9];
    int views[9][4];
    int N;
    int x;
    int y;
    int z;
};
int					get_cell_value(struct solve_state current, int x, int y);
struct	solve_state	remove_value(struct solve_state current,int x, int y, int z);
struct	solve_state	set_value(struct solve_state current, int x, int y, int z);


//to remove the value given to a cell (at pos (x,y) ) from the 
//possible values of its corresponding row and column.
struct solve_state	update_possible_values(struct solve_state current, int x, int y, int z)
{
	int	i;
	int	j;

	j = 0;
	i = x;
	set_value(current, x, y, z);
	while(j < current.N){
		if (j != y)
			remove_value(current, i, j, z);
		j++;
	}
	j = y;
	i = 0;
	while (i < current.N) {
		if (i != x)
			remove_value(current, i, j, z);
		i++;
	}
	return (current);
}

//Checks the 10th layer of the 3D array to make sure that there is only 
//one possibility,and fetches said possibility from the possible values.
int get_cell_value(struct solve_state current, int x, int y)
{
	int i;

	i = 0;
	if (current.board[9][y][x] == 1) {
		if (current.board[0][y][x] == 1)
			return (1);
		while (current.board[i][y][x] == 0)
			i++;
		return (current.board[i][y][x]);
	}
	return (0);
}

//Takes the value to be removed, puts that index at 0, and decrements the total possible value count by 1
struct solve_state    remove_value(struct solve_state current, int x, int y, int z) {
	current.board[z - 1][y][x] = 0;                 //WHAT IS THE Z VALUE AT THIS POINT?
	current.board[9][y][x] -= 1;
	return (current);
}

//Sets the passed value as a set one for the next iteration
struct solve_state    set_value(struct solve_state current, int x, int y, int z) {
	int zndex;

	zndex = 0;
	current.board[9][x][1] = 1;
	while (zndex < current.N) {
		if (zndex != z - 1)
			current.board[zndex][x][y] = 0;
		zndex++;
	}
	return (current);
}
