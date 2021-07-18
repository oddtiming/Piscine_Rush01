int is_solution(int **current_view, int **target_view, int N)
{
    int i;
    int j;

    j = 0;
    while (j < 4)
    {
        i = 0;
        while (i < N)
        {
            if (current_view[j][i] != target_view[j][i])
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}