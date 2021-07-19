//This function will read the input from argv and set the inital matrix states

//This section is for headers and function prototypes (in that order)
#include <stdlib.h>

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


//These functions will strip out whitespaces and return a pointer to the string of only ints
int str_len(char *str) {
    int i;
    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int   *string_to_int(char *str) {
    int i;
    int j;
    int *intstr;
    i = str_len(str);
    intstr = (int *)malloc(sizeof(int));
    i = 0;
    j = 0;
    while (i < str_len(str))
    {
        if (str[i] >= '0' && str[i] <= '9') 
        {
            intstr[j] = str[i] - '0';
            j++;
        }
        i++;
    }
    return (intstr);
}

struct solve_state put_target_view(struct solve_state current, char *argv)
{
    current.x = 0;
    current.y = 0;
    current.z = 0;
    int k;
    int *intstr;

    intstr = string_to_int(argv);
    k = 0;
    //Set the values of the target_view matrix using the input
    while (current.y < 4)
    {
        while (current.x < current.N)
        {

            current.views[current.y][current.x] = intstr[current.x + (current.y * current.N)];
            current.x++;
        }
        current.x = 0;
        current.y++;
    }
    return (current);
}