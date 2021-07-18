//This is our main function, keep this clean and well commented to we can track what is happening

//This section is for headers and function prototypes (in that order)


//Main starts here
int main(int argc, *argv)
{
    int N;

    //This will tell us if the string contains only valid characters, as well as check that the number of arguments is valid
    valid_character_and_argc_check(argc, argv[1]);

    //This will tell us what the board size is, and will return an error if the number of elements passed by argv[1] is invalid
    N = find_board_size(argv[1]);

    //This will tell is if the digits in the string are valid for the board size
    valid_digit_check(argv[1], N);

    //Now we need to create our matrices to store our board state, our target_views, and our current_views
    //Does this need to return a pointer??
    put_matrix(argv[1], N);
   




    if (arg_check(argc, argv[1]) != 1)
        ft_putchar("ERROR");

    //Now we need to call our put_matrix function     



    return(0);
}
