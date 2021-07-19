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

//Run a check to ensure that the command line inputs are valid
//Need to ensure that number of strings passed with argc is valid for board size
//Need to make sure that the values passed in argv strings are valid for board size
//Return 1 if arg check passes, return 0 if arg check is ERROR


//This function will check if the string contains only valid characters
//Return of 1 is valid, return of 0 is error

int valid_character_and_argc_check(int argc, char *argv)
{
    int i;

    i = 0;
    if (argc != 2)
        return (0);
    while (argv[i] != '\0')
    {
        if (((argv[i] > '9') || (argv[i] < '0')) && (argv[i] != ' '))
            return (0);
        i++;
    }
    i = 1;
    while (argv[i] != '\0')
    {
        if ((argv[i] == ' ') && ((argv[i - 1] < '0') || argv[i - 1] > '9')) //if there's more than one space
            return (0);
        i++;
    }
    return (1);
}

//This function will check if the digits in the string are valid for the current board size
int valid_digit_check(char *argv, int N)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (((argv[i] > N + '0') || (argv[i] < '1')) && argv[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

int find_board_size(char *argv)
{
    int n;
    int count;

    count = 0;
    n = 0;
    //First we must count the number of elements in the string
    while (argv[n] != '\0')
    {
        if (argv[n] != ' ')
            count++;
        n++;
    }
    n = count;
    //Now we need to find check if the number of elements is evenly divisible by 4
    if ((n % 4) != 0)
        return 0;
    else
        return (n / 4);
}

//This function is a wrapper to call the other functions and save space in main
struct solve_state arg_check_board_size(struct solve_state current, int argc, char *argv)
{
    //This will tell us if the string contains only valid characters, as well as check that the number of arguments is valid
    if (valid_character_and_argc_check(argc, argv) != 1)
    {
        current.N = 0;
        return (current);
    }
    //This will tell us what the board size is, and will return an error if the number of elements passed by argv[1] is invalid
    current.N = find_board_size(argv);

    //This will tell is if the digits in the string are valid for the board size
    if (valid_digit_check(argv, current.N) != 1)
    {
        current.N = 0;
        return (current);
    }  
    return (current);
}