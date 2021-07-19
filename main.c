//This is our main function, keep this clean and well commented to we can track what is happening


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
//This section is for headers and function prototypes (in that order)
#include <unistd.h>
#include <stdlib.h>
struct solve_state valid_character_and_argc_check(int argc, char *argv);
struct solve_state arg_check_board_size(struct solve_state current, int argc, char *argv);
struct solve_state put_target_view(struct solve_state current, char *argv);
struct solve_state board_initialization(struct solve_state current);
void    solver(struct solve_state current);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    print_board(struct solve_state current);
void    print_entire_board(struct solve_state current);





//Main starts here
int main(int argc, char **argv)
{
   //Declate struct variables
   struct solve_state current;

    //Run our function to check if input is valid and find the size of the board, if inputs are invalid return error
    current.N = 0;
    current = arg_check_board_size(current, argc, argv[1]);
    if (current.N < 4)
    {
        ft_putstr("Error1");
        ft_putchar('\n');
        return (0);
    }
   

    //Now we need to set our target view matrix with the values passed from command line
    current = put_target_view(current, argv[1]);

    //Now we run our board initialization function to set our initial board state
    current = board_initialization(current);

    
    //Finally we can print our solution and end the program, or print error if we dont find one
    //This function will return an int S, where S = 1 means a valis solution was found, or S = 0 means there was no solution
    solver(current);
    ft_putstr("Error2");
    ft_putchar('\n');
    return(0);
}
