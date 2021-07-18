//Will determine what the next possible value is for a given cell. If there is no possible value, returns 0.
int determine_next_digit(int *possible_values, int current_value, int N)
{
    int i;

    i = current_value;
    while (i < N)
    {
        if (possible_values[i])
            return (i);
    }
    return (0);
}