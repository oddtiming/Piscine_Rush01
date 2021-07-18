//Will determine what the next possible value is for a given cell. If there is no possible value, returns 0.
int next_value(int ***possible_values, int x, int y, int current_value, int N)
{
    int i;

    i = current_value;
    while (i < N)
    {
        if (possible_values[i][y][x])
            return (i);
    }
    return (0);
}